#define                 LengthPassWord  5       // Number of characters in the password
#define                 NumCodeRepeat   2       // Number of tenations
#define                 Enable_PW       8       // Keyboard reactivation character

#define                 Temps_ms_sens1  5000    // Rotation time in + direction
#define                 Temps_ms_sens2  5000    // Rotation time in - direction
#define                 Temps_ms_door   3000    // Door opening time


// LCD module connections
sbit LCD_RS at RB1_bit;
sbit LCD_EN at RB2_bit;
sbit LCD_D4 at RB3_bit;
sbit LCD_D5 at RB4_bit;
sbit LCD_D6 at RB5_bit;
sbit LCD_D7 at RB6_bit;

sbit LCD_RS_Direction at TRISB1_bit;
sbit LCD_EN_Direction at TRISB2_bit;
sbit LCD_D4_Direction at TRISB3_bit;
sbit LCD_D5_Direction at TRISB4_bit;
sbit LCD_D6_Direction at TRISB5_bit;
sbit LCD_D7_Direction at TRISB6_bit;

// Initialization of the keyboard in port D
char  keypadPort at PORTD;

unsigned short kp, count=0,i;
unsigned short CntWrongPW=0;
unsigned short Password[LengthPassWord]={1,2,3,4,5};


void Tone1() {
  Sound_Play(659, 250);   // Frequency = 659Hz, duration = 250ms
}

void Tone2() {
  Sound_Play(698, 250);   // Frequency = 698Hz, duration = 250ms
}

void Tone3() {
  Sound_Play(784, 250);   // Frequency = 784Hz, duration = 250ms
}

void Melody() {           // Plays the melody "Yellow house"
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3();
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3();
  Tone3(); Tone3(); Tone2(); Tone2(); Tone1();
}

void Melody_Happy_BD(void)
{
    unsigned int Notes_Hz[6]={262,262,294,262,349,330};
    unsigned int Duration_ms[6]={200,200,400,400,400,500};
    unsigned int i;
    
    for(i=0;i<6;i++)
    {
       sound_play(Notes_Hz[i],Duration_ms[i]);
       delay_ms(100);
    }
}

void Melody_alarme_1(void)
{
    Sound_Play(400, 100);
    delay_ms(50);
    Sound_Play(600, 50);
    delay_ms(50);
    Sound_Play(800, 100);
    delay_ms(50);
    Sound_Play(700, 50);
    delay_ms(50);
    Sound_Play(500, 50);
}

void Melody_alarme_2(void)
{
    Sound_Play(400, 100);
    delay_ms(50);
    Sound_Play(500, 70);
    delay_ms(50);
    Sound_Play(600, 80);
    delay_ms(50);
    Sound_Play(700, 48);
    delay_ms(50);
    Sound_Play(800, 102);
    Sound_Play(900, 150);
    delay_ms(50);
    Sound_Play(1000, 40);
}
void Melody_alarme_3(void)
{
    Sound_Play(1500, 100);
    delay_ms(50);
    Sound_Play(2000, 50);
}

unsigned short GetKeyPressed(void)
{
    kp=0;
    do
      //kp = Keypad_Key_Press();
      kp = Keypad_Key_Click();
    while (!kp);

    switch (kp)
    {
      case  1: kp = 49; break; // 1
      case  2: kp = 50; break; // 2
      case  3: kp = 51; break; // 3
      case  4: kp = 65; break; // A
      case  5: kp = 52; break; // 4
      case  6: kp = 53; break; // 5
      case  7: kp = 54; break; // 6
      case  8: kp = 66; break; // B
      case  9: kp = 55; break; // 7
      case 10: kp = 56; break; // 8
      case 11: kp = 57; break; // 9
      case 12: kp = 67; break; // C
      case 13: kp = 42; break; // *
      case 14: kp = 48; break; // 0
      case 15: kp = 35; break; // #
      case 16: kp = 68; break; // D
    }
    return kp ;
}

void Sens_1_motor(void)
{
    PORTC.F5=1;
    PORTC.F6=0;
    delay_ms(Temps_ms_sens1);
}

void Sens_2_motor(void)
{
    PORTC.F5=0;
    PORTC.F6=1;
    delay_ms(Temps_ms_sens2);
}

void Frein_motor(void)
{
    PORTC.F5=0;
    PORTC.F6=0;
    
    // or alternatively
    //PORTC.F5=1;
    //PORTC.F6=1;
}


void main()
{

  TRISB = 0x01;
  TRISC = 0x00;
  PORTC=  0x00;
  
  Keypad_Init();                           // Init Keypad
  Sound_Init(&PORTC, 4);                   // Init Sound
  Lcd_Init();                              // Init LCD
  Lcd_Cmd(_LCD_CLEAR);                     // clear the  LCD
  Lcd_Cmd(_LCD_CURSOR_OFF);                // Disable the cursor

  Lcd_Out(1, 1, "1");
  Lcd_Out(1, 1, "Key  :");                 // Write message text on LCD
  Lcd_Out(2, 1, "Password:");


  while(1)
  {
    for(i=0;i<LengthPassWord;i++)
    {
        kp=GetKeyPressed();
        Lcd_Chr(1, 10+i, kp);
        Lcd_Chr(2, 10+i, '*');
        if(Password[i]+48==kp  ) count++;
    }

    if (count==LengthPassWord)
    {
      count = 0;
      Lcd_Out(2,10,"Correct");
      // LED ON
      PORTC.F0=1;
      
      // DOOR ON
      PORTC.F3=1;
      Melody_Happy_BD();
      
      // Ouverture de la porte
      Sens_1_motor();
      Frein_motor();
      delay_ms(Temps_ms_door);
      Sens_2_motor();
      Frein_motor();
      
      // INIT
      PORTC=0x00;
    }
    else
    {
      count++;
      Lcd_Out(2,10,"Erreur");
      PORTC.F1=1;
      delay_ms(1000);
      PORTC=0x00;
      
      CntWrongPW++;
      
      if(CntWrongPW==NumCodeRepeat)
      {
         CntWrongPW=0;
         count=0;
         while(kp=GetKeyPressed()-48!=Enable_PW)
         {
             Lcd_Out(2,1,"Password Blocked");
             Lcd_Out(1,1,"Password Blocked");
             PORTC.F1=1;
             
             while(1)
             {
                 Melody_alarme_1();
                 //Melody_alarme_2();
                 //Melody_alarme_3();
                 //Melody();
                 if(PORTB.F0==1) break;
             }
             PORTC=0x00;
             
         }
      }
    }

    delay_ms(1000);

    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Out(1, 1, "Key  :");
    Lcd_Out(2, 1, "Password:");

  }
}
