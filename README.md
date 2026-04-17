# 🔥 IoT Smart Smoke & Gas Detector (MQ2 + MQ135)

## 📌 Project Description

This project is a **prototype smart smoke and gas detection system** built using Arduino.
It detects changes in air quality using MQ sensors and triggers an alarm system with buzzers and LED indicators.

The system is designed as a **foundation for a future IoT device**, which will later include ESP32, mobile app integration, and OTA updates.

---

## ⚙️ Hardware Used

* Arduino Uno / Mega 2560 R3
* MQ2 Gas Sensor
* MQ135 Air Quality Sensor
* 2x Active Buzzer
* NPN Transistor (2N2222)
* 1kΩ Resistor (transistor base)
* 220Ω Resistor (LED)
* Red LED
* Push Button (Test Button)
* 470µF Capacitor (25V)
* 100nF Ceramic Capacitor
* Breadboard & Jumper Wires

---

## 🔌 System Features

* 🔥 Smoke & gas detection (MQ2 + MQ135)
* 🚨 Dual buzzer alarm system
* 💡 LED status indicator
* 🔘 Manual test button
* ⏳ Warm-up time for sensor stabilization
* 📊 Analog + Digital sensor reading
* 🧠 Baseline-based detection system (adaptive to environment)

---

## 🧠 How It Works

1. System starts and enters **warm-up mode**
2. Sensors stabilize and baseline values are calculated
3. System continuously reads air quality
4. If gas/smoke levels increase:

   * ⚠️ Warning mode → slow alert
   * 🚨 Alarm mode → buzzer + LED activated
5. Button allows manual testing of the system

---

## 🧪 Testing

The system was tested in different conditions:

* Closed room (night conditions)
* Open window (fresh air)
* Gas exposure test (lighter)

📊 Observations:

* Sensors react **quickly to gas increase**
* Recovery (value drop) is slower, which is normal
* Different environments require dynamic baseline calibration

---

## 📷 Current Build

<p align="center">
  <img src="images/projekt.jpg" width="500">
</p>

---

## 🎥 Demo

📌 A video demonstration of the alarm system will be uploaded here:
➡️ *(Link will be coming soon!)*

---

## 🚀 Future Plans

* 🔌 Upgrade to ESP32
* 📱 Mobile app (Unity) integration
* 📡 Bluetooth communication
* 🔄 OTA (Over-The-Air) updates
* 🔋 Battery-powered system
* 🧠 Advanced false alarm filtering

---

## ⚠️ Notes

* This is a **prototype system**, not a certified safety device
* MQ sensors require calibration depending on environment
* Results may vary based on room size, airflow, and usage

---

## 👨‍💻 Author

Developed as a personal learning and IoT project.

---

## ⭐ Support

If you like this project, consider giving it a ⭐ on GitHub!
