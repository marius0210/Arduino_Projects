#include<dht.h>
dht DHT;

// if you require to change the pin number, Edit the pin with your arduino pin.

#define DHT11_PIN 13
int WaterAlarm = A1;
int Led=10;
int Buzzer=11;
boolean val; //simply reads 1 or 0 as a value 1 when detecting water

// here i set up the tones, you can change them @ void loop.
int tones[] = {261, 277, 293, 311, 329, 349, 369, 392, 415, 440, 466, 493, 523 ,554};
//              1    2    3    4    5    6    7    8    9    10   11   12   13   14
// You can add more tones but i added 14. Just fill in what tone you would like to use, @ void loop you see " tone(Buzzer, tones[12]); " below,  digitalWrite(Buzzer, HIGH);
// here you can change the tones by filling in a number between 1 and 14

int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the analog resistor divider

//Moisture soil

int MoistureSoil = A2;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor


void setup() {

Serial.begin(9600);
Serial.println("Detector temp-hum"); 
pinMode(WaterAlarm, INPUT);
pinMode(Led, OUTPUT);
pinMode(Buzzer, OUTPUT);
}

void loop() { // READ DATA

  /*Water Sensor LED Monitor*/

 val = analogRead(WaterAlarm);
  // Serial.println(val);
    if (val == 1)
    {
      Serial.println("Alerta APA");
    digitalWrite(Led, HIGH);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[6]);
    delay(200);
    digitalWrite(Led, LOW);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    delay(200);
    digitalWrite(Led, HIGH);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[14]);
    delay(200);
    digitalWrite(Led, LOW);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    delay(200);
    }
    else
    {
    digitalWrite(Led, LOW);
    digitalWrite(Buzzer, LOW); 
    }
    Serial.println("--------------------");
  
/*Temp and hum serial*/
int chk = DHT.read11(DHT11_PIN);//READ DATA Temp-Hum
Serial.println(" Umiditate " );
Serial.println(DHT.humidity, 1);
Serial.println(" Temperatura ");
Serial.println(DHT.temperature, 1);
delay(1000);
Serial.println("-------------------");



/*Photocell sensor*/

photocellReading = analogRead(photocellPin);
    Serial.print("Analog reading = ");
    Serial.println(photocellReading); // the raw analog reading
     if (photocellReading < 10) {
    Serial.println(" - Intuneric");
  } else if (photocellReading < 200) {
    Serial.println(" - Lumina slaba");
  } else if (photocellReading < 500) {
    Serial.println(" - Lumina Normala");
  } else if (photocellReading < 800) {
    Serial.println(" - Luminos");
  } else {
    Serial.println(" - Foarte Luminos");
  }
    delay(1000);        

   Serial.println("----------------------");

/*Moisture soil sensor
 # the sensor value description
 # 0  ~300     dry soil
 # 300~700     humid soil
 # 700~950     in water
*/

sensorValue = analogRead(MoistureSoil);    
  delay(10*10);          
  Serial.print("Umiditate Sol = " );                       
  Serial.println(sensorValue);       

   
    
    
}
