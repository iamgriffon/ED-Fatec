//EXEMPLO 1

#include <stdlib.h>

int main(int argc, char *argv[])
{
    int valor = 10;
    int *ptr;

    ptr = &valor;

    printf("End. valor: %x \n", &valor);
    printf("End. ponteiro: %x \n", ptr);
    printf("conteudo da variavel valor: %d \n", valor);
    printf("conteudo do ponteiro: %d \n", *ptr);

    *ptr = 45;

    printf("conteudo da variavel valor: %d \n", valor);
    printf("conteudo do ponteiro: %d \n", *ptr);
    //Resultado: ambos viram 45;

    //  x = &y
    //  *x = y
    //  no printf(): %x -> &y
    //  no printf(): %i -> y

    //%x = endereço de memória;
    //%d = integer;
    //%f = float;

    return 0;
}

//EXEMPLO 2

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    float teste = 20;
    float *ptr1;
    float **ptr2;

    ptr2 = &ptr1;
    ptr1 = &teste;
    printf("Endereco do teste: %x \n", &teste);
    printf("Endereco do ptr1: %x \n", &ptr1);
    printf("Endereco do ptr2: %x \n", &ptr2);

    printf("Conteudo do ptr1: %f \n", *ptr1);
    printf("Conteudo do ptr2: %f \n", **ptr2);

    //Resultado:
    // End. teste = 8bc7979c;
    // End. ptr1 = 8bc797a0;
    // End. teste = 8bc79a8;
    //Conteudo ptr1 = 20.00000;
    //Conteudo ptr2 = 20.00000;

    return 0;
}

//EXEMPLO 3

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 20;
    int *pA, *pB;

    pA = &a;
    pB = &b;
    printf("End pA=%x, valor pA=%i \n", pA, *pA);
    printf("End pB=%x, valor pB=%i \n", pB, *pB);
    //Resultado:
    //  End pA=ed6c4b88, valor pA=10
    //  End pB=ed6c4b8c, valor pB=20

    *pA = *pB;
    printf("End pA=%x, valor pA=%i \n", pA, *pA);
    printf("End pB=%x, valor pB=%i \n", pB, *pB);
    //Resultado
    //  End pA=ed6c4b88, valor pA=20
    //  End pB=ed6c4b8c, valor pB=20

    *(pA)++;

    printf("End pA=%x, valor pA=%i \n", pA, *pA);
    printf("End pB=%x, valor pB=%i \n", pB, *pB);
    //Resultado
    // End pA=ed6c4b8c, valor pA=20
    // End pB=ed6c4b8c, valor pB=20

    *pA = *pA + 1;

    printf("End pA=%x, valor pA=%i \n", pA, *pA);
    printf("End pB=%x, valor pB=%i \n", pB, *pB);
    //Resultado
    // End pA=ed6c4b8c, valor pA=21
    // End pB=ed6c4b8c, valor pB=21

    pA = pB;
    a = 50;

    printf("End a=%x, valor a=%i \n", &a, a);
    printf("End pA=%x, valor a=%i \n", pA, *pA);
    printf("End pB=%x, valor b=%i \n", pB, *pB);
    printf("End b=%x, valor b=%i \n", &b, b);
    //Resultado:
    // End a=ed6c4b88, valor a=50
    // End pA=ed6c4b8c, valor pA=21
    // End pB=ed6c4b8c, valor pB=21
    // End b=ed6c4b8c, valor b=21

    if (pA == pB)
    {
        printf("Eles apontam para o mesmo lugar :)");
    };
    //Resultado: true;

    return 0;
}

//EXEMPLO 4

#include <stdlib.h>
#include <stdio.h>

void soma10(int x)
{
    x = x + 10;
    printf("O valor de x apos a soma: %i \n", x);
    return;
}

void soma10p(int *x)
{
    *x = *x + 10;
    printf("O valor do ponteiro de x apos a soma: %i \n", *x);
    return;
}

int main(int argc, char *argv[])
{

    int x = 34;

    printf("Numero = %i \n", x);
    soma10(x);
    //Resultado:
    //  Numero = 34
    //  O valor de x apos a soma: 44

    printf("Numero = %i \n", x);
    soma10p(&x);
    //Resultado:
    //  Numero = 44
    //  O valor de x apos a soma: 44

    printf("Numero = %i \n", x);
    soma10p(&x);
    //Resultado:
    //  O valor do ponteiro de x apos a soma: 44
    //  Numero = 44

    printf("Numero = %i \n", x);
    //Resultado:
    //Numero = 54

    return 0;
}

// EXEMPLO 5

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int v[] = {3, 2, 5, 7, 10, 5};
    int *p;
    p = v;
    printf("Pos=%x, Valor=%i \n", p, *p);
    printf("Pos=%x, Valor=%i \n", (p + 1), *(p + 1));
    printf("Pos=%x, Valor=%i \n", (p + 3), *(p + 3));
    printf("Pos=%x, Valor=%i \n", &p[4], p[4]);

    //Resultado:
    // Pos=ccafc6e0, Valor=3
    // Pos=ccafc6e4, Valor=2
    // Pos=ccafc6ec, Valor=7
    // Pos=ccafc6f0, Valor=10

    return 0;
}

//EXEMPLO 6

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *p[4], x;
    int vA[] = {2, 5, 7, 8, 9};
    int vB[] = {9, 3, 2};
    int vC[] = {7, 8, 9, 1};
    int vD[] = {3, 5, 7};

    p[0] = vA;
    p[1] = vB;
    p[2] = vC;
    p[3] = vD;

    for (x = 0; x < 4; x++)
    {
        printf("Endereco=%x, Valor=%i \n", p[x], *p[x]);
    }
    
    //Resultados:
    // Endereco=93b67f00, Valor=2
    // Endereco=93b67ed8, Valor=9
    // Endereco=93b67ef0, Valor=7
    // Endereco=93b67ee4, Valor=3

    return 0;
}