#include <Servo.h> //Include servo library
Servo servo; //Define servo name
int Spos; //Serpo poition int

#include <DHT.h> //DHT library inclusion
#define DHTTYPE DHT11 //Define DHT type
const int DHTPin = 5; //Define DHT data pin
DHT dht(DHTPin, DHTTYPE); //Configure library

#include <Ultrasonic.h> //Ultrasonic library inclusion
Ultrasonic ultrasonic(8, 7); //Ultrasonic sensor pin setting



const int LED_US = 4; //define Ultrasonic Sensor
const int LED_TS = 3; //define Temperature Sensor

int US_Distance; //Create int for distance value
int TS_Temperature; //Create int for temperature value. Float is not needed.


void setup() 
{
  Serial.begin(9600); //Start serial comunication
  dht.begin(); //Start DHT library
  servo.attach(2); //Attach servo to pin 2
}


void loop() 
{
  US_Distance = ultrasonic.distanceRead(); //Read distance and store in int value
  TS_Temperature = dht.readTemperature(); //Read temperature and store in int value
  
  //Interface for serial monitor. Makes it more easy to read.
  Serial.print("Distance in CM: ");
  Serial.print(US_Distance); //Print distance in cm
  
  Serial.print("         Rough temperature: ");
  Serial.print(TS_Temperature); //Print temperature
  Serial.println(" ºC");

  delay(500);

/*
 * These if statements are written in a compact way since they are very simple.
 */
 
  //If the distance is less that 50 cm, turn on LED_US. Else, turn it off.
  if( US_Distance < 50 )
    { digitalWrite(LED_US, HIGH); }
  else
    { digitalWrite(LED_US, LOW); }

  //If the temperature is bigger than 27ºC, turn on the LES_TS. Else, turn it off.
  if( TS_Temperature > 27 )
    { digitalWrite(LED_TS, HIGH); }
  else
    { digitalWrite(LED_TS, LOW); }

  //If the temparature is above 30ºC and the distance under 50 cm serco will trigger if not, it will stay at 0º
  if( TS_Temperature > 30 && US_Distance < 50)
    { 
     servo.write(60); //Set servo position to 60º
     delay(500); //Wait half a second
     servo.write(0); //Set servo position to 0º
     delay(500); //Wait half a second
    }
    
  else
  { servo.write(0); } //Stay at 0º

}
