/*
  Purpose of this program is to know how to use and understand the funcion of stepper motors with a joystick.
  Stepper motor connects ULN2003a driver module then connected to ardunio.
  Stepper motor connects to digital pins 2, 3, 4, 5 of the ardunio.
  The direction of stepper motor is being changed using the X axis of the joystick.
  Joystick connects to analog pin A1 of the ardunio.
  Joystick ground connects to analog pin A2, 5V pin connects to analog pin A3.
*/

#include <Stepper.h>

#define GROUND_JOY_PIN A3  //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2  //joystick +5 V pin will connect to Arduino analog pin A2
#define X_pin A1  //X axis reading from joystick will go into analog pin A1

const int stepsPerRevolution = 2048;  //steps per revolution
const int rolePerMinute = 8;
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps

  myStepper.setSpeed(rolePerMinute);

  pinMode(VOUT_JOY_PIN, OUTPUT) ; //pin A3 as output
  pinMode(GROUND_JOY_PIN, OUTPUT) ; //pin A2 as output
  digitalWrite(VOUT_JOY_PIN, HIGH) ; //set pin A2 to high (+5V)
  digitalWrite(GROUND_JOY_PIN, LOW) ; //set pin A3 to low (ground)
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print(" X-axis: "); //print text " X-axis: "
  Serial.println(analogRead(X_pin)); //read joystick input on pin A1
  int a = analogRead(X_pin);
  if (a > 400 && a < 520)
  {
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, LOW);
    }
  }
  else if (a < 400)
  {
    myStepper.setSpeed(rolePerMinute); //set speed according to value of role per minute
    myStepper.step(-30);
  }
  else if (a > 530)
  {
    myStepper.setSpeed(rolePerMinute); //set speed according to value of role per minute
    myStepper.step(30);
  }



}
