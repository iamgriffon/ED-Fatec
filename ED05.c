#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/* 1-Faça um programa que leia 5 numeros inserindo-os em uma lista de forma ordenada utilizando a ideia do algoritmo de insert sort.
 No final, o programa deve mostrar todos os nomes ordenados alfabeticamente. */


void insertionSort(int *v, int tamanho){
    int i = 0, j = 1, aux = 0;

    while (j<tamanho){
        aux = v[j];
        i = j - 1;

        while((i >= 0) && (v[i] > aux)){
            v[i + 1] = v[i];
            i = i - 1;
        }
        v[i + 1] = aux;
        j = j + 1;
    }
}

int main(void){
    int t[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int tamanho = sizeof(t)/sizeof(int);
    insertionSort(&t, tamanho);
    int x = 0;
    for (x = 0; x < tamanho; x++){
        printf("%i \n", t[x]);
    }
    getch();
}

/* 2. Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo
algoritmo de Bubble sort. */

void bubbleSort(char *vector, int size){
    char aux;
    int i, j;
    for (j=size-1; j >=1; j++){
        for(i=0; i < j; i++){
            if(vector[i] > vector[i+1]){
                aux = vector[i];
                vector[i] = vector[i+1];
                vector[i+1] = aux;
                }
            }
        }
    };

/*  3- Faça um programa que leia 10 numeros e ordene-os pelo tamanho utilizando o algoritmo
da seleção. No final, o algoritmo deve mostrar todos os nomes ordenados. */ 

void selectionSort(int *v, int tamanho){
    int i, j, aux, min;
        for(i = 0; i < (tamanho -1 ); i++){
            min = i;
            for (j = (i+1); j < tamanho; j++){
                if(v[j] < v[min]) min = j;
            }
            if (v[i] != v[min]){
                aux = v[i];
                v[i] = v[min];
                v[min] = aux;
        }
    }
}

int main(void){
    int numeros[10];
    int tamanho = sizeof(numeros)/sizeof(int);
    selectionSort(&numeros, tamanho);
    int x = 0;
    for (x=0; x<tamanho; x++){
        printf("%i \n", numeros[x]);
    }
    getch();
}

/* 4-Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo
algoritmo quick-sort. */ 

void quickSort(int *a, int left, int right){
    int i, j, x, y;
    i = left;
    j = right;
    x = a[(left + right)/2];
    while( i <= j){
        while(a[i] < x && i < right){
            i++; 
        };
        while(a[j] > x && j > left) {
            j--;
        };
        if(i <= j){
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
    if (j > left){
        quickSort(a, left, j);
    }
    if (i < right){
        quickSort(a, i, right);
    }
}

int main(void){
    int numeros[10];
    int tamanho = sizeof(numeros)/sizeof(int);
    selectionSort(&numeros, tamanho);
    int x = 0;
    for (x=0; x<tamanho; x++){
        printf("%i \n", numeros[x]);
    }
    getch();
}
