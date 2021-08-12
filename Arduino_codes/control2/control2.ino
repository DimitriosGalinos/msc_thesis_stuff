#include <Servo.h>

Servo myservo;

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int sum = 0;
int flag = 0;
int oldSum = 9999;
int abss = 9999;

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
  sum = sum + val;
  if (flag < 10){
    flag = flag + 1;
  }
  else{
    sum = sum/11;
    abss = abs(oldSum - sum);
    if (oldSum == 9999 || abss > 4 ){
      Serial.println(sum); //print out the value you read
      val = map(sum, 0, 680, 10, 180);     // scale it to use it with the servo (value between 0 and 180)
      Serial.println(val); //print out the value you send to the servo
      myservo.write(val);                  // sets the servo position according to the scaled value
    }
    oldSum = sum;
    sum = 0;
    flag = 0;
  }
  delay(5); //delay in between reads for stability
}
