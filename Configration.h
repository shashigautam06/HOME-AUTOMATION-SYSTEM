
/***********BLUETOOTH BUTTON VALUES***************************/
int BluetoothData; // the Bluetooth data received 
unsigned int bt_fan1_speed_value=0;
unsigned int bt_fan2_speed_value=0;
byte fan_ide=0;
int    btPower = 12,  
       btSleep = 46824,
       btlight_1 = 1 ,
       btlight_2 = 2,
       btlight_3 = 3,
       btlight_4 = 4 ,
       btlight_5 = 5,
       btlight_6 = 6,
       btlight_7 = 7,
       btfan_auto_fan1 = 34, //fan 1 ,auto mode button code for bluetooth
       btfan_auto_fan2 = 15, //fan 2 ,auto mode button code for bluetooth
       bt_fan1  =  17 ,
       bt_fan1_  =  16 ,
       bt_fan2  =  33,
       bt_fan2_  =  32
     ; /*
#define btPower 12  
#define btSleep  46824
#define btlight_1 1
#define btlight_2 2
#define btlight_3  3
#define btlight_4  4
#define btlight_5  5
#define btlight_6  6
#define btlight_7  7
#define btfan_auto_fan1  34  //fan 1 ,auto mode button code for bluetooth
#define btfan_auto_fan2   15  //fan 2 ,auto mode button code for bluetooth
#define bt_fan1   17 
#define bt_fan1_   16
#define bt_fan2    33
#define bt_fan2_  32*/


/***********bluetooth***************************/

/*red 10372,24153
green  57171,48614
yellow 48211,57574
blue 19306,15223 */
//ir remote TOGGLE code
#define light_red1  10372 //light1 button 
#define light_red1_  24153 //light1 button 
#define light_green2  57171//light2 button 
#define light_green2_  48614 //light2 button  
#define light_yellow3  48211 //light3 button  
#define light_yellow3_  57574 //light3 button 
#define light_blue4  19306 //light1 button
#define light_blue4_  15223 //light1 button
 
/**********************IR REMOTE CODE SETUP SECTION***********************/ 
// ir remote speed control
#define fan1_code2  2065      //fan1 speed down button -
#define fan1_code2_  17      //fan1 speed down button - 
#define fan1_code1  2064       //fan1 speed up button +
#define fan1_code1_  16       //fan1 speed up button +

#define fan2_code2  2081     //fan2 speed down button -  
#define fan2_code2_ 33     //fan2 speed down button -  
#define fan2_code1   2080     //fan2 speed up button + 
#define fan2_code1_   32     //fan2 speed up button + 
 
#define fan_auto_button1  2082      //fan1  mode button (auto/manual)
#define fan_auto_button1_  34

#define fan_auto_button2  2063      //fan2  mode button (auto/manual)
#define fan_auto_button2_  15

#define irPower  2060      //power on/off mode button 
#define irPower_  12      //power on/off mode button 

#define sleep_mode 46824  //sleep mode button 
#define sleep_mode_ 34909  //sleep mode button 

//ir remote TOGGLE code
#define light_1  2049 //light1 button  
#define light_2  2050 //light2 button  
#define light_3  2051 //light3 button  
#define light_4  2052 //light1 button  
#define light_5  2053 //light2 button  
#define light_6  2054 //light3 button  
#define light_7  2055 //light3 button
/******/
#define light_1_  1 //light1 button  
#define light_2_  2 //light2 button  
#define light_3_  3 //light3 button  
#define light_4_  4 //light1 button  
#define light_5_  5 //light2 button  
#define light_6_  6 //light3 button  
#define light_7_   7 //light3 button
/*****/
#define error_code 65535
/**********************IR REMOTE CODE SETUP SECTION***********************/ 

/*********************PIR_CONFIGRATION*************/
unsigned int calibrationTime=3;          //the time we give the sensor to calibrate (10-60 secs according to the datasheet)
long unsigned int lowIn;          //the time when the sensor outputs a low impulse     
unsigned int pause = 5000;                //the amount of milliseconds the sensor has to be low before we assume all motion has stopped   
boolean lockLow = true;
boolean takeLowTime;  
#define pirPin A0    //the digital pin connected to the PIR sensor's output

/*********************PIR_CONFIGRATION***************/

/***************TEMPRATURE****************************/
#define temp_sensor  A1   //temprature sensor LM35 to analog pin A0
//int temp,fanSpeed,fanLCD,tempMin = 27,tempMax = 40; 
int reading,cel;

/***************TEMPRATURE****************************/

/******************LDR SENSOR***************************/
#define LDR A2   //LDR input pin
int LDR_val=0;
unsigned int turnOnValue=1000;
 
/******************LDR SENSOR***************************/


/**********************IR SENSOR***********************/
#define RECV_PIN  A3 //3 // the pin where you connect the output pin of TSOP4838
/**********************IR SENSOR***********************/

/******************TOGGLE LIGHT ON/OFF SETUP PINS*************************/
byte itsONled[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  //array used for toggle button store 0,1 only.
#define led1    A4 //output pin CFL1
#define led2    A5//output pin CFL2
#define led3    2//output pin CFL3
#define led4    4//output pin CFL4
#define led5    7//output pin CFL5
#define led6    18//output pin CFL6
#define led7    12//output pin CFL7
#define Foot_lamp 8 //Night ground lights
#define fan  5 // the ~5 pin where fan is
#define fan_2  6 // the ~6 pin where fan is
#define TFT_led 3 //~3 PWM PIN  ,user ontroll lcd led brightness
/******************TOGGLE LIGHT ON/OFF SETUP PINS*************************/

/*******************PWM FAN PIN*********************************/
 
  int count,fanSpeed2,fanLCD2;
  int count2,fanLCD3;


/*******************PWM FAN PIN*********************************/

/*******************OTHER*******************/
//unsigned int recieve_value;
//int value2;
byte binary_bit=0;
byte IDE; 
byte mode=0; 
byte power=0;
byte mode_sleep=0;
byte night_mode=0;
byte pir_count=0;
int dimming = 128;
/*******************OTHER*******************/ 






