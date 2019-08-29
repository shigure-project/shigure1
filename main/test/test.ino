#include <Servo.h>

boolean flag0 = false;
boolean flag1 = false;
boolean flag2 = false;

unsigned long release_time;

Servo servo1;
Servo servo2;


void setup() {
  servo1.attach(0);
  servo2.attach(6);
  servo1.write(0);
  servo2.write(0);

}

void loop() {
  if (flag0 == false){
    release_time = millis();
    if (digitalRead(4) == LOW) {
      flag0 == true;
    }
    
  } else {
    if ((flag1 == false) && (millis() > release_time + 5000)) {
      servo1.write(180);
      flag1 = true;
      
    } else if ((flag2 == false) && (millis() > release_time + 7000)) {
      servo2.write(180);
      flag2 = true;
      
    }
    
  }

}