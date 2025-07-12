# 🏠 IoT Home Automation using ESP8266 with Google Home and Manual Control

This project demonstrates a smart home automation system that controls appliances using the **NodeMCU ESP8266**. It supports **dual control**:  
- 📱 Voice control via **Google Home App**  
- ✋ Manual control via **physical switches**

No third-party platforms like IFTTT are used — the system works over **local Wi-Fi communication**, providing fast and reliable smart control.

---

## 🚀 Features

- 🎙️ Voice commands through Google Assistant (via Google Home App)
- ✋ Manual switch-based control
- 🔁 Real-time state sync — use either method to toggle appliances
- 🌐 Works over local Wi-Fi (no external cloud or IFTTT dependency)
- 💡 Controls lights, fans, or any Door Gate via relays

---

## 🧰 Tech Stack

| Component     | Description                         |
|--------------|-------------------------------------|
| NodeMCU ESP8266 | Wi-Fi-enabled microcontroller        |
| Google Home App | Voice assistant for appliance control |
| Relay Module  | Controls AC loads (light, fan, etc.) |
| Manual Switch | For physical control (toggle/push)  |
| Arduino IDE   | To program the ESP8266              |

---

## 🔌 System Overview

- The ESP8266 is connected to relays and manual switches.
- Voice commands from Google Home trigger appliance actions (either via HTTP requests from the app or via routines).
- Manual switches are wired to GPIOs and also toggle appliance state.
- State is handled efficiently on the microcontroller side.

---

## 🛠️ Hardware Requirements

- ✅ NodeMCU ESP8266
- ✅ Relay Module (1/2/4 Channel)
- ✅ Manual Switches (push or toggle)
- ✅ Appliances (Bulbs/Fans)
- ✅ Breadboard, jumper wires
- ✅ Power supply (5V)

---

## 🔧 Setup Instructions

### 1. Circuit Setup
- Connect **relays** to digital GPIO pins of ESP8266.
- Connect **manual switches** to GPIOs using pull-up/pull-down configuration.
- Relay NO (Normally Open) connected to appliance wiring.

### 2. ESP8266 Programming
- Open the `.ino` file in Arduino IDE.
- Update your **Wi-Fi SSID and Password** in the code.
- Upload the code to your ESP8266 via USB.

### 3. Google Home Integration
- Add your ESP device to **Google Home** via platforms like **Smart Life / Tuya / custom firmware (e.g., Tasmota/ESPHome)**.
- Create scenes or routines in the Google Home App that send commands to ESP’s IP (e.g., using HTTP or MQTT).
- Test control using voice:  
  _“Hey Google, turn on the living room light.”_

---

## 📱 Control Methods

| Method  | Tool/Platform      | Description              |
|---------|--------------------|--------------------------|
| Voice   | Google Assistant    | Via Google Home app      |
| Manual  | Physical Switch     | Wired to ESP GPIO pins   |
