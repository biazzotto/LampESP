#include <Arduino.h>
#include <TaskScheduler.h>

Scheduler runner;

void setup() {
  Serial.begin(115200);
  delay(10);
  runner.init();

  setupWifi(60);
  setupOTA();
  setupWebServer();
  setupMQTT();

  // true - to enable functionality
  setupRelay(true, D1);
  setupRGBLED(false, D2, D5, D3);
  setupPhotocell(true, A0);
  setupDHT(true, D4);
  setupLED(true, D6);
  setupPIR(true, D7);

  // true - to enable functionality
  setupAirSensor(false, A0);
  setupWaterLevelSensor(true, D2);
}

void loop() {
  handleOTA();
  checkMQTTConnection();
  handleDHT();
  handleWebServer();
  handleMQTT();

  runner.execute();
}
