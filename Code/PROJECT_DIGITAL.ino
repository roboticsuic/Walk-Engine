#include <Stepper.h> //Load from library
#define STEPS 200 //We are defining the steps (the number of steps in one revolution of our motor)
Stepper stepper(STEPS, 8, 9, 10, 11); //defines the 4 pins that are attached to the motor
const int sensor=A0; //Myoware sensor labeled as "sensor" defined in pin A0
int speed_=0; //defining variable speed as 0
#define stp 2 //defines stp variable (which controls the number of spets doned by the motor) in pin2
#define dir 3 //defines dir variable (which controls movement direction) in pin3
#define MS1 4 //defines MS1 variable (coil 1 of the motor) in pin4
#define MS2 5 //defines MS2 variable (coil 2 of the motor) in pin5
#define EN  6 //defines EN variable (enables stepper motor) in pin6
//Declare variables for functions
char user_input;
int x; //defining x as an intager (which will be the number of steps)
int y; //defining y as an intager
int state; //defining state as an intager 
int pos; //defining position as an intager variable (pos will tell us if the leg is up or down)
int norm; //defines norm as an intager (norm will be the normalized value of the sensor lecture)
int thr; //defines thr as an intager (thr is the threshold which will help us to normalize the sensor lecture)
void setup() {
  // put your setup code here, to run once:
  pinMode(stp, OUTPUT); //defining stp as output
  pinMode(dir, OUTPUT); //defining dir as output
  pinMode(MS1, OUTPUT); //defining MS1 as output
  pinMode(MS2, OUTPUT); //defining MS2 as output
  pinMode(EN, OUTPUT); //defining EN as output
  Serial.begin(9600); //Open Serial connection for debugging
  pinMode(sensor, INPUT); //defining sensor as input
  pos=0; //defining initial position as 0
  thr=600; //defining threshold as 600 to normalize the sensor input (threshold value changes depending on the patient)
}

void loop() {
  
  int val = analogRead(sensor); //defining "value" as the intager that the sensor pin reads
  delay(500); //delay between sensor pin lectures
  norm=val/thr; //normalizing the value dividing it by the threshold to obtain a number between 0 and 1
  Serial.println(norm); //print in the monitor the normalized value
  if (pos==0){ //if we are in position 0 (leg down) enter loop
    if (norm>0.7){ //if our normalized value is bigger than 0.7 enter loop
      
      Serial.println("mueve la pierna"); //if previous conditions where met then print "mueve la pierna" in the monitor
      Subir(); //do function "Subir()" described below
      pos=1; //update position value as 1 (leg up)
    }
  }
  else { //if we are not in position 0 enter loop
    if(norm<0.3){ //if our normalized value is smaller than 0.3 enter loop
      Serial.println("baja la pierna"); //if previous conditions where met then print "baja la pierna" in the monitor
      Bajar(); //do function "Bajar()" described below
      pos=0; //update position value as 0 (leg down)
    }
  }

    
}

void Subir() //defines function "Subir()"
{
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x= 0; x<50; x++)  //Loop the forward stepping enough times for motion to be visible (50 steps in this case)
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
}

void Bajar() //defines function "Bajar()"
{
  digitalWrite(dir, HIGH); //Pull direction pin high to move in "reverse"
  for(x= 0; x<50; x++)  //Loop the stepping enough times for motion to be visible (50 steps in this case)
  {
    digitalWrite(stp,HIGH); //Trigger one step
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
}
