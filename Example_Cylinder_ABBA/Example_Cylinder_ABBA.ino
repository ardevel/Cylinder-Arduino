#include <Cylinder.h>

int START = 2; // Tombol / Sensor start
int STOP = 3; // Tombol / Sensor Stop
int MIN_A = 4; // Limit Switch Silinder A (Min)
int MAX_A = 5; // Limit Switch Silinder A (Max)
int MIN_B = 6; // Limit Switch Silinder B (Min)
int MAX_B = 7; // Limit Switch Silinder B (Max)
int AF = 8; // Silinder A Push
int AB = 9; // Silinder A Pull
int BF = 10; // Silinder B Push
int BB = 11; // Silinder B Pull
Cylinder silA(MAX_A,MIN_A,AF,AB); // Silinder A Objek
Cylinder silB(MAX_B,MIN_B,BF,BB); // Silinder B Objek
int watcher = 0;

void setup() {
  pinMode(START,INPUT);
  pinMode(STOP,INPUT);
  silA.setState(HIGH); // Kondisi awal silinder A max, silinder B min
  silB.setState(LOW);
  watcher = 0;
}

void loop() {
  if ((digitalRead(START) == HIGH) && (silA.getState() == HIGH) && (silB.getState() == LOW)) 
  {
    //  Jika tombol / sensor start aktif, silinder A max, dan silinder B min    
    silA.setState(LOW);
    silB.setState(LOW);
  } 
  else if ((silA.getState() == LOW) && (silB.getState() == LOW) && (watcher == 0)) 
  {
    //  Jika silinder A min, dan silinder B min (1)
    silA.setState(LOW);
    silB.setState(HIGH);
    watcher = 1;
  } 
  else if ((silA.getState() == LOW) && (silB.getState() == HIGH)) 
  {
    //  Jika silinder A min, dan silinder B max
    silA.setState(LOW);
    silB.setState(LOW);
  } 
  else if ((silA.getState() == LOW) && (silB.getState() == LOW) && (watcher == 1)) 
  {
    //  Jika silinder A min, dan silinder B min (2)
    silA.setState(HIGH);
    silB.setState(LOW);
    watcher = 0;
  }
}
