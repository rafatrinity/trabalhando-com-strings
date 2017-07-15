#define A 2
#define B 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h>
#include "sis.h"

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
				esp[i]++;
		}
		totletras[i]=(tam[i]-esp[i])-1;
	}
}


int main()
{
	setlocale(LC_ALL,"portuguesse");
	char nome[A][B], consoante[A][B], tipo[A][1], SISTEMA, refazer;
	int total, vogal[A][B], vog, con[A],igual[A],diferente[A], vd[A], i, j;
	apresenta();
	cab();
	getchar();
	inicio:
	for (i = 0; i < A; i++)
	{
		printf("\nInforme o %dº nome: ",(i+1));
		fgets(nome[i],B,stdin);
		//convertendo para minusculas
		for (j = 0; j < B; j++)
			nome[i][j]=tolower(nome[i][j]);
			//o Linux não da suporte para função strlwr();
		cab();
	}
	cab();	
	tot(nome);
	for (i = 0; i < A; i++)
	{
		int z=1;
		con[i]=0;
		j=0;
		vog=0;
		igual[i]=0;
		diferente[i]=0;
		
		//zerando matriz
		for (int y = 0; y <= B; y++)
			vogal[i][y]=0;
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
					tipo[i][0]='c';
				con[i]++;
			}
			j++;
		}

		int t=0;
		for (int d = 0; d < con[i]; d++)
		{
			for (int e = 0; e < con[i]; e++)
			{
				if (consoante[i][e]==consoante[i][d])
					igual[i]++;
				t++;
			}
		}
		diferente[i]=(igual[i]-con[i]);
		diferente[i]/=2;
		vd[i]=con[i]-diferente[i];
		vd[i]-=1;

		for (int k = 0; k < B; k++)
			vog+=vogal[i][k];
		//testando
		nome[i][0]=toupper(nome[i][0]);
		for (int h = 0; h < strlen(nome[i]); h++)
		{
			if (nome[i][h]==' ')
				nome[i][h+1]=toupper(nome[i][h+1]);
		}

		usleep(200000);
		printf("NOME: %s",nome[i]);
		usleep(200000);
		printf("\nTOTAL DE LETRAS DO %i° NOME: %d\n",(i+1),totletras[i]);
		usleep(200000);
		printf("\nTOTAL DE VOGAIS DIFERENTES DO %i° NOME: %d\n",(i+1),vog);
		usleep(200000);
		printf("\nCONSOANTES: %s \nCONSOANTES DIFERENTES: %d\n",consoante[i],vd[i]);
		if (tipo[i][0]=='c')
			printf("\nA 1ª LETRA DO %i° NOME É CONSOANTE\n",(i+1));
		else
			printf("\nA 1ª LETRA DO %i° NOME É VOGAL\n",(i+1));
		usleep(200000);

		for (int v = 0; v <=vog; v++){
			total=0;
			for(j = 0; j <=v; j++){
	    		// Caso a primeira letra do nome seja vogal
				if(tipo[i][0]!='c')
					total += v * j;
	    		// Caso a primeira letra do nome seja consoante
				else
					total += v + j;
			}
		}
		usleep(200000);
		printf("\nRESULTADO DA OPERAÇÃO: %d\n",total);
		usleep(200000);
		printf("\nRESULTADO FINAL: %d\n",(totletras[i]+vog+vd[i]+total));
		linha();
	}
	getchar();
	printf("\tDESEJA REFAZER O TESTE COM MAIS 2 NOMES?\nS=SIM\nQUALQUER OUTRA=NÃO");
	scanf("%c",&refazer);
	refazer=toupper(refazer);
	if (refazer=='S')
		goto inicio;
	fim();
	return 0;
}
