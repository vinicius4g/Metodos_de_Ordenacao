#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define TAMANHO 10 //constante usada para controlar o tamanho do vetor utilizado

void quicksort(long int *v, long int inicio, long int fim) //essa funçao ordena o vetor atraves do metodo "quicksort"
{

    long int i, j, x, aux;
    x = v[(inicio+fim)/2]; // x é escolhido como pivô, e no caso ele pega o elemento do meio do vetor para se tornar o melhor caso.
    i=inicio; //equivale a esquerda
    j=fim; 	//equivale a direita

    while (i<=j)
    {
        while ( v[i] < x && i < fim ) i++;     //Particiona: rearranje a lista de forma que todos os elementos anteriores ao pivô sejam menores que ele, 
		while ( v[j] > x && j > inicio) j--;   //e todos os elementos posteriores ao pivô sejam maiores que ele. Ao fim do processo o pivô estará em sua posição final e haverá duas sub listas não ordenadas. 
											  //Essa operação é denominada partição;

        if ( i <= j )
        {
            aux = v[i];  //a variavel aux recebe o valor da variavel que esta passando no laço.
            v[i] = v[j]; //a variavel que esta passando no laço recebe o valor do mesmo vetor, só que no caso posiçao da variavel j.  Obs: a variavel j esta no segundo laço.
            v[j] = aux; // o elemento que esta na posicao j do vetor, recebe a variavel aux.
            i++;        //incrementa a variavel i.
            j--;		//decrementa a variavel j. Obs: parte importante para que a variavel i cruze com a j.
        }

    }


	//Recursivamente ordene a sub lista dos elementos menores e a sub lista dos elementos maiores;
    if ( j > inicio ) //se j for maior que a variavel inicio, é feita uma chamada recursiva passsando 3 variaveis para que ordenaçao continue.
        quicksort(v, inicio, j);
 
    if ( i < fim ) //se i for menor que a variavel fim, é feita uma chamada recursiva passsando 3 variaveis para que ordenaçao continue.
        quicksort(v, i, fim); 
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
    quicksort(vetor, 0,TAMANHO-1);  //chama a funçao de ordenaçao
    fim = clock();			//fim que é uma variavel, recebe uma funcao da biblioteca time.h para calcular o tempo

    float tempo = (fim - inicio) / (float)CLOCKS_PER_SEC; // para calcular o tempo total gasto no algoritmo é pega o tempo recebido na variavel fim e subtrai pela variavel inicio
    printf("Tempo: %.3f",  tempo) ; //exibe o tempo gasto
    printf("\n");

    // for(long int i = 0; i < TAMANHO; i++){
    //     printf("%ld - ", vetor[i]);
    // }
    // printf("\n");

}



