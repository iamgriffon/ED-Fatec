#include <stdio.h>
#include <stdlib.h>

/* 1 – Construa um programa em C que utiliza uma matriz 10×3 que armazene as  temperaturas máxima e minima do dia,
 assim como a media de temperatura na ultima coluna.  Crie um menu de escolha que ofereça as seguintes informações:

1- temperatura minima de todos os dias.
2- temperatura máxima de todos os dias.
3- maior variação de temperatura de todos os dias.
4- Sair do programa.*/

int main(int argc, char *argv[])
{

	float temperatura[10][3];
	int dia, op, i, j;
	float maior, variacao[10][1];

	for (i = 0; i < 10; ++i)
	{

		printf("Insira a temperatura maxima do dia %i : ", i + 1);
		scanf("%f", &temperatura[i][0]);
		printf("Insira a temperatura minima do dia %i : ", i + 1);
		scanf("%f", &temperatura[i][1]);
		temperatura[i][2] = (temperatura[i][0] + temperatura[i][1]) / 2;
		variacao[i][0] = temperatura[i][0] - temperatura[i][1];

		if (i == 0)
		{
			maior = variacao[i][0];
		}

		if (variacao[i][0] > maior)
		{
			maior = variacao[i][0];
			dia = i;
		}
	}

	printf("\n");

	for (i = 0; i < 10; i++)
	{

		for (j = 0; j < 3; j++)
		{

			printf("%.1f ", temperatura[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	while (op != 4)
	{

		printf("\n1- Temperatura minima de todos os dias.\n2- Temperatura maxima de todos os dias.\n3- Maior variacao de temperatura de todos os dias.\n4- Sair do programa.\n\n");
		scanf("%i", &op);

		switch (op)
		{

		case 1:

			for (i = 0; i < 10; i++)
			{

				printf("Dia %i temperatura min : %.1f\n", i + 1, temperatura[i][1]);
			}
			break;

		case 2:

			for (i = 0; i < 10; i++)
			{

				printf("Dia %i temperatura max : %.1f\n", i + 1, temperatura[i][0]);
			}
			break;

		case 3:

			printf("Dia %i, variacao de : %.1f\n\n", dia + 1, maior);

			break;

		default:

			return 0;

			break;
		}
	}
}

#include <stdio.h>
#include <stdlib.h>

/* 2 – Armazene em uma matriz 10×5 o resultado de uma prova de alternativas:

a – coluna 0
b – coluna 1
c – coluna 2
d – coluna 3
e – coluna 4

Exemplo da resposta da primeira questão com a alternativa C:

prova[0][0]=0 ; prova[0][1]=0; prova[0][2]=1;prova[0][3]=0;prova[0][4]=0; */

int main(int argc, char *argv[]) {
	int prova[10][5], gabarito[10][5], i,j, nota = 0;
	char resp;
	
	 for (i=0; i<10; i++){
			
			for (j=0; j<5; j++){
				gabarito[i][j] = 2;
			}
			
		} 
		
	 gabarito[0][0] = 1; // a é a certa
	 gabarito[1][2] = 1; // c é a certa
	 gabarito[2][1] = 1; // b é a certa
	 gabarito[3][3] = 1; // d é a certa
	 gabarito[4][4] = 1; // e é a certa
	 gabarito[5][4] = 1; // e é a certa
	 gabarito[6][2] = 1; // c é a certa
	 gabarito[7][0] = 1; // a é a certa
	 gabarito[8][3] = 1; // d é a certa
	 gabarito[9][0] = 1; // a é a certa
	
	for (i=0; i<9; i++){
			
			for (j=0; j<5; j++){
				prova[i][j] = 0;
			}
			
		} 
		
	for (i=0; i<10; i++){
	
	printf("Exercicio %i : ", i+1);
	scanf("%s", &resp);
	
		switch (resp){
			
			case 'a' :
				prova[i][0] = 1;
				break;
				
			case 'b' :
				prova[i][1] = 1;
				break;
				
			case 'c' :
				prova[i][2] = 1;
				break;
				
			case 'd' :
				prova[i][3] = 1;
				break;
				
			case 'e' :
				prova[i][4] = 1;
				break;
				
			default : 
				printf ("Alternativa Invalida \n");
				break;
		}
	}
		
		for (i=0; i<10; i++){
			
			for (j=0; j<5; j++){
			
				if (prova[i][j] == gabarito[i][j]) {
					nota = nota + 1;		
				}
			}
		}
		
		printf ("\n A nota do aluno e : %i", nota);
		
		return 0;
}
	