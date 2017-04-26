#define A 2
#define B 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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
	setlocale(LC_ALL,"portuguesse");
	char nome[A][B], consoante[A][B], tipo[A][1];
	int total, vogal[A][B], vog, con[A],igual[A],diferente[A], vd[A], i, j;
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
		igual[i]=0;
		diferente[i]=0;
		
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

		int t=0;
		for (int d = 0; d < con[i]; d++)
		{
			for (int e = 0; e < con[i]; e++)
			{
				if (consoante[i][e]==consoante[i][d])
				{
					igual[i]++;
				}
				t++;
			}
		}
		diferente[i]=(igual[i]-con[i]);
		diferente[i]/=2;
		vd[i]=con[i]-diferente[i];
		vd[i]-=1;

		for (int k = 0; k < B; k++)
		{
			vog+=vogal[i][k];
		}
		
		//testando
		printf("\ntotal de letras do %i° nome: %d\n",(i+1),totletras[i]);
		printf("total de vogais diferentes do %i° nome: %d\n",(i+1),vog);
		printf("consoantes: %sconsoantes diferentes: %d\n",consoante[i],vd[i]);
		if (tipo[i][0]=='c')
		{
			printf("a 1ª letra do %i° nome é consoante\n",(i+1));
		}
		else{
			printf("a 1ª letra do %i° nome é vogal\n",(i+1));
		}
		for (int v = 0; v <=vog; v++){
			total=0;
			for(j = 0; j <=v; j++){
	    		// Caso a primeira letra do nome seja vogal
				if(tipo[i][0]!='c')
				{
					total += v * j;
				}
	    		// Caso a primeira letra do nome seja consoante
				else{
					total += v + j;
				}
			}
		}
		printf("resultado da operação: %d\n",total);
		printf("resultado final: %d\n",(totletras[i]+vog+vd[i]));
	}
	return 0;
}
