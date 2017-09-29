# Cylinder-Arduino

Cylinder-Arduino adalah library yang berfungsi untuk mengontrol dan mendeteksi kondisi silinder (Push atau Pull direction).

## Petunjuk penggunaan

Membuat **Object Cylinder** :

``` c++
int maxSensor = 2;
int minSensor = 3;
int pushPin = 4;
int pullPin = 5;
Cylinder silinder_a(maxSensor,minSensor,pushPin,pullPin);
```
**Mendeteksi** kondisi silinder :

``` c++
silinder_a.getState();
```
Perintah tersebut akan me-return sebuah value. HIGH untuk Push direction, dan LOW untuk kondisi Pull direction.

**Mengubah** kondisi silinder :

``` c++
silinder_a.setState(HIGH);
```
Perintah tersebut akan mengubah kondisi silinder sesuai dengan parameter yang diberikan. HIGH untuk Push, LOW untuk Pull.