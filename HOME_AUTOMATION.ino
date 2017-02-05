
//#include <Wire.h>
#include <IRremote.h>
#include "Configration.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9340.h"
const uint8_t TFT_LIGHT =6;

/*****************SPI DISPLAY CONFIG************/
#define _sclk 13
//#define _miso 12
#define _mosi 11
#define _cs 10
#define _dc 9
//#define  _rst 8
int _rst;
/*****************SPI DISPLAY CONFIG************/
#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif
Adafruit_ILI9340 tft = Adafruit_ILI9340(_cs, _dc, _rst);//_rst
/*********************SCREEN COLOR********************/
byte screen_color = ILI9340_BLACK; //HERE SCREEN COLOR CAN BE CHANGE

/*********************SCREEN COLOR********************/


IRrecv irrecv(RECV_PIN);
decode_results results;



void setup()
{
  //Wire.begin();//i2c bus
  Serial.begin(9600);
  tft.begin();
#if defined(__MK20DX128__) || defined(__MK20DX256__)
  //want try the fastest?
  tft.setBitrate(24000000);
#endif
  tft.setRotation(3);           // SCREEN LANDSCAPE
  tft.fillScreen(ILI9340_BLACK);
  //power_off_mode();
  tft.setTextSize(2);
  tft.setTextColor(ILI9340_RED, screen_color);
  pinMode(fan, OUTPUT);          //fan output
  pinMode(fan_2, OUTPUT);          //fan output
  irrecv.enableIRIn();          // Start the receiver
  pinMode(led1, OUTPUT);        // declare the LDR as an OUTPUT
  pinMode(led2, OUTPUT);      // declare the LDR as an OUTPUT
  pinMode(led3, OUTPUT);       // declare the LDR as an OUTPUT
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  pinMode(Foot_lamp, OUTPUT); // declare the LDR as an OUTPUT
  pinMode(TFT_led, OUTPUT);   // declare the LDR as an OUTPUT
  pinMode(LDR, INPUT);       // declare the LDR as an INPUT


  /*******PIR setup***********/
  pinMode(pirPin, INPUT);
  pinMode(RECV_PIN, INPUT);
  digitalWrite(RECV_PIN, LOW);
  digitalWrite(pirPin, LOW);//use to protect sensor reverse 5v ,because it is digital pin
  tft.setCursor(4, 4);
  tft.println("Please Wait!");
  delay(500);
  tft.println("SETUP BLUETOOTH SETTING.");
  delay(500);
  tft.println("CALIBRATING SENSOR. ");
  tft.println("PIR");
  //.println("Calibrating sensor "); //give the sensor some time to calibrate
  //.println("setup bluetooth settings ");
  for (byte i = 0; i < calibrationTime; i++)
  {
    tft.setTextColor(ILI9340_YELLOW);
    //.print(".");
    tft.print(".");
    delay(1000);
  }
  //.println("DONE");
  //.println("SENSOR ACTIVE");
  tft.println("");
  tft.setTextColor(ILI9340_GREEN);
  tft.print("DONE.");
  delay(500);
  display_main_frame();

  /*******PIR setup END***********/

}


