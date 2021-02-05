#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Obs Pessoais.
// � visivel a necessidade de refatora��o para redu��o do c�digo, v�rios elementos podem vrar fun��es com ou sem recursvidade.
// Fazer uma fun��o que compare duas strings. Abordagem atual n�o est� dando certo.

/** STRUCTS E VARIAVEIS **/

typedef struct _veiculo{
    char placa[8];
    char modelo[16];
    char proprietario[16];
    int ano;
    int preco;
} Veiculo;

int contador = 0;

/** UTEIS E AUXILIARES **/

Veiculo* CriaVetor(int tamanho){
    Veiculo* vetor = (Veiculo *) calloc (tamanho, sizeof (Veiculo));
    return vetor;
}

void InsereVeiculo(Veiculo *vetor, char placa[8], char modelo[16], char proprietario[16], int ano, int preco){
    strcpy(vetor[contador].placa, placa);
    strcpy(vetor[contador].modelo, modelo);
    strcpy(vetor[contador].proprietario, proprietario);
    vetor[contador].ano = ano;
    vetor[contador].preco = preco;
    contador ++;
}

void imprimeVeiculo(Veiculo *vetor, int tamanho){

    int i = 0;

    for (i = 0; i< tamanho ; i++){
        printf("%s %s %s %i %i\n", vetor[i].placa, vetor[i].modelo, vetor[i].proprietario, vetor[i].ano, vetor[i].preco);
    }
}

void destroiVetor(Veiculo *vetor, int tamanho){
    printf("\nLimpando Vetor...\n");

    int i = 0;
    int j = 0;

    for (i = 0; i< tamanho ; i++){
        for (j = 0; j <8; j++){
            (vetor[i].placa[j] = NULL);
        }
        for (j = 0; j <16; j++){
            (vetor[i].modelo[j] = NULL);
        }
        for (j = 0; j <16; j++){
            (vetor[i].proprietario[j] = NULL);
        }
        (vetor[i].ano = NULL);
        (vetor[i].preco = NULL);
    }

    free(vetor);
}

void inverte(Veiculo* a, Veiculo* b){
    Veiculo aux = *a;
    *a = *b;
    *b = aux;
}

/** BUBBLE SORT - TESTE PURPOSE ONLY **/

void bubbleSortAno(Veiculo *vetor, int tamanho){
   int i, j;

   for (i = 0; i < tamanho-1; i++){
       for (j = 0; j < tamanho-i-1; j++){
           if (vetor[j].ano > vetor[j+1].ano){
              inverte(&vetor[j], &vetor[j+1]);
           }
       }
   }
}

/** ORDERING BY PLACA CRES **/

int dividedToConquerPlaca(Veiculo *vetor, int inicio, int fim) {
    int pivot = inicio;
    for(int i = inicio + 1; i <= fim; ++i) {

        if(
            (strncmp(vetor[i].placa,vetor[pivot].placa,1) < 0)
            ){
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
        else if (
            (strncmp(vetor[i].placa,vetor[pivot].placa,1) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,2) < 0)
            ){
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
        else if (
            (strncmp(vetor[i].placa,vetor[pivot].placa,1) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,2) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,3) < 0)
            ){
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
        else if (
            (strncmp(vetor[i].placa,vetor[pivot].placa,1) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,2) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,3) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,4) < 0)
            ){
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
        else if (
            (strncmp(vetor[i].placa,vetor[pivot].placa,1) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,2) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,3) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,4) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,5) < 0)
            ){
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
        else if (
            (strncmp(vetor[i].placa,vetor[pivot].placa,1) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,2) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,3) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,4) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,5) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,6) < 0)
            ){
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
        else if (
            (strncmp(vetor[i].placa,vetor[pivot].placa,1) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,2) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,3) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,4) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,5) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,6) == 0) &&
            (strncmp(vetor[i].placa,vetor[pivot].placa,7) < 0)
            ){
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
    }
    return pivot;
}

void insertionSortPlaca(Veiculo *vetor, int inicio, int fim) {
    for(int i = inicio; i <= fim; i++) {
        int j = i;

        while((j > inicio) && (
            (
            (strncmp(vetor[j-1].placa,vetor[j].placa, 1) > 0))
            || (
            (strncmp(vetor[j-1].placa,vetor[j].placa,1) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,2) > 0))
            || (
            (strncmp(vetor[j-1].placa,vetor[j].placa,1) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,2) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,3) > 0))
            || (
            (strncmp(vetor[j-1].placa,vetor[j].placa,1) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,2) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,3) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,4) > 0))
            || (
            (strncmp(vetor[j-1].placa,vetor[j].placa,1) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,2) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,3) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,4) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,5) > 0))
            || (
            (strncmp(vetor[j-1].placa,vetor[j].placa,1) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,2) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,3) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,4) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,5) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,6) > 0))
            || (
            (strncmp(vetor[j-1].placa,vetor[j].placa,1) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,2) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,3) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,4) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,5) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,6) == 0) &&
            (strncmp(vetor[j-1].placa,vetor[j].placa,7) > 0))
            )
            ){
            inverte(&vetor[j-1], &vetor[j]);
            j--;
        }
    }
}

