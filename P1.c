#include <stdio.h>
#include <stdlib.h>

//Questão 1

int verificar(int *p, int n, int *v, int i) {   
    if (i == n) return -1;
    else if (*p == v[i]) return i;
    else verificar(p, n, v, ++i);
}


void adicionar(int *p, int *v, int size) {
    int *aux = (int) malloc(sizeof(int));

    printf("\nDigite o numero que deseja inserir na posição %d: ", *p);
     scanf("%d", aux);
    int check = verificar(aux, size, v, 0);

    if (check == -1) {
        v[*p] = *aux;
        printf("\n Sucesso ao inserir numero \n");
        (*p)++;
    } else {
        printf("\n Erro, esse numero ja existe na posicao %d.", check);
    }
}

int main() {
    int *v = (int) malloc(20 * sizeof(int));
    int i;
    int p = 0;

    while(p != 20)
        adicionar(&p, v, 20);
        
        for(i = 0; i<20; i++){
            printf("\n%i, ", *v);
            *(v)++;
        }
        
    return 0;
}

//Questão 4

#include <stdio.h>
#include <stdlib.h>

char ordenar(int *vetor, int inicio, int tamanho_vetor)
{
    int i, j;
    int aux = 0, pivo = 0;

    i = inicio;
    j = tamanho_vetor - 1;
    pivo = vetor[(i + j) / 2];

    while (i <= j)
    {
        while (vetor[i] < pivo) i++;
        
        while (vetor[j] > pivo) j--;
  
        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }   
    }

    if (j > inicio)
        ordenar(vetor, inicio, j + 1);

    if (i < tamanho_vetor)
        ordenar(vetor, i, tamanho_vetor);
}

int main()
{
    int numero;
    int *vetor = (int*) malloc(sizeof(int));
    int i = 0, count = 2;

    do {
        printf("Digite um número: ");
         scanf("%d", &numero);

         if (numero != 0)
         {
             vetor[i] = numero;
             vetor = (int*) realloc(vetor, count * sizeof(int));
             count++;
             i++;
         }

    } while (numero != 0);


    printf("\n Valores com ordem : \n[ ");

    ordenar(vetor, 0, count - 2);

    for(int j = 0; j < i; j++)
        printf("%d, ", vetor[j]);

    printf("]\n ");

    return 0;
}
