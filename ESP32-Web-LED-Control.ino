#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define LED_PIN 2

// ضع بيانات الشبكة الحقيقية هنا عند تشغيل المشروع
const char* WIFI_NAME = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const char* SERVER_URL =
  "http://faisal-esp32-control.xo.je/t.txt";

void connectToWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(1000);

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  Serial.print("Connecting to WiFi");

  int attempts = 0;

  while (WiFi.status() != WL_CONNECTED && attempts < 40) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi connection failed");
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  connectToWiFi();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconnecting to WiFi...");
    connectToWiFi();
    delay(3000);
    return;
  }

  WiFiClient client;
  HTTPClient http;

  // إضافة قيمة متغيرة لمنع قراءة نسخة قديمة من الملف
  String requestURL =
    String(SERVER_URL) + "?time=" + String(millis());

  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);

  if (!http.begin(client, requestURL)) {
    Serial.println("Unable to start HTTP connection");
    delay(3000);
    return;
  }

  http.addHeader("User-Agent", "ESP32-Web-LED-Control");

  int httpCode = http.GET();

  if (httpCode == HTTP_CODE_OK) {
    String payload = http.getString();
    payload.trim();

    Serial.print("Server value: ");
    Serial.println(payload);

    if (payload == "1") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED is ON");
    } else if (payload == "0") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED is OFF");
    } else {
      Serial.println("Invalid server value");
    }
  } else {
    Serial.print("HTTP error code: ");
    Serial.println(httpCode);
  }

  http.end();
  delay(3000);
}