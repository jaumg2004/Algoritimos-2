#include<iostream>
#include<list>
#include<climits>
using namespace std;
struct no{
	int v;//vertice de destino
	int peso;//peso da aresta
};
void prim(list<no>adj[], int nVertices, int start){
	
	bool intree[10];
	int distance[10];
	int parent[10];
	int i,cont=0;//contadores
	int v;//variavel auxiliar
	int dist;//melhor caminho
	int destino;//destino da aresta
	int weight;//caminho entre as arestas
	list<no>::iterator p;//ponteiro auxiliar 
	
	for(i=0;i<nVertices;i++){
		intree[i]=false;
        distance[i]=INT_MAX;
        parent[i]=-1;
	}//inciando tabela
        
    distance[start]=0;
    v=start;
    
    while(intree[v]==false){
        intree[v]=true;
        for(p=adj[v].begin();p!=adj[v].end();p++){
            destino=p->v;
            weight=p->peso;
            if(distance[destino] > weight && intree[destino]==false){
                distance[destino]=weight;
                parent[destino]=v;
                
			}
		}
        v=0;
	    dist=INT_MAX;
	    for(i=0;i<nVertices;i++){
	    	if(intree[i]==false && dist>distance[i]){
	    		dist=distance[i];
	    		v=i;
			}
		}
	}
	cout<<"Arvore Geradora Minima:"<<endl;
	for(i=0;i<nVertices;i++)
		if(i!=start){
			cout<<parent[i]<<" "<<i<<endl;
			cont+=distance[i];
		}
				
	cout<<"Custo: "<<cont<<endl;
	
}
void cria_aresta(list<no>adj[], int u, int v, int p, int orientado){
	no aux;//var aux p/ inserir as arestas em adj
	aux.v=v;
	aux.peso=p;
	adj[u].push_back(aux);//criando aresta
	
	//criando aresta de volta
	if(orientado==1){
	    	aux.v=u;//destino
  	        adj[v].push_back(aux);
    }    
}
int main()
{
	list<no> adj[1000];//lista de adjacencias
	int u,v;//origem e destino do vertice
	int orientado;//orientação do grafo
	int p;//peso
	int nVertices;//numero de vertices do grafo
	int start;//vertice inicial
	
	//entrada de dados
	cin>>nVertices;
	while(nVertices<1 || nVertices>10)
		cin>>nVertices;
	cin>>orientado;
	while(orientado!=1 && orientado!=0)
		cin>>orientado;
	cin>>start;
	
	//criando uma aresta
	cin>>u>>v>>p;//lendo origem, destino e peso
	while(u!=-1 && v!=-1 && p!=-1){
		cria_aresta(adj,u,v,p,orientado);
		cin>>u>>v>>p;
	}
	
	//montando a árvore
	prim(adj, nVertices, start);		
	
	return 0;
}