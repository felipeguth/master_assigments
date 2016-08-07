#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
/*Felipe Guth - 99781 - precisa de adaptação para casos impares - adaptação com mallock para 
liberar memória nesse experimento sera simulado com o valor 0 

/*Determinar o limite inferior para o problema da ordenação por inserção,
 com o uso de um oráculo.  

Teorema: Qualquer algoritmo para encontrar o maior e o menor elementos de
um conjunto com n elementos não ordenados, n>1, faz pelo menos 3n-2comparações */
 
 
#define numElements 11 

int main()
{
 int vetElements[numElements]; 
 int vetNeverCompared[numElements]; //nunca foram comparados Estado Inicial
 int vetWinnersNeverLost[numElements/2]; //foram vencedores e nunca perderam em compara
 int vetLosersNeverWin[numElements/2]; // perdedores que nunca venceram em comporações
 int vetWinnersLosers[numElements-2]; // foram vencedores e perdedores em comparações

 int cont = numElements;
 int contWL = 0;  //win and lost
 int contNW = 0; //never win
 int contNL = 0; // never lost
 int  i, j, nCompar=0;
 
 
 /* inicializar o gerador de números aleatórios */
 /* com time(NULL)  */
 srand(time(NULL));
  for (i=0; i<numElements; i++)
      {
           /* para gerar números aleatórios de 0 a 1000 */
          // printf("%d \n", rand() % 1000);
          vetElements[i] =  rand() % 10000;            
      }   

 //for (j=0; j<numElements; j++) //verificar valores gerados
 //     {
           /* para gerar números aleatórios de 0 a 1000 */
          // printf("%d \n", rand() % 1000);
          //vetElements[i] =  rand() % 1000;
 //         printf("\n i %d = %d", j, vetElements[j]);
          
 //     } 

      
  
 ///////////////////////A
 j = numElements-1;
 i=0;
 do{
    if(vetElements[i] > vetElements[j])
    {
     vetWinnersNeverLost[contNL]= vetElements[i]  ; // vencedores 
     vetLosersNeverWin[contNW] = vetElements[j]; //perdedores    
    }
    else 
    {
     vetWinnersNeverLost[contNL]= vetElements[j]  ; // vencedores 
     vetLosersNeverWin[contNW] = vetElements[i]; //perdedores
    }    
    
    vetElements[i] = 0; //simula liberar espaço
    vetElements[j] =0;  //simula liberar espaço
    cont = cont-2;
    contNL++;
    contNW++;
    i++;
    j--;
    nCompar++;
 }while (cont >= 2); 
 
  if (cont >= 1)  //mais uma comparação se tiver numero impar de elementos
 { printf("CU");
	nCompar++;
    if(vetElements[i] > vetWinnersNeverLost[0]) //compara elemento com primeiro valor do vetor de vencedores
    {    
     vetWinnersLosers[contWL] = vetWinnersNeverLost[0];
     vetWinnersNeverLost[0] = vetElements[i];
     contWL++;
    }
    else
    {
      vetLosersNeverWin[contNW] = vetElements[i];
      contNW++;
    }         
 }
 ////////////////////////A
  
 
 ////////////////////////B
 cont = contNL - 1; //diminui 1 para ajustar o numero que esta adaptado p prox inserção
 j = contNL - 1; //ajusta para comparação do vetor
 i = 0;
 int auxMaior = 0; //variavel auxiliar para guardar maior valor 
 
 do{  //elimina um valor por vez, passa n/2 - 1 vezes uma vez que vet tem n/2 elementos
  //  printf("\n first = %d, last = %d", vetWinnersNeverLost[i], vetWinnersNeverLost[j]);
    
    if(vetWinnersNeverLost[i] > vetWinnersNeverLost[j])
    {
     vetWinnersLosers[contWL] = vetWinnersNeverLost[j];
     auxMaior = vetWinnersNeverLost[i];
     
     vetWinnersNeverLost[j] = 0;
     j--;         //compara i novamente com próximo j - decrescente
    }
    else 
    {
     vetWinnersLosers[contWL] = vetWinnersNeverLost[i];
     auxMaior = vetWinnersNeverLost[j];
     vetWinnersNeverLost[i] = 0;     
     i++;       //compara j novamente com próximo i  - crescente
    }       
    cont = cont--; 
    contWL++;
    nCompar++;
 }while (cont >= 1);  
 ////////////////////////B 
 
 //printf("\n B valor maximo = %d \n", auxMaior);      
 //  printf("\n firsteD = %d, lasteD = %d", vetLosersNeverWin[0], vetLosersNeverWin[4]);
      
 
 ////////////////////////C
 cont = contNW - 1; //diminui 1 para ajustar o numero que esta adaptado p prox inserção
 j = contNW - 1; //ajusta para comparação do vetor
 i = 0;
 int auxMenor = 0; //variavel auxiliar para guardar menor valor 
 do{  //elimina um valor por vez, passa n/2 - 1 vezes uma vez que vet tem n/2 elementos
  //printf("\n i = %d, j = %d", i,j); 
  //printf("\n firsteD = %d, lasteD = %d", vetLosersNeverWin[i], vetLosersNeverWin[j]);
  
    if(vetLosersNeverWin[i] < vetLosersNeverWin[j]) //el i menor
    {      
     vetWinnersLosers[contWL] = vetLosersNeverWin[j];
     auxMenor = vetLosersNeverWin[i];
     vetLosersNeverWin[j] = 0;
     j--;         //compara i novamente com próximo j - decrescente     
    }
    else //el i maior
    {      
     vetWinnersLosers[contWL] = vetLosersNeverWin[i];
     auxMenor = vetLosersNeverWin[j];
     vetLosersNeverWin[i] = 0;     
     i++;       //compara j novamente com próximo i  - crescente    
    }       
    cont = cont--; 
    contWL++;
    nCompar++;
 }while (cont >= 1);  
 ////////////////////////C
  
  //printf("\n C valor minimo = %d \n", auxMenor);
       
 
 printf("\n Num Elementos = %d \n Num Comparacoes = %d \n Limite Superior = %d \n Limite Inferior = %d", numElements, nCompar, auxMaior, auxMenor);
 
 return 0;
 
}

