//99781 - Felipe Guth
//solução deve realizar 2^n -1 movimentos


#include <stdio.h>

int cont;

void movetorre (int n, char orig, char dest, char aux) //função recursiva
{
//printf("\n n = %d orig %c dest %c aux %c cont %d", n, orig, dest, aux, cont);
  
   cont ++;
   if (n==1) 
	{
	//	printf("IF");		
		printf("\nMover disco 1 da torre %c para a torre %c", orig, dest);
	  	return;
	}
    else {
	 // printf("Else");
          movetorre(n-1,orig,aux,dest);
          printf("\nMover disco %d da torre %c para a torre %c", n, orig, dest);
          movetorre(n-1,aux,dest,orig);
    	}
//printf("\n n = %d orig %c dest %c aux %c cont %d", n, orig, dest, aux, cont);
};

int main(){
   int discos;
   printf("Felipe Guth - 99781 - TORRE DE HANOY\n\n");
   printf("Digite a quantidade de discos: ");
   scanf("%d",&discos);
   movetorre(discos,'A','C','B'); //Origem, Destino, Auxiliar
   printf("\n numero de movimentos = %d \n", cont);
  
   system("pause");
    return 0;
}
