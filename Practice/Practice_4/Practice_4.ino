int valor = 0, led = 3, intensidad = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  valor = analogRead(A0);
  intensidad = map(valor,0,1024,0,255);
  analogWrite(led,intensidad);
}
