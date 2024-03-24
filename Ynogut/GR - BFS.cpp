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
void bfs(list<no>adj[], int nVertices, int s){
	char state[1000]; 
	int pai[1000];
	int u;//aresta
	int v;//vertice
	int cont=1;//contador
	list<int> Q;//lista aux
	list<no>::iterator p;
	
	for(int u=0; u<nVertices; u++){
		if(u!=s){
			state[u]='u';//não descoberto
			pai[u]=-1;//sem pai
		}
	}
	state[s]='d';//descoberto
	pai[s]=-1;
	Q.push_back(s);
	
	while(!Q.empty()){
		u=*Q.begin();
		Q.pop_front();
		for(p=adj[u].begin();p!=adj[u].end();p++){
			v=p->v;
			if(state[v]=='u'){
				state[v]='d';
				pai[v]=u;
				Q.push_back(v);
				cont++;
			}
		}
		state[u]='p';//processado
	}
	if(cont==nVertices){
		cout<<"Conexo"<<endl;
	}
	else
	{
		cout<<"Nao conexo"<<endl;
	}
}
int main()
{
	list<no> adj[1000];//lista de adjacencias
	int u,v;//origem e destino do vertice
	int p;//peso
	int nVertices;//numero de vertices do grafo
	int i;//vertice inicial
	
	cin>>nVertices>>i;
	//criando uma aresta
	cin>>u>>v>>p;//lendo origem, destino e peso
	while(u!=-1 && v!=-1 && p!=-1){
		cria_aresta(adj,u,v,p,i);
		cin>>u>>v>>p;
	}
 	   
	
	//mostrando a lista de adjacencias
	bfs(adj,nVertices,i);
	
	
	return 0;
}