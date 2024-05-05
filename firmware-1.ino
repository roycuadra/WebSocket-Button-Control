#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "IoT Home Automation"; // Access Point Name 
const char* password = "admin12345";

const int output5 = 2; // Connect To D4 PIN
const int buzzerPin = 5; // Connect To D1 PIN for Buzzer

WebSocketsServer webSocket = WebSocketsServer(81);
AsyncWebServer server(80); // Initialize AsyncWebServer object

// Declaration of INDEX_HTML globally
const char PROGMEM INDEX_HTML[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>WebSocket Button Control</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
      margin: 0;
      background-color: #f2f2f2;
    }
    .button-container {
      text-align: center;
      background-color: #333;
      padding: 20px;
      border-radius: 10px;
      box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
    }
    h1 {
      color: white;
      font-size: 24px;
      margin-bottom: 20px;
    }
    button {
      width: 100px;
      height: 100px;
      border-radius: 50%;
      font-size: 16px;
      background-color: #4CAF50;
      color: white;
      border: 3px solid #4CAF50; /* Border color same as button background */
      cursor: pointer;
      transition: background-color 0.3s ease, border-color 0.3s ease; /* Added border-color transition */
    }
    button:hover {
      background-color: #45a049;
      border-color: #45a049; /* Change border color on hover */
    }
    button:active {
      background-color: #f44336;
      border-color: #f44336; /* Change border color on active state */
    }
    button:focus {
      outline: none;
    }
    /* Disable copy and paste */
    body {
      -webkit-touch-callout: none; /* iOS Safari */
      -webkit-user-select: none; /* Safari */
      -khtml-user-select: none; /* Konqueror HTML */
      -moz-user-select: none; /* Firefox */
      -ms-user-select: none; /* Internet Explorer/Edge */
      user-select: none; /* Non-prefixed version, currently supported by Chrome and Opera */
    }
    @media screen and (max-width: 600px) {
      button {
        font-size: 14px;
        width: 80px;
        height: 80px;
      }
    }
  </style>
</head>
<body>
  <div class="button-container">
    <h1>Control Panel</h1>
    <button onclick="buttonPressed()">Push</button>
  </div>
  <script>
    var socket = new WebSocket("ws://192.168.4.1:81");

    function buttonPressed() {
      socket.send("ON");
      setTimeout(() => {
        socket.send("OFF");
      }, 150); // sending OFF after 200ms (adjust as needed)
    }
  </script>
</body>
</html>

)rawliteral";

void handleWebSocketMessage(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
    case WStype_TEXT:
      if (strcmp((char*)payload, "ON") == 0) {
        digitalWrite(output5, LOW);
        tone(buzzerPin, 1000); // Turn buzzer ON
      } else if (strcmp((char*)payload, "OFF") == 0) {
        digitalWrite(output5, HIGH);
        noTone(buzzerPin); // Turn buzzer OFF
      }
      break;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(output5, OUTPUT);
  digitalWrite(output5, HIGH);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.print("Setting AP (Access Point)...");
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  webSocket.begin();
  webSocket.onEvent(handleWebSocketMessage);

  // Handle HTTP requests
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", INDEX_HTML);
  });

  server.begin();
}

void loop() {
  webSocket.loop();
}