void loop()
{

   
  //zero_crosss_fan1();
 lamp();
  reading = analogRead(temp_sensor);
   LDR_val = analogRead(LDR);
 Serial.print("ldr ---------------->");
   Serial.println(LDR_val);
  cel = reading * (5.0 / 1023.0) * 100;
  TEMP_lcd_print(cel);
  Serial.println("*T" + String(cel) + "*"); //Send data over Bluetooth

  if (digitalRead(pirPin) == HIGH)
  {
    Serial.println("*P" + String("MOTION DETECTED") + "*"); //Send data over Bluetooth
    night_mode=0;
    //.println(" PIR ON ");
    /******************************bluetooth code here************************/
    if (Serial.available())
    {

      BluetoothData = Serial.parseInt(); //Get next character from bluetooth
      Serial.println(BluetoothData);
      if (BluetoothData == btPower)
      {

        ir_remote_controller(btPower);
      }
      if (BluetoothData == btSleep)
      {

        ir_remote_controller(btSleep);
      }
      if (BluetoothData == btlight_1)
      {


        ir_remote_controller(btlight_1);

      }
      if (BluetoothData == btlight_2)
      {

        ir_remote_controller(btlight_2);
      }
      if (BluetoothData == btlight_3)
      {

        ir_remote_controller(btlight_3);
      }
      if (BluetoothData == btlight_4)
      {

        ir_remote_controller(btlight_4);
      }
      if (BluetoothData == btlight_5)
      {

        ir_remote_controller(btlight_5);
      }
      if (BluetoothData == btlight_6)
      {

        ir_remote_controller(btlight_6);
      }
      if (BluetoothData == btlight_7)
      {

        ir_remote_controller(btlight_7);
      }
      /***********************auto mode**********************************/
      if (BluetoothData == btfan_auto_fan1)
      {
        mode = 1; // put 1 to goto auto mode
        ir_remote_controller(btfan_auto_fan1);
      }

      if (BluetoothData == btfan_auto_fan2)
      {
        mode = 10; // put 1 to goto auto mode
        ir_remote_controller(btfan_auto_fan2);
      }
      /***********************auto mode**********************************/
      if (BluetoothData == bt_fan1)
      {
        
        ir_remote_controller(bt_fan1);
         
      }
      if (BluetoothData == bt_fan1_)
      {
        
        ir_remote_controller(bt_fan1_);
         
      }
      if (BluetoothData == bt_fan2)
      {
        
        ir_remote_controller(bt_fan2);
        
      }
      if (BluetoothData == bt_fan2_)
      {
        
        ir_remote_controller(bt_fan2_);
        
      }
      
    }
    else
    {
      if ((digitalRead(pirPin) == HIGH )&& (pir_count == 1))
      {
        if (LDR_val >= turnOnValue)
        {

          digitalWrite(led1, HIGH);
          pir_count=0;
        }
        
      }
    }
    /******************************bluetooth code here************************/

    /*****************************ir remote code here************************/
    if (irrecv.decode(&results))
    {
      // recieve_value = results.value;
      ir_remote_controller(results.value);
    }
   /* else
    {
      if (digitalRead(pirPin) == HIGH)
      {
        if (LDR_val >= turnOnValue)
        {
          digitalWrite(led1, HIGH);
        }
      }
    }*/

    /******************************ir remode code here************************/

    if (mode == 1 )
    {
      //fan_Controll_1();
      //fan_Controll_2();
    }
    if (mode == 10 )
    {
      //fan_Controll_1();
      //fan_Controll_2();
    }
    
    if (lockLow)
    {
      //makes sure we wait for a transition to LOW before any further output is made:
      lockLow = false;
      //.println("---");
      //.print("motion detected at ");
      //.print(millis()/1000);
      //.println(" sec");
      delay(50);
    }
    else
    {
      takeLowTime = true;
    }




    /******if else end here****/


  }   //PIR PART1 ENDS

  if (digitalRead(pirPin) == LOW)  //PIR PART2 STARS FOR IF PIR SENSOR IS LOW
  {
    pir_count=1;
     Serial.println("*P" + String("ROOM IS EMPTY") + "*"); //Send data over Bluetooth
        night_mode=1;
        power_off_mode();    
        itsONled[1] = 0;         
        itsONled[2] = 0;         
        itsONled[3] = 0;         
        itsONled[12] = 0;        
        itsONled[13] = 0;         
        itsONled[14] = 0;         
        itsONled[15] = 0;
    tft.setCursor(4, 4);
    tft.setTextColor(ILI9340_RED, ILI9340_BLACK);
    tft.setTextSize(2);
    tft.println(" ROOM IS EMPTY!      ");

    tft.setTextSize(2);
    tft.setCursor(30, 80); //30,100
    tft.setTextColor(ILI9340_GREEN, ILI9340_BLACK);
    tft.print("   SAVE ENERGY  ");

    tft.setTextSize(2);
    tft.setCursor(10, 210);
    tft.setTextColor(ILI9340_BLUE, ILI9340_BLACK);
    tft.print("POWER ");
    delay(500);
    tft.print("SAVER ");
    delay(500);
    tft.print("MODE ");
    delay(500);
    tft.setTextColor(ILI9340_GREEN, ILI9340_BLACK);
    tft.print("ACTIVE  ");
    delay(500);
    tft.setTextSize(2);
    tft.setCursor(10, 210);
    tft.setTextColor(ILI9340_BLUE, ILI9340_BLACK);
    tft.print("                        ");




    if (takeLowTime)
    {
      lowIn = millis();          //save the time of the transition from high to LOW
      takeLowTime = false;       //make sure this is only done at the start of a LOW phase
    }

    if (!lockLow && millis() - lowIn > pause)
    {
      //makes sure this block of code is only executed again after
      //a new motion sequence has been detected
      lockLow = true;
      //.print(" motion ended at ");      //output
      //.print((millis() - pause)/1000);
      //.println(" sec");
      delay(50);
    }
  }
  else
  {
    tft.setTextSize(2);
    tft.setCursor(4, 4);
    tft.setTextColor(ILI9340_GREEN, ILI9340_BLACK);
    tft.setTextSize(2);
    tft.println("MOTION detect!...      ");
    tft.setCursor(30, 80); //30,100
    tft.setTextColor(ILI9340_GREEN, ILI9340_BLACK);
    tft.print("                ");


  }
}
/******loop end here****/


