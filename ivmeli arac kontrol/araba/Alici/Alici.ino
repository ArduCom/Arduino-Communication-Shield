/*
ArduCom Pin 
NRF:
CSN:7
CE:8

__

SD Kart
CS:6


___
Led:5



*/


#include <SPI.h>
#include <nRF24L01p.h>

nRF24L01p receiver(7,8);//CSN,CE

 
#include <SD.h>

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

#include<Wire.h>

int rst=5;

const int chipSelect = 6;
File myFile;


void setup(){
  
 
    pinMode(chipSelect, OUTPUT);
    pinMode(rst,OUTPUT);
    digitalWrite(rst, HIGH);
    
  delay(150);
  Serial.begin(9600);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  receiver.channel(90);
  receiver.RXaddress("Mert");
  receiver.init();
  
  
  if (!SD.begin(6)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

   myFile = SD.open("bbbb.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
}

String message;
int data1,data2,data3;

long say=0;

void loop()
{ 
    digitalWrite(rst, HIGH);
  if(receiver.available())
  {

    receiver.read();
    receiver.rxPL(data1);
  myFile = SD.open("arducom.txt", FILE_WRITE);
  
  if (myFile) 
  {
    myFile.print("\t gelen data:\t");
    myFile.print(data1); 
    myFile.close();
    Serial.println("done.");
  }else{ 
    Serial.println("*");
    }
    
    Serial.print("\t gelen data:\t");
    Serial.println(data1);
  }
 
    digitalWrite(rst, LOW);
    delay(200);
}







