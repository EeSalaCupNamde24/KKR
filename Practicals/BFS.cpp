#include <iostream>
#include <queue>

using namespace std;

struct Vertex {
    enum Color { WHITE, GREY, BLACK };
    Color color;
    int d; 
    Vertex* p; 
    int index; 
};


void BFS(int** adj, int n, int s) {
    Vertex* vertices = new Vertex[n];

    for (int v = 0; v < n; ++v) {
        vertices[v].color = Vertex::WHITE;
        vertices[v].d = -1; 
        vertices[v].p = NULL;
        vertices[v].index = v;
    }

    vertices[s].color = Vertex::GREY;
    vertices[s].d = 0;
    vertices[s].p = NULL;

    queue<int> Q;
    Q.push(s);
    
    cout<<"Breath First traversal starting from vertex  "<<s<< " : ";

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        cout << vertices[u].index<<" ";

        for (int w = 0; w < n; ++w) {
            if (adj[u][w] && vertices[w].color == Vertex::WHITE) {
                vertices[w].color = Vertex::GREY;
                vertices[w].d = vertices[u].d + 1;
                vertices[w].p = &vertices[u];
                Q.push(w);
            }
        }
        vertices[u].color = Vertex::BLACK;
    }

    delete[] vertices;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int** adj = new int*[n];
    for (int i = 0; i < n; ++i) {
        adj[i] = new int[n]{0};
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i != j) {
                char connected;
                cout << "Is vertex " << i << " connected to vertex " << j << "? (y/n): ";
                cin >> connected;
                if (connected == 'y' || connected == 'Y') {
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
            }
        }
    }

    int source_vertex;
    cout << "Enter the source vertex for BFS: ";
    cin >> source_vertex;

    BFS(adj, n, source_vertex);

    return 0;
}

