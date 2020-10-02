#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 1- Reescreva o programa do caixa eletronico utilizando ponteiro de funções.

// faça um algoritmo que simule o funcionamento de um caixa eletrônico, onde será apresentado uma lista de operações:

// 1-Saldo
// 2-Saque
// 3-Deposito

// Ao iniciar o programa determine um valor inicial para a variável saldo (utilize um ponteiro para manter o valor do saldo), 
// se o cliente escolher a opção 1 mostre o valor do saldo, caso escolha o valor 2 leia o valor a ser sacado e verifique se existe saldo suficiente,
// se o saldo for maior ou igual , deduza da variável saldo o valor solicitado, 
// caso não haja saldo suficiente mostre a mensagem “Saldo Insuficiente”, 
// caso a opção 3 seja escolhida adicione o valor informado de deposito ao saldo. 
// Implemente um laço faça enquanto que verifique se o usuário deseja continuar, 
// caso a variável coletada for igual 1 reinicie o laço, mantendo o valor do saldo.


void saque(float *sq2, float *sld2){
	float temp;

	temp = *sq2;
	*sld2=*sld2-temp;
	printf("\nSaque efetuado com sucesso\nPressione enter para prosseguir.\n\n");
	getch();
	system("cls");
}
void deposito(float *dp2, float *sld2){
		float temp;

	temp = *dp2;
	*sld2=*sld2+temp;
	printf("\nDepósito efetuado com sucesso\nPressione enter para prosseguir.\n\n");
	getch();
	system("cls");
}


int main(int argc, char *argv[]) { setlocale(LC_ALL, "Portuguese");
	int i=0, x=0, t=0;
	float sld=1000, sq, dp, *p;
	p=&sld;
	
	do{
		printf("\nEscolha uma opção:\n1-Saldo\n2-Saque\n3-Depósito.\n\n");
		scanf("%d", &i);
		system("cls");
		switch(i){
			case 1:
				printf("\nSeu saldo é: R$ %.2f\nPressione enter para prosseguir.\n\n", *p);
				getch();
				system("cls");
				break;
			case 2:
				printf("\nDigite o valor a ser sacado:\n");
				scanf("%f", &sq);
				system("cls");
				if (sq<=sld){
					saque(&sq, &*p);
				}else{
					printf("\nSaldo insuficiente.\nSeu saldo é: R$ %.2f\nPressione enter para prosseguir.\n\n", *p);
					getch();
					system("cls");
				}
				
				break;
			case 3:
				printf("\nDigite o valor do depósito:\n");
				scanf("%f", &dp);
				system("cls");
				deposito(&dp, &*p);
				break;
			default:
				printf("\nComando inválido, tente novamente.\nPressione enter para prosseguir.\n\n");
				getch();
				system("cls");
				break;
		}
		printf("\nAperte 1 para encerrar\n ou outro número para fazer outra operação.\n");
		scanf("%d", &x);
		system("cls");
		if(x==1) printf("Encerrando...");		
	
	}while(x!=1);
	return 0;
}

//2- Crie um vetor de 10 posições de um struct com os dados de um aluno{ra, nome, idade} 
//atraves de um ponteiro passe o parametro por referencia para a função adicionar que ira adicionar um novo struct dentro do vetor;

int main(int argc, char *argv[]) {
	
	int *pv;// vetor/ponteiro
	int qte;// quantidade
	int i;// contador
	float md=0; //media
	
//3- Crie um programa em C que adicione dinamicamente uma nova posição e um vetor que armazene a qtd de clientes por dia, 
// ao final do programa calcule a media destes clientes, mostre a quantidade de dias e limpe a memoria.

	printf("Quantos dias serao considerados para o calculo?\n");
	scanf("%d", &qte);
	pv=(int *)(malloc(qte*sizeof(int)));
	
	if(pv==NULL){
		printf("Erro!");
		system("pause");
		exit(1);
	}else{
		for(i=0;i<qte;i++){
			printf("Digite a clientela do dia %d:", i+1);
			scanf("%d", &pv[i]);
			md=md+pv[i];
		}
		md=md/i;
		printf("\nMedia:%.2f\n Dias:%d", md, i);
	}
	free(pv);	
		


