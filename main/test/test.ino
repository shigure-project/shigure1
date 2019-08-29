#include <Servo.h>

boolean flag0 = false;
boolean flag1 = false;
boolean flag2 = false;

unsigned long release_time;

Servo servo1;
Servo servo2;


void setup() {
  Serial.begin(115200);
  servo1.attach(0);
  servo2.attach(6);
  servo1.write(0);
  servo2.write(0);

  pinMode(4, INPUT_PULLUP);

}

void loop() {
  if (flag0 == false) {
    release_time = millis();
    Serial.println("ready");
    if (digitalRead(4) == HIGH) {
      flag0 = true;
      Serial.println("released");
    }
    
  } else {
    if ((flag1 == false) && (millis() > release_time + 5000)) {
      servo1.write(180);
      flag1 = true;
      Serial.println("servo1 rotate");
      
    } else if ((flag2 == false) && (millis() > release_time + 7000)) {
      servo2.write(180);
      flag2 = true;
      Serial.println("servo2 rotate");
      
    }
    
  }

}