# Cylinder Arduino

Cylinder Arduino adalah library yang berfungsi untuk mengontrol silinder pneumatik, serta mendeteksi kondisi silinder (Push atau Pull direction).

## Petunjuk penggunaan

Buat **Object Cylinder** dengan scope global :

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
perintah diatas menghasilkan return value HIGH untuk kondisi Push, dan LOW untuk kondisi Pull.

**Mengubah** kondisi silinder :

``` c++
silinder_a.setState(HIGH);
```
perintah tersebut akan mengubah kondisi silinder menjadi Push direction. (HIGH untuk Push, LOW untuk Pull).