// djikstra.cpp : Defines the entry point for the console application.
//Felipe Guth - 99781

//#include "stdafx.h" 
#include <stdio.h>
#define MAX 7
#define INFINITO 100

int todosSelec(int *selected)
{
    int i;
    for(i=0;i<MAX;i++)
        if(selected[i]==0)
            return 0;
    return 1;
}

void dijkstra(int cost[][MAX],int *preced,int *distance)
{
    int selected[MAX]={0};
    int current=0,i,k,dc,smalldist,newdist;
    for(i=0;i<MAX;i++)
       distance[i]=INFINITO;
    selected[current]=1;
    distance[0]=0;
    current=0;
    while(!todosSelec(selected)) //executa teste enquanto nao testar todas opções
    {
        smalldist=INFINITO;
        dc=distance[current];
        for(i=0;i<MAX;i++)
        {
			if(selected[i]==0) //analisa apenas elementos novos
			{
				newdist=dc+cost[current][i];
				//printf("current i %d = %d \n", i, cost[current][i]); //função que verifica o minimo caminho possível
				//int j;
				//scanf("%d",&j);
				if(newdist<distance[i])
				{
					distance[i]=newdist;
					preced[i]=current;
				}

				if(distance[i]<smalldist)
				{
					smalldist=distance[i];
					k=i;
				}
          }
        }
        current=k;
        selected[current]=1;
   }
}

int _tmain(int argc, _TCHAR* argv[])
{

//Define matriz de custo de origem a distancia
int cost[MAX][MAX]={
{INFINITO,2,4,7,INFINITO,5,INFINITO}, //custo de A para o elemento seguinte X
{2,INFINITO,INFINITO,6,3,INFINITO,8}, // Custo de X para elemento seguinte .... 
{4,INFINITO,INFINITO,INFINITO,INFINITO,6,INFINITO},
{7,6,INFINITO,INFINITO,INFINITO,1,6},
{INFINITO,3,INFINITO,INFINITO,INFINITO,INFINITO,7},
{5,INFINITO,6,1,INFINITO,INFINITO,6},
{INFINITO,8,INFINITO,6,7,6,INFINITO}};
    int i,j,preced[MAX]={0},distance[MAX];

	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
		printf(" %d %d %d \n", i, j, cost[i][j]);

    dijkstra(cost,preced,distance); //função que verifica o minimo caminho possível

    for(i=0;i<MAX;i++)
       printf("%d\n",distance[i]);

	return 0;
}

