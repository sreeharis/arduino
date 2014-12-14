#include <Wire.h>
#include "RTClib.h"
#include <EEPROMex.h>
RTC_DS1307 rtc;
DateTime tnow;
void display_data();
void custom_day();
void regular_day();
void holiday();
void exam();
void friday();
void ring();

struct data{
         double exam[20];
         double special[10];
         double examt[10];
         double regulart[10];
         double fridayt[10];
         double specialt[10];
          
        }t1,t0;
        t1.exam[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        t1.special[]={0,0,0,0,0,0,0,0,0,0};
        t1.examt[]={0,0,0,0,0,0,0,0,0,0};
        t1.regulart[]={0,0,0,0,0,0,0,0,0,0};
        t1.fridayt[]={0,0,0,0,0,0,0,0,0,0};
        t1.specialt[]={0,0,0,0,0,0,0,0,0,0};


void setup(){
  int address=0;
  EEPROM.readBlock(address, t0);
  
}
void loop(){
  tnow = rtc.now();
  char date[8];
  double ee=tnow.year()/100;
  double date=tnow.day()*100+tnow.month()+ee-int(ee);
  double time=tnow.hour+tnow.minute;
  
  display_data();
  int i=0;
  while(i>limit){
    if(date==d1.exam[i])
     exam();
     i++;
}
//else regular
  if(tnow.dayOfWeek()==6)
   friday();
  else if((tnow.dayOfWeek()==1)||(tnow.dayOfWeek()==7))
   continue;
  else
   regular();

}

void regular(){
  int j=0;
  while(limit){
    if(t1.regular[j]==time)
     ring();
  }
}
void friday(){
  int j=0;
  while(limit){
    if(t1.friday[j]==time)
     ring();
  }
  }
void exam(){
int j=0;
  while(limit){
    if(t1.exam[j]==time)
     ring();
  }
  }
  
