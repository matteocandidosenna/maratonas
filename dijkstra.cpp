#include<bits/stdc++.h>
using namespace std;
int main(){
    int num_nos,num_arestas;
    cin>>num_nos>>num_arestas;
    vector<vector<pair<int,int>>>grafo(num_nos);
    for(int i=0;i<num_arestas;i++){
        int origem,destino,peso;
        cin>>origem>>destino>>peso;
        grafo[origem].push_back({destino,peso});
        //grafo[destino].push_back({origem,peso}); //caso bidirecionado (corrigido typo)
    }
    int no_inicial;
    cin>>no_inicial;
    vector<int>distancias(num_nos,INT_MAX);
    distancias[no_inicial]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>fila_prioridade;
    fila_prioridade.push({0,no_inicial});
    while(!fila_prioridade.empty()){ //Faltava o !
        int distancia_atual=fila_prioridade.top().first;
        int no_atual=fila_prioridade.top().second;
        fila_prioridade.pop();
        if(distancia_atual>distancias[no_atual]){
            continue;
        }
        for(int i=0;i<grafo[no_atual].size();i++){
            int no_vizinho=grafo[no_atual][i].first;
            int peso=grafo[no_atual][i].second;
            int distancia=distancia_atual+peso;
            if(distancia<distancias[no_vizinho]){
                distancias[no_vizinho]=distancia;
                fila_prioridade.push({distancia,no_vizinho});
            }
        }
    }
    for(int i=0;i<num_nos;i++){
        cout<<"nó"<<i<<": ";
        if(distancias[i]==INT_MAX)cout<<"inalçável";
        else cout<<distancias[i];
        cout<<endl;
    }
    return 0;
}