/************************ir_remote_call****************************/
void ir_remote_controller(int code_get1)

{

  //unsigned int code_get=code_get1;
  analogWrite(TFT_led, 255);
  int value2;
  switch (code_get1)
  {
    case irPower:
    case irPower_:
      if (itsONled[6] == 1)
      {
        mode_sleep = 0; 
        tft.setTextSize(2);
        tft.setCursor(10, 210);
        tft.setTextColor(ILI9340_RED, screen_color);
        tft.print("      POWER OFF         ");
         power_off_mode();
        //digitalWrite(led1, LOW);
        power = 0;
        value2 = 0;
        //code_get=0;
        mode = 2;
        tft.setTextSize(2);
        tft.setCursor(30, 100);
        tft.setTextColor(ILI9340_YELLOW, screen_color);
        //tft.print("FAN MANUAL MODE   ");
        tft.print("                  ");
        tft.setTextSize(2);
        tft.setCursor(30, 120);
        tft.setTextColor(ILI9340_YELLOW, screen_color);
        tft.print("                    ");
        tft.setTextSize(2);
        tft.setCursor(30, 150);
        tft.setTextColor(ILI9340_BLUE, screen_color);
        tft.print("                    "); 

        itsONled[6] = 0;           // and set its state as off
      }
      else
      {
        itsONled[1] = 0;         
        itsONled[2] = 0;         
        itsONled[3] = 0;         
        itsONled[12] =  0;        
        itsONled[13] = 0;         
        itsONled[14] = 0;         
        itsONled[15] = 0;

        TEMP_lcd_print(cel);
        tft.setTextSize(2);
        tft.setCursor(10, 210);
        tft.setTextColor(ILI9340_GREEN, screen_color);
        tft.print("      POWER  ON         ");
        delay(100);
        tft.setTextSize(3);
        tft.setCursor(50, 199);
        tft.println();
        power = 1;
        mode = 0;
        value2 = code_get1;
        
        itsONled[6] = 1;          // and set its state as on
      }
      break;

    /***sleep_mode***/
    case sleep_mode:
    case sleep_mode_:
      if (itsONled[7] == 1)
      {
        itsONled[1] = 0;         
        itsONled[2] = 0;         
        itsONled[3] = 0;         
        itsONled[12] =  0;        
        itsONled[13] = 0;         
        itsONled[14] = 0;         
        itsONled[15] = 0;
          
        mode_sleep = 0;
        tft.setTextSize(2);
        tft.setCursor(10, 210);
        tft.setTextColor(ILI9340_GREEN, screen_color);
        tft.print(" SLEEP MODE ");
        tft.setTextColor(ILI9340_RED, screen_color);
        tft.print("OFF  ");
        digitalWrite(Foot_lamp, LOW);
        delay(1000);
        tft.setTextSize(2);
        tft.setCursor(10, 210);
        tft.setTextColor(ILI9340_GREEN, screen_color);
        tft.print("      POWER  ON      ");
        tft.setTextSize(2);
        tft.setCursor(30, 150);
        tft.setTextColor(ILI9340_BLUE, screen_color);
        tft.print("               ");
        power = 1;
        value2 = code_get1;
        //.print("SLEEP MODE=");
        //.print(power);
        //.println(" SLEEP MODE OFF  ");
        digitalWrite(TFT_led, HIGH);
        itsONled[7] = 0;          // and set its state as on
        
      }
      else
      {
        power = 0;
        mode_sleep = 1; 
        power_off_mode();
        tft.setTextSize(2);
        tft.setCursor(10, 210);
        tft.setTextColor(ILI9340_GREEN, screen_color);
        tft.print(" SLEEP MODE ON     ");        
        value2 = 0; //int variable to store data from ir/bluetooth/serial
        
              
       /*

        if (LDR_val >= turnOnValue)//night  foot lamp will on and display light on for sec and goes off till morning comes
        { 
          night_mode=1;
         
        }
        else
        { 
          night_mode=0;
        }
        /**********************/

        if (BluetoothData == btfan_auto_fan1 || code_get1 == fan_auto_button1) //if press button than fan off
        {
          if (itsONled[8] == 1)
          {
            mode = 1;
            itsONled[8] = 1;

          }
          else
          {
            mode = -1;
            itsONled[8] = 0;
          }
        }
        if (BluetoothData == btfan_auto_fan2 || code_get1 == fan_auto_button2) // if press button than fan off
        {
          if (itsONled[9] == 1)
          {
            mode = 10;
            itsONled[9] = 1;
          }
          else
          {
            mode = -1;
            itsONled[9] = 0;
          }
        }

        //.print("SLEEP MODE=");
        //.print(power);
        //.println(" SLEEP MODE ON  ");
        itsONled[7] = 1;           // and set its state as off
      }
      break;

    default:
      {

        error_call();
      }
  }
  //SWITCH CASE END HERE

  irrecv.resume();
  ir_RemoteCall(code_get1, power);
}
//IR ENDS

