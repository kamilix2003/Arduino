#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const byte LED = 13;
const byte PROBE_PIN = 11;

OneWire probe(PROBE_PIN);
DallasTemperature sensor(&probe);

int temperature;
int prev_temp = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  sensor.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.requestTemperatures();
  temperature = 10 * sensor.getTempCByIndex(0) + 0.05;
  if(temperature > prev_temp) { digitalWrite(LED, HIGH); }
  else { digitalWrite(LED, LOW); }
  Serial.println(float(temperature), 1);
  delay(100);

  prev_temp = temperature;
}