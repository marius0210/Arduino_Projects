int WaterAlarm = A0;
int Buzzer = 4;
int Led_water = 3;
int Led_gas = 2;
int water;

//boolean water; //simply reads 1 or 0 as a value 1 when detecting water

// here i set up the tones, you can change them @ void loop.
int tones[] = {261, 277, 293, 311, 329, 349, 369, 392, 415, 440, 466, 493, 523 ,554};
//              1    2    3    4    5    6    7    8    9    10   11   12   13   14
// You can add more tones but i added 14. Just fill in what tone you would like to use, @ void loop you see " tone(Buzzer, tones[12]); " below,  digitalWrite(Buzzer, HIGH);
// here you can change the tones by filling in a number between 1 and 14

long previousMillis_water = 0;        // will store last time LED was updated

long interval_water = 1000; 


int GasSensor = A1;
//int Led_gas = 11;
long previousMillis_gas=0;
long interval_gas=1000;
int gas;


void setup() {
  Serial.begin(9600);
    pinMode (WaterAlarm, INPUT);
        pinMode (GasSensor, INPUT);

    //pinMode (Switch,INPUT);
    pinMode (Buzzer, OUTPUT);
    pinMode (Led_water, OUTPUT);
    pinMode (Led_gas, OUTPUT);
}

void loop(){

        unsigned long currentMillis = millis();
        if(currentMillis - previousMillis_water >interval_water){
                previousMillis_water = currentMillis; 
                water= analogRead(WaterAlarm);
                                  Serial.print("APA:");
                  Serial.println(WaterAlarm);
                if(water >100){
                  /*client.println("Alerta APA!!!");
                  client.println("<br />");*/
                  digitalWrite(Led_water, HIGH);
                  digitalWrite(Buzzer, HIGH);
                  tone(Buzzer, tones[8]);
                }
                else
            {
              /*client.println("Alarma apa functionala");
              client.println("<br />"); */
              digitalWrite(Led_water, LOW);
              digitalWrite(Buzzer, LOW); 
              noTone(Buzzer);
              }
        }  
        
        if(currentMillis - previousMillis_gas > interval_gas){
    previousMillis_gas = currentMillis;
    gas =analogRead(GasSensor);
    Serial.print("GAZ:");
                  Serial.println(WaterAlarm);
    if(gas>800)
    {
      digitalWrite(Led_gas, HIGH);
      digitalWrite(Buzzer,HIGH);
      tone(Buzzer, tones[6]);
    }
    else
    {
      digitalWrite(Led_gas, LOW);
      digitalWrite(Buzzer, LOW); 
      noTone(Buzzer);
    }
  } 
        

}

