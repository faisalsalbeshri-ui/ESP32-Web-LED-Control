<?php
header('Content-Type: application/json; charset=utf-8');
header('Cache-Control: no-store, no-cache, must-revalidate, max-age=0');
$file = __DIR__ . '/t.txt';
$state = $_GET['state'] ?? $_POST['state'] ?? null;
if ($state === null) {
    $currentState = file_exists($file) ? trim((string) file_get_contents($file)) : '0';
    echo json_encode(['success' => true, 'state' => $currentState === '1' ? '1' : '0']);
    exit;
}
$state = (string) $state;
if ($state !== '0' && $state !== '1') {
    http_response_code(400);
    echo json_encode(['success' => false, 'message' => 'State must be 0 or 1.']);
    exit;
}
$result = file_put_contents($file, $state, LOCK_EX);
if ($result === false) {
    http_response_code(500);
    echo json_encode(['success' => false, 'message' => 'Unable to update t.txt. Check file permissions.']);
    exit;
}
echo json_encode(['success' => true, 'state' => $state]);
?>
