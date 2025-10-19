# WebSocket Button Control

## Video Demonstration
Check this out [Video Demonstration](https://www.dropbox.com/scl/fi/bhwhayw5pzsaq8l1o01bk/VID_20240430_162429.mp4?rlkey=pt3q5pkhtozs4dacati978z99&st=lgvf5v1u&dl=0) to see the WebSocket Button Control in action.

## Description
The WebSocket Button Control code allows you to control a button wirelessly through a web interface served by an ESP8266 microcontroller. It creates a WebSocket server that listens for commands to turn the button on or off. Additionally, it hosts a simple web page with a button interface for user interaction.

## ⚠️ Disclaimer

This project is for educational and experimental purposes only. The creator is not responsible for any damage, injury, or loss caused by using this project. Always handle electronics safely and operate the device in a controlled environment.

## Hardwares
- ESP8266 microcontroller
- Relay connected to pin D4 (GPIO 2)
- High Voltage Generator(200kv)

## Software Dependencies
- ESP8266WiFi library
- WebSocketsServer library
- ESPAsyncTCP library
- ESPAsyncWebServer library

## License
This project is open-source and available under the MIT License. See the [LICENSE](LICENSE) file for more details.
