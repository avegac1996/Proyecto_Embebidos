
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h> //Librería de conexión WiFi del módulo ESP8266

#include "DHT.h" //Librería de los sensores DHT11, DHT22, etc.

//Tomar datos de la plataforma firebase
//#define FIREBASE_HOST "fir-nodemcu-dht11-rafa-default-rtdb.firebaseio.com"                          // la direccion del nombre del proyecto de firebase id
//#define FIREBASE_AUTH "H5o0MeuFIfNQUI3G7wJ1nLGdEaSHnzaBJ0ammCht"            // copiar este codigoen secretos de la base de firebase
//Tomar datos de la red inalambrica de la casa
//#define WIFI_SSID ""
//#define WIFI_PASSWORD "Liga_1996"
#define FIREBASE_HOST "nodemcu-firebase-p59-default-rtdb.firebaseio.com/
#define FIREBASE_AUTH "eTNPzSJmvWONrHmLJeqtFQ8LMRx8R0g20JeCS3wt"    
#define WIFI_SSID "CELERITY_OPEN SOURCE"
#define WIFI_PASSWORD "Liga_1996"

#define DHTPIN 0    // Conectar Data pin de sensor DHT a D3=GPIO0
int Led = 4;      // Conectar Led a D2=GPIO4
#define DHTTYPE    DHT11
DHT sensor_dht(DHTPIN, DHTTYPE); // creamos el obteto sensor_dht

//Definimos FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData datoLED;

FirebaseJson json;


void setup()
{

  Serial.begin(9600);

  sensor_dht.begin();
  pinMode(Led,OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando a red Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Conectado con IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void sensorUpdate(){
  
  float h = sensor_dht.readHumidity(); //Lee la humedad
  
  // Lee la temperatura como grados Celsius (por default)
  float t = sensor_dht.readTemperature();
  // Lee la temperatura como grados Fahrenheit (isFahrenheit = true)
  float f = sensor_dht.readTemperature(true);

  // Chequeo si algo lee mal 
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Fallo lectura desde el sensor DHT!"));
    return;
  }

  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.print(F("C  ,"));
  Serial.print(f);
  Serial.println(F("F  "));

  if (Firebase.setFloat(firebaseData, "/FirebaseIOT/temperatura", t))
  {
    Serial.println("ENVIADO");
    
  }
  else
  {
    Serial.println("NO ENVIADO");
    
  }

  if (Firebase.setFloat(firebaseData, "/FirebaseIOT/humedad", h))
  {
    Serial.println("ENVIADO");
  }
  else
  {
    Serial.println("NO ENVIADO");
    
  }
}
void loop() {
  
  sensorUpdate(); //envio de datos de H y T
  
  if (Firebase.getString(datoLED, "/FirebaseIOT/Led")){
    Serial.println(datoLED.stringData());
    if (datoLED.stringData() == "ON") {
    digitalWrite(Led, HIGH);
    }
  else if (datoLED.stringData() == "OFF"){
    digitalWrite(Led, LOW);
    }
  }
  delay(3000);
}
