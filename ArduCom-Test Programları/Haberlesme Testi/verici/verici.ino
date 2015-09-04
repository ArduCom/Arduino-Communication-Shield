#include <SPI.h>
#include <nRF24L01p.h>

nRF24L01p transmitter(7,8);//CSN,CE

void setup(){
  delay(150);
  Serial.begin(9600);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  transmitter.channel(90);
  transmitter.TXaddress("Mert2");
  transmitter.init();
  
  Serial.print("verici");
}

byte myData[5]={18,05,19,89,24};                 // 5 Bytes
char *myCharArray="KirmiziSpor";                   //14 Bytes
int myInts[3]={311,220,311};                    // 6 Bytes
unsigned int myUint[5]={101,102,103,104,105};//10 Bytes +
                                              // = 31 Bytes
                                  //less than 32 Bytes PayLoad
                                  
                                  
int xEkseni=0;
int yEkseni=0;

String ileti = "Mert!";

unsigned long time;


void loop(){
    time = millis();


      transmitter.txPL(time);
      transmitter.txPL("1000");
      
      
      transmitter.send(SLOW);
      Serial.println("gonderildi");
      delay(1000);
      
    }
 
