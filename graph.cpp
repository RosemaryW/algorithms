#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
  int numVertex;
  bool isDirected;
  vector< vector<bool> > adjMatrix;

  public:
    Graph (int numVertex, bool isDirected = false) {
      this->isDirected = isDirected;
      this->numVertex = numVertex;
      vector<bool> temp;
      for (int i = 0; i < numVertex; i++) {
        temp.push_back(0);
      }
      
      for (int i = 0; i < numVertex; i++) {
        adjMatrix.push_back(temp);
      }
    }
    
    void addEdge (int m, int n) {
      adjMatrix[m][n] = 1;
      if (!isDirected) {
        adjMatrix[n][m] = 1;
      }
    }

    void printMatrix () {
      for (int i = 0; i < numVertex; i++) {
        for (int j = 0; j < numVertex; j++) {
          cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
      }
    }

    void BFS (int start) {
      bool* visited = new bool[numVertex];
      for (int i = 0; i < numVertex; i++) {
        visited[i] = 0;
      }

      queue<int> q;
      q.push(start);
      visited[start] = 1;

      while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << "->";
        for (int i = 0; i < numVertex; i++) {
          if (!visited[i] && adjMatrix[curr][i]) {
            q.push(i);
            visited[i] = 1;
          }
        }
      }
      cout << endl;
    }

    void DFS (int start) {
      bool* visited = new bool[numVertex];
      for (int i = 0; i < numVertex; i++) {
        visited[i] = 0;
      }
      dfsHelper(visited, start);
      cout << endl;
    }

    vector<int> shortestPath (int a, int b) { // with bidirectional search 
      // return empty vector if path DNE

    }
  
  private:
    void dfsHelper(bool*& visited, int vertex) {
      if (visited[vertex]) {
        return;
      }
      cout << vertex << "->";
      visited[vertex] = 1;
      for (int i = 0; i < numVertex; i++) {
        if (adjMatrix[vertex][i]) {
          dfsHelper(visited, i);
        }
      }
    }
};

int main () {
  Graph graph(6, true);
  graph.addEdge(0, 5);
  graph.addEdge(4, 3);
  graph.addEdge(2, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 4);
  graph.addEdge(1, 5);
  graph.addEdge(3, 1);

  graph.printMatrix();

  graph.BFS(4);
  graph.DFS(4);

  return 0;
}