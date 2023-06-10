#define BLYNK_PRINT Serial 
#define RELE_ON = 0;
#define RELE_OFF=1;
#include <BlynkSimpleEsp8266.h>

//Const values provided by Blynk App Web
#define BLYNK_TEMPLATE_ID "TMPL2U2UMCDlx"
#define BLYNK_TEMPLATE_NAME "Automatic Irrigation System"
#define BLYNK_AUTH_TOKEN "zbo1m3QhRuoKYmqvdC-Yc91vYZtLPGl3"

const int sensor_pin = A0;
int rele = 5;

//Constant of Wi-Fi, values may change
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Familia_Rodriguez";
char pass[] = "Rodriguez1234";

//Widgets of Virtual LEDS and Virtual Pins
WidgetLED led1(V1); //Virtual Pins
WidgetLED led2(V2); //Virtual pins

BlynkTimer timer;


void principal() {
  float moisture_percentage;
  float moisture_float;

 

  moisture_float = analogRead(sensor_pin);
  delay(1000);

  
  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Blynk.virtualWrite(V3, moisture_percentage);

  if (moisture_float >= 650)
  {
    digitalWrite(rele, RELE_ON);
    Serial.println("Medida: ");
    Serial.println(moisture_float);
    delay(2000);
    led1.on();
    led2.off();
  }
  else
  {
    digitalWrite(rele, RELE_OFF);
    Serial.println("Medida: ");
    Serial.println(moisture_float);
    led2.on();
    led1.off();
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); //Start the session
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 8080); Change for this if dont work first
  timer.setInterval(1000L, principal()); //Set time and call the function
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run(); //Call the function timer
}
