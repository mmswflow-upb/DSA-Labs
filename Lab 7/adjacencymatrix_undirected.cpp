#include <stdio.h>
#include <queue>
#include <iostream>
/// http://www.cplusplus.com/reference/queue/queue/

using namespace std;

template<typename TnodeInfo, typename TedgeInfo>
class Graph {
public:
    int N;
    char** A;
    TnodeInfo* nodeInfo;
    TedgeInfo** edgeInfo;

    Graph(int numNodes) {
        int i, j;

        N = numNodes;

        /// allocate the adjacency matrix
        A = new char* [N]; ///allocated rows
        for (i = 0; i < N; i++)
            A[i] = new char[N]; ///allocated columns

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                A[i][j] = 0;

        // allocate the array with node information
        nodeInfo = new TnodeInfo[N];

        // allocate the matrix of edge information
        edgeInfo = new TedgeInfo * [N];
        for (i = 0; i < N; i++)
            edgeInfo[i] = new TedgeInfo[N];
    }

    void setNodeInfo(int i, TnodeInfo info) {
        nodeInfo[i] = info;
    }

    TnodeInfo getNodeInfo(int i) {
        return nodeInfo[i];
    }

    void addEdge(int i, int j) {
        A[i][j] = A[j][i] = 1;
    }
    void removeEdge(int i, int j) {
        A[i][j] = A[j][i] = 0;
    }

    void setEdgeInfo(int i, int j, TedgeInfo info) {
        edgeInfo[i][j] = edgeInfo[j][i] = info;
    }

    TedgeInfo getEdgeInfo(int i, int j) {
        return edgeInfo[i][j];
    }

    ~Graph() {

        int i;
        for (i = 0; i < N; i++) {
            delete A[i];
            delete edgeInfo[i];
        }
        delete A;
        delete edgeInfo;
        delete nodeInfo;

    }
};

Graph<int, int> g(8);
Graph<int, int> G(9);
char* visited;
char* set;

void dfs(int x) {
    int y;
    printf("%d\n", x);
    visited[x] = 1;

    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs(y);
}
void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
        Q.pop(); ///dequeue
        printf("%d\n", x);
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
                Q.push(y);
            }
    }
}

void exerciseOne() {

    int i;

    for (int i = 0; i < 8; i++) {
        g.setNodeInfo(i, i);
    }

    g.addEdge(1, 3);
    g.addEdge(3, 7);
    g.addEdge(7, 5);
    g.addEdge(7, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 0);

    visited = new char[g.N];
    for (i = 0; i < g.N; i++)
        visited[i] = 0;

    cout << "DFS of 4: \n";
    dfs(4);

    visited = new char[g.N];
    for (i = 0; i < g.N; i++)
        visited[i] = 0;

    cout << "\n\n BFS of 4: \n";
    bfs(4);
}

void displaySetsBipartite(int size) {
    cout << "Set A: ";

    for (int i = 0; i < size; i++) {

        if (set[i] == 'a') {
            cout << i << " ";
        }
    }

    cout << "\nSet B: ";

    for (int i = 0; i < size; i++) {

        if (set[i] == 'b') {
            cout << i << " ";
        }
    }
}

bool isBipartite(int x) {

    int i, z = 0;

    visited = new char[G.N];
    set = new char[G.N];
    for (i = 0; i < G.N; i++) {

        visited[i] = '0';
        set[i] = '_';
    }

    queue<int> qAlg;
    qAlg.push(x);
    visited[z] = 1;
    set[z] = 'a';


    while (!qAlg.empty()) {

        z = qAlg.front();
        qAlg.pop();
        for (i = 0; i < G.N; i++) {

            if (G.A[z][i] == 1) {

                if (set[z] == set[i]) {

                    return false;

                }
                else {

                    if (visited[i] == '0') {
                        qAlg.push(i);
                        visited[i] = 1;

                        if (set[z] == 'a') {
                            set[i] = 'b';
                        }
                        else {
                            set[i] = 'a';
                        }
                    }

                }
            }

        }

    }
    displaySetsBipartite(G.N);
    return true;
}

void exerciseTwo() {


    for (int i = 0; i < 9; i++) {
        G.setNodeInfo(i, i);
    }
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(6, 4);
    G.addEdge(1, 3);
    G.addEdge(4, 7);
    G.addEdge(6, 8);
    G.addEdge(3, 2);
    G.addEdge(7, 8);


    bool isBipart = isBipartite(0);



    cout << "\n\nIs Graph 2 bipartite: " << isBipart << " \n\n";


    G.addEdge(3, 6);
    isBipart = isBipartite(0);
    cout << "\n\nIs Graph 3 bipartite: " << isBipart << "\n";

}

void displayFriends(int x, int maxDeg) {

    int i, z = 0;


    visited = new char[G.N];
    set = new char[G.N];
    for (i = 0; i < G.N; i++) {

        visited[i] = 0;
        set[i] = 0;
    }

    queue<int> qAlg;
    qAlg.push(x);
    visited[z] = 1;
    set[z] = 0;

    while (!qAlg.empty()) {

        z = qAlg.front();
        qAlg.pop();

        if (set[z] <= maxDeg) {
            for (i = 0; i < G.N; i++)
                if (G.A[z][i] && !visited[i]) {

                    visited[i] = 1;
                    qAlg.push(i);
                    set[i] = set[z] + 1;
                }
        }


    }

    for (i = 1; i <= maxDeg; i++) {

        cout << "\n\nFriends of degree " << i << ": ";

        for (z = 0; z < G.N; z++) {

            if (set[z] == i) {
                cout << z << " ";
            }
        }
    }
    cout << "\n\n";
}

void exerciseThree() {

    cout << "\n\nWhose friends are we looking for:  ";
    int usr;
    cin >> usr;

    cout << "\n\nInput maximum degree of friendship:  ";
    int x;
    cin >> x;
    cout << "\n\n";


    for (int i = 0; i < 8; i++) {
        G.setNodeInfo(i, i);
    }
    G.addEdge(0, 1);
    G.addEdge(2, 3);
    G.addEdge(0, 2);
    G.addEdge(0, 6);
    G.addEdge(4, 5);
    G.addEdge(7, 5);
    G.addEdge(6, 4);

    displayFriends(usr, x);

}

int main() {

    //cout << "\n\nEXERCISE ONE: \n\n";
    //exerciseOne();


    //cout << "\n\n\EXERCISE TWO: \n\n";
    //exerciseTwo();

    cout << "\n\n\EXERCISE THREE: \n\n";
    exerciseThree();

}