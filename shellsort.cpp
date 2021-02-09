#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define TAMANHO 10 	//constante usada para controlar o tamanho do vetor utilizado

void shellsort(long int *v, long int n)  //essa fun�ao ordena o vetor atraves do metodo "shellsort"
{
    int x, i, j, k, passo[5], inc;
    passo[0] = 9;
    passo[1] = 7;
    passo[2] = 5;
    passo[3] = 3;
    passo[4] = 1;

    for (k=0; k<5; k++) //o la�o conta os 5 passos
    {
        inc = passo[k]; //variavel inc recebe o passo correspondente.
        for (i=inc; i<n; i++) //la�o vai vai rodar o vetor todo.
        {
            x = v[i]; //a variavel x recebe o valor que esta no la�o
            for (j=i-inc; j>=0 && v[j]>x; j=j-inc) 
                v[j+inc] = v[j]; //o vetor na posi�ao que esta na posi�ao j+inc recebe o mesmo vetor so que na posicao j (obs: a variavel j esta rodando segundo la�o)
            v[j+inc] = x; // vetor na posi�ao que esta na posi�ao j+inc � atualizado recebendo x. 
        }
    }
}


long int* valorVetorCrescente()  //essa fun�ao gera um vetor com numeros crescente
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

long int* valorVetorAleatorio()  //essa fun�ao gera um vetor com numeros aleatorios
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

long int* valorVetorDescrescente()  //essa fun�ao gera um vetor decrescente
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


    srand(time(NULL)); //� usado para sortear os numeros de forma aleatoria 
    long int *vetor;
    clock_t inicio, fim; //declarada duas variaveis do tipo clock
	
    //vetor = valorVetorCrescente();   //fun�ao auxiliar para preencher o vetor
   // vetor = valorVetorDescrescente();  //fun�ao auxiliar para preencher o vetor
    vetor = valorVetorAleatorio();  //fun�ao auxiliar para preencher o vetor
    
    inicio = clock(); 		//inicio que � uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo
    shellsort(vetor,TAMANHO);  //chama a fun�ao de ordena�ao
    fim = clock();			//fim que � uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo

    float tempo = (fim - inicio) / (float)CLOCKS_PER_SEC; // para calcular o tempo total gasto no algoritmo � pega o tempo recebido na variavel fim e subtrai pela variavel inicio
    printf("Tempo: %.3f",  tempo) ; //exibe o tempo gasto
    printf("\n");

    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");

}
