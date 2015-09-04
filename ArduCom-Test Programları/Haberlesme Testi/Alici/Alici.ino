#include <SPI.h>
#include <nRF24L01p.h>

nRF24L01p receiver(7,8);//CSN,CE
/*
CSN –> 7
CE –> 8
MOSI –> 11
MISO –> 12
SCK –> 13
VCC –> 3.3V
GND –> GND
IRQ –> Boşta
*/


void setup(){
  delay(150);
  Serial.begin(9600);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  receiver.channel(90);
  receiver.RXaddress("Mert2");
  receiver.init();
}

String message;
int data1,data2,data3;
void loop(){ 
  if(receiver.available()){
    receiver.read();
    //receiver.rxPL(message);
    receiver.rxPL(data1);
    receiver.rxPL(data2);
    Serial.print("X Ekseni :");
    Serial.print(data1);
    Serial.print("\t Y Ekseni :");
    Serial.println(data2);

  }
}
