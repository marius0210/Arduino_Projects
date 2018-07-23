int temp_sensor= A0;
int temp_reading;
long previousMillis_temp=0;
long interval_temp =1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
       unsigned long currentMillis = millis();

if(currentMillis - previousMillis_temp > interval_temp) {
        previousMillis_temp = currentMillis;
        temp_reading=analogRead (temp_sensor);   
        float mv = (temp_reading/1024.0)*5000; 
        float cel = mv/10;
        float farh = (cel*9)/5 + 32;
        Serial.print("TEMPRATURE = ");
        Serial.print(cel);
        Serial.print("*C");
        Serial.println();
  }
}
