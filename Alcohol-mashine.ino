#include "Relay.h"
#include "tsensor.h"

/*
0: стоп
1: r1 - on,                       ten1 - on(max), ten2 - on(max);     t1<=t1max;  t3<=92C; \/
2:                                ten1 - off,     ten2 - on(Uconst);  M<=Mmax;    t3<=92C; \/
3: r1 - off,  r2 - on,  r4 - on,  если t4 >= 80 \/
0: стоп
 */
byte rezhim = 0;

Relay relay[] = {3, 4, 5, 6};

Tsensor sensor;
#define t1 sensor.temp(0)
#define t2 sensor.temp(1)
#define t3 sensor.temp(2)

void setup() {
  Serial.begin(9600);
}

void loop() {
//  for(int i=0; i<4; i++){
//    relay[i].setState(!relay[i].getState());
//    delay(1000);
//    relay[i].setState(!relay[i].getState()); 
//  }
  
//  for(int i=0; i<sensor.sensorsCount; i++){
//    Serial.print(sensor.temp(i));
//    Serial.print(" ");  
//  }

  Serial.print(t1);
  Serial.print(" ");
  Serial.print(t2);
  Serial.print(" ");
  Serial.print(t3);
  Serial.print(" ");
  Serial.println();
}

/*
Device 0 Address: 28FF8E328C160313 Resolution: 9
Device 1 Address: 28FFE5EE8B16031B Resolution: 9
Device 2 Address: 28FFBBFF8B16039B Resolution: 9
 */
