#include <stdio.h>
#include <stdlib.h>

struct Item {
    int num;
    struct Item *prox;
};
typedef struct Item item;

item *aloca();
void insere(item *FILA);
item *retira (item *FILA);
void exibe(item *FILA);
void libera(item *FILA);

int tam;

int main(int argc, char *argv[]){
    //Iniciando fila
    item *FILA = (item *) malloc(sizeof(item));
    FILA ->prox = NULL;
    tam = 0;

    insere(FILA);
    insere(FILA);
    insere(FILA);
    exibe(FILA);
    retira(FILA); //FIFO = FIRST IN FIRST OUT
    libera(FILA);
    return 0;
}

int vazia(item *FILA){
    //Existe o end do prox item?
    if (FILA ->prox == NULL){
        return 1;
    } else {
        return 0;
    }
}

int *aloca(){
    item *novo = (item *) malloc(sizeof(item));
    if(!novo){
        printf("Sem memoria disponivel \n");
        exit(1);
    } else {
        printf("Novo elemento: ");
        scanf("%d", &novo->num);
    }
    return novo;
}

void insere(item* FILA){
    //Cria um ponteiro do novo item alocado na memória
    item *novo=aloca();
    novo -> prox = NULL;

    //Testa pra ver se a fila está vazia
    if(vazia(FILA)){
        FILA->prox = novo;
        //Se está, insere como um novo
    } else {
        item *tmp = FILA->prox;
        while(tmp -> prox != NULL){
            tmp = tmp -> prox;
           //Se não estiver, varre o array todo até que ele vire o último
           //Isso é, quando o próximo for "NULL" 
        }
        tmp -> prox = novo;
        //Torna o valor novo inserido como o últino.
    }
    tam++;
}

void exibe(item *FILA){
    if(vazia(FILA)){
        printf("FILA VAZIA! \n");
    } else {
        item *tmp;
        tmp = FILA->prox;
        printf("Fila: \n");
        while(tmp != NULL){
            printf("%i \n", tmp->num);
            tmp = tmp -> prox;
        }
    }
}

item *retira(item *FILA){
    if(FILA -> prox == NULL){
        printf("FILA JÁ ESTÁ VAZIA \n");
        return NULL;
    } else {
        item *tmp = FILA -> prox;
        FILA -> prox = tmp -> prox;
        tam--;
        return tmp;
    }
}

void exibe(item *FILA{
    if(vazia(FILA)){
        printf("FILA VAZIA! \n");
    } else {
        item *tmp;
        tmp = FILA -> prox;
        printf("FILA: \n");
        while(tmp != NULL){
            printf("%i \n", tmp -> num);
            tmp = tmp -> prox;
        }
    }
}

void libera(item *FILA){
    if(!vazia(FILA)){
        item* proxNode, *atual;
        atual = FILA -> prox;
        while(atual != NULL){
            free(atual);
            atual = proxNode;
        }
    } 
}