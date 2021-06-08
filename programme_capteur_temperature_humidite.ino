#include "DHT.h"     // Librairie des capteurs DHT
#define DHTPIN 5    // Changer le pin sur lequel est branché le DHT
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Test du composant DHT11 !");
 
  dht.begin();
}
void loop() {
  // Délai de 2 secondes entre chaque mesure. La lecture prend 250 millisecondes
  delay(500);
  // Lecture du taux d'humidité
  float h = dht.readHumidity();
  // Lecture de la température en Celcius
  float t = dht.readTemperature();
  // Pour lire la température en Fahrenheit
  float f = dht.readTemperature(true);
 
  // Stop le programme et renvoi un message d'erreur si le capteur ne renvoi aucune mesure
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Echec de lecture !");
    return;
  }
 
  Serial.print("Humidite: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
}
