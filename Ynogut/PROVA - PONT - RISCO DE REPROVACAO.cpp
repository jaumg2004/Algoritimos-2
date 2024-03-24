#include<iostream>
using namespace std;
int main(){
    
    char *p=NULL, *v=NULL;
    int n;//numero de alunos
    int i,cont=0;//contadores auxiliares
    
    cin>>n;//entrando com o número de alunos
    
    v=new char [n];
    
    p=v;
    for(i=0;i<n;i++){//entrando com as notas dos alunos
        cin>>*p;
        switch(*p){
            case 'E':
             cont++;
             break;
            case 'D':
             cont++;
             break;
        }
        p++;
    }
    cout<<cont<<" alunos em risco de reprovacao"<<endl;
    
    //apagando as notas dos alunos
    delete[]v;
    
    return 0;
}