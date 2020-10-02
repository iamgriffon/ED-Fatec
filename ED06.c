#include <stdio.h>
#include <stdlib.h>


/*  1-Reescreva o algoritmo de busca sequencial usando recursão */

int main(int argc, char *argv[]){
    int vet[] = {1,6,5,9,8,11,98,7,54};
    int n = sizeof(vet)/sizeof(int);
    int valor;
    printf("Informe o valor a ser buscado: ");
    scanf("%i", &valor);
    int pos = buscaSequencial(valor, n, vet);
    if (pos < 0) {
        printf("Nao encontrado");
    } else {
        printf("Pos = %i, Valor = %i", pos, vet[pos]);
    };
    return 0;
};


int buscaSequencial(int x, int n, int v[]){
    int j, p = -1;
    for (j = 0; j < n; j++){
        if (x == v[j]){
            p = j;
            break;
        }
    }
    return p;
}

/* 2-Crie um algoritmo de busca binaria, mas antes faça a ordenação do vetor utilizando alguma técnica apresentada na aula anterior*/

int buscaChar(char c, char n, char *v);

    int main(int argc, char *argv[]){
        char t[] = {'a', 'c', 'z', 'e', 'x', 'p', 'k'};
        int tamanho = sizeof(t)/sizeof(int);
        char x;
        printf("Informe o valor desejado");
        scanf("%c", &x);
        int pos = buscaChar(x, tamanho, t);
        if (pos<0){
            printf("Nao encontrado!");
        } else {
            printf("Pos = %i, Valor = %c \n", pos, t[pos]);
        }
        return 0;
    }

    int buscaChar(char c, int n, char *v){
        int mid, cmp, ini = 0;
        int end = n - 1;
        while (ini <= end){
            mid = (ini + end)/2;
            printf("Tentativa %i %i ate %i \n", mid, ini, end);
        if (c < v[mid]) cmp = -1;
        else if (c > v[mid]) cmp = 1;
        else cmp = 0;

        if (cmp < 0) end = mid - 1;
        else if (cmp > 0) ini = mid + 1;
        else return mid;
        };
        return -1;
    };


