int sensorPin = A0;                                          //on definit la constante et nos variables
int sensorValue = 0;
int sensorValue2 = 0;

void setup() {
    Serial.begin(9600);                                      //on definit la transmission afin de lire les données à 9600 bits/seconde
}
void loop() {
    sensorValue = analogRead(sensorPin);                     //on definit la variable sur le pin A0
    sensorValue2 = map(sensorValue,0,1024,0,100);            //on convertit notre analogique qui va de 0 à 1024 en pourcentage c'est-à-dire de 0 à 100
    Serial.print("Humidité = " );                            //on écrit la donnée qui est mesurée
    Serial.print(sensorValue2);                              //on affiche la mesure en pourcentage de l'humidité
    Serial.print(" ");                                       
    Serial.println("%");                                     //on écrit l'unité de la donnée mesurée
    delay(1000);                                             //on relance la mesure chaque seconde

    if(sensorValue2 == 0){                                   //si l'humidité est de 0, cela signifie qu'il n'y a plus de sirop et donc on avertis l'utilisateur de ce manque
      Serial.println("On avertit l'utilisateur!");
      delay(1500);
    }
}
