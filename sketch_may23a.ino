// Libraries used for this project
//https://github.com/adafruit/DHT-sensor-library For DHT Sensor
//https://github.com/adafruit/Adafruit_Sensor Dependencie for the library

//Include an define sensor and libraries
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
const int sensor_pin = A0;

//Define the DHTTYPE
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Init dht to read the data
  dht.begin();
}

// Create a void to DHT Reads
void dhtRead() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}

// Create a void to fc128 sensor read the data

void fc128Read() {
 
  float moisture_percentage;
  //float moisture_float;

  //moisture_float = analogRead(sensor_pin);

  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  //Serial.println("-----------");
  //Serial.println("Soil Moisture(in float) =");
  //Serial.println(moisture_float);

  delay(2000);

}

//Pass in void loop the two functions
void loop() {
  dhtRead();
  fc128Read();
}