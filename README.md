# IFSP-ler-do-serial

Repositório para armazenar uma biblioteca de arduino pra ler um número inteiro ou uma string do monitor serial

# Uso da biblioteca

para fazer o uso da biblioteca, basta colocar o arquivo ler_do_serial.h na mesma pasta do seu sketch do arduino, no começo do arquivo do sketch, inserir `#include "ler_do_serial.h"`, antes de utilizar as funções da biblioteca, basta inicializar o serial com o comando `Serial.begin(baud_rate);`(`baud_rate` é a frequência de comunicação serial, normalmente setada para `9600`) por fim basta utilizar a função desejada no ponto desejado do código, como a função `ler_inteiro_do_serial()`(que retorna o inteiro inserido no serial).


