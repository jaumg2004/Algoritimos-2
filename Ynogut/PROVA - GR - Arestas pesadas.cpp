#include <iostream>
#include <list>
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
int arestasPesadas(list<no>adj[], int nVertices, int s, int limiar){
    char state[10];
    int p[10];
    list<int> Q;
    int i, cont=0;//contadores
    int u,v,t; // vars aux para mostrar os vértices
    list<no>::iterator q; // iterador para varrer a lista de adjacências
    
    for(i=0;i<nVertices;i++)
    {
        state[i] = 'u';
        p[i] = -1;
    }    
    state[s] = 'd';
    p[s] = -1;
    Q.push_back(s);
    while(!Q.empty())
    {
        u = *Q.begin();
        Q.pop_front();
        for(q=adj[u].begin();q!=adj[u].end();q++)
        {
            v = q->v;
            if(state[v]=='u')
            {
                state[v] = 'd';
                p[v] = u;
                Q.push_back(v);
            }
            
            t = q->p;
            if(t>limiar){
                cont++;
            }
        }
        state[u] = 'p';
    }
    
    return cont/2;//divide por dois, pois o grafo é não orientado, então as arestas acabam repetindo
}
int main()
{
	list<no> adj[1000];//lista de adjacencias
	int u,v;//origem e destino do vertice
	int orientado=0;//orientação do grafo
	int p;//peso
	int nVertices;//numero de vertices do grafo
	int start;//vertice inicial
	int L;//limiar
	
	//entrada de dados
	cin>>nVertices;
	while(nVertices<1 || nVertices>10)
		cin>>nVertices;
	
	cin>>start;
	
	//criando uma aresta
	cin>>u>>v>>p;//lendo origem, destino e peso
	while(u!=-1 && v!=-1 && p!=-1){
		cria_aresta(adj,u,v,p,orientado);
		cin>>u>>v>>p;
	}
	
	cin>>L;
	
	//chamando a função de largura
	cout<<arestasPesadas(adj, nVertices, start, L)<<" arestas com peso acima de "<<L;
	
	return 0;
}