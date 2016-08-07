#include <iostream>
#include <string>
#include <cstring>

#define SIZE 100
#define NIL -1

const float INFINITO = -1.0;

using namespace std;

//Lista para fazer a seleção do elemento com menor chave
struct lista{
        int indices[SIZE];            //Vetor de indices do grafo
        float pesos[SIZE];              //Vetor de pesos para o grafo
        int numElem;                    //numero de indices presentes no vetor
};

lista constroiLista(int vetor[], int n);
bool listaEhVazia(lista aux);
int extraiMinimoLista(lista &aux);


struct grafo{
        string vetor[SIZE];             //nome do vertice
        float adj[SIZE][SIZE];          //matriz de adjacencias do grafo
        float key[SIZE];                //peso para chegar ao nodo
        int pai[SIZE];                  //pai do nodo
        int numElem;                    //numero de elementos no grafo
};

 grafo constroiGrafo(){
        grafo aux;

        memset(aux.adj,0,sizeof(aux.adj));
        memset(aux.pai,NIL,sizeof(aux.pai));
        
        for (int i=0;i<SIZE;i++){
                aux.key[i] = INFINITO;
        }
        
        aux.numElem = 0;


        return (aux);
}

lista constroiLista(float vetor[], int n){
        lista aux;

        aux.numElem = n;
        for (int i=0;i<aux.numElem;i++){
                aux.indices[i] = i;
                aux.pesos[i] = vetor[i];
        }

        return aux;
}

bool listaEhVazia(lista aux){
        return (aux.numElem == 0);
}

int extraiMinimoLista(lista &aux){
        int ind_minimo =0,ind = 0;
        float minimo = aux.pesos[ind_minimo];

        for (int i=1;i<aux.numElem ; i++){
                if((aux.pesos[i] != INFINITO) && (minimo == INFINITO  || minimo > aux.pesos[i])){
                        minimo = aux.pesos[i];
                        ind = i;
                }
        }


        ind_minimo = aux.indices[ind];
        aux.numElem--;
        aux.indices[ind] = aux.indices[aux.numElem];
        aux.pesos[ind] = aux.pesos[aux.numElem];

        return (ind_minimo);
}

int  pegaAdjacentes(grafo G,int aresta, int result[]){
        int j=0;

        for(int i=0;i<G.numElem;i++){
                if (G.adj[aresta][i] != 0){
                        result[j] = i;
                        j++;
                }
        }

        return j;
}

bool existe(lista Q,int v){
        for (int i=0; i <  Q.numElem ; i++){
                if (v == Q.indices[i]){
                        return true;
                }
        }
        return false;
}

void imprimeLista(lista Q){
        cout << endl;
        for(int i=0;i<Q.numElem;i++){
                cout << Q.indices[i] << "->" << Q.pesos[i] << endl;
        }

}

void mudaKeyLista(lista &Q, int indice, float peso){
        for (int i=0; i <  Q.numElem ; i++){
                if (indice == Q.indices[i]){
                        Q.pesos[i] = peso;
                        break;
                }
        }
}

void mst_prim(grafo &G, int paiGeral){
        int u;
        int adj[SIZE];
        int numAdj;
        G.key[paiGeral] = 0;
        lista Q = constroiLista(G.key,G.numElem);

        while(!listaEhVazia(Q)){

                u = extraiMinimoLista(Q);


                numAdj = pegaAdjacentes(G,u,adj);



                for (int i=0; i < numAdj ; i++){
                        int v = adj[i];

                        if (existe(Q,v) && (G.adj[u][v] < G.key[v] || G.key[v] == INFINITO)){
                                G.pai[v] = u;
                                G.key[v] = G.adj[u][v];
                                mudaKeyLista(Q,v,G.key[v]);
                        }


                }




        }
}

int searchCidade(grafo G,string aux){
        for (int i=0; i <  G.numElem ; i++){
                if (aux == G.vetor[i]){
                        return i;
                }
        }
}

int main(){
        int n,x,y;
        int ligacoes;
        float peso;
        string aux,aux2;
        grafo G;

        cin >>  n;



        for (int i=0;i<n;i++){

                G = constroiGrafo();

                cin >> G.numElem >> ligacoes;

                for(int j=0;j< G.numElem; j++){
                        cin >> G.vetor[j];
                }

                for (int j=0;j<ligacoes;j++){
                        cin >> aux >> aux2 >> peso;
                        x = searchCidade(G,aux);
                        y = searchCidade(G,aux2);
                        G.adj[x][y] = G.adj[y][x] = peso;
                }


//                cout << "Cidades = " << G.numElem << "\nLigacoes =  " << ligacoes << endl;
//
//                cout << "Matriz :"<<endl;
//                for (int j=0;j<G.numElem;j++){
//                        for (int k=0;k<G.numElem;k++){
//                        cout << G.adj[j][k] << "\t";
//                        }
//                        cout << endl;
//                }

                mst_prim(G,0);



                for(int j=0;j<G.numElem; j++){
                        if (G.pai[j]!=NIL){
                                cout << G.vetor[G.pai[j]] << " " << G.vetor[j]  <<  " " << G.key[j] << endl;
                        }
                }


                cout << endl;

        }

        return 0;

}

