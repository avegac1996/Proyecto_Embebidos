#include "NewPing.h"      // include NewPing library
#include <DHT.h>

// Dependiendo del tipo de sensor
#define DHTTYPE DHT11

int DHTPIN = D2; 

// for ESP8266 microcontroller
int trigPin = D0;      // trigger pin
int echoPin = D1;      // echo pin

NewPing sonar(trigPin, echoPin);


// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);


#include <ESP8266WiFi.h> //Librería de conexión WiFi del módulo ESP8266
#include <ThingerESP8266.h> //Librería de la plataforma thinger.io
#include "DHT.h" //Librería de los sensores DHT11, DHT22, etc.
// Parámetros del conexión con thinger.io
#define usuario "avegac"
#define device_Id "DHT11"
#define device_credentials "tEIvBV1vA80fBGsJ"
ThingerESP8266 thing(usuario, device_Id, device_credentials);
// Parámetros de conexión WiFi
const char WiFi_ssid[]="Dante"; //Nombre de red
const char WiFi_password[]="Darkdevil2247"; //Clave de red


void setup() {
  // Inicializamos comunicación serie
  Serial.begin(9600);
 
  // Comenzamos el sensor DHT
  dht.begin();

   // Inicialización de la WiFi para comunicarse con la API
 thing.add_wifi(WiFi_ssid, WiFi_password);
 // Inicialización de la lectura de datos desde la API
  thing["Humedad"]>>outputValue(dht.readHumidity());
  thing["Temperatura"]>>outputValue(dht.readTemperature());


  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT);

  thing["SONIC"] >> [] (pson& out){
      double duration, distance;
      digitalWrite(D0, LOW);  // Get Start
      delayMicroseconds(2); // stable the line 
      digitalWrite(D0, HIGH); // sending 10 us pulse
      delayMicroseconds(10); // delay 
      digitalWrite(D0, LOW); // after sending pulse wating to receive signals 
      duration = pulseIn(D1, HIGH); // calculating time 
      distance = (duration/2) / 29.1; // single path 
      out = distance;
  };

 
}
 
void loop() {
    // Esperamos 5 segundos entre medidas
 delay(1000);

  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahreheit
  float f = dht.readTemperature(true);
  
   
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
  // Calcular el índice de calor en Fahreheit
  float hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);

  
 float distance = sonar.ping_median(5);

  if(distance>2500 || distance<1) Serial.println("Out of range");
  else
  {
    Serial.print("Distance: ");
    Serial.print(distance, 1); Serial.println(" cm");

  }
 
    Serial.print("Humedad: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t");
    Serial.print("Índice de calor: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.println(" *F");

   Serial.println(dht.readTemperature());
   Serial.println(dht.readHumidity());
   thing.handle();
 
}
