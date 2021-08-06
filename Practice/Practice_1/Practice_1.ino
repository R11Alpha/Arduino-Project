int led = 4; //Número de salida de un led

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); //Definir la salida del led
}

void loop() {
  digitalWrite(led, HIGH);
}
