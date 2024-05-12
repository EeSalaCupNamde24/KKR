#include <iostream>

#define INF 9999999

using namespace std;

int main() {
    int V; 
    cout << "Enter the number of vertices: ";
    cin >> V;

    int G[V][V];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            G[i][j] = INF;
        }
    }

    cout << "Enter the weight of each edge connecting vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            int weight;
            cout << "Weight from vertex " << i << " to vertex " << j << ": ";
            cin >> weight;
            G[i][j] = G[j][i] = weight; 
        }
    }

    cout << "The adjacency matrix for the graph is:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }

    int no_edge = 0; 
    bool selected[V] = {false}; 
    selected[0] = true; 
    cout << "Edge : Weight" << endl;

    while (no_edge < V - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < V; ++i) {
            if (selected[i]) {
                for (int j = 0; j < V; ++j) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << G[x][y] << endl;
        selected[y] = true;
        ++no_edge;
    }

    return 0;
}

