

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Servo.h>
#include <DHT.h>
#include "thingProperties.h"

const int led_pin = D1; // Define the relay pin
const int RELAY_PIN = D2;
Servo myServo; // Create servo object to control a servo
const int servoPin = D5; // D5 connected to the servo motor

// Define the DHT sensor type and pin
#define DHTTYPE DHT11
#define DHTPIN D8 // GPIO4 on NodeMCU

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

ESP8266WiFiMulti WiFiMulti; // Object to manage multiple Wi-Fi networks

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  delay(1500);

    myServo.attach(servoPin); // Attaches the servo on pin 5 to the servo object
  Serial.println("Servo control ready");

  // Initialize pin modes
  pinMode(led_pin, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Initialize DHT sensor
  dht.begin();

  // Set Wi-Fi credentials
  WiFiMulti.addAP("Sadalgekar House", "8080808080");

  // Attempt to connect to Wi-Fi
  Serial.println("Connecting to Wi-Fi...");
  while (WiFiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  // Reconnect to Wi-Fi if disconnected
  if (WiFiMulti.run() != WL_CONNECTED) {
    Serial.println("Reconnecting to Wi-Fi...");
    while (WiFiMulti.run() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nReconnected to Wi-Fi");
  }

  // Update IoT Cloud
  ArduinoCloud.update();

  // Perform sensor readings
  float temp = dht.readTemperature(); // Temperature in Celsius
  float hum = dht.readHumidity();    // Humidity in percentage

  // Check if the readings are valid
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the readings to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.println(hum);

  // Update the IoT Cloud variables
  temperature = temp;
  humidity = hum;

  // Control lights and fans
  onLightChange();
  onFanChange();
  onFanChange();
}

void onLightChange() {
  if (light) {
    digitalWrite(led_pin, HIGH); // Turn ON relay
  } else {
    digitalWrite(led_pin, LOW); // Turn OFF relay
  }
}

void onFanChange() {
  digitalWrite(RELAY_PIN, fan ? HIGH : LOW);
}

void onGateControlChange()  {
  if(gateControl){
    // Open the gate
  Serial.println("Opening gate...");
  myServo.write(160); // Rotate the servo to 90 degrees (or another angle to open the gate)
  }else{
    Serial.println("Closing gate...");
  myServo.write(0); // Rotate the servo back to 0 degrees (or another angle to close the gate)
  }
}
