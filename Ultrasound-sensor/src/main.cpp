#include <Arduino.h>

const byte TRIG = 2;
const byte ECHO = 3;

void trigger();
long get_period();
float get_distance();

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  trigger();
  Serial.println(get_distance());
  delay(10);
}

float get_distance()
{
  return float(get_period())/58;
}

long get_period()
{
  trigger();
  digitalWrite(ECHO, HIGH);
  int period = pulseIn(ECHO, HIGH);
  if(period <= 38000) { return period; }
  else { return 0; }
}

void trigger()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
}