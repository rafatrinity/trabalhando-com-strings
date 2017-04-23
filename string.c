#define A 2
#define B 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char nome[A][B];
	int total[A], tam, i, j;
	for (i = 0; i < A; i++)
	{
		printf("\nInforme seu nome: ");
		fgets(nome[i],B,stdin);
		//getchar();
	}
	for (i = 0; i < A; i++)
	{
		tam=-1;
		j=0;
		while(nome[i][j] != '\0')
		{
			if (nome[i][j] != ' ')
			{
				tam++;
				printf("%c",nome[i][j]);
			}
			j++;
		}
		printf("%d\n",tam);
	}
/*
	for (i = 0; i <=A; i++){
		total[i]=0;
		for(j = 0; j <=i; j++){
	    // Caso a primeira letra do nome seja vogal
			if ((nome[i][1]=='a')||(nome[i][1]=='e')||(nome[i][1]=='i')||(nome[i][1]=='o')||(nome[i][1]=='u'))
			{
				total[i] += i * j;
			}
	    // Caso a primeira letra do nome seja consoante
			else{
				total[i] += i + j;
			}
		}
		printf("%d\n",total[i]);
	}
*/
	return 0;
} 