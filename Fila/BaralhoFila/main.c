#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int val; // poderia ser de outro tipo: Alunos, Livros, float, char*, ...
    struct _no *prox; // ponteiro para o próximo elemento da fila
} No;

typedef struct _fila {
    No *inicio;
    No *fim;
} Fila;

Fila *CriaFila();

void DestroiFila(Fila **T);

No *CriaNo(int val);

void Enfileira(Fila *L, int val);

void ImprimeFila(Fila *L);

int FilaEstaVazia(Fila *F);

int Desenfileira(Fila *F);

void darCartas(Fila *fila){

    int darCarta = 1;

    No *aux = fila->inicio;
    No *ant = aux;

    printf("Cartas jogadas: ");

    while(aux != NULL){

        if(darCarta == 1){

            //Condição unica para Baralho de uma carta.
            if(fila->inicio == fila->fim){
                printf("\nCarta restante: %d\n", aux->val);
                break;
            }

            if(aux->prox == fila->fim){
                printf("%d", aux->val);
            }else{
                printf("%d, ", aux->val);
            }

            darCarta = 0;

            ant = aux;
            aux = aux->prox;

        }else{

            if(aux == fila->fim){
                printf("\nCarta restante: %d\n", aux->val);
                //printf("%d", aux->val);
            }

            ant->prox = aux->prox;
            fila->fim->prox = aux;
            fila->fim = aux;
            fila->fim->prox = NULL;

            aux = ant->prox;

            darCarta = 1;

        }

    }

}

int main() {

    int n, i/*,m*/;
    Fila* fila;
	scanf("%d", &n);

	while (n != 0) {

		fila = CriaFila();

        //Cria Baralho
		for (i = 1; i <= n; i++){
			Enfileira(fila, i);
            //printf("Cartas jogadas:");
		}

		darCartas(fila);

		//ImprimeFila(fila);

    //puts("");
    //printf("Carta restante: %d\n", m);
    DestroiFila(&fila);
    scanf("%d", &n);

    }

    return 0;

}

Fila *CriaFila() {
    Fila *F  = (Fila *) calloc(1, sizeof(Fila));
    F->inicio = F->fim = NULL;
    return F;
}

void DestroiFila(Fila **T) {
    Fila *F = *T;
    No *p = NULL, *q = NULL;
    // apaga todos os nós da fila
    p = F->inicio;
    while (p != NULL) {
        q = p;
        p = p->prox;
        free(q);
    }
    // apaga/desaloca a fila
    free(F);
    *T = NULL;
}

No *CriaNo(int val) {
    No *no   = (No*) calloc(1, sizeof(No));
    no->val  = val;
    no->prox = NULL;
    return no;
}

void Enfileira(Fila *fila, int val) {

    No *novo = CriaNo(val);

    if(fila->inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;
        fila->fim->prox = NULL;
    }else{
        fila->fim->prox = novo;
        fila->fim = novo;
        fila->fim->prox = NULL;
    }

}

void ImprimeFila(Fila *F) {

    No *p = F->inicio;

    while (p != NULL) {
        if(p == F->fim){
            printf("%d", p->val);

        }else{
            printf("%d, ", p->val);

        }

        p = p->prox;
    }

}

int FilaEstaVazia(Fila *F) {
    return (F->inicio == NULL);
}

/*
int Desenfileira(Fila *F){
int a;
 conteudo de Desenfileira

   return (a);
}
*/
