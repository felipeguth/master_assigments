//99781 - Felipe Guth
/*Problema da mochila:
Considere n itens a serem levados para uma viagem, dentro de uma mochila de capacidade L que não pode comportar todos os itens. Cada item tem um peso wi e uma utilidade ci. Quais itens escolher de modo que a utilidade total dos itens levados seja a maior possível?*/

#include <stdio.h>

int main()
{

int W = 10; //capacidade da mochila
int j = 10; //itens
int w[] = {2,1,5,2,8,7,3,8,8,3}; //tamanho dos X itens
int v[] = {0,100,200,300,400,500,600,700,800,900}; //valor dos itens - utilidade
int x[] = {0,0,0,0,0,0,0,0,0,0}; //mochila        
int carga = 0;
int k=0;


while(j >=1 && carga < W)
{
	//printf("\nJ %d , Carga %d, w[%d], %d", j,carga,j-1,w[j-1]);

	if ( w[j-1] + carga <= W) // se caber item insere
	{
		x[j-1] = 1; //insere o item na mochila
		carga = carga + w[j-1]; //aumenta carga mochila		
	}
	else
	{
		x[j-1] = 0;	
	}
	
	printf("\nCarga : %d", carga);
	j--; //decrementa itens
}
	

        int total = 0;
	int m=0;
        for (m=0; m < sizeof(x) / sizeof(int); m++) //tamanho de x
	{
	    printf("\n Item X %d : %d", m, x[m]); //0 N 1 presente
            total += x[m];	   
        }


            
       printf("\n Total de itens: %d \n", total);


return 0;


}





