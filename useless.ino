/*
    Arduino "useless machine" (simulation)
    By thebrentc (thebrentc.net)
    Button switches LED on, servo switches it off
    See: https://en.wikipedia.org/wiki/Useless_machine
*/

#include <Servo.h> 

int buttonPin = 2;    
int ledPin =  9;      
Servo servo;

void setup() {
  Serial.begin(9600);
  Serial.print("Hello world\n");
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);     
  servo.attach(10);
    
  moveServoTo(servo, 0);
}

void moveServoTo(Servo servo, int pos) { // servo goes from 0 degrees to max 180 degrees 
  servo.write(pos);
}

int reach = 177;
void switchOff() {    
  for(int pos = 0; pos < reach; pos += 1)  
  {                                  
    moveServoTo(servo, pos);                 
    delay(15);                       // waits for the servo to reach the position     
    if(digitalRead(buttonPin) == LOW){ // <-- button setup is LOW == pressed down   
      Serial.write("Arduino Button\n ");          
      moveServoTo(servo, 0); 
      switchLed();      
      break;
    }
  }  
}

void switchLed() {  
  digitalWrite(ledPin, !digitalRead(ledPin));  // toggle
  delay(500);
}

void loop() {
  
   if(digitalRead(buttonPin) == LOW){  
      Serial.write("Button\n ");
      switchLed();
   }
  if (digitalRead(ledPin) == HIGH) {    
    switchOff(); 
  }
   
}

