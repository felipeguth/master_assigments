//Felipe Guth - 99781

#include <stdio.h>
#define MAX 7
#define INFINITE 998

int todosSelec(int *selected)
{
    int i;
    for(i=0;i<MAX;i++)
        if(selected[i]==0)
            return 0;
    return 1;
}

void shortpath(int cost[][MAX],int *preced,int *distance)
{
    int selected[MAX]={0};
    int current=0,i,k,dc,smalldist,newdist;
    for(i=0;i<MAX;i++)
       distance[i]=INFINITE;
    selected[current]=1;
    distance[0]=0;
    current=0;
    while(!todosSelec(selected))
    {
        smalldist=INFINITE;
        dc=distance[current];
        for(i=0;i<MAX;i++)
        {
          if(selected[i]==0) //analisa apenas elementos que ainda não foram incluidos no conjunto
          {
	    newdist=dc+cost[current][i];
	    printf("current i %d = %d \n", i, cost[current][i]);
		int j;
	    scanf("%d",&j);
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

int main()
{

//Define matriz de custo de origem a distancia
int cost[MAX][MAX]={
{INFINITE,2,4,7,INFINITE,5,INFINITE},
{2,INFINITE,INFINITE,6,3,INFINITE,8},
{4,INFINITE,INFINITE,INFINITE,INFINITE,6,INFINITE},
{7,6,INFINITE,INFINITE,INFINITE,1,6},
{INFINITE,3,INFINITE,INFINITE,INFINITE,INFINITE,7},
{5,INFINITE,6,1,INFINITE,INFINITE,6},
{INFINITE,8,INFINITE,6,7,6,INFINITE}};
    int i,j,preced[MAX]={0},distance[MAX];

		

	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
		printf(" %d %d %d \n", i, j, cost[i][j]);

    shortpath(cost,preced,distance);

    for(i=0;i<MAX;i++)
       printf("%d\n",distance[i]);
    return 0;
}

