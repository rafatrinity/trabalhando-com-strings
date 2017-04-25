#define A 2
#define B 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int totletras[A];
//contando as letras sem os espaços
int tot(char nome[A][B]){
	int esp[A], tam[A];
	for (int i = 0; i < A; i++)
	{
		esp[i]=0;
		tam[i]=strlen(nome[i]);
		for (int j = 0; j < tam[i]; j++)
		{
			if (nome[i][j]==' ')
			{
				esp[i]++;
			}
		}
		totletras[i]=(tam[i]-esp[i])-1;
	}
}

int main()
{
	char nome[A][B], consoante[A][B], tipo[A][1];
	int total[A], vogal[A][B], vog, con[A], i, j;
	for (i = 0; i < A; i++)
	{
		printf("\nInforme seu nome: ");
		fgets(nome[i],B,stdin);
		//getchar();
	}
	tot(nome);
	for (i = 0; i < A; i++)
	{
		int z=1;
		con[i]=0;
		j=0;
		vog=0;
		
		//zerando matriz
		for (int y = 0; y <= B; y++)
		{
			vogal[i][y]=0;
		}
		while(j<strlen(nome[i])){
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
				case ' ':
				break;
				default:
				consoante[i][con[i]]=nome[i][j];
				if (j==0)
				{
					tipo[i][0]='c';
				}
				con[i]++;
			}
			j++;
		}
		for (int d = 0; d < con[i]; d++)
		{
			for (int e = 0; e < con[i]; e++)
			{
				if (consoante[i][e]==consoante[i][d])
				{
					
				}
			}
		}
		for (int k = 0; k < B; k++)
		{
			vog+=vogal[i][k];
		}
		
		//testando
		printf("\ntotal de letras do %i° nome: %d\n",(i+1),totletras[i]);
		printf("total de vogais diferentes do %i° nome: %d\n",(i+1),vog);
		printf("\nconsoantes: %s\ntotal: %d\n",consoante[i],con[i]);
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
		printf("%d",total[i]);
	}
	return 0;
}
