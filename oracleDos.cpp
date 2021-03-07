#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Recorrido BFS del grafo para determinar si puede ser bipartita
bool bipartiteGraph(vector < vector < int > > graph){
    //array de colores
    bool* colors = new bool[graph.size()];
    //array de booleanos
    bool* visits = new bool[graph.size()];
    //dejar en false el array
    for(int k=0; k<graph.size(); k++){
        visits[k] = false;
    }
    //cola de nodos
    queue<int> cola;
    //inicilizar los valores
    cola.push(0);
    visits[0] = true;
    colors[0] = true;
    int i=0, j=0, count=0;
    while(count < graph.size()){
        //sacar el primer nodo de la cola
        i = cola.front();
        cola.pop();
        //recorrer la fila
        for(j=0; j<graph.size(); j++){
            //si hay una adyacencia
            if(graph[i][j] > 0){
                //si no ha sido recorrido ya
                if(visits[j] == false){
                    //agregar a la cola
                    cola.push(j);
                    //marcarlo como visitado
                    visits[j] = true;
                    //asignarle el color opuesto al actual
                    colors[j] = !colors[i];
                }
                //si hay un enlace a un nodo que ya ha sido recorrido
                else{
                    //si son del mismo color
                    if(colors[i] == colors[j]){
                        //no puede ser bipartita
                        return false;
                    }
                }
            }
        }
        count++;
    }
    return true;
}


int main() {
  int n, m, x, y;
  vector < vector < int > > graph;
  cin >> n;
  cin >> m;
  vector <int> temp;
  for (int i = 0; i < n; i++){
      temp.clear();
      for (int j = 0; j < n; j++){
          temp.push_back(0); 
      }
      graph.push_back(temp);
  }
  
  for (int k = 0; k < m; k++){
      cin >> x;
      cin >> y;
      x--;
      y--;
      graph[x][y] = 1;
  }

  cout << bipartiteGraph(graph);
}