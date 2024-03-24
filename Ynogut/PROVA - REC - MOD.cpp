#include<iostream>
using namespace std;
int mod(int x, int y){
     if(x>y){
        return mod(x-y,y);
    }
    if(x<y){
        return x;
    }
    if(x==y){
        return 0;
    }
}//função restante
 int main(){
     int x,y;//variaveis que serão utilizadas na função
     
     cin>>x>>y;//entrando com as variaveis
     
     while(x!=-1 && y!=-1){//condição de variaveis
         cout<<mod(x,y)<<endl;//chamando a função de restante e mostrando os valores
         cin>>x>>y;
     }
    return 0;
}