#include<iostream>
#include<list>
#include<climits>
using namespace std;
struct no{
	int v;//vertice de destino
	int peso;//peso da aresta
};
void dijkstra(list<no>adj[], int nVertices, int start, int end){
	
	bool intree[10];
	int distance[10];
	int parent[10];
	int aux;
	int vet[10];
	int i,cont=0;//contadores
	int v;//variavel auxiliar
	int dist;//melhor caminho
	int destino;//destino da aresta
	int weight;//caminho entre as arestas
	list<no>::iterator p;//ponteiro auxiliar 
	
	aux=end;
	
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
            if(distance[destino] > distance[v]+weight){
                distance[destino]=distance[v]+weight;
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
	cout<<"Menor caminho: "<<endl;
	i=0;
	while(aux!=start){
		aux=parent[aux];
		vet[i]=aux;
		i++;
	}
		
    for(int j=i-1;j>=0;j--){
		cout<<vet[j]<<" ";
	}
	cout<<end<<endl;
	
	cont=distance[end];			
				
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
	int end;//vertice final
	
	//entrada de dados
	cin>>nVertices;
	while(nVertices<1 || nVertices>10)
		cin>>nVertices;
	cin>>orientado;
	while(orientado!=1 && orientado!=0)
		cin>>orientado;
	cin>>start;
	cin>>end;
	
	//criando uma aresta
	cin>>u>>v>>p;//lendo origem, destino e peso
	while(u!=-1 && v!=-1 && p!=-1){
		cria_aresta(adj,u,v,p,orientado);
		cin>>u>>v>>p;
	}
	
	//montando a árvore
	dijkstra(adj, nVertices, start, end);		
	
	return 0;
}