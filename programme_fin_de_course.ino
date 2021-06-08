void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
}
 
void loop()
{
  int b2 = digitalRead(2);
  Serial.println(b2);
  }
