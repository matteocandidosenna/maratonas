// Inclui todas as bibliotecas padrão do C++ (prática comum em competições)
#include<bits/stdc++.h>
// Permite usar nomes do padrão C++ sem prefixo (ex: cout em vez de std::cout)
using namespace std;

// Função principal
int main(){
    // Declara variáveis para número de nós (vértices) e arestas
    int num_nos,num_arestas;
    // Lê o número de nós e arestas a partir da entrada padrão
    cin>>num_nos>>num_arestas;

    // Cria o grafo como lista de adjacência:
    // Cada nó tem um vetor de pares (vizinho, peso)
    vector<vector<pair<int,int>>>grafo(num_nos);

    // Lê todas as arestas
    for(int i=0;i<num_arestas;i++){
        int origem,destino,peso;
        // Lê origem, destino e peso da aresta
        cin>>origem>>destino>>peso;
        // Adiciona aresta direcionada (origem -> destino) com peso
        grafo[origem].push_back({destino,peso});
        // Se quiser grafo não-direcionado, descomente a linha abaixo:
        // grafo[destino].push_back({origem,peso});
    }

    // Lê o nó inicial para o algoritmo de Dijkstra
    int no_inicial;
    cin>>no_inicial;

    // Inicializa vetor de distâncias com infinito (INT_MAX)
    vector<int>distancias(num_nos,INT_MAX);
    // A distância do nó inicial para ele mesmo é zero
    distancias[no_inicial]=0;

    // Fila de prioridade mínima (heap) para Dijkstra:
    // Armazena pares (distância, nó) ordenados por menor distância
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>fila_prioridade;
    // Insere o nó inicial na fila com distância zero
    fila_prioridade.push({0,no_inicial});

    // Algoritmo de Dijkstra principal
    while(!fila_prioridade.empty()){
        // Pega o nó com menor distância atual
        int distancia_atual=fila_prioridade.top().first;
        int no_atual=fila_prioridade.top().second;
        // Remove o nó da fila
        fila_prioridade.pop();

        // Se já encontramos um caminho melhor, ignora
        if(distancia_atual>distancias[no_atual]){
            continue;
        }

        // Para cada vizinho do nó atual
        for(int i=0;i<grafo[no_atual].size();i++){
            int no_vizinho=grafo[no_atual][i].first;
            int peso=grafo[no_atual][i].second;
            // Calcula nova distância possível
            int distancia=distancia_atual+peso;

            // Se encontramos um caminho melhor
            if(distancia<distancias[no_vizinho]){
                // Atualiza a distância
                distancias[no_vizinho]=distancia;
                // Insere na fila para processar depois
                fila_prioridade.push({distancia,no_vizinho});
            }
        }
    }

    // Imprime os resultados
    for(int i=0;i<num_nos;i++){
        cout<<"nó"<<i<<": ";
        // Verifica se o nó é inalcançável
        if(distancias[i]==INT_MAX)cout<<"inalçável";
        else cout<<distancias[i];
        cout<<endl;
    }

    // Fim do programa
    return 0;
}
