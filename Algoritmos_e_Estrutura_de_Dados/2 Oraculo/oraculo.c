#include <stdio.h>
#include <windows.h>
/*Felipe Guth - 99781 - precisa de adapta��o para casos impares - adapta��o com mallock para 
liberar mem�ria nesse experimento sera simulado com o valor 0 

/*Determinar o limite inferior para o problema da ordena��o por inser��o,
 com o uso de um or�culo.  

Teorema: Qualquer algoritmo para encontrar o maior e o menor elementos de
um conjunto com n elementos n�o ordenados, n>1, faz pelo menos 3n-2compara��es */
 
 
#define numElements 100 

main()
{
 int vetElements[numElements]; 
 int vetNeverCompared[numElements]; //nunca foram comparados Estado Inicial
 int vetWinnersNeverLost[numElements/2]; //foram vencedores e nunca perderam em compara
 int vetLosersNeverWin[numElements/2]; // perdedores que nunca venceram em compora��es
 int vetWinnersLosers[numElements-2]; // foram vencedores e perdedores em compara��es
 int  i, j, par; 
 
 
 /* inicializar o gerador de n�meros aleat�rios */
 /* com time(NULL)  */
 srand(time(NULL));
  for (i=0; i<numElements; i++)
      {
           /* para gerar n�meros aleat�rios de 0 a 1000 */
          // printf("%d \n", rand() % 1000);
          vetElements[i] =  rand() % 1000;            
      } 
 
// for (j=0; j<numElements; j++) //verificar valores gerados
//      {
//           /* para gerar n�meros aleat�rios de 0 a 1000 */
//          // printf("%d \n", rand() % 1000);
//          //vetElements[i] =  rand() % 1000;
//          printf("\n i %d = %d", j, vetElements[j]);
//          
//      } 


        //verificar se n�mero � par
        if (numElements %2 == 0)
          par = 1;
        else
           par = 0;
        


        int a=0, b=0;
        j = numElements-1;
        // n/2 compara��es para zerar  vetNeverCompared
        
        for(i=0; i<= ((numElements/2)-1); i++) //Arredonda para baixo a divis�o
        {
                // printf("A = %d, B = %d, i = %d, j = %d \n", a, b, i, j);
                 //system("pause");
                // printf("elei = %d, eleJ = %d", vetElements[i],vetElements[j]);
                 //system("pause");
                 if(vetElements[i] > vetElements[j])
                 {
                  vetWinnersNeverLost[a]= vetElements[i]  ; // vencedores 
                  vetLosersNeverWin[b] = vetElements[j]; //perdedores    
                               }
                 else 
                 {
                  vetWinnersNeverLost[a]= vetElements[j]  ; // vencedores 
                  vetLosersNeverWin[b] = vetElements[i]; //perdedores
                      
                 } 
                 printf("Comparacoes A : %d \n", i);
                // printf("eleW = %d, eleL = %d", vetWinnersNeverLost[a],vetLosersNeverWin[b]);
                 //system("pause");
         a++;
         b++;
         j--;
        }
        //faz + 1 verifica��o se numelementos for impar com primeiro valor do vetor de ganhadores
        if (par==0)
        {
          if(vetElements[numElements - 1] > vetWinnersNeverLost[0])
                             
        }
        
        
        
        
      
      // n/2 compara��es para reduzir a 1 vetWinnersNeverLost
        a =0;
        b=0;        
        j = numElements-1;
        
        for(i=0; i<= (((numElements/2)/2)-1); i++)
        {
                // printf("A = %d, B = %d, i = %d, j = %d \n", a, b, i, j);
                 //system("pause");
                // printf("elei = %d, eleJ = %d", vetElements[i],vetElements[j]);
                 //system("pause");
                 if(vetLosersNeverWin[i] > vetLosersNeverWin[j])
                 {
                  vetWinnersLosers[a] = vetLosersNeverWin[i]; //ganhadores    
                               }
                 else 
                 {                   
                  vetWinnersLosers[a] = vetLosersNeverWin[j]; //ganhadores                      
                 } 
                 printf("Comparacoes A : %d \n", i);
                // printf("eleW = %d, eleL = %d", vetWinnersNeverLost[a],vetLosersNeverWin[b]);
                 //system("pause");
         a++;
         //b++;
         j--;
        }
      
      
     // n/2 compara��es para reduzir a 1 vetWinnersNeverLost vetLosersNeverWin 
      
        a =0;
        b=0;        
        j = numElements-1;
        
        for(i=0; i<= (((numElements/2)/2)-1); i++)
        {
                // printf("A = %d, B = %d, i = %d, j = %d \n", a, b, i, j);
                 //system("pause");
                // printf("elei = %d, eleJ = %d", vetElements[i],vetElements[j]);
                 //system("pause");
                 if(vetWinnersNeverLost[i] > vetWinnersNeverLost[j])
                 {
                  vetWinnersLosers[a] = vetWinnersNeverLost[j]; //perdedores    
                               }
                 else 
                 {                   
                  vetWinnersLosers[a] = vetWinnersNeverLost[i]; //perdedores                      
                 } 
                 printf("Comparacoes A : %d \n", i);
                // printf("eleW = %d, eleL = %d", vetWinnersNeverLost[a],vetLosersNeverWin[b]);
                 //system("pause");
         a++;
         //b++;
         j--;
        }
      
      
      system("pause");            
      
      }
