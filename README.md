# trabalhando-com-strings

objetivo:

APS – Parte II
Valor : 1,0 ponto
Grupo: até 03 pessoas
---------
  A partir do nome completo de cada integrante, o algoritmo deverá para cada um destes nomes
informar uma numeração, sendo que esta será resultado da seguinte fórmula:
numero_final = total de letras do nome + vogais distintas do nome + consoantes distintas do
nome + numero obtido através da iteração abaixo:
iteração hipotética:

int total = 0;
  for (int v = 0; v <=total de vogais distintas; v++){
    for( int c = 0; c <= v; c++){
    // Caso a primeira letra do nome seja vogal
    total += v * c;
    // Caso a primeira letra do nome seja consoante
    total += v + c;
    }
  }
A entrega deverá ocorrer até a próxima aula (27/04/2017), através do AVA, o resultado
deverá ser apresentado no início do algoritmo em forma de comentário:

  // Nome do primeiro Integrante = 482;
  // Nome do segundo Integrante = 310;
Obs: Podem ser utilizadas bibliotecas auxiliares, a exemplo <string.h>

#será publicado dia 27/04/2017 para que não haja plagio.
