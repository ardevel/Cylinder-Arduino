#include <Cylinder.h>

int START = 2;int STOP = 3;
int MIN_A = 4;int MAX_A = 5;
int MIN_B = 6;int MAX_B = 7;
int AF = 8;int AB = 9;
int BF = 10;int BB = 11;
int watcher = 0;
Cylinder silA(MAX_A,MIN_A,AF,AB);
Cylinder silB(MAX_B,MIN_B,BF,BB);

void setup() {
  pinMode(START,INPUT);
  pinMode(STOP,INPUT);
  silA.setState(LOW);
  silB.setState(LOW);
  watcher = 0;
}

void loop() {
  if ((digitalRead(START) == HIGH) && (silA.getState() == LOW) && (silB.getState() == LOW)) {
    silA.setState(HIGH);
    silB.setState(LOW);
  } else if ((silA.getState() == HIGH) && (silB.getState() == LOW)) {
    silA.setState(HIGH);
    silB.setState(HIGH);
  } else if ((silA.getState() == HIGH) && (silB.getState() == HIGH) && watcher == 0) {
    silA.setState(HIGH);
    silB.setState(LOW);
    watcher = 1;
  } else if ((silA.getState() == HIGH) && (silB.getState() == LOW) && watcher == 1) {
    silA.setState(LOW);
    silB.setState(LOW);
    watcher = 0;
  }
}
