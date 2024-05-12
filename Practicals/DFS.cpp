#include <iostream>
#include <stack>

using namespace std;

struct Vertex {
    enum Color { WHITE, GREY, BLACK };
    Color color;
    int d; 
    int f; 
    Vertex* p; 
    int index;
};


void DFS(int** adj, int n, int s) {
    Vertex* vertices = new Vertex[n];

    for (int v = 0; v < n; ++v) {
        vertices[v].color = Vertex::WHITE;
        vertices[v].d = -1; 
        vertices[v].f = -1; 
        vertices[v].p = NULL;
        vertices[v].index = v;
    }

    int time = 0; 

    stack<int> S;
    S.push(s);

    cout << "Depth First traversal starting from vertex " << s << " : ";

    while (!S.empty()) {
        int u = S.top();
        S.pop();

        if (vertices[u].color == Vertex::WHITE) {
            vertices[u].color = Vertex::GREY;
            vertices[u].d = ++time;
            cout << vertices[u].index << " ";

            for (int w = n - 1; w >= 0; --w) {
                if (adj[u][w] && vertices[w].color == Vertex::WHITE) {
                    vertices[w].p = &vertices[u];
                    S.push(w);
                }
            }
        }
        vertices[u].color = Vertex::BLACK;
        vertices[u].f = ++time;
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
        for (int j = 0; j < n; ++j) {
            char connected;
            cout << "Is vertex " << i << " connected to vertex " << j << "? (y/n): ";
            cin >> connected;
            if (connected == 'y' || connected == 'Y') {
                adj[i][j] = 1;
            }
        }
    }

    int source_vertex;
    cout << "Enter the source vertex for DFS: ";
    cin >> source_vertex;

    DFS(adj, n, source_vertex);
    cout << endl;

    for (int i = 0; i < n; ++i) {
        delete[] adj[i];
    }
    delete[] adj;

    return 0;
}

