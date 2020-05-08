#include <SoftwareSerial.h>
SoftwareSerial BT1(4,2); // RX, TX recorder que se cruzan
void setup()
   {
       Serial.begin(9600);
        pinMode(8, OUTPUT);
       Serial.println("Enter AT commands:");
       BT1.begin(9600);
   }

void loop()
   {
       if (BT1.available())
           Serial.write(BT1.read());
           

       
       if (Serial.available()>0)
          {  String q = GetLine();
              
              BT1.print(q);
              Serial.println("---> " + q);
              digitalWrite(8,9);
              delay(100);
              digitalWrite(8,0);     
              if(q.equals("hola")){
              Serial.println("encendido");
              digitalWrite(8,1);
              delay(100);
              }
             
          }
}

String GetLine()
   {   String S = "" ;
       if (Serial.available())
          {    char c = Serial.read(); ;
                while ( c != '\n')            //Hasta que el caracter sea intro
                  {     S = S + c ;
                        delay(25) ;
                        c = Serial.read();
                  }
                return( S + '\n') ;
          }
   }
