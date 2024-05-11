# WebSocket Button Control

WebSocket Button Control is an Arduino sketch that enables wireless control of a button using an ESP8266 microcontroller. It provides a web interface for users to interact with the button remotely via a WebSocket connection.

## Description
The WebSocket Button Control code allows you to control a button wirelessly through a web interface served by an ESP8266 microcontroller. It creates a WebSocket server that listens for commands to turn the button on or off. Additionally, it hosts a simple web page with a button interface for user interaction.

## Hardware Requirements
- ESP8266 microcontroller
- Button connected to pin D4 (GPIO 2)
- Buzzer connected to pin D1 (GPIO 5)

## Software Dependencies
- ESP8266WiFi library
- WebSocketsServer library
- ESPAsyncTCP library
- ESPAsyncWebServer library

## Setup Instructions
1. Connect the ESP8266 microcontroller to your computer via USB.
2. Open the Arduino IDE and install the necessary libraries mentioned above.
3. Copy and paste the provided code into your Arduino sketch.
4. Modify the SSID and password variables with your WiFi credentials.
5. Upload the code to the ESP8266 microcontroller.

## Usage
1. After uploading the code, the ESP8266 will create a WiFi access point with the SSID "IoT Home Automation" and the specified password.
2. Connect your device (e.g., smartphone, laptop) to this WiFi network.
3. Open a web browser and navigate to the IP address of the ESP8266 (usually `192.168.4.1`).
4. You will be presented with a web page containing a single button labeled "Push."
5. Clicking the button will send a command to the ESP8266 via WebSocket to turn the button on momentarily and then off.
6. Additionally, when the button is turned on, the buzzer connected to pin D1 will produce a sound.

## Notes
- The HTML for the web interface is stored in PROGMEM to save memory.
- The WebSocket server listens on port 81 for incoming connections.
- The web server serves the HTML page on port 80.
- The `handleWebSocketMessage()` function handles WebSocket messages, interpreting "ON" as turning the button on and "OFF" as turning it off.
- The `loop()` function is dedicated to handling WebSocket events.

## Compatibility
This code is specifically designed for the ESP8266 microcontroller and may not be compatible with other platforms without modification.
