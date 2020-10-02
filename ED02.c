// 1 - Qual o valor de y no final do programa ?

#include <stdio.h>
    int main()
{
    int y, *p, x;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    ++(*p);
    x--;
    (*p) += x++;
    printf("y = % d\n", y);
    return 0;
};

    // R : y = 4;

    // ····················································································································································

// 2-Teste e explique a diferença, caso exista, entre

// a) p++;
// (*p)++;
// *(++p);
// b) O que quer dizer *(p+10)?

//  p++ : Pós-Incrementador do endereço de memória apontado por p.
//  (*p)++ : Pós-Incrementador do valor da variável apontada por p.
//  *(++p) : Pré-Incrementador do endereço de memória apontado por p.

// b) Utilizar o conteúdo da memória apontada por p, 10 posições adiante.

// ····················································································································································

// 3-Quais serão os valores de x, y e p ao final do trecho de código
// abaixo?

int main(int argc, char *argv[]){

int x, y, *p;
y = 0;
p = &y;
x = *p;
x = 4;
(*p)++;
--x;
(*p) += x;

}


// R : x = 3, y = 4, p = endereço de onde está armazenado y, *p = 4;

// ····················································································································································

// 4-Os programas (trechos de código) abaixo possuem erros. Qual(is)?
// Como deveriam ser?

// a)
void main()
{
    int x, *p;
    x = 100;
    p = x;
    printf("Valor de p: % d.\n", *p);
}

// R : Na linha 4, p = x, faltou o & para dizer que p aponta para o endereço de x.

// b)
void troca(int *i, int *j)
{
    int *temp;
    *temp = *i;
    *i = *j;
    *j = *temp;
}

// R : Na linha 2, temp é um ponteiro. Poderiamos utilizar temp apenas como variavel auxiliar do tipo int e
// não como ponteiro.

// c)
int main(){
    char *a, *b;
    a = "abacate";
    b = "uva";
    if (a < b) {
        printf("% s vem antes de % s no dicionário", a, b);
    } 
    else {
        printf("% s vem depois de % s no dicionário", a, b);
    } 
};

// R : Na condição do if, estamos comparando o endereço das strings, e não as strings em si.
// Para comparar as strings devemos utilizar o *, então o bloco ficaria if(*a < *b).

// ····················································································································································

// 5- Suponha que os elementos do vetor v são do tipo int e cada int
// ocupa 8 bytesno seu computador. Se o endereço de v[0] é 55000, qual o
// valor daexpressão v + 3?

// R : 55000 + (8*3) = 55024.

// ····················································································································································

// 6 - Escreva uma função mm que receba um vetor inteiro v[0..n - 1] e os
//         endereços de duas variáveis inteiras,
//     digamos min e max, e deposite nessas variáveis o valor de um elemento mínimo e o valor de um elemento máximo do vetor.Escreva também uma função main que use a função mm.

#include <stdio.h>
#include <malloc.h>

void mm(int *vetor, int *min, int *max, int tamanho_vetor){
    for (int i = 0; i < tamanho_vetor; i++)
    {
        if (i == 0)
        {
            *max = vetor[0];
            *min = vetor[0];
        }
        if (vetor[i] > *max)
            *max = vetor[i];
        if (vetor[i] < *min)
            *min = vetor[i];
    }
}

int main()
{
    int minimo = 0, maximo = 0, tamanho = 0;

    printf("Digite o numero de elementos do vetor :  ");
    scanf(" %d", &tamanho);

    int *vet = (int *)malloc(tamanho * (sizeof(int)));

    for (int j = 0; j < tamanho; j++)
        printf("%d ", vet[j]);

    printf("\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("\nDigite um valor para vet[%d] :  ", i);
        scanf(" %d", &vet[i]);
    }

    mm(vet, &minimo, &maximo, tamanho);
    printf("\nMinimo = %d\nMáximo = %d\n", minimo, maximo);

    return 0;
}

// ····················································································································································

// 7- Suponha que v é um vetor. Descreva a diferença conceitual entre
// as expressões v[3] e v + 3.

// v[3] : estamos acessando o valor que está na posição de número 3 no vetor v.
// v + 3 : estamos pulando 3 posições de memória a partir do primeiro elemento do vetor v, sabendo que cada incremento pulará o número de bytes
// referente ao tipo primitivo daquele vetor.

// ····················································································································································

// 8 - Escreva uma função chamada troca que troca os valores dos
//         parâmetros recebidos.Sua assinatura deve ser : void
//                                                        troca(float *a, float *b);

void troca(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}
