#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int valor;
    struct _no *prox;
}No;

typedef struct _pilha {
    No *topo;
}Pilha;

Pilha *criarPilha();
No *criaNo();

void inserirTopo(Pilha *pilha, int val){

    No *novo = criaNo(val);

    if(pilha->topo == NULL){
        pilha->topo = novo;
        pilha->topo->prox = NULL;
    }else{
        novo->prox = pilha->topo;
        pilha->topo = novo;
    }

}

void exibirPilha(Pilha *pilha){

    Pilha *pilhaAux = malloc(sizeof(Pilha));



}

void removerTopo(Pilha *pilha){

    if(pilha->topo != NULL){

        No *aux = pilha->topo;

        pilha->topo = pilha->topo->prox;
        printf("Elemento %d removido com sucesso\n", aux->valor);
        free(aux);

    }else{
        printf("Pilha Vazia\n");

    }
}

int main(){

    Pilha* pilha = criarPilha();

    int opcao = -1;

    do{

        printf("MENU---------------------\n");
        printf("1 - Inserir na Pilha\n");
        printf("2 - Remover Elemento\n");
        printf("3 - Exibir (Provisorio)\n");
        printf("4 - Sair\n");
        printf("-------------------------\n");
        printf("Digite Opçao: ");
        scanf("%d", &opcao);

        switch (opcao){
            int envio;
            case 1:
                printf("----Inserir Elemento\n");
                printf("Digite o valor: ");
                scanf("%d",&envio);
                inserirTopo(pilha, envio);
                break;
            case 2:
                printf("----Remover Elemento:\n");
                removerTopo(pilha);
                break;
            case 3:
                printf("----Exibir Pilha:\n");
                break;
            default:
                break;
        }

        system("pause");
        system("cls");

    }while(opcao != 4 );


    return 0;
}

Pilha *criarPilha() {
    Pilha *P  = (Pilha *) calloc(1, sizeof(Pilha));
    P->topo = NULL;
    return P;
}

No *criaNo(int val) {
    No *no   = (No*) calloc(1, sizeof(No));
    no->valor  = val;
    no->prox = NULL;
    return no;
}