void error_call()
{
  tft.setTextSize(2);
  tft.setCursor(280, 5);
  tft.setTextColor(ILI9340_RED, screen_color);
  tft.print("NA");
  delay(200);
  tft.setTextSize(2);
  tft.setCursor(280, 5);
  tft.setTextColor(ILI9340_RED, screen_color);
  tft.print("  ");

}

void Lcd_print_Call(byte binary_bit , byte ide)
{
  if (binary_bit == 0)
  {

    tft.setTextSize(2);
    tft.setCursor(30, 150);
    tft.setTextColor(ILI9340_BLUE, screen_color);
    tft.print("LIGHT");
    tft.setTextColor(ILI9340_YELLOW, screen_color);
    tft.print(ide);
    tft.setTextColor(ILI9340_RED, screen_color);
    tft.print(" OFF     ");
  }
  else
  {

    tft.setTextSize(2);
    tft.setCursor(30, 150);
    tft.setTextColor(ILI9340_BLUE, screen_color);
    tft.print("LIGHT");
    tft.setTextColor(ILI9340_YELLOW, screen_color);
    tft.print(ide);
    tft.setTextColor(ILI9340_GREEN, screen_color);
    tft.print("  ON       ");
  }
}

void Lcd_fan_printManual(byte value_fan)
{
  if (mode == 0 || mode == 4)
  {
    tft.setTextSize(2);
    tft.setCursor(30, 100);
    tft.setTextColor(ILI9340_YELLOW, screen_color);
    tft.print("FAN MANUAL MODE   ");
  }
  if (mode == 1 || mode == 10 ) // code6 is for auto mode button
  {
    tft.setTextSize(2);
    tft.setCursor(30, 100);
    tft.setTextColor(ILI9340_YELLOW, screen_color);
    tft.print("FAN AUTO  MODE   ");
  }

  /*if (value_fan <= 0)
  {
    tft.setTextSize(2);
    tft.setCursor(30, 120);
    tft.setTextColor(ILI9340_BLUE, screen_color);
    tft.print("FAN");
    tft.setTextColor(ILI9340_YELLOW, screen_color);
    tft.print(fan_ide);
    tft.setTextColor(ILI9340_BLUE, screen_color);
    tft.print(" SPEED ");
    tft.setTextColor(ILI9340_YELLOW, screen_color);
    tft.print(value_fan);
    tft.print("%");
    tft.setTextColor(ILI9340_RED, screen_color);
    tft.print(" OFF ");
  }*/
  if ((value_fan >= 0) && (value_fan <= 200))
  {
    tft.setTextSize(2);
    tft.setCursor(30, 120);
    tft.setTextColor(ILI9340_BLUE, screen_color);
    tft.print("FAN");
    tft.setTextColor(ILI9340_YELLOW, screen_color);
    tft.print(fan_ide);
    tft.setTextColor(ILI9340_BLUE, screen_color);
    tft.print(" SPEED ");
    tft.setTextColor(ILI9340_YELLOW, screen_color);
    tft.print(value_fan);
    tft.print("%");
    tft.setTextColor(ILI9340_GREEN, screen_color);
    tft.print("  ON  ");
  }
 /* if (value_fan >= 50)
  {
    tft.setTextSize(2);
    tft.setCursor(30, 120);
    tft.setTextColor(ILI9340_BLUE, screen_color);
    tft.print("FAN");
    tft.setTextColor(ILI9340_YELLOW, screen_color);
    tft.print(fan_ide);
    tft.setTextColor(ILI9340_RED, screen_color);
    tft.print("  SPEED MAX    ");
  }*/
}

