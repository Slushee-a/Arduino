//You need to tweak the settings to your need.
#include <AnalogSmooth.h>
 
 int analogPin = 0;
 int lednum;

AnalogSmooth as70 = AnalogSmooth(70);
 
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(0, INPUT);

  Serial.begin(9600);
}

void loop()
{

  float analog = analogRead(analogPin);
  float analogSmooth = as70.smooth(analog);
  int analogSmoothInt = analogSmooth;
  
  lednum = map(analogSmooth, 0, 80, 255, 100);

  analogWrite(3, lednum);
  delay(1);
  analogWrite(3, lednum);
  delay(1);
  analogWrite(3, lednum);

  Serial.println(analogSmoothInt);
  //Serial.println(map (lednum, 0, 255, 45, 0));
}