void hybridSortPlaca(Veiculo *vetor, int inicio, int fim, int threshold){
    if(inicio < fim){
        if (fim-inicio <= threshold){
            insertionSortPlaca(vetor, inicio, fim);
        } else {
            int pivot = dividedToConquerPlaca(vetor, inicio, fim);
            hybridSortPlaca(vetor, inicio, pivot-1, threshold);
            hybridSortPlaca(vetor, pivot+1, fim, threshold);
        }
    }
}

/** ORDERING BY MODELO CRES **/

int dividedToConquerModelo(Veiculo *vetor, int inicio, int fim) {
    int pivot = inicio;
    for(int i = inicio + 1; i <= fim; ++i) {

        if(strncmp(
            vetor[i].modelo,
            vetor[pivot].modelo,
            1) < 0)
        {
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
    }
    return pivot;
}

void insertionSortModelo(Veiculo *vetor, int inicio, int fim) {
    for(int i = inicio; i <= fim; i++) {
        int j = i;

        while((j > inicio) && (
            strncmp(vetor[j-1].modelo,vetor[j].modelo, 1) > 0))
            {
            inverte(&vetor[j-1], &vetor[j]);
            j--;
        }
    }
}

void hybridSortModelo(Veiculo *vetor, int inicio, int fim, int threshold){
    if(inicio < fim){
        if (fim-inicio <= threshold){
            insertionSortModelo(vetor, inicio, fim);
        } else {
            int pivot = dividedToConquerModelo(vetor, inicio, fim);
            hybridSortModelo(vetor, inicio, pivot-1, threshold);
            hybridSortModelo(vetor, pivot+1, fim, threshold);
        }
    }
}

/** ORDERING BY ANO CRES **/

int dividedToConquerAno(Veiculo *vetor, int inicio, int fim) {
    int pivot = inicio;
    for(int i = inicio + 1; i <= fim; ++i) {
        if(vetor[i].ano < vetor[pivot].ano) {
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
    }
    return pivot;
}

void insertionSortAno(Veiculo *vetor, int inicio, int fim) {
    for(int i = inicio; i <= fim; i++) {
        int j = i;
        while(j > inicio && vetor[j-1].ano > vetor[j].ano) {
            inverte(&vetor[j-1], &vetor[j]);
            j--;
        }
    }
}

void hybridSortAno(Veiculo *vetor, int inicio, int fim, int threshold){
    if(inicio < fim){
        if (fim-inicio <= threshold){
            insertionSortAno(vetor, inicio, fim);
        } else {
            int pivot = dividedToConquerAno(vetor, inicio, fim);
            hybridSortAno(vetor, inicio, pivot-1, threshold);
            hybridSortAno(vetor, pivot+1, fim, threshold);
        }
    }
}

/** ORDERING BY ANO DECRES **/

int dividedToConquerAnoDec(Veiculo *vetor, int inicio, int fim) {
    int pivot = inicio;
    for(int i = inicio + 1; i <= fim; ++i) {
        if(vetor[i].ano > vetor[pivot].ano) {
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            --pivot;
        }
    }
    return pivot;
}

void insertionSortAnoDec(Veiculo *vetor, int inicio, int fim) {
    for(int i = inicio; i <= fim; i++) {
        int j = i;
        while(j > inicio && vetor[j-1].ano < vetor[j].ano) {
            inverte(&vetor[j-1], &vetor[j]);
            j--;
        }
    }
}

void hybridSortAnoDec(Veiculo *vetor, int inicio, int fim, int threshold){
    if(inicio < fim){
        if (fim-inicio <= threshold){
            insertionSortAnoDec(vetor, inicio, fim);
        } else {
            int pivot = dividedToConquerAnoDec(vetor, inicio, fim);
            hybridSortAnoDec(vetor, inicio, pivot-1, threshold);
            hybridSortAnoDec(vetor, pivot+1, fim, threshold);
        }
    }
}

/** ORDERING BY PRECO CRES **/

int dividedToConquerPreco(Veiculo *vetor, int inicio, int fim) {
    int pivot = inicio;
    for(int i = inicio + 1; i <= fim; ++i) {
        if(vetor[i].preco < vetor[pivot].preco) {
            inverte(&vetor[pivot + 1], &vetor[i]);
            inverte(&vetor[pivot], &vetor[pivot + 1]);
            ++pivot;
        }
        else if (vetor[i].preco == vetor[pivot].preco){
            if (vetor[i].ano < vetor[pivot].ano){
                inverte(&vetor[pivot + 1], &vetor[i]);
                inverte(&vetor[pivot], &vetor[pivot + 1]);
                ++pivot;
            }
            else if (vetor[i].ano == vetor[pivot].ano){
                if(strncmp(vetor[i].modelo,vetor[pivot].modelo,1) < 0){
                    inverte(&vetor[pivot + 1], &vetor[i]);
                    inverte(&vetor[pivot], &vetor[pivot + 1]);
                    ++pivot;
                }
                else if (strcmp(vetor[i].modelo,vetor[pivot].modelo) == 0){
                    if(strncmp(vetor[i].placa,vetor[pivot].placa,1) < 0){
                        inverte(&vetor[pivot + 1], &vetor[i]);
                        inverte(&vetor[pivot], &vetor[pivot + 1]);
                        ++pivot;
                    }
                }
            }
        }
    }
    return pivot;
}

void insertionSortPreco(Veiculo *vetor, int inicio, int fim) {
    for(int i = inicio; i <= fim; i++) {
        int j = i;
        while(j > inicio && vetor[j-1].preco > vetor[j].preco) {
            inverte(&vetor[j-1], &vetor[j]);
            j--;
        }
    }
}

void hybridSortPreco(Veiculo *vetor, int inicio, int fim, int threshold){
    if(inicio < fim){
        if (fim-inicio <= threshold){
            insertionSortPreco(vetor, inicio, fim);
        } else {
            int pivot = dividedToConquerPreco(vetor, inicio, fim);
            hybridSortPreco(vetor, inicio, pivot-1, threshold);
            hybridSortPreco(vetor, pivot+1, fim, threshold);
        }
    }
}

/** MAIN EXTENSIONS **/

void ordenarPlacaProprietario(Veiculo *vetor, int inicio, int fim, int threshold){
    hybridSortPlaca(vetor, inicio, fim, threshold);

    int i = 0;

    for (i = 0; i< fim+1 ; i++){
        printf("%s %s\n", vetor[i].placa, vetor[i].proprietario);
    }
}

void ordenarPlacaPreco(Veiculo *vetor, int inicio, int fim, int threshold){
    hybridSortPreco(vetor, inicio, fim, threshold);

    int i = 0;

    for (i = 0; i< fim+1 ; i++){
        printf("%s %i\n", vetor[i].placa, vetor[i].preco);
    }
}

void ordenarProprietarioAnoPlaca(Veiculo *vetor, int inicio, int fim, int threshold){
    hybridSortAnoDec(vetor, inicio, fim, threshold);

    int i = 0;

    for (i = 0; i< fim+1 ; i++){
        printf("%s %i %s\n", vetor[i].proprietario, vetor[i].ano, vetor[i].placa);
    }

}

void ordenarModeloPrecoPlaca(Veiculo *vetor, int inicio, int fim, int threshold){
    hybridSortModelo(vetor, inicio, fim, threshold);

    int i = 0;

    for (i = 0; i< fim+1 ; i++){
        printf("%s %i %s\n", vetor[i].modelo, vetor[i].preco, vetor[i].placa);
    }
}

/** MAIN **/

int main(){
    Veiculo **vetor;

    int linhaLida, threshold;

    char placa[8], modelo[16], proprietario[16];
    int ano, preco;

    scanf("%i",&linhaLida);

    int tamanho = linhaLida;
    vetor = CriaVetor(linhaLida);

    scanf("%i",&threshold);

    do{
        scanf("%s",placa);
        scanf("%s",modelo);
        scanf("%i",&ano);
        scanf("%s",proprietario);
        scanf("%i",&preco);
        InsereVeiculo(vetor,placa,modelo,proprietario,ano,preco);
        linhaLida--;
    }while(linhaLida > 0);

    //printf("\nVETOR ORIGINAL:\n");
    //imprimeVeiculo(vetor, tamanho);

    //printf("\nORDENADO POR ANO:\n");
    //bubbleSortAno(vetor, tamanho); // Test Purpose
    //hybridSortPlaca(vetor, 0, tamanho-1, threshold);
    //imprimeVeiculo(vetor, tamanho);

    ordenarPlacaProprietario(vetor, 0, tamanho-1, threshold);

    printf("\n");

    ordenarPlacaPreco(vetor, 0, tamanho-1, threshold);

    printf("\n");

    ordenarProprietarioAnoPlaca(vetor, 0, tamanho-1, threshold);

    printf("\n");

    ordenarModeloPrecoPlaca(vetor, 0, tamanho-1, threshold);

    destroiVetor(vetor, tamanho);

    //imprimeVeiculo(vetor, tamanho);

    return 0;
}