void TEMP_lcd_print(byte temp_val)
{
  tft.setTextSize(3);
  tft.setCursor(210, 40);
  tft.setTextColor(ILI9340_GREEN, screen_color);
  tft.print(temp_val);
  tft.setTextColor(ILI9340_RED, screen_color);
  tft.print((char)247);//print degree symbol
  tft.print("C");
}

void display_main_frame()
{
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = tft.width(),
                h = tft.height();
  tft.fillScreen(ILI9340_BLACK);
  start = micros();
  tft.drawLine(0, 0, 0, h, ILI9340_RED);//virtical
  tft.drawLine(0, 0, w, 0, ILI9340_RED);//top
  tft.drawLine(0, 30, w, 30, ILI9340_RED);//top+line
  tft.drawLine(0, 200, w, 200, ILI9340_RED);//bottom
  tft.drawLine(w, h - 1, 0, h - 1, ILI9340_RED); //top
  tft.drawLine(w - 1, 0, w - 1, h, ILI9340_RED); //virtical
  tft.setTextSize(3);
  tft.setCursor(10, 40);
  tft.setTextColor(ILI9340_YELLOW);
  tft.print("Temprature ");
}

void lamp()
{ 
  if(night_mode == 0)
   {
    if (LDR_val >= turnOnValue)
    {
     //here resistence of ldr equals to 1k omh
          digitalWrite(Foot_lamp, HIGH);  // turn the Foot_lamp on
          digitalWrite(TFT_led, HIGH);  // turn the TFT_led on for 5 sec
          tft.setTextSize(2);
          tft.setCursor(30, 170);
          tft.setTextColor(ILI9340_BLUE, screen_color);
          tft.print("FOOT LAMP");
          tft.setTextColor(ILI9340_GREEN, screen_color);
          tft.print(" ON         ");
          delay(1000);
          digitalWrite(TFT_led, LOW); //turn the TFT_led off
  }
  else
  {
    //day light  foot lamp will off and display light on
          digitalWrite(Foot_lamp, LOW);   // turn the Foot_lamp off
          digitalWrite(TFT_led, HIGH);  // turn the TFT_led on
          tft.setTextSize(2);
          tft.setCursor(30, 170);
          tft.setTextColor(ILI9340_BLUE, screen_color);
          tft.print("FOOT LAMP");
          tft.setTextColor(ILI9340_RED, screen_color);
          tft.print(" OFF         ");
  }
}
  
}

void zero_crosss_fan1()  // function to be fired at the zero crossing to dim the light
{
  // Firing angle calculation :: 60Hz-> 8.33ms (1/2 Cycle)
  // (8333us - 8.33us) / 128 = 65 (Approx)
  int dimtime = dimming;  //dimming    
  delayMicroseconds(dimtime);    // Off cycle
  digitalWrite(fan, HIGH);   // triac firing
  delayMicroseconds(8.33);         // triac On propogation delay
  digitalWrite(fan, LOW);    // triac Off
}







