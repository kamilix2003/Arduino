#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <HardwareSerial.h>


const byte THERMISTOR = 11;
const byte US_TRIG = 2;
const byte US_ECHO = 3;

OneWire sensor(11);
DallasTemperature thermistor(&sensor);

void trigger();
long get_period();
float get_distance();
float get_temp(DallasTemperature);

void setup() {
  // put your setup code here, to run once:
  pinMode(US_TRIG, OUTPUT);
  pinMode(US_ECHO, INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  trigger();
  Serial.print("temp ");
  Serial.println(get_temp(thermistor));
  Serial.print("distance ");
  Serial.println(get_distance());
  delay(100);
} 

float get_temp(DallasTemperature sensor)
{
  sensor.requestTemperatures();
  return sensor.getTempCByIndex(0);
}

float get_distance()
{
  return float(get_period())/58;
}

long get_period()
{
  trigger();
  digitalWrite(US_ECHO, HIGH);
  int period = pulseIn(US_ECHO, HIGH);
  if(period <= 38000) { return period; }
  else { return 0; }
}

void trigger()
{
  digitalWrite(US_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG, LOW);
}