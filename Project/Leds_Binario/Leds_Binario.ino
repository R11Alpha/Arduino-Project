#include <math.h> //Biblioteca que se necesita para hacer funciones matematicas
int numero,  digito, cont;
double binario, ex, base;//Variables para poder hacer funciones con decimales
int leds[4];//Matriz de leds

int led1 = 3, led2 = 4, led3 = 5, led4 = 6; //Asignación de cada led a su respectiva salida

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT); //Introducimos el tipo de cada led en este caso como salida
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.println("Introduce un numero"); //Impresión en el monitor para introducir el número

}

void loop() {
  if (Serial.available() > 0 ) {

    do {

      numero = Serial.parseInt();//Convierte el número decimal a número entero
    } while (numero < 0); //Condición While
    base = 10;
    ex = 0;
    cont = 0;
    binario = 0;
    leds[3] = 0;
    leds[2] = 0;
    leds[1] = 0;
    leds[0] = 0;
    while (numero != 0 ) {
      digito = numero % 2;
      binario =  binario + digito * Exp(base, ex)  ;
      leds[cont] = digito;
      ex++;
      cont++;
      numero = numero / 2;
      digito = 0;
    }
    Serial.println(binario);
    digitalWrite(led4, leds[3]);
    digitalWrite(led3, leds[2]);
    digitalWrite(led2, leds[1]);
    digitalWrite(led1, leds[0]);

    delay(1000);
    Serial.println("Introduce un numero");
  }
}

double Exp ( double base, double exponente ) {
  double respuesta = 1;

  for (int i = 1; i <= exponente; i++) {
    respuesta = respuesta * base;

  }
  return respuesta;

}
