#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define TAMANHO 10 //constante usada para controlar o tamanho do vetor utilizado

void selecao(long int *v, long int n) //essa fun�ao ordena o vetor atraves do metodo "sele�ao"
{
    long int i,j,menor,aux;
    for(i=0; i<n-1; i++)
    {
        menor=i; //o menor elemento � o primeiro afim de compara�oes
        for(j=i+1; j<n; j++)
            if(v[j]<v[menor])	//ele pega o menor e compara com elemento da frente
                menor=j;		 //pega a posicao do menor	             					
        aux=v[i];   				//se for menor ele troca de posi�ao; Trocando o elemento da frente com o elemento de tr�s.                 
        v[i]=v[menor];
        v[menor]=aux;
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
    vetor = valorVetorDescrescente();  //fun�ao auxiliar para preencher o vetor
    //vetor = valorVetorAleatorio();  //fun�ao auxiliar para preencher o vetor
    
    inicio = clock(); 		//inicio que � uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo
    selecao(vetor,TAMANHO);  //chama a fun�ao de ordena�ao
    fim = clock();			//fim que � uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo

    float tempo = (fim - inicio) / (float)CLOCKS_PER_SEC; // para calcular o tempo total gasto no algoritmo � pega o tempo recebido na variavel fim e subtrai pela variavel inicio
    printf("Tempo: %.3f",  tempo) ; //exibe o tempo gasto
    printf("\n");

    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");

}

