// PROJECT ANALOG CODE 

const int sensor=A0; //Myoware sensor labeled as "sensor" defined in pin A0
int speed_=0; //Define variable speed as 0
#define stp 2 //Define stp variable (which controls the number of steps done by the motor) in pin 2 
#define dir 3 //Define dir variable (which controls the movement direction) in pin 3
#define MS1 4 //Define MS1 variable (coil 1 of the motor) in pin 4
#define MS2 5 //Define MS2 variable (coil 2 of the motor) in pin 5
#define EN  6 //Define EN variable (enables stepper motor) in pin 6
#define IN_PIN A0 
#define WINDOW_SIZE 3 //Define Window size at 3

//Declare variables for functions
char user_input;
int x; //Declare x as an intager variable (x is the number of steps)
int norm; //Declare norm as an intager variable (norm is the nomalized value of the sensor reading)
int ratio; //Declare ratio as an intager variable (ratio is the maximum value of the sensor divided by maximum number of steps)
int actualnorm; //Declare actualnorm as an intager variable (actualnorm is the old nomalized value of the sensor reading)
int restnorm; //Declare restnorm as an intager variable (restnorm is the difference between the norm and the actualnorm)
int interruptor=11; //Declare interruptor (switch) as an intager variable 
int INDEX = 0; //Declare INDEX as an intager variable   
int val = 0; //Declare val as an intager variable (sensor value)
int SUM = 0; //Declare SUM as an intager variable
int READINGS[WINDOW_SIZE]; // Declare READINGS as an intager variable
int AVERAGED = 0; //Declare AVERAGED as an intager variable
int a = 0; //Declare a as an intager variable (which will be the switch state)

void setup() {
  // put your setup code here, to run once:
  pinMode(interruptor, INPUT_PULLUP); //Define switch as an input pullup signal
  pinMode(stp, OUTPUT); //Define stp as an output signal
  pinMode(dir, OUTPUT); //Define dir as an output signal
  pinMode(MS1, OUTPUT); //Define MS1 as an output signal
  pinMode(MS2, OUTPUT); //Define MS2 as an output signal
  pinMode(EN, OUTPUT); //Define EN as an output signal
  Serial.begin(9600); //Open Serial connection for debugging
  pinMode(sensor, INPUT); //Define sensor as an input signal
  digitalWrite(EN, HIGH); //Pull Enabler high to activate Stepper motor
  ratio=6; // Maximum value of the sensor divided by maximum number of steps (100)
}

void loop() {
  // put your main code here, to run repeatedly:
  SUM = SUM - READINGS[INDEX]; // Remove the oldest entry from the sum
  val = analogRead(sensor); // Read the next sensor value
  READINGS[INDEX] = val; // Add the newest reading to the window
  SUM = SUM + val; // Add the newest reading to the sum
  INDEX = (INDEX+1) % WINDOW_SIZE; // Increment the index, and wrap to 0 if it exceeds the window size
  AVERAGED = SUM / WINDOW_SIZE; // Divide the sum of the window by the window size for the result

  delay(500); // Wait for 500 milliseconds
  a=digitalRead(interruptor); //Read the switch
  Serial.print (a); //Print the swith value (1 for off and 0 for on)
  if (a==LOW){ // Only when the swith is on (0)  
     norm=(AVERAGED/ratio); //Calculate the normalized value
     restnorm=abs(actualnorm-norm); //Calculate the difference between the norm and the actualnorm as an absolute value
    Serial.println(norm); //Print norm value
    if (actualnorm<norm){ //Only when actual norm is smaller than norm 
      Subir(); //Do the function to move leg ahead
      actualnorm=norm; //Reset norm (save new actualnorm as norm)
      }
    if (actualnorm>norm){ //Only when actual norm is bigger than norm
      Bajar(); //Do the function to move leg back
      actualnorm=norm; //Reset norm (save new actualnorm as norm)
      }
  }
}


void Subir() //Function to move leg ahead
{
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x= 0; x<restnorm; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
}

void Bajar() //Funtion to move leg backwards 
{
  digitalWrite(dir, HIGH); //Pull direction pin high to move in "reverse"
  for(x= 0; x<restnorm; x++)  //Loop the reverse stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step 
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
}
