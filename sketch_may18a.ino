const int sensor_pin = A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float moisture_percentage;
  float moisture_float;

  moisture_float = analogRead(sensor_pin);

  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  Serial.println("-----------");
  Serial.println("Soil Moisture(in float) =");
  Serial.println(moisture_float);

  delay(1000);

}
