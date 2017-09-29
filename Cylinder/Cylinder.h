#ifndef Cylinder_H
#define Cylinder_H

#include "Arduino.h"

class Cylinder {
  public:
    Cylinder(int maxPin,int minPin,int forwardPin,int backwardPin);
    ~Cylinder();
    int getState();
    void setState(int state);
  private:
    int _maxPin;
    int _minPin;
    int _forwardPin;
    int _backwardPin;
};

#endif