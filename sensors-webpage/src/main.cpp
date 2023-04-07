#include <Arduino.h>
#include <HardwareSerial.h>

const byte LED = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial1.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial1.println("hello");
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);

}