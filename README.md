# 🏠 Smart Home Automation using ESP8266 | Cloud-Based Control with Sensors & Servo

This project demonstrates a **cloud-connected smart home system** built using the **ESP8266 NodeMCU**, enabling remote control of appliances and monitoring environmental data through the **Arduino IoT Cloud**. It supports:

- Switching **lights and fans** (via relay modules)
- Operating a **servo-based gate**
- Monitoring **temperature and humidity** in real-time with a **DHT11** sensor

Everything runs over Wi-Fi, ensuring seamless home control from anywhere.

---

## 🌟 Highlights

- 🔌 Control home appliances remotely
- 🚪 Open and close gate using servo motor
- 🌡️ Monitor room temperature and humidity live
- ☁️ Secure cloud connectivity with Arduino IoT Cloud
- 🔄 Auto Wi-Fi reconnection logic for reliability

---

## 🧰 Components Required

| Part              | Function                             |
|------------------|--------------------------------------|
| ESP8266 NodeMCU  | Wi-Fi-enabled microcontroller         |
| Relay Module     | Used to switch light & fan            |
| DHT11 Sensor     | Measures ambient temperature & humidity |
| Servo Motor      | Controls mechanical gate action       |
| Jumper Wires     | Circuit connections                   |

---

## 🧪 Software Stack

- **Arduino IDE** – Code development & upload
- **Arduino IoT Cloud** – Dashboard for live control
- **Libraries Used**:
  - `ESP8266WiFiMulti.h`
  - `DHT.h`
  - `Servo.h`

---

## 🔌 Wiring & Pin Mapping

| Device           | Connected to ESP8266 Pin |
|------------------|--------------------------|
| Light Relay      | D1 (GPIO5)               |
| Fan Relay        | D2 (GPIO4)               |
| Servo Motor      | D5 (GPIO14)              |
| DHT11 Sensor     | D8 (GPIO15)              |

---

## 🔄 Functionality Overview

- Upon startup, the ESP8266 connects to the configured Wi-Fi.
- Sensor values are continuously read and uploaded to the cloud dashboard.
- Based on user input from the cloud:
  - **Relays** toggle lights and fan.
  - **Servo motor** triggers gate mechanism (open/close).
- If Wi-Fi drops, the device attempts reconnection automatically.

---

## 🌐 Cloud Variables (Arduino IoT Cloud)

| Cloud Variable  | Data Type | Role                         |
|-----------------|-----------|------------------------------|
| `light`         | Boolean   | Light control (ON/OFF)       |
| `fan`           | Boolean   | Fan control (ON/OFF)         |
| `gateControl`   | Boolean   | Gate servo trigger           |
| `temperature`   | Float     | Current temperature (°C)     |
| `humidity`      | Float     | Current humidity (%)         |

---

## ⚙️ Setup Instructions

1. Open Arduino IDE and install necessary libraries.
2. Include your **Wi-Fi SSID and password** in the sketch.
3. Sync your sketch with **Arduino IoT Cloud** and ensure variables match.
4. Wire the components as per the table above.
5. Upload code to ESP8266 and monitor via serial or cloud dashboard.

---

## 🧠 Logic Snapshot

```cpp
if (WiFi.status() != WL_CONNECTED) {
  WiFi.begin(ssid, password);
}

temperature = dht.readTemperature();
humidity = dht.readHumidity();

if (light) digitalWrite(relay1, HIGH); else digitalWrite(relay1, LOW);
if (fan) digitalWrite(relay2, HIGH); else digitalWrite(relay2, LOW);

if (gateControl) {
  servo.write(90);  // Open
  delay(1500);
  servo.write(0);   // Close
}
