#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_ESTACIONAMETO 10

//Estacionamento

typedef struct _no {
    int placa;
    struct _no *prox;
} No;

typedef struct _fila {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

Fila *criarFila();
No *criaNo();

void retirarCarro(Fila *fila, int placa){

    No *aux = fila->inicio;

    int retiradas = 0;

    while(aux != NULL){

        if(aux->placa != placa){

            fila->inicio = fila->inicio->prox;
            fila->fim->prox = aux;
            fila->fim = aux;
            fila->fim->prox = NULL;
            aux = fila->inicio;

        }else{

            if(fila->fim == fila->inicio){
                printf("- Carro Placa %d removido com sucesso\n",aux->placa);
                printf("- Numero de carros deslocados: %d\n", retiradas);
                fila->inicio = NULL;
                fila->fim = NULL;
                fila->tamanho = 0;
                free(aux);
                break;

            }

            fila->inicio = fila->inicio->prox;
            fila->tamanho --;
            printf("- Carro Placa %d removido com sucesso\n",aux->placa);
            printf("- Numero de carros deslocados: %d\n", retiradas);
            free(aux);
            break;

        }

        retiradas ++;
    }

}

void estacionarCarro(Fila *fila, int placa){

    No *novo = criaNo(placa);

    if(fila->tamanho == TAMANHO_ESTACIONAMETO){
        printf("Estacionamento cheio, carro deve esperar:\n");


    }else{

        if(fila->inicio == NULL){
            fila->inicio = novo;
            fila->fim = novo;
            fila->fim->prox = NULL;
        }else{
            fila->fim->prox = novo;
            fila->fim = novo;
            fila->fim->prox = NULL;
        }

        fila->tamanho ++;

        printf("Carro Placa %d Estacionado com Sucesso.\n", placa);
    }

}

void exibirCarros(Fila *F) {

    No *aux = F->inicio;

    printf("[P] RUA B <- ");

    while (aux != NULL) {
        printf("%d <-", aux->placa);
        aux = aux->prox;
    }

    if(F->tamanho < TAMANHO_ESTACIONAMETO){
        int vagas = TAMANHO_ESTACIONAMETO - F->tamanho;
        for(int i = 0; i<vagas; i++){
            printf("VAGA <-");
        }
    }

    printf(" RUA A [C]\n");

}

int main(){

    char comando;
    int placa;

    Fila* fila = criarFila();

    //Populando
    estacionarCarro(fila, 1001);
    estacionarCarro(fila, 1002);
    estacionarCarro(fila, 1003);
    estacionarCarro(fila, 1004);
    estacionarCarro(fila, 1005);
    estacionarCarro(fila, 1006);

    do{

        int placa = NULL;

        printf("--------ESTACIONAMENTO Beco da Sardinha\n");
        printf("Numero de vagas ocupadas %d/%d\n",fila->tamanho, TAMANHO_ESTACIONAMETO);
        printf("C - Chegada\n");
        printf("P - Partida\n");
        printf("E - Exibir Carros\n");
        printf("S - Sair\n");
        printf("---------------------------------------\n");
        printf("Digite Comando:\n");

        scanf("%c",&comando);

        switch(comando){
            case 'P':
                printf("-- Retirar Carro.\n");
                printf("Digite a Placa: ");
                scanf("%d",&placa);
                retirarCarro(fila, placa);
                break;

            case 'C':
                printf("-- Estacionar Carro.\n");
                printf("Digite a Placa: ");
                scanf("%d",&placa);
                estacionarCarro(fila, placa);
                break;

            case 'E':
                printf("-- Exbir carros estacionados.\n");
                exibirCarros(fila);
                break;

            default:
                break;

        }

        system("pause");
        system("cls");

    }while(comando != 'S');

    return 0;
}

Fila *criarFila() {
    Fila *F  = (Fila *) calloc(1, sizeof(Fila));
    F->inicio = F->fim = NULL;
    F->tamanho = 0;
    return F;
}

No *criaNo(int val) {
    No *no   = (No*) calloc(1, sizeof(No));
    no->placa  = val;
    no->prox = NULL;
    return no;
}
