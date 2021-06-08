                                                                         // importation des librairies nécéssaires
#include <DallasTemperature.h> 
#include <OneWire.h>              
 
                                                                         // déclaration de l'entrée auquel est relié le capteur de température
#define KY001_Signal_PIN 4
 
                                                                         // configuration des librairies pour notre utilisation
OneWire oneWire(KY001_Signal_PIN);          
DallasTemperature sensors(&oneWire);   
 
 
void setup() {
 
                                                                         // initialisation de la sortie
    Serial.begin(9600);
    Serial.println("KY-001 temperature measurement");
     
                                                                         // initialisation du capteur
    sensors.begin();  
}
 
                                                                         //boucle du programme principal
void loop()
{
                                                                         // la mesure de la température va commencer...
    sensors.requestTemperatures(); 
                                                                         // ... et la température mesurée va être affichée
    Serial.print("Temperature: ");
    Serial.print(sensors.getTempCByIndex(0));
    Serial.println(" degrés mesurés");
         
    delay(1000);                                                         // 1 seconde d'intervalle entre les mesures
}
