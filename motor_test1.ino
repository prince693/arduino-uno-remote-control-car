#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <IRremote.h>
int reep=9;
int red=12;
int green=13;
int mp1=5;
int mp2=6;
int mp3=7;
int mp4=8;
IRrecv irrecv(reep);
decode_results result;
void setup() {
  // put your setup code here, to run once:
  pinMode(mp1,OUTPUT);
    pinMode(mp2,OUTPUT);
    pinMode(mp3,OUTPUT);
    pinMode(mp4,OUTPUT);
      pinMode(red,OUTPUT);
       pinMode(green,OUTPUT);
Serial.begin(9600);
irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
if(irrecv.decode(&result)==true){
Serial.println(result.value);
irrecv.resume();
}
delay(200);
if(result.value==16732845){
  //forward
  digitalWrite(mp2,HIGH);
  digitalWrite(mp1,LOW);
  digitalWrite(mp3,HIGH);
  digitalWrite(mp4,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
delay(200);
  }
  else if(result.value==16742535){
    //reverse
     digitalWrite(mp2,LOW);
  digitalWrite(mp1,HIGH);
   digitalWrite(mp3,LOW);
  digitalWrite(mp4,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  delay(200);
    }
    else if(result.value==16769565){
      //stop
     digitalWrite(mp1,LOW);
  digitalWrite(mp2,LOW);
  digitalWrite(mp4,LOW);
  digitalWrite(mp3,LOW);
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  delay(200);
    }

    else if(result.value==16758855  ){
      //LEFT
     digitalWrite(mp3,HIGH);
  digitalWrite(mp2,LOW);
  digitalWrite(mp4,LOW);
  digitalWrite(mp1,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  delay(200);
    }
     else if(result.value==16728765){
      //RIGHT
     digitalWrite(mp4,HIGH);
  digitalWrite(mp1,LOW);
  digitalWrite(mp3,LOW);
  digitalWrite(mp2,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  delay(200);
    }
}
