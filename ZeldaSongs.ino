#include "pitches.h"
int pressPin = 0;
int initRead;
int reading;
boolean startUp;
int speaker = 11;
int song;

void setup(){
  Serial.begin(9600); 
  initRead = 0;
  song = 0;
  reading = analogRead(pressPin);
  startUp = true;
  pinMode(speaker,OUTPUT);
}

void loop(){
  calibrate();
  Serial.print(song);
  reading = analogRead(pressPin);

  if (reading > 0)
  {
    if(song==0){  
      overworld();
      song = song + 1;
    }
    else
    {
      if (song == 1)
      {
        songOfStorms();
        song = song + 1;
      }
      else
      {
        if (song == 2){
          windFish();
          song = 0;
        }
      }
    }
  }
  else
  {
    noTone(speaker);
  }
}


void calibrate ()
{
  if(startUp == true)
  {
    initRead = reading;
    startUp = false;
  }
}

void windFish ()
{
  tone(speaker, NOTE_D5);
  delay(400);
  tone(speaker, NOTE_E5);
  delay(400);
  tone(speaker, NOTE_F5);
  delay(1400);
  tone(speaker, NOTE_D5);
  delay(400);
  tone(speaker, NOTE_E5);
  delay(400);
  tone(speaker, NOTE_F5);
  delay(1400);
  tone(speaker, NOTE_E5);
  delay(400);
  tone(speaker, NOTE_D5);
  delay(400);
  tone(speaker, NOTE_A4);
  delay(400);
  tone(speaker, NOTE_C5);
  delay(800);
  tone(speaker, NOTE_D5);
  delay(1000);
}

void songOfStorms ()
{
  tone(speaker, NOTE_D4);
  delay(200);
  tone(speaker, NOTE_F4);
  delay(200);
  tone(speaker, NOTE_D5);
  delay(600);
  noTone(speaker);
  delay(50);
  tone(speaker, NOTE_D4);
  delay(200);
  tone(speaker, NOTE_F4);
  delay(200);
  tone(speaker, NOTE_D5);
  delay(600);
  noTone(speaker);
  delay(50);
  tone(speaker, NOTE_E5);
  delay(600);
  tone(speaker, NOTE_F5);
  delay(200);
  tone(speaker, NOTE_E5);
  delay(200);
  tone(speaker, NOTE_F5);
  delay(200);
  tone(speaker, NOTE_E5);
  delay(200);
  tone(speaker, NOTE_C5);
  delay(200);
  tone(speaker, NOTE_A4);
  delay(600);
  noTone(speaker);
  delay(50);
  
}

void overworld(){
  tone(speaker, NOTE_A4);
  delay(400);
  tone(speaker, NOTE_E4);
  delay(800);
  
  tone(speaker, NOTE_A4);
  delay(150);
  noTone(speaker);
  delay(10);
  tone(speaker, NOTE_A4);
  delay(150);
  tone(speaker, NOTE_B4);
  delay(150);
  tone(speaker, NOTE_C5);
  delay(150);
  tone(speaker, NOTE_D5);
  delay(150);
  tone(speaker, NOTE_E5);
  delay(800);


}


