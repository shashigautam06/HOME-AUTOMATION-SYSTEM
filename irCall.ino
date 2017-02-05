void ir_RemoteCall(int value_switch,byte power) 
  {  
    //int value_switch = results.value;
      // results.value
       if((power==1 && mode_sleep==0)||(mode_sleep==1))
           {    
             switch(value_switch) 
              {
        
              case light_1:
              case light_1_:
              case light_red1:
              case light_red1_:
                   if(itsONled[1] == 1 )
                       {        // if first led is on then
                         digitalWrite(led1, LOW);   // turn it off when button is pressed
                         //.print("  Remote toggle button is pressed,  code is:");
                         //.print(value); // you can comment this line
                         //.println("  led1 off"); 
                         binary_bit=0; 
                         IDE=1;
                         Lcd_print_Call(binary_bit,IDE);
                         itsONled[1] = 0;           // and set its state as off
                      } 
                    else 
                     {                      // else if first led is off
                        digitalWrite(led1, HIGH); // turn it on when the button is pressed
                        //.print("  Remote toggle button is pressed,  code is:");
                        //.print(value); // you can comment this line
                        //.println(" led1 on");  
                        binary_bit=1; 
                        IDE=1;
                        Lcd_print_Call(binary_bit,IDE);
                        itsONled[1] = 1;          // and set its state as on
                      } break; 
                      
              case light_2:
              case light_2_:
              case light_green2:
              case light_green2_:
                   if(itsONled[2] == 1 )
                        {
                            binary_bit=0; 
                            IDE=2;
                            Lcd_print_Call(binary_bit,IDE);            
                            digitalWrite(led2, LOW); 
                            //.print("  Remote toggle button is pressed,  code is:");
                            //.print(value); // you can comment this line
                            //.println(" led2 off");  
                            itsONled[2] = 0;
                        }
                       else
                        {
                            binary_bit=1; 
                            IDE=2;
                            Lcd_print_Call(binary_bit,IDE);              
                            digitalWrite(led2, HIGH);
                            //.print("  Remote toggle button is pressed,  code is:");
                            //.print(value); // you can comment this line
                            //.println("  led2 on"); 
                            itsONled[2] = 1;
                         } break;
          
              case light_3:
              case light_3_:
              case light_yellow3:
              case light_yellow3_:
                    if(itsONled[3] == 1 )         
                        {
                            binary_bit=0; 
                            IDE=3;
                            Lcd_print_Call(binary_bit,IDE);
                            digitalWrite(led3, LOW);
                            //.print("  Remote toggle button is pressed,  code is:");
                            //.print(value); // you can comment this line
                            //.println("  led3 off"); 
                            itsONled[3] = 0;
                         } 
                        else 
                         {
                            binary_bit=1; 
                            IDE=3;
                            Lcd_print_Call(binary_bit,IDE);
                            digitalWrite(led3, HIGH);             
                            //.print("  Remote toggle button is pressed,  code is:");
                            //.print(value); // you can comment this line
                            //.println("  led3 on"); 
                            itsONled[3] = 1;
                          }  break;

               case fan_auto_button1:  // fan_auto_button1 code 
               case fan_auto_button1_:   // fan_auto_button1 code         
                      if(itsONled[4] == 1)
                         {             
                            mode=0;                                          
                            //.print("Auto mode off ,"); 
                            //.print("  Remote toggle button is pressed,  code is:");
                            //.println(value_switch); // you can comment this line
                            itsONled[4] = 0;
                         }
                        else 
                         {
                               
                             mode=1;  
                                         
                           //.println("Auto mode on ,"); 
                           //.print("  Remote toggle button is pressed,  code is:");
                           //.println(value_switch); // you can comment this line
                           itsONled[4] = 1;
                         }  break;  

              case fan_auto_button2:    // fan_auto_button2 code   
              case fan_auto_button2_:   // fan_auto_button2 code   
                     if(itsONled[5] == 1)
                       {             
                           mode=20; 
                                         
                          //.print("Auto mode off ,"); 
                          //.print("  Remote toggle button is pressed,  code is:");
                          //.println(value_switch); // you can comment this line
                          itsONled[5] = 0;
                      }
                    else 
                     {
                          
                          
                             mode=10;  
                                       
                         //.println("Auto mode on ,"); 
                         //.print("  Remote toggle button is pressed,  code is:");
                         //.println(value_switch); // you can comment this line
                         itsONled[5] = 1;
                   }    break;   

                          
                   case fan2_code1:
                   case fan2_code2:
                   case fan2_code1_:
                   case fan2_code2_:
                   if(itsONled[10] == 1)
                       {             
                          
                          itsONled[10] = 0;
                      }
                    else 
                     {
                         mode=20;             
                         //.println("Auto mode on ,"); 
                         //.print("  Remote toggle button is pressed,  code is:");
                         //.println(value_switch); // you can comment this line
                         itsONled[10] = 1;
                   }    break; 
 
                   case fan1_code1:
                   case fan1_code2:
                   case fan1_code1_:
                   case fan1_code2_:
                   if(itsONled[11] == 1)
                       {             
                          
                          itsONled[11] = 0;
                      }
                    else 
                     {
                         mode=0;             
                         //.println("Auto mode on ,"); 
                         //.print("  Remote toggle button is pressed,  code is:");
                         //.println(value_switch); // you can comment this line
                         itsONled[11] = 1;
                   }    break; 
                     
                   case light_4:
                   case light_4_:
                   case light_blue4:
                   case light_blue4_:
                   if(itsONled[12] == 1  )
                       {        // if first led is on then
                         digitalWrite(led4, LOW);   // turn it off when button is pressed
                         //.print("  Remote toggle button is pressed,  code is:");
                         //.print(value); // you can comment this line
                         //.println("  led1 off"); 
                         binary_bit=0; 
                         IDE=4;
                         Lcd_print_Call(binary_bit,IDE);
                         itsONled[12] = 0;           // and set its state as off
                      } 
                    else 
                     {                      // else if first led is off
                        digitalWrite(led4, HIGH); // turn it on when the button is pressed
                        //.print("  Remote toggle button is pressed,  code is:");
                        //.print(value); // you can comment this line
                        //.println(" led1 on");  
                        binary_bit=1; 
                        IDE=4;
                        Lcd_print_Call(binary_bit,IDE);
                        itsONled[12] = 1;          // and set its state as on
                      } break;
                       
                 case light_5:
                 case light_5_:
                   if(itsONled[13] == 1 )
                       {        // if first led is on then
                         digitalWrite(led5, LOW);   // turn it off when button is pressed
                         //.print("  Remote toggle button is pressed,  code is:");
                         //.print(value); // you can comment this line
                         //.println("  led1 off"); 
                         binary_bit=0; 
                         IDE=5;
                         Lcd_print_Call(binary_bit,IDE);
                         itsONled[13] = 0;           // and set its state as off
                      } 
                    else 
                     {                      // else if first led is off
                        digitalWrite(led5, HIGH); // turn it on when the button is pressed
                        //.print("  Remote toggle button is pressed,  code is:");
                        //.print(value); // you can comment this line
                        //.println(" led1 on");  
                        binary_bit=1; 
                        IDE=5;
                        Lcd_print_Call(binary_bit,IDE);
                        itsONled[13] = 1;          // and set its state as on
                      } break; 

                      case light_6:
                      case light_6_:
                   if(itsONled[14] == 1 )
                       {        // if first led is on then
                         digitalWrite(led6, LOW);   // turn it off when button is pressed
                         //.print("  Remote toggle button is pressed,  code is:");
                         //.print(value); // you can comment this line
                         //.println("  led1 off"); 
                         binary_bit=0; 
                         IDE=6;
                         Lcd_print_Call(binary_bit,IDE);
                         itsONled[14] = 0;           // and set its state as off
                      } 
                    else 
                     {                      // else if first led is off
                        digitalWrite(led6, HIGH); // turn it on when the button is pressed
                        //.print("  Remote toggle button is pressed,  code is:");
                        //.print(value); // you can comment this line
                        //.println(" led1 on");  
                        binary_bit=1; 
                        IDE=6;
                        Lcd_print_Call(binary_bit,IDE);
                        itsONled[14] = 1;          // and set its state as on
                      } break; 

                      case light_7:
                      case light_7_:
                   if(itsONled[15] == 1 )
                       {        // if first led is on then
                         digitalWrite(led7, LOW);   // turn it off when button is pressed
                         //.print("  Remote toggle button is pressed,  code is:");
                         //.print(value); // you can comment this line
                         //.println("  led1 off"); 
                         binary_bit=0; 
                         IDE=7;
                         Lcd_print_Call(binary_bit,IDE);
                         itsONled[15] = 0;           // and set its state as off
                      } 
                    else 
                     {                      // else if first led is off
                        digitalWrite(led7, HIGH); // turn it on when the button is pressed
                        //.print("  Remote toggle button is pressed,  code is:");
                        //.print(value); // you can comment this line
                        //.println(" led1 on");  
                        binary_bit=1; 
                        IDE=7;
                        Lcd_print_Call(binary_bit,IDE);
                        itsONled[15] = 1;          // and set its state as on
                      } break; 
                      
                      /*case light_8:
                      case light_8_:
                   if(itsONled[15] == 1 )
                       {        // if first led is on then
                         digitalWrite(Foot_lamp, LOW);    // turn it off when button is pressed
                         //.print("  Remote toggle button is pressed,  code is:");
                         //.print(value); // you can comment this line
                         //.println("  led1 off"); 
                         binary_bit=0; 
                         IDE=8;
                         Lcd_print_Call(binary_bit,IDE);
                         itsONled[16] = 0;           // and set its state as off
                      } 
                    else 
                     {                      // else if first led is off
                        digitalWrite(Foot_lamp, HIGH); // turn it on when the button is pressed
                        //.print("  Remote toggle button is pressed,  code is:");
                        //.print(value); // you can comment this line
                        //.println(" led1 on");  
                        binary_bit=1; 
                        IDE=8;
                        Lcd_print_Call(binary_bit,IDE);
                        itsONled[16] = 1;          // and set its state as on
                      } break; */


          
      }    
    irrecv.resume(); // Receive the next value
    ir_fan_Controll(value_switch,mode);   
  }
  else
  {
    power_off_mode();
  }
 
}
