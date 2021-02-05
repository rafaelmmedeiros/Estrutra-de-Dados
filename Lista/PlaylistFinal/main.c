#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _musica {
    char titulo[128];
    struct _musica *prox;
    struct _musica *ant;
} Musica;

typedef struct _playlist {
    Musica *inicio;
    Musica *fim;
    Musica *cursor;
} Playlist;

Musica *CriaMusica(const char *titulo);
void DestroiMusica(Musica **m);

Playlist *CriaPlaylist();

int PlaylistEstaVazia(Playlist *P);
void DestroiPlaylist(Playlist **P);

void InsereMusica(Playlist *P, const char *titulo){

    Musica *m = CriaMusica(titulo);

    if(P->inicio == NULL){
        P->inicio = m;
        P->fim = m;
        P->cursor = P->inicio;
        P->fim->prox = P->inicio;
        P->inicio->ant = P->fim;

    }else if(P->inicio == P->fim){
        m->ant = P->cursor;
        P->cursor->prox = m;
        P->fim = m;
        P->fim->prox = P->inicio;
        P->inicio->ant = P->fim;

    }else{
        m->prox = P->cursor->prox;
        P->cursor->prox->ant = m;
        P->cursor->prox = m;
        m->ant = P->cursor;
    }

}

void RemoveMusica(Playlist *P, const char *titulo){

    Musica *aux = P->inicio;

    if(P->inicio == NULL){
        //Nada
    }else{
        do{
            if(strcmp(aux->titulo,titulo) == 0){
            //printf("REMOVER\n");
                if(aux == P->inicio){
                    if(P->inicio->prox == P->inicio){
                        free(aux);
                        P->inicio = NULL;
                        P->cursor = P->inicio;
                        break;
                    }
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    P->inicio = aux->prox;
                    if(aux == P->cursor){
                        P->cursor = P->inicio;
                    }
                    free(aux);
                    break;

                }else if(aux == P->cursor){
                    //printf("CURSOS");
                    if(aux == P->fim){
                        P->fim = aux->ant;
                    }
                    P->cursor = aux->ant;
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux);
                    break;

                }else{
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux);
                    break;
            }

        }

        aux = aux->prox;

        }while(aux != P->inicio);

    }

}

void toca(Playlist *P){

    if(P->inicio == NULL){
        printf("\n");
    }else{
        printf("%s\n", P->cursor->titulo);
        P->cursor = P->cursor->prox;
    }
}

void volta(Playlist *P){

    if(P->inicio == NULL){
        //NADA ACONTECE
    }else{
        P->cursor = P->cursor->ant;
    }

}

void final(Playlist *P){

    Musica *aux = P->cursor;

    if(P->inicio == NULL){
        printf("\n");
    }else{
        do{
            printf("%s\n",aux->titulo);
            aux = aux->prox;
        }while(aux != P->cursor);

        P->cursor = P->cursor->ant;

    }


    /*
    if(P->inicio == NULL){
        printf("\n");
    }else{
        do{
            printf("%s\n",P->cursor->titulo);
            P->cursor = P->cursor->prox;
        }while(P->cursor != P->inicio);
    }
    */

    //TRAZ
    /*
    P->cursor = P->fim;

    if(P->inicio == NULL){
    printf("\n");
    }else{
        do{
            printf("%s\n",P->cursor->titulo);
            P->cursor = P->cursor->ant;
        }while(P->cursor != P->fim);
    }
    */

}

void invertePlaylist(Playlist *P){

    if(P->inicio == NULL){
        //NADA ACONTECE

    }else{

        P->inicio = P->inicio->ant;
        P->fim = P->fim->prox;

        Musica *aux = P->inicio;
        Musica *antAux = P->inicio->ant;
        struct _musica *temp = NULL;

        do{
            //printf("ANT: %s AUX: %s\n ",antAux->titulo, aux->titulo);
            temp = antAux->ant;
            antAux->ant = antAux->prox;
            antAux->prox = temp;
            antAux = aux;
            aux = aux->prox;
        }while(antAux != P->inicio->prox);

    }

}

void imprime(Playlist *P);
void imprimePointers(Playlist *P);

// Playlist *CriaPlaylist();
// void DestroiPlaylist(Playlist **P);
// int PlaylistEstaVazia(Playlist *P);
// void InsereNoInicioPlaylist(Playlist *P, consta char *musica);
// void InsereNoFimPlaylist(Playlist *P, int val);
// void RemoveMusica(Playlist *P, int val);



int main() {
    int n; // num de comandos
    int i;

    scanf("%d", &n);

    while (n != 0) {
        char comando[128];
        char titulo[128];

        Playlist *P = CriaPlaylist();

        for (i = 0; i < n; i++) {
            scanf("%s", comando);

            if (strcmp(comando, "insere") == 0) {
                scanf(" %[^\t\n]s", titulo);
                InsereMusica(P, titulo);
            }
            else if (strcmp(comando, "remove") == 0) {
                scanf(" %[^\t\n]s", titulo);
                RemoveMusica(P, titulo);
            }
            else if (strcmp(comando, "toca") == 0) {
                toca(P);
            }
            else if (strcmp(comando, "volta") == 0) {
                volta(P);
            }
            else if (strcmp(comando, "final") == 0) {
                final(P);
            }
            else if (strcmp(comando, "inverte") == 0) {
                invertePlaylist(P);
            }
        }

        DestroiPlaylist(&P);

        scanf("%d", &n);
        if (n != 0) {
            puts("");
        }
    }

    return 0;
}

Musica *CriaMusica(const char *titulo) {
    Musica *m = (Musica *) calloc(1, sizeof(Musica));
    strcpy(m->titulo, titulo);
    m->ant = m->prox = m;

    return m;
}

void DestroiMusica(Musica **m) {

    Musica *aux = *m;

    if (aux != NULL) {
        free(aux);
        *m = NULL;
    }

}

Playlist *CriaPlaylist() {
    return calloc(1, sizeof(Playlist));
}

int PlaylistEstaVazia(Playlist *P) {
    return (P->inicio == NULL);
}

void DestroiPlaylist(Playlist **P) {
    Playlist *aux = *P;

    if (aux != NULL) {
        // a lista possui elementos
        if (!PlaylistEstaVazia(aux)) {
            Musica *m = aux->inicio;

            while (m != aux->fim) {
                Musica *q = m;
                m         = m->prox;
                free(q);
            }
            free(m);
        }
        free(aux);
        *P = NULL;
    }
}

void imprime(Playlist *P) {
    if (!PlaylistEstaVazia(P)) {
        Musica *m = P->inicio;

        do {
            printf("%s\n", m->titulo);
            m = m->prox;
        } while(m != P->inicio);
    }
}

/*
void imprimePointers(Playlist *P) {
    if (!PlaylistEstaVazia(P)) {
        puts("-----");
        printf("P->inicio: %s\n", P->inicio->titulo);
        printf("P->fim: %s\n", P->fim->titulo);
        printf("P->cursor: %s\n", P->cursor->titulo);
        puts("-----\n");
    }
}
*/
