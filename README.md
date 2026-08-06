# ESP32 Web LED Control

A web-based IoT project that controls the built-in LED of an ESP32 through an online interface.

The ESP32 connects to Wi-Fi and periodically reads a control value from a web server. When the server value is `1`, the LED turns ON. When the value is `0`, the LED turns OFF.

---

## Live Website

[Open the ESP32 LED Control Website](http://faisal-esp32-control.xo.je)

---

## Project Objectives

- Connect an ESP32 board to a Wi-Fi network.
- Send HTTP requests from the ESP32 to a web server.
- Control the ESP32 built-in LED remotely.
- Create a responsive web interface with ON and OFF buttons.
- Use PHP to update the LED state stored on the server.
- Demonstrate communication between hardware and a web application.

---

## Technologies and Tools

- ESP32 Dev Module
- Arduino IDE
- Arduino C++
- Wi-Fi
- HTTP
- HTML5
- CSS3
- JavaScript
- PHP
- InfinityFree Web Hosting
- GitHub

---

## Project Structure

```text
ESP32-Web-LED-Control/
├── ESP32-Web-LED-Control.ino
├── index.html
├── style.css
├── script.js
├── control.php
├── t.txt
├── ESP32-Web-LED-Control-Demo.mp4.MOV
└── README.md
```

---

## System Workflow

```text
Web Interface
     │
     ▼
control.php
     │
     ▼
   t.txt
     │
     ▼
HTTP Request from ESP32
     │
     ▼
Built-in LED on GPIO 2
```

1. The user presses **Turn ON** or **Turn OFF** on the website.
2. JavaScript sends the selected state to `control.php`.
3. The PHP file writes either `1` or `0` into `t.txt`.
4. The ESP32 reads `t.txt` from the server using an HTTP GET request.
5. The built-in LED changes according to the received value.

---

## LED Control Values

| Server Value | ESP32 Action |
|---|---|
| `1` | LED turns ON |
| `0` | LED turns OFF |

---

## Hardware Requirements

- ESP32 development board
- USB data cable
- Computer with Arduino IDE
- Wi-Fi connection
- Built-in LED connected to GPIO 2

No external LED or breadboard is required because the project uses the ESP32 built-in LED.

---

## Web Application

The web application contains two control buttons:

- **Turn ON:** writes `1` to `t.txt`.
- **Turn OFF:** writes `0` to `t.txt`.

The website files are:

```text
index.html
style.css
script.js
control.php
t.txt
```

All web files must be uploaded to the same directory on a PHP-supported web server.

---

## Arduino Configuration

Before uploading the Arduino code, replace the Wi-Fi placeholders with the correct network information:

```cpp
const char* WIFI_NAME = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
```

The server URL used by the ESP32 is:

```cpp
const char* SERVER_URL =
  "http://faisal-esp32-control.xo.je/t.txt";
```

The built-in LED pin is defined as:

```cpp
#define LED_PIN 2
```

---

## Uploading the Arduino Code

1. Open `ESP32-Web-LED-Control.ino` in Arduino IDE.
2. Select:

```text
Tools → Board → ESP32 Arduino → ESP32 Dev Module
```

3. Select the correct COM port.
4. Enter the Wi-Fi name and password.
5. Upload the code to the ESP32.
6. Open the Serial Monitor.
7. Set the baud rate to:

```text
115200
```

After a successful connection, the Serial Monitor displays information similar to:

```text
WiFi connected
IP address: 172.20.10.3
Server value: 1
LED is ON
```

When the OFF button is pressed, it displays:

```text
Server value: 0
LED is OFF
```

---

## Web Server Deployment

The web files were deployed using InfinityFree hosting.

Upload the following files into the server's `htdocs` directory:

```text
index.html
style.css
script.js
control.php
t.txt
```

The PHP server must have permission to modify `t.txt`.

---

## Demonstration Video

[Watch the ESP32 Web LED Control Demo](ESP32-Web-LED-Control-Demo.mp4.MOV)

The demonstration shows:

- The ESP32 connecting to Wi-Fi.
- The website sending ON and OFF commands.
- The ESP32 reading the server value.
- The built-in LED responding to the web commands.
- Serial Monitor messages confirming the LED status.

---

## Project Results

The project successfully demonstrated:

- Wi-Fi communication using ESP32.
- HTTP communication between the ESP32 and a web server.
- Remote LED control through a website.
- PHP-based server-side file updates.
- Real-time hardware response to web commands.
- Integration between embedded systems and web development.

---

## Security Note

Wi-Fi credentials are not included in the public repository.

Use your own network information in the Arduino code before uploading it to the ESP32:

```cpp
const char* WIFI_NAME = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
```

---

## Author

**Faisal Albeshri**  
Computer Engineering Student
