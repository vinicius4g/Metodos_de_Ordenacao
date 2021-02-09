#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define TAMANHO 10 //constante usada para controlar o tamanho do vetor utilizado

void ordenaVetor1(long int *v, long int n) // essa funçao ordena a primeira parte do vetor 
{
    long int i,j,menor,aux;
    for(i=0; i<n; i++)
    {
        menor=i;  //o menor elemento é o primeiro afim de comparaçoes
        for(j=i+1; j<=n; j++)   
            if(v[j]<v[menor]) //ele pega o menor e compara com elemento da frente     
                menor=j;   //pega a posicao do menor
        aux=v[i];           	//se for menor ele troca de posiçao; Trocando o elemento da frente com o elemento de trás.       
        v[i]=v[menor];
        v[menor]=aux;
    }
}

void ordenaVetor2(long int *v, long int *v1, long int *v2, long int c, long int n) // essa funçao insere a segunda parte do vetor ja ordenando. 
{
    long int i, j, count=0, menor, aux, meio = (n+c)/2;
    for(i=0; i<meio; i++) { //o laço preenche a primeira metade do vetor com os elementos ja ordenados.
        v[i] = v2[i]; 
    }
    for(i=meio; i<n; i++) { //o laço insere na segunda parte do vetor os elementos desordenados.
        v[i] = v1[count]; 
        count++;
    }
    // for(long int i = 0; i < meio; i++){
    //     printf("%ld - ", v1[i]);
    // }
    // printf("\n");
    // for(long int i = 0; i < meio; i++){
    //     printf("%ld - ", v2[i]);
    // }
    // printf("\n");
    ordenaVetor1(v, n); //reoordeanr o vetor completo.
}

void ccsort(long int *v, long int comeco, long int fim){  //essa funçao ordena o vetor atraves do metodo "ccsort"
    if (comeco < fim) {
        long int meio = (fim+comeco)/2;

        long int com1 = comeco, com2 = meio, i = 0;
        long int *vetAux1, *vetAux2;
        vetAux1 = (long int*)malloc(meio * sizeof(long int));
        vetAux2 = (long int*)malloc(com2 * sizeof(long int));
	
		//quebra o vetor em 2 partes.

        while(com1 < meio){ // esse laço pega a primeira parte do vetor.

            vetAux1[i] = v[com1];
            com1++;

            i++;
        }
        i = 0;
        while(com2 < fim){ // esse laço pega a segunda parte do vetor

            vetAux2[i] = v[com2];
            com2++;
            
            i++;
        }
        ordenaVetor1(vetAux2, meio); //chama a funcao auxiliar para ordenar só a primeira parte
        ordenaVetor2(v, vetAux1, vetAux2, comeco, fim); //chama a funcao auxiliar para ordenar todo o vetor, de forma que a primeira entre na segunda ja ordenando.
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
    ccsort(vetor, 0, TAMANHO);  //chama a funçao de ordenaçao
    fim = clock();			//fim que é uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo

    float tempo = (fim - inicio) / (float)CLOCKS_PER_SEC; // para calcular o tempo total gasto no algoritmo é pega o tempo recebido na variavel fim e subtrai pela variavel inicio
    printf("Tempo: %.3f",  tempo) ; //exibe o tempo gasto
    printf("\n");

    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");

}

