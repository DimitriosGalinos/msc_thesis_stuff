#include <Servo.h>

Servo myservo;

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  //the setup routine runs once when you press reset
  
  Serial.begin(9600); //initialize serial communication at 9600 bits per second
  myservo.attach(30); // initialize servo to pin 30
  myservo.write(90); // initialize servo to 0 degrees
}

void loop() {
  //the loop routine runs over and over again forever

  int sensorValue = analogRead(A0); //read the input on analog pin 0
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  Serial.println(sensorValue); //print out the value you read
  delay(50); //delay in between reads for stability
}
