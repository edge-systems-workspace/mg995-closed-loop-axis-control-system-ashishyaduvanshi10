#include <Arduino.h>
#include <Servo.h>

Servo MYSERVO;

int trigPin = 9;
int echoPin = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  MYSERVO.attach(5);
  Serial.begin(9600);
}

void loop() {
}