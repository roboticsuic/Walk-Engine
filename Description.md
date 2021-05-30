# Walk-Engine 
## PROJECT: Leg exoskeleton controlled by a myoelectric sensor
Nowadays, there are many health aids to combat illnesses or disabilities, but not everything is solved. A large part of the disabilities solutions can be very expensive or even have no solution at all. We believe it is necessary to create new methods to help these patients. For this reason, we have designed a method in which you can be able to create this help by your hands in your own home.

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

_Results_:

**SolidWorks**
As for the exoskeleton parts in CAD models, the first thing that had to be done was to scale down piece by piece. It turns out that the model we found was designed for an adult of average height, and we were looking to design an exoskeleton for infants of about 5 years of age. That's why we decided to adapt the pieces by reducing the dimensions with a scale of 0.41.
Even though, there were some parts that required more adaptation, so we redesigned them on  Solid Works.

