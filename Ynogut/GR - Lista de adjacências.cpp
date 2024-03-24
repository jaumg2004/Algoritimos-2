#include<iostream>
#include<list>
using namespace std;
struct no{
	int v;//vertice de destino
	int p;//peso da aresta
};
void cria_aresta(list<no>adj[], int u, int v, int p, int orientado){
	no aux;//var aux p/ inserir as arestas em adj
	aux.v=v;
	aux.p=p;
	adj[u].push_back(aux);//criando aresta
	
	//criando aresta de volta
	if(orientado==0){
	    	aux.v=u;//destino
  	        adj[v].push_back(aux);
		}    
}
int main()
{
	list<no> adj[1000];//lista de adjacencias
	int orientado;//0:nao orientado-1:orientado
	int u,v;//origem e destino do vertice
	int p;//peso
	int nVertices;//numero de vertices do grafo
	int i;//contador
	list<no>::iterator q;//"ponteiro" para varrer as listas de adj[]
	
	cin>>nVertices>>orientado;
	//criando uma aresta
	cin>>u>>v>>p;//lendo origem, destino e peso
	while(u!=-1 && v!=-1 && p!=-1){
		cria_aresta(adj,u,v,p,orientado);
		cin>>u>>v>>p;
	}
	    
	
	//mostrando a lista de adjacencias
	for(i=0;i<nVertices;i++)
		for(q=adj[i].begin();q!=adj[i].end();q++)
			cout<<i<<" "<<q->v<<" "<<q->p<<endl;
	
	
	return 0;
}