#include <SPI.h>
#include <nRF24L01p.h>

nRF24L01p transmitter(7,8);//CSN,CE
byte myData[5]={18,05,19,89,24};                 // 5 Bytes
char *myCharArray="NRF24L01+";                   //10 Bytes
int myInts[3]={-311,220,311};                    // 6 Bytes
unsigned int myUint[5]={101,102,103,104,105};//10 Bytes +
                                              // = 31 Bytes
                                  //less than 32 Bytes PayLoad
String ileti = "Mert!";


#include<Wire.h>
const int MPU=0x68;  // I2C address of the MPU-6050
int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

long AcXk,AcYk,AcZk;


void setup(){
  delay(150);
  Serial.begin(9600);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  transmitter.channel(90);
  transmitter.TXaddress("Mert");
  transmitter.init();
  
  Serial.print("verici");
  
  
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  
  kalibrasyon();
}





void ivmeOku()
{
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)  
}
int i=0;
void kalibrasyon()
{
  AcXk=0;
  AcYk=0;
  AcZk=0;
  for(i=1;i<100;i++)
  {
    ivmeOku();
    AcXk=AcXk+AcX;
    AcYk=AcYk+AcY;
    AcZk=AcZk+AcZ;
  }
  AcXk=AcXk/100;
  AcYk=AcYk/100;
  AcZk=AcZk/100;
  Serial.print("\t i = "); Serial.print(i);
  Serial.print("\t | AcXk = "); Serial.print(AcXk);
  Serial.print("\t | AcYk = "); Serial.print(AcYk);
  Serial.print("\t | AcZk = "); Serial.println(AcZk);
  
  
}

void hareketGonder()
{
  
  


}





void loop(){
 

       
     ivmeOku();    
  
   
     AcY=AcY-AcYk;
     AcZ=AcZ-AcZk;
     AcX=AcX-AcXk;
     AcY=map(AcY, -16000, 16000, -255, 255); 
     AcZ=map(AcZ, -16000, 16000, -255, 255); 
 
  
  //Serial.print("\t | AcX = "); Serial.println();
  //Serial.print("\t | AcY = "); Serial.print(AcY);
  //Serial.print("\t | AcZ = "); Serial.println(AcZ);
  //delay(500);    
   
      myInts[0]=AcY;
      myInts[1]=100;
      myInts[2]=100;
   
//      transmitter.txPL(myData,5);
//      transmitter.txPL(myCharArray,10);
      transmitter.txPL(myInts,1);
//      transmitter.txPL(myUint,5);
      
      transmitter.send(FAST);
     // Serial.println("gonderildi");   
      
   
    }
 
