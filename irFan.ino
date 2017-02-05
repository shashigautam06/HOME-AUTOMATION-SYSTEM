

void ir_fan_Controll(int value2,byte mode)
    { 
      
             
      
      if((mode==0  && power==1) ||(mode==0 && mode_sleep==1))      
        {    
            if(count <= -1)// remove over (-ve) range
                 count=0;
            if(count >= 200)   // remove over limit (+ve) range
                 count=200;       //Max limit        
                 
            if(fan1_code1==value2 || fan1_code1_==value2)
                 count=count+50;        
            if(fan1_code2==value2 || fan1_code2_==value2)
                 count=count-50;

             
           if((count >= 0) && (count <= 200)) 
                 { 
                    dimming=count;
                     
                    fan_ide=1;
                    Lcd_fan_printManual(count);          
                 } 
          zero_crosss_fan1();
           irrecv.resume();
      }
/*************************fan1 ends********************/

/**************************fan2 starts*******************/
        if((mode==20  && power==1)||(mode==20 && mode_sleep==1))
             {     
       
                if(count2 <= -1)// remove over (-ve) range
                     count2=0;
                if(count2 >= 50)   // remove over limit (+ve) range
                     count2=50;       //Max limit        
                if(fan2_code1==value2 || fan2_code1_==value2)
                     count2=count2+1;        
                 if(fan2_code2==value2 || fan2_code2_==value2)
                      count2=count2-1;
                 if(count2 <= 0)
                     {   // if count2 is lower than minimum count2
                          fanSpeed2 = 0;      // fan is not spinning
                          digitalWrite(fan_2, LOW);    
                          //.print("fan stop due to count2<=0"); 
                          //.print("  count2 :"); 
                          //.print(count2); 
                          //.print("  Remote button  code for ir fan is:"); 
                          //.println(value2);
                          fanLCD3=0;
                          fan_ide=2;
                          Lcd_fan_printManual(fanLCD3);
                      }

                if((count2 >= 1) && (count2 <= 50)) 
                     { 
                        // if temperature is higher than minimum temp
                        fanSpeed2 = map(count2, 1, 50, 32, 255); // the actual speed of fan
                        fanLCD3 = map(count2, 1, 50, 0, 50);  // speed of fan to display on LCD
                         // fanSpeed = map(count2, 0, 1023, 0, 255);
                        analogWrite(fan_2, fanSpeed2);  // spin the fan at the fanSpeed speed
                        //.print("(count2 >= 1) && (count2 <= 50) fan speed :"); 
                        //.print(fanLCD3);
                        //.println("%"); 
                        //.print("  count2 :"); 
                        //.print(count2); 
                        //.print("  Remote button  code for ir fan is:"); 
                        //.println(value2);
                        fan_ide=2;
                        Lcd_fan_printManual(fanLCD3);          
                     } 
             if(count2 > 50)
                    {        // if count2 is higher than 50
                        digitalWrite(fan_2 , HIGH);  // turn on fan full speed
                        //.print("count2 > 50 ,Fan speed full 100% :"); 
                        //.print("  count2 :"); 
                        //.print(count2); 
                        //.print("  Remote button  code for ir fan is:"); 
                        //.println(value2); 
                        fanLCD3=50;
                        fan_ide=2;
                        Lcd_fan_printManual(fanLCD3);
                     }        
              irrecv.resume();
      }
      
/*************************fan2 ends****************/
      
      else
      {
        if(mode==1)
          {
         
           //.print(" Mode value is:"); 
           //.print(mode); 
           //.print("  Remote Auto button  pressed code  is:"); 
           //.println(value2); 
           fan_Controll_1();
          }
       if(mode==10 )
       {
         
           //.print(" Mode value is:"); 
           //.print(mode); 
           //.print("  Remote Auto button  pressed code  is:"); 
           //.println(value2); 
            fan_Controll_2();
         }
      }
   
   }
      
