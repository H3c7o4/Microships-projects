# Coded lock based on the PIC16F877 microcontroller

## Components and supplies

 - PIC16F877
 - Trimmers 10K
 - Crystal 4MHz
 - LCD screen 16 * 4
 - Push button
 - Polarized capacitors 33nF
 - Resistors 1K (4)
 - Sounder
 - Blue led
 - Red led
 - Connectors
 - Motor
 - IRF9530

## Necessary tools and Machines

 - Soldering Iron
 - Hot gkue gun

## APPS and Online Services

 - MikroC Pro for PICs
 - Proteus (for simulation)

## ABOUT this Project

### Goals of the electronic project

1. Know how to use the 3×4 keyboard using very simple functions on MikroC
2. Know how to generate different tones to create melodies with already existing functions
3. Using the full H-bridge to start the direction of rotation of the DC motor
4. Other tips with the usage of PICs

### Functional principle

The project consists of a 4×3 keyboard, a 16×2 LCD display, status LEDs, a speaker and a push button.

1. **Keyboard:** Allows to write the password, the size of the word is variable according to the value of the parameter LengthPassWord, by default LengthPassWord=5. The keyboard also allows to reactivate the keyboard in case of exceeding the number of allowed attempts. The unlocking character = Enable_PW.
2. **LCD display:** Display of the characters instructed by the keyboard and the status of the password ' or 'Correct'.
3. **Status LED:** 3 status LEDs : Correct password and door open
4. **Speaker:** Alarm when the number of allowed attempts is exceeded
5. **Push button :** Alarm stop. The button only allows to block the alarm, in case of pressing one of the buttons of the keyboard, the alarm starts from. To unblock the alarm it is necessary to type the reactivation character of the keyboard.

If the correct password is entered, the motor turns in direction 1 for 5 seconds, brakes for 3 seconds and then turns in direction 2 for 5 seconds. The times (braking, rotation direction1/2) can be set by the following parameters in the program: Time_ms_sens1, Time_ms_sens2 and Time_ms_door.

### Schematics

<img align="Center" alt="Coded lock" width="500px" src="https://github.com/H3c7o4/Microships-projects/blob/master/MikroC/images/github1.png" />
<img align="center" alt="Coded lock" width="300px" src="https://github.com/H3c7o4/Microships-projects/blob/master/MikroC/images/github2.png" />
<img align="center" alt="Coded lock" width="300px" src="https://github.com/H3c7o4/Microships-projects/blob/master/MikroC/images/github3.png" />

## Notions of music on the microphone (Alarm bell & doorbell)

Every musical sound (or note) has a fundamental frequency (number of vibrations per second calculated in hertz) corresponding to its pitch. Two notes whose fundamental frequencies have a ratio that is a power of two (i.e. half, double, quadruple...) give two very similar sounds and have the same name. This observation makes it possible to group all notes that have this property in the same pitch category.

In Western music, there are twelve pitch categories. Seven of them are considered to be the main ones and are named: C, D, E, F, G, A and B. The interval between two pitches where the frequency of one is twice (or half) that of the other is called an octave. To distinguish two notes of the same name in two different octaves, we number the octaves and give this number to the corresponding notes: for example, the A3 has a frequency of 440 hertz in the international standard. This reference frequency is given by a tuning fork.

<img align="center" alt="Coded lock" width="1000px" src="https://github.com/H3c7o4/Microships-projects/blob/master/MikroC/images/github5.jpg" />

<img align="center" alt="Coded lock" width="300px" src="https://github.com/H3c7o4/Microships-projects/blob/master/MikroC/images/github4.png" />

## Exemple :

 - Note C4 during 1 second : Sound_play(523,1000)
 - Note F4 during 400 ms : Sound_play(698,400)

> Note: Before using the Sound_play function, you must assign a pin and a port to output the sound using the Sound_Init(&PORT, Num_Pin) function [Sound_init(&PORTD,4)]

For more informations on this project or things related to microcontroller, please [contact me](mailto:hectorvladitok@gmail.com).

Author :**ITOK Steve Hector**

Where to reach me :

<a href="https://www.instagram.com/HectorVladitok/">
  <img align="left" alt="Hector's Instagram" width="22px" src="https://raw.githubusercontent.com/hussainweb/hussainweb/main/icons/instagram.png" />
</a>
<a href="https://discord.com/channels/@Hector BenMyriam#0823">
  <img align="left" alt="Hector's Discord" width="22px" src="https://raw.githubusercontent.com/peterthehan/peterthehan/master/assets/discord.svg" />
</a>
<a href="https://twitter.com/ItokVlad">
  <img align="left" alt="Hector Vlad | Twitter" width="22px" src="https://raw.githubusercontent.com/peterthehan/peterthehan/master/assets/twitter.svg" />
</a>
<a href="https://www.linkedin.com/in/hector-vlad-itok-1a3829182">
  <img align="left" alt="Hector's LinkedIN" width="22px" src="https://raw.githubusercontent.com/peterthehan/peterthehan/master/assets/linkedin.svg" />
</a>
