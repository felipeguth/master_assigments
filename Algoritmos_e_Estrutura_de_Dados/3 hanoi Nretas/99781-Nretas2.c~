//99781 - Felipe Guth
//Qual é o número máximo de regiões Ln determinado por n retas no plano
//limite superior Ln = Ln -1 + n

#include <stdio.h>

int calculaRegioes(int retas){
if (retas == 0)
	return 1;

return calculaRegioes(retas-1) + retas;
}

int main(){
int nretas=0;


printf("Informe a quantidade de retas: ");
scanf("%d",&nretas);
printf("Numero maximo de regios Ln com %d retas =  %d \n", nretas, calculaRegioes(nretas));
}
