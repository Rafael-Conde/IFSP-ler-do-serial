#include "ler_do_serial.h"
//long value {};

String entrada;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(500);
  //value = ler_inteiro_do_serial();
  entrada = ler_generico_do_serial();
  /*
  if (value == NO_INPUT)
  {
    Serial.println("No input");
  }
  else
  {
    Serial.print("Value: ");
    Serial.println(value);
  }*/

  if(entrada != "")
  {
    Serial.print("Entrada : ");
    Serial.println(entrada);
  }
  
}
