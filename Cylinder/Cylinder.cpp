#include "Arduino.h"
#include "Cylinder.h"

Cylinder::Cylinder(int maxPin,int minPin,int forwardPin,int backwardPin) {
  _maxPin = maxPin;
  _minPin = minPin;
  _forwardPin = forwardPin;
  _backwardPin = backwardPin;
  pinMode(_maxPin,INPUT);
  pinMode(_minPin,INPUT);
  pinMode(_forwardPin,OUTPUT);
  pinMode(_backwardPin,OUTPUT);
}

Cylinder::~Cylinder() {}

int Cylinder::getState() {
  int a = digitalRead(_maxPin);
  int b = digitalRead(_minPin);
  if ((a == HIGH) && (b == LOW)) {
    return HIGH;
  } else if ((a == LOW) && (b == HIGH)) {
    return LOW;
  }
}

void Cylinder::setState(int state) {
  if (state == HIGH) {
    digitalWrite(_backwardPin,LOW);
    digitalWrite(_forwardPin,HIGH);
  } else if (state == LOW) {
    digitalWrite(_forwardPin,LOW);
    digitalWrite(_backwardPin,HIGH);    
  }
}