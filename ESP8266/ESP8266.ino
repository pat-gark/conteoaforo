

//librerias modulo WiFi Access Point

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "FirebaseESP8266.h"
#include <Wire.h>

#define FIREBASE_HOST "https://aforolocal-15a56-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "dV8OIvL8A6qjEGlUA6RKTzt7uZeoL4NtpIFCYpIW"


int Contador = 0;
int p = 5;
int LEDV = 13; //D7
boolean inicio=true;

//Definir las credenciales de acceso

const char* ssid = "FIBRAMAX_SUBIA";
const char* password = "samantha2019";

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);
  pinMode(LEDV,OUTPUT);
  digitalWrite(LEDV,LOW);
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.print("Conectando");

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
    }   
  Serial.println();
  Serial.println("WiFi conectado");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  delay(5000);
}

void loop() {
  while (inicio){
    Firebase.setInt(firebaseData,"Capacidad/Contador",Contador);
    inicio=false;
    }
  Firebase.getInt(firebaseData,"Capacidad/Contador");
  Contador=firebaseData.intData();
  Serial.println(Contador);
  int valor=analogRead(A0);
  Serial.println(valor);
  if (valor >= 342 and valor <= 684){
    Contador = Contador;
    digitalWrite(LEDV,LOW);
    
    }
  if (valor>684 and Contador<p ){
    Contador++;
    digitalWrite(LEDV,HIGH);
    Firebase.setInt(firebaseData,"Capacidad/Contador",Contador); 
    }
  if (valor<342 and Contador>0){
    Contador--;
    digitalWrite(LEDV,HIGH);
    Firebase.setInt(firebaseData,"Capacidad/Contador",Contador);
    }  
  
  delay(1000);
 }
