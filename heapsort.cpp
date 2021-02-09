#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define TAMANHO 10 //constante usada para controlar o tamanho do vetor utilizado

long heapsort(long int *v, long int n)
{
    long trocas =0;
    int meioTamanho = n/2, parent, child, t;

															
    for (;;)
    {
        if (meioTamanho > 0)
        {
            meioTamanho--;						//ele pega o valor do meio e compara se � maior que zero.
            t = v[meioTamanho];					//a variavel t recebe esse valor que esta no meio do vetor.
        }
      
	    else
        {
            n--;								// se o elemento que est� no meio vetor for menor que zero, decrementa a variavel n.
            if (n == 0) return trocas;			//e, compara se o n � igual a zero, se for retorna trocas.
            t = v[n];							//a variavel recebe o elemento do vetor que esta passando on la�o
            v[n] = v[0];						//o vetor na posicao que o la�o esta passando recebe o primeiro elemento do vetor. 
        }

        parent = meioTamanho;			// a variavel pai recebe a variavel meioTamanho.
        child = meioTamanho*2 + 1;		// a variavel filho recebe a variavel meioTamanho multiplicada por 2 + 1.	

        while (child < n)  //la�o que compara o filho enquanto o tamanho do vetor for menor que variavel n, essa variavel n representa o tamanho do vetor.
        {
            if (child + 1 < n  &&  v[child + 1] > v[child]) //compara�ao para ver se  nao vai ultrapassar o tamanho do vetor e se a proxima do vetor � maior que a atual.
            {
                child++; //variavel filho � incrementada se a condi�ao acima for verdadeira.
            }
            if (v[child] > t) //comparacao para ver se o vetor na posi�ao filho � maior que a variavel t.
            {
                v[parent] = v[child]; //vetor na posi�ao pai recebe o valor da posi�ao filho.
                parent = child; //pai recebe o valor do filho.
                child = parent*2 + 1; //filho vai receber o pai multiplicado por 2 mais 1.
                trocas = trocas +1;//trocas recebe ele mesmo mais 1.
            }
            else 
            {
                break; // quando as condicoes acima forem falsas o la�o e pausado.
            }
        }
        v[parent] = t; //o vetor na posi�ao pai recebe a variavel t.
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
    heapsort(vetor,TAMANHO);  //chama a fun�ao de ordena�ao
    fim = clock();			//fim que � uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo

    float tempo = (fim - inicio) / (float)CLOCKS_PER_SEC; // para calcular o tempo total gasto no algoritmo � pega o tempo recebido na variavel fim e subtrai pela variavel inicio
    printf("Tempo: %.3f",  tempo) ; //exibe o tempo gasto
    printf("\n");

    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");

}

