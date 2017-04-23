#define A 2
#define B 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char nome[A][B];
	int total[A], vogal[A][B], vog, tam, i, j;
	for (i = 0; i < A; i++)
	{
		printf("\nInforme seu nome: ");
		fgets(nome[i],B,stdin);
		//getchar();
	}

	for (i = 0; i < A; i++)
	{
		int z=1;
		j=0;
		vog=0;
		//total de letras e espaços do nome
		tam=strlen(nome[i]);
		for (int y = 0; y <= B; y++)
		{
			vogal[i][y]=0;
		}
		while(j<tam){
			if (nome[i][j] == ' ')
			{
				z++;
			}
			switch(nome[i][j]){
				case 'a':
				vogal[i][0]=1;
				break;
				case 'e':
				vogal[i][1]=1;
				break;
				case 'i':
				vogal[i][2]=1;
				break;
				case 'o':
				vogal[i][3]=1;
				break;
				case 'u':
				vogal[i][4]=1;
				break;
			}
			j++;
		}
		for (int k = 0; k < B; k++)
		{
			vog+=vogal[i][k];
		}

		//retirando os espaços
		tam-=z;
		printf("\ntotal de letras do %i° nome: %d\n",(i+1),tam);
		printf("total de vogais diferentes do %i° nome: %d\n",(i+1),vog);
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
