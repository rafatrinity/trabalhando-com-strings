#define A 2
#define B 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char nome[A][B], consoante[A][B], tipo[A][1];
	int total[A], vogal[A][B], vog, con[A], tam, i, j;
	for (i = 0; i < A; i++)
	{
		printf("\nInforme seu nome: ");
		fgets(nome[i],B,stdin);
		//getchar();
	}

	for (i = 0; i < A; i++)
	{
		int z=1;
		con[i]=0;
		j=0;
		vog=0;
		//total de letras e espaços do nome
		tam=strlen(nome[i]);
		//zerando matriz
		for (int y = 0; y <= B; y++)
		{
			vogal[i][y]=0;
		}
		while(j<tam){
			//contando espaços
			if (nome[i][j] == ' ')
			{
				z++;
			}
			//diferenciando vogais de consoantes e contando
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
				default:
				if (j==0)
				{
					tipo[i][0]='c';
				}
				consoante[i][con[i]]=nome[i][j];
				con[i]++;
			}
			j++;
		}

		for (int k = 0; k < B; k++)
		{
			vog+=vogal[i][k];
		}

		//retirando os espaços
		tam-=z;
		//testando
		printf("\ntotal de letras do %i° nome: %d\n",(i+1),tam);
		printf("total de vogais diferentes do %i° nome: %d\n",(i+1),vog);
		if (tipo[i][0]=='c')
		{
			printf("a 1ª letra do %i° nome e consoante\n",(i+1));
		}
		else{
			printf("a 1ª letra do %i° nome e vogal\n",(i+1));
		}
		
	}

	for (i = 0; i <=A; i++){
		total[i]=0;
		for(j = 0; j <=i; j++){
	    // Caso a primeira letra do nome seja vogal
			if(tipo[i][0]!='c')
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
	return 0;
}
