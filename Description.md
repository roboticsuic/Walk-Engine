# Walk-Engine 
## PROJECT: Leg exoskeleton controlled by a myoelectric sensor
Nowadays, there are many health aids to combat illnesses or disabilities, but not everything is solved. A large part of the disabilities solutions can be very expensive or even have no solution at all and we believe it is necessary to create new methods to help these patients. For this reason, we have designed a method in which it would be possible to create this help by your hands in your own home.

This project aims to create a leg exoskeleton that has the function of aiding walk movement but without replacing the limb itself.  It serves to people which have Spinal Cord injury (SCI) and have either no sensibility or an impairment in the limb performance.  It goes from the knee to the foot.  It is powered by a stepper motor which is connected to an Arduino platform and controlled by a myoelectric sensor placed in another person.  The project is based on an existing project (https://www.myminifactory.com/object/3d-print-cre-008-lower-limb-exoskeleton-huced-despro-its-70180) but reduced in size, as it is for child patients.


_Objectives:_
- Learn to 3D print complicated objects and to re-scale and adapt them for the size wanted.  Thus, some objects required designing in SOLIDWORKS.
- Connect a stepper motor to the Arduino platform.
- Recognize patterns in the forearm muscle movement and transform it into electrical signals to control the motor mentioned above.
- Adapt this movements to work for a child-size knee exoskeleton 


_Materials_:
- **For 3d printing**:
  - PLA: biodegradable polymer derived from polylactic acid, rigid and with good tensile strength. 
  - PRUSA i3 printer model MK3s: 3D printer 
  - Adhesive spray 3DLAC: spray used in 3D printers to prevent warping
  - Ensamble materials
  - Screw M4, M2, M1: different size screws
  - Nut M4, M2, M1: different size nuts
  - Velcro: fastening system consisting of two strips of fabric, each with a different warp, which when joined and pressed together are hooked together
- **Electronics**:
  - Cable: a bundle of wires serving as a conductor
  - Stepper motor: stepper motors are DC motors that move in discrete steps
  - Arduino UNO: microcontroller board containing analog and digital, input and output pins. 
  - MyoWare sensor: measures and filters the electrical activity of muscles through electromyography and converts it into a voltage signal. 
  - Easy Driver by Sparkfun: to connect the motor to the Arduino without using the Protoboard
- **Softwares**:
  - PRUSA slicer 3D: MSLA slicer software for Prusa used to determine the setting parameters for printing. 
  - Ultimaker Cura: open 3D printing software used to determine the setting parameters for printing.
  - SOLIDWORKS: 3D CAD design program used to create or modify the pieces that will be printed.


_Technical characteristics_:

**Arduino UNO**
  - Microcontroller: ATmega328
  - Operating Voltage: 5v
  - Digital Input / Output Pins: 14 (Of which 6 are PWM outputs
  - Analog Input Pins: 6
  - Flash memory: 32 KB (ATmega328) of which 0.5 KB is used by Bootloader.
  - SRAM: 2 KB (ATmega328)
  - EEPROM: 1 KB (ATmega328)
  - Clock Speed: 16 MHZ.
![Arduino](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/arduino.jpeg)

**Myoware Sensor**
  - Dimensions: 2.1″ × 0.8″ (excluding reference electrode cable, which is about  3″ long) 
  - Operating voltage: 2.9 V to 5.7 V (unlike previous sensor versions, no negative supply is required)
  - Analog voltage output from 0 V to +Vs (supply voltage)
  - Adjustable gain
  - Both EMG envelope and raw EMG outputs available
  - Embedded electrode connectors – electrodes snap directly into MyoWare (alternatively, external electrode cables can be connected)
  - LED Indicators – one power LED, and one LED that brightens when the muscle is flexed
  - Power switch
  - Reverse voltage protection
  - Two mounting holes (suitable for M3 or #4 screws)
  - Informative user’s guide (1MB pdf)
![Myoware](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/myoware.jpeg)

**Easy driver**
  - Dimensions: 3.31 x 2.68 x 0.39 inches
  - Voltage: 5 V or 3.3 V
  - Works for bipolar motors (4, 6 or 8 wire stepper motor)
  - Potentiometer: from 150 mA to 750 mA per phase
![easydriver](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/easydriver.jpeg)

**Stepper motor:Nema17**
- Dimensions:
 ![dimensions](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/dim_motor.png)
- Weight: 0.24 kg 
- Drive system: Unipolar
- Step angle: 1.8º full step (0.9º half step)
- 200 steps per revolution
- Number of phases: 4
- Voltage & Current: 12 V at 400 mA
- Resistance per phase: 30 ohms
- Max continuous power: 5 V 
- Operating Temperature: -10º to +50º


_Results_:

The exoskeleton has three pieces, the upper part belongs to the thigh and it is where the motor is placed.  Then there is the middle part which has the engine that runs along with the engine of the motor.  Finally the lower part is where the foot is placed.  This parts are combined with screws and attached to the leg using velcro straps.
The upper part has a piece which supports the motor and therefore is incorporated to the exoskeleton.  However, the easy driver and the sensor go separated and connected by some cables.
![initial](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/initial1.jpeg)
![pieces](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/intial_pieces.jpeg)
The work mentioned in the introduction was adapted to a knee exoskeleton instead of a full exoskeleton.  We took the following pieces: 11, 8, 7, 6, 12, 13, 14, 26, 28, 4, 5 and some were adapted, for example the foot.  This happened because when the scale was reduced, the foot did not fit the patient's foot and we had to increase the width.

This is the scheme it has to be followed to assemble the cirucit.  It incorporates the stepper motor, the easy driver along with the sensor and the arduino.
![scheme](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/scheme.png)

**SolidWorks**. 
As for the exoskeleton parts in CAD models, the first thing that had to be done was to scale down piece by piece. It turns out that the model we found was designed for an adult of average height, and we were looking to design an exoskeleton for infants of about 5 years of age. That's why we decided to adapt the pieces by reducing the dimensions with a scale of 0.41.
Even though, there were some parts that required more adaptation, so we redesigned them on  Solid Works.

  - Foot
For the insole or base of the foot, small adjustments had to be made. First, we printed the piece by simply scaling it down to 0.41 and we saw that, unlike most of the pieces, it didn't fit in our subject feet. The sole of the exoskeleton foot was too small and required both lengthening and widening. To do this, we transferred the piece to Solid Works software and by means of extrusions, cuts and lofts operations we redesigned it. In addition, in order to save unnecessary material we drew an empty pattern on the back of the heel. The result was printed and this time it really fit. In the image we can see on the left, unmodified piece and on the right, modified part and its respective operations in Solid Works.
![foot](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/foot.png)

  - Support box
As a support for the stepper motor it was necessary to create a base strong enough to support the weight of the stepper motor and also resistant to vibrations. In addition to this, it was necessary to immobilise the motor to avoid misalignment. For all these reasons it was decided to design a support in the form of a box. This box would have its respective holes in order to screw the motor and minimise misalignment. In addition, a small cylinder was extruded in the base of this box, which would serve as a joint to attach this support box to the rest of the exoskeleton in the middle part of the leg. 
![motorbox](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/motorbox.png)

-   Thigh
The exoskeleton we chose as a reference was complete and went from the hip to the foot. Our subject required a partial exoskeleton from the knee to the foot. Therefore we had to adjust the design a little more. The upper part of the thigh support (what would become the tibia of the exoskeleton) was split in half and fixed using extrusions, cuts and lofts in Solid Works. This was done to obtain the leg support that would connect to the knee without having to go all the way to the hip (as our exoskeleton did not have any joints there).
![motorbox](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/thigh.png)

  - Gears
As for the gears, by downscaling to 0.41 the gears reduced the size of the hole where the stepper motor shaft would go. This means that they were not well made and the shaft was too big for the holes. So it was decided to modify these round slots with Solid Works. Extrusion and cutting operations were used to enlarge the hole to the perfect size for the motor shaft. To do this we first measured the shaft itself and then made the holes to size. The results were printed and were satisfactory.
![motorbox](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/gears.png)

**Arduino codes**

The project was started doing a digital code and then an analog code was implemented.  
In the first place, in the code there are 5 outputs and 1 input:

_Input_:

- Myoware sensor, named sensor in the pin A0

_Outputs_:
- stp in pin 2: controls the number of steps that the motor does
- dir in pin 3: controls the direction of the movement in the motor
- MS1 and MS2 in pin 4 and 5: are the 2 coils of the motor
- EN in pin 6: enables stp

Then inside the void set up, all the pin modes are writen:
- pinMode(stp, OUTPUT);
- pinMode(dir, OUTPUT);
- pinMode(MS1, OUTPUT);
- pinMode(MS2, OUTPUT);
- pinMode(EN, OUTPUT);
- pinMode(sensor, INPUT);

In addition the function _Serial.begin ()_ is also added to the void.setup with the 9600 baudio velocity.  In the void loop there is the main logic of the code.

The objective is to have two positions so that when it is in position 0 moves 90 degrees to one direction and when it is in the other position it moves 90 degrees to the opposite direction.  For this loop to work we define the position as 0 and every time the program is loaded it starts with position 0, that corresponds to the exoskeleton being down (0 degrees).  In addition the function analogRead(sensor) is used to read the value of the sensor and the Serial.print() to print the value of the sensor in the serial port with a delay of 100 ms.

The muscular electrical signal was analyzed using the serial port and it was observed that when the person contracted the forearm the signal increased above 300 and when the person stopped the contraction, the signal decreased to below 150.  It is worth having in mind that this code only works for a particular person, it is not normalized.

In addition, two functions were created: _Subir()_ and _Bajar()_.   Firstly uses the pin dir to set the direction in which the motor is going to move when this function is called (up). Then, a for loop is done which states that the motor has to move from step 0, defined by the variable x (previously defined), to step 50.  As the motor can move 200 steps/turn, 50 steps correspond to 90 degrees.  The x++ means that the steps are incremented 1 by 1.  In each of these steps (x) there is another digital write, which calls the pin stp (the one that controls the steps) and moves 1 (HIGH) and deactivates the pin so it can be triggered again (LOW).
The function Bajar() does the same but the direction is the oposite.

Then with an if the logic of the code is written.  As it is said, at the beginning the position is 0 as it is defined so it enters the if that defines the pos==0, then when the position is 0 we want the exoskeleton to move upwards so we set a threshold value of 300 (contracted).  In addition, when this value is surpassed, “mueve la pierna” is printed in the serial port, so you know that the motor is going to do a movement.  Then, the function Subir is called.  When this if ends it changes to position 1, that corresponds to the leg being at 90 degrees.

Moreover, if the position is 0 but the value is not over 300 it does not do anything, this ensures that if the leg is flexed and we don’t do a force it does not flex more.
Furthermore, there is an else which is activated when the position has been turned to 1, this means that the leg is extended.  Then, another if sets the threshold value to 150, which corresponds to no contraction in the forearm.  If these two conditions are fulfilled, the serial port prints “baja la pierna” and the function Bajar() is called, so it moves 90 degrees down, and the position is turned back to 0, so it can be extended again.

This code is not very optimal because it is personalized, and with particular values of forces.  If these values are changed, because the person gets more strong or because the sensor is not well adjusted, it could cause the leg to move with the minimal force.
This is why we decided to do another code but analogic.

In the analog code all the inputs and outputs are the same except for that we incorporated a switch in the pin 11:

- pinMode(interruptor, INPUT_PULLUP);

What was done in this code is to set a value of ratio which was 6.  This ratio corresponds to the value by which is divided the output of the sensor.  This way, the result is normalized to have an output of the steps and not the sensor value.  This value is 6 because the maximum force that the sensor could detect was approximately 600 and the number of steps that we wanted was approximately 100 (we realized that it was needed to turn more than 50 steps because the engine on the motor was smaller than the one below.

Then, a filter was added to avoid fluctuations of the movement.  The functioning of this filter is to average some values of the sensor in order to have a more homogeneous signal every half second.


The interruptor was implemented with an if. A digitalRead reads the interruptor value and if it is low it runs the code that is inside the if. In addition, it prints the interruptor value next to the sensor value in the serial port.


The next step was to normalize our values.  We had to values:

norm=(AVERAGED/ratio): averaged signal(filtered) divided by the ratio mentioned above; number of steps.
restnorm=abs(actualnorm-norm): absolute value of the subtraction between the last value recorded and the one is reading now.

Moreover, another if was written to move the motor.  If the actual norm (last one) was smaller than the one reading now (norm) it means that the person is doing more force and therefore the motor has to move upwards.  At the end of the if we record the value as actualnorm=norm.  On the contrary, if actualnorm is higher than norm, the person is doing less force so it has to go down.

In addition, we used the same functions as in the digital one but with some modifications.  In the For that establishes the number of steps to move it does not move a fixated number but corresponds to the restnorm value. This way it is only moving a number of steps proportional to the force, and it does not start from 0 but from the last value position.


  
**Ensambling**

Once all the pieces have been printed, we are going to assemble them. In order to have a good result, it is advisable to assemble in blocks; Upper (Femur), Middle (Tibia/Fibula area) and finally the Lower (foot). 

We will start assembling the Upper part. With the help of superglue, we are going to bind the file “Caja” with “5-cover-paha-dalam” following the guidelines of the pieces. 

Appart, we are going to assemble the Middle part using the “6-shank-bawah-metal-material” file, “12-Cover-Shank-Frame”, “13-Shank-Atas-Metal-Material” file, “26-cover-shank” file, “7-Pengait-Pegas” file and “14-straight-bevel-gear10” file. With a little bit of pressure, we have to bind “12-Cover-Shank-Frame” with “26-cover-shank” by putting the pins in the corresponding holes. Then, we have to bind “13-Shank-Atas-Metal-Material” in the upper part and “6-shank-bawah-metal-material” in the bottom part, both inside of the “12-Cover-Shank-Frame”. Once done, we will assemble “14-straight-bevel-gear10” with “13-Shank-Atas-Metal-Material” using M1 screws. To end this part, we will add the “7-Pengait-Pegas” at the bottom part of this block. (If we want to achieve an adjustable exoskeleton, we will leave it like this, but if we don't want to obtain an adjustable result, we will block this adjustment with the help of superglue by adjusting the ideal size we want.) 

The Lower part is basically composed of the food, so finally we will assemble all the blocks using the corresponding screws. Finally, we assemble the stepper motor in “Caja” and we will insert “28-pinion-gear10”, adjusted correctly with “14-straight-bevel-gear10” and add the Velcro straps to adjust the exoskeleton to the patient.

**Printing settings**

The printer used is the Prusa i3 MK3s, and the material used to print the pieces is PLA filament. 

- Layer height: 0,2 mm
- Line width: 0,4 mm
- Wall thickness (shell): 0,8 mm
- Infill pattern: grid
- Infill density: 20%
- Printing temperature: 195º
- Build Plate Temperature: 60º
- Flow: 100%
- Speed: 40 mm/s
- Fan speed: 100%
- Build Plate adhesion: none

![Result](https://github.com/roboticsuic/Walk-Engine/blob/main/Images/Result.png)

**Conclusions**
As a conclusion, the 3d printed parts had a good resolution having in mind that when reducing the size of an object the mechanical properties decrease.  Even though, our prosthesis had good mechanical properties to support its function.  Some pieces were well adapted with also good mechanical and visual results.  
The principal idea was to record the leg myoelectrical signal but finally it was used the forearm signal as it was more uniform.  In addition, we realized that it could be more functional than in the leg.
A digital code was first done, but as mentioned earlier, it was not very reproducible as it was not standardized.  Thus, the best code is by using the analog signal which reproduces the contractions of the forearm to leg movements continuously.
Some improvements we think could be made are:
- Incorporating in the code a stop function which would stop the motor from working when a short circuit happens.
- A more potent stepper motor would have to be used because it did not have enough force to move the leg properly.
- The engines should be made from metal because by 3D printing they were not functional enough and slipped between each other.
- As all the electrical components were outside the exoskeleton, it should be needed a box or something to hold all the components together.
