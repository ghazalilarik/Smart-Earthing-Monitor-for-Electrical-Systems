# Smart Earthing Monitor for Electrical Systems ⚡🌍

Electrical safety just got smarter! This project monitors the quality of the earthing in your electrical systems using an ESP8266 and provides real-time feedback on the earthing resistance. Perfect for electricians, engineers, or anyone who values safety. ⚡

---

## Features 🚀
- Measure earthing resistance in real-time.
- Wi-Fi-enabled interface for remote monitoring.
- Visual feedback on earthing status: "Good" or "Poor."

---

## Requirements 🛠️
- ESP8266 (e.g., NodeMCU, Wemos D1 Mini).
- Analog input sensor (simulate resistance measurement).
- Jumper wires and a breadboard.
- Arduino IDE installed on your computer.

---

## Installation 🧑‍💻
1. Install the Arduino IDE.
2. Add ESP8266 board support to Arduino IDE:
   - Open **File** > **Preferences**.
   - Add this URL to Additional Board Manager URLs:  
     `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
   - Go to **Tools** > **Board** > **Boards Manager** and install "esp8266".
3. Connect your ESP8266 to your computer.
4. Open the `earthing_monitor.ino` file in Arduino IDE.
5. Replace `YourWiFiSSID` and `YourWiFiPassword` with your Wi-Fi credentials.
6. Select the correct **Board** and **Port** from the Tools menu.
7. Click **Upload**.

---

## How to Use 🕹️
1. Power your ESP8266 after uploading the code.
2. Open the Serial Monitor in Arduino IDE to find the ESP8266's IP address.
3. Open a browser and enter the IP address.
4. View real-time earthing resistance and status.

---

Here is a basic **circuit diagram** description for the **Smart Earthing Monitor for Electrical Systems** using ESP8266. You can follow these steps to visualize it.

### **Components:**
1. **ESP8266 (NodeMCU/Wemos D1 Mini)**  
2. **Analog Input (Simulated Resistance Sensor or Potentiometer)**  
3. **Resistors (optional for safe measurements)**  
4. **Breadboard and Jumper Wires**  

---

### **Circuit Connections:**
| ESP8266 Pin | Connection               |
|-------------|--------------------------|
| A0          | To simulated resistance  |
| GND         | To the negative terminal |
| 3.3V        | To the positive terminal |

---

### **Explanation:**
1. **Simulated Resistance Sensor**:
   - Use a potentiometer or resistor to simulate the varying resistance that mimics the earthing resistance.
   - Connect one terminal of the potentiometer to the **3.3V** pin on the ESP8266.
   - Connect the middle pin (wiper) of the potentiometer to the **A0** pin on the ESP8266.
   - Connect the third terminal of the potentiometer to the **GND** pin.

2. **ESP8266 Power**:
   - Ensure the ESP8266 is powered via USB or an external power source.

3. **Safety**:
   - If working with real-world earthing systems, always use proper sensors designed to measure resistance safely without exposing the ESP8266 to high voltages.

---

## Contributing 🤝
Feel free to fork and improve this project. PRs are welcome!

---

## License 📜
MIT License. Use it, modify it, make it yours!
