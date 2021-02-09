#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define TAMANHO 10 //constante usada para controlar o tamanho do vetor utilizado

void merge(long int v[], long int comeco, long int meio, long int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){ //Preencher as duas metades do vetor.
        if(v[com1] < v[com2]) {
            vetAux[comAux] = v[com1];
            com1++;
        } else {
            vetAux[comAux] = v[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = v[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = v[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        v[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(long int *v, long int comeco, long int fim) //essa funçao ordena o vetor atraves do metodo "mergeSort"
{ 
    if (comeco < fim) {
        int meio = (fim+comeco)/2; //pega o elemento do meio do vetor.

        mergeSort(v, comeco, meio); //chamada recursiva para a continuaçao da ordenaçao
        mergeSort(v, meio+1, fim);  //chamada recursiva para a continuaçao da ordenaçao
        merge(v, comeco, meio, fim);  //chamada de uma funçao auxiliar da ordenaçao mergeSort
    }
}

long int* valorVetorCrescente()  //essa funçao gera um vetor com numeros crescente
{
    long int i, *vetor;
    vetor = (long int*) malloc(sizeof(long int) * TAMANHO);  //aloca o vetor dinamicamente de acordo com o tamanho do vetor necessario

    for(i=0; i<TAMANHO; i++)
        vetor[i] = i; //vetor recebe os valores de forma decrescente

    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");
    return vetor; //retorna o vetor ja preenchido
}

long int* valorVetorAleatorio()  //essa funçao gera um vetor com numeros aleatorios
{
    long int i, *vetor;
    srand(time(NULL));
    vetor = (long int*) malloc(sizeof(long int) * TAMANHO); //aloca o vetor dinamicamente de acordo com o tamanho do vetor necessario

    for(i=0; i<TAMANHO; i++)
        vetor[TAMANHO-i] = rand() % TAMANHO;  //vetor recebe os valores de forma aleatoria atraves do "rand ()% TAMANHO "

    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");
  
    return vetor; //retorna o vetor ja preenchido
}

long int* valorVetorDescrescente()  //essa funçao gera um vetor decrescente
{
    long int i, *vetor;
    vetor = (long int*) malloc(sizeof(long int) * TAMANHO); //aloca o vetor dinamicamente de acordo com o tamanho do vetor necessario

    for(i=TAMANHO; i>0; i--)
        vetor[TAMANHO-i] = i; //vetor recebe os valores de forma decrescente
			
    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");
   
    return vetor; //retorna o vetor ja preenchido
}

int main() {

    srand(time(NULL)); //É usado para sortear os numeros de forma aleatoria 
    long int *vetor;
    clock_t inicio, fim; //declarada duas variaveis do tipo clock

    //vetor = valorVetorCrescente();   //funçao auxiliar para preencher o vetor
   // vetor = valorVetorDescrescente();  //funçao auxiliar para preencher o vetor
    vetor = valorVetorAleatorio();  //funçao auxiliar para preencher o vetor
    
    inicio = clock(); 		//inicio que é uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo
    mergeSort(vetor, 1, TAMANHO);  //chama a funçao de ordenaçao
    fim = clock();			//fim que é uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo

    float tempo = (fim - inicio) / (float)CLOCKS_PER_SEC; // para calcular o tempo total gasto no algoritmo é pega o tempo recebido na variavel fim e subtrai pela variavel inicio
    printf("Tempo: %.3f",  tempo) ; //exibe o tempo gasto
    printf("\n");

    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");

}
