#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define TAMANHO 10 //constante usada para controlar o tamanho do vetor utilizado

void insercao(long int *v, long int n) //essa funçao ordena o vetor atraves do metodo "insercao"
{
    int i,j,aux;


	//	A cada novo elemento adicionada à seu vetor, a novo elemento pode ser menor que alguns elementos que você já tem ou maior,
	//e assim, é comparado a novo elemento com todas os outros do seu vetor  até encontrar sua posição correta.
	//Você insere o novo elemento na posição correta, e, novamente, seu vetor é composto de elementos totalmente ordenadas.
	//  Então, você recebe outro elemento e repete o mesmo procedimento. Então outro elemento, e outro, e assim por diante, até você não receber mais.


    for(j=1; j<n; j++)
    {
        aux=v[j];						
        for(i=j-1; i>=0 && v[i]>aux; i--) //( nessa linha é comparado a novo elemento com todas os outros do seu vetor até encontrar sua posição correta)	
            v[i+1]=v[i];	//( nessa linha é inserido o elemento na posição correta )
        v[i+1]=aux; 	//( nessa linha elemento da frente é inseirdo para fazer as comparaçoes novamente)
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
    vetor = valorVetorDescrescente();  //funçao auxiliar para preencher o vetor
    //vetor = valorVetorAleatorio();  //funçao auxiliar para preencher o vetor
    
    inicio = clock(); 		//inicio que é uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo
    insercao(vetor,TAMANHO);  //chama a funçao de ordenaçao
    fim = clock();			//fim que é uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo

    float tempo = (fim - inicio) / (float)CLOCKS_PER_SEC; // para calcular o tempo total gasto no algoritmo é pega o tempo recebido na variavel fim e subtrai pela variavel inicio
    printf("Tempo: %.3f",  tempo) ; //exibe o tempo gasto
    printf("\n");

    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");

}

