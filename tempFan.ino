int temp,fanSpeed,fanLCD ;
int temp2,fanSpeed3,fan_temp_lcd ;
 
 void fan_Controll_1()    
    {               
          temp = cel;     // get the temperature
          if(temp < 27)
               {   // if temp is lower than minimum temp
                   fanSpeed = 0;      // fan is not spinning
                   fanLCD=0;
                   digitalWrite(fan , LOW);                  
                } 
          if((temp >= 27) && (temp <= 50)) 
               { 
                  // if temperature is higher than minimum temp
                  fanSpeed = map(temp, 27, 50, 32, 255); // the actual speed of fan
                  fanLCD = map(temp, 27, 50, 0, 100);  // speed of fan to display on LCD
                  analogWrite(fan, fanSpeed);  // spin the fan at the fanSpeed speed                      
                }     
          if(temp > 50)
                {        // if temp is higher than 50
                   //fanSpeed = map(temp, 27, 50, 32, 255); // the actual speed of fan
                    digitalWrite(fan , HIGH);  // turn on led                    
                    //.println("temp is higher than 50");
                    fanLCD=100;
                 } 
       Lcd_fan_printManual(fanLCD);       
       //.print("TEMPRATURE=");  
       //.print(temp);  
       //.print("*C  ");  
       //.print("FAN SPEED=");  
       //.print(fanLCD);  
       //.print("%");        
       //.println();    
    }


/******************fan_ auto********************/

void fan_Controll_2()    
    {              
         temp2 = cel;     // get the temperature
         if(temp2 < 27)
              {    // if temp is lower than minimum temp
                   fanSpeed3 = 0;      // fan is not spinning
                   fan_temp_lcd=0;          
                   digitalWrite(fan_2 , LOW);      
             } 
         if((temp2 >= 27) && (temp2 <= 50)) 
             { 
                   // if temperature is higher than minimum temp
                   fanSpeed3 = map(temp2, 27, 50, 32, 255); // the actual speed of fan
                   fan_temp_lcd = map(temp2, 27, 50, 0, 100);  // speed of fan to display on LCD      
                   analogWrite(fan_2, fanSpeed3);    
              }     
        if(temp2 > 50)
              {     // if temp is higher than 50          
                   digitalWrite(fan_2 , HIGH);
                   //.println("temp is higher than 50");
                   fan_temp_lcd=100;
              } 
         Lcd_fan_printManual(fan_temp_lcd);    
    }
    
