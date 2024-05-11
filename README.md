# WebSocket Button Control

## Video Demonstration
Check out this [Video Demonstration](https://www.dropbox.com/scl/fi/bhwhayw5pzsaq8l1o01bk/VID_20240430_162429.mp4?rlkey=pt3q5pkhtozs4dacati978z99&st=lgvf5v1u&dl=0) to see the WebSocket Button Control in action.

## Description
The WebSocket Button Control code allows you to control a button wirelessly through a web interface served by an ESP8266 microcontroller. It creates a WebSocket server that listens for commands to turn the button on or off. Additionally, it hosts a simple web page with a button interface for user interaction.

## Hardware Requirements
- ESP8266 microcontroller
- Relay connected to pin D4 (GPIO 2)
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
