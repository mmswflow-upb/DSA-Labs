#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;
template<typename TnodeInfo, typename TedgeInfo>class Graph {
    public:
        int N;
        char **A;
        TnodeInfo *nodeInfo;
        TedgeInfo **edgeInfo;

        Graph(int numNodes) {
            int i, j;

            N = numNodes;

            /// allocate the adjacency matrix
            A = new char*[N]; ///allocated rows
            for (i = 0; i < N; i++)
                A[i] = new char[N]; ///allocated columns

			for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    A[i][j] = 0;

            // allocate the array with node information
            nodeInfo = new TnodeInfo[N];

            // allocate the matrix of edge information
            edgeInfo = new TedgeInfo*[N];
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
            A[i][j] = 1;
            A[j][i] = 1;
        }
        void removeEdge(int i, int j) {
            A[i][j] = 0;
            A[j][i] = 0;
            }

        void setEdgeInfo(int i, int j, TedgeInfo info) {
            edgeInfo[i][j] = info;
            edgeInfo[j][i] = info;
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
            delete [] nodeInfo;
        }
};
template<typename TnodeInfo, typename TedgeInfo>class DiGraph {
public:
    int N;
    char** A;
    TnodeInfo* nodeInfo;
    TedgeInfo** edgeInfo;

    DiGraph(int numNodes) {
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
        A[i][j] = 1;
    }
    void removeEdge(int i, int j) {
        A[i][j] = 0;
    }

    void setEdgeInfo(int i, int j, TedgeInfo info) {
        edgeInfo[i][j] = info;
    }

    TedgeInfo getEdgeInfo(int i, int j) {
        return edgeInfo[i][j];
    }

    ~DiGraph() {
        int i;
        for (i = 0; i < N; i++) {
            delete A[i];
            delete edgeInfo[i];
        }
        delete A;
        delete edgeInfo;
        delete[] nodeInfo;
    }
};
Graph<int, int> g(8);
DiGraph<int, int> g2(4);
char* visited;

void dfs(int x) {
    int y;
   
    visited[x] = 1;
    cout << g.getNodeInfo(x) << " ";
    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs(y);
}

void dfs_noOut(int x) {
    int y;

    visited[x] = 1;
    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs_noOut(y);
}
void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
		Q.pop(); ///dequeue
        
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
               Q.push(y);
            }
    }
}

void dfs2(int x) {
    int y;

    visited[x] = 1;
    cout << g2.getNodeInfo(x) << " ";
    for (y = 0; y < g.N; y++)
        if (g2.A[x][y] && !visited[y])
            dfs2(y);
    
}

void bfs2(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
        Q.pop(); ///dequeue
        cout << g2.getNodeInfo(x) << " ";

        for (y = 0; y < g2.N; y++)
            if (g2.A[x][y] && !visited[y]) {
                visited[y] = 1;
                Q.push(y);
            }
    }
    cout << "\n\n";
}

int getDegree(int nodeIndex) {

    int deg = 0;
    int z = 0;

    for (z = 0; z < g.N; z++) {
        if (g.A[nodeIndex][z]) {
            deg++;
        }
    }

    return deg;

}

bool isConnected() {
    int i,z;

    visited = new char[g.N];

    for (i = 0; i < g.N; i++) {

        visited[i] = 0;
    }

    dfs(0);

    for (i = 0; i < g.N; i++) {
        if (!visited[i]) {

            return false;
        }
    }

    return true;

}

void exerciseOne() {

    for (int i = 0; i < 4; i++) {

        g.setNodeInfo(i,i+1);
    }

    g.addEdge(0,1);
    g.addEdge(0, 2);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2, 3);

    


    if (isConnected()) {

        cout << "Graph is connected.\n\n";

    }
    else {


        cout << "Graph is not connected.\n\n";
    }


}

bool isHamiltonian() {

    if (g.N == 2) {
        if (g.A[0][1]) {
            return true;
        }
        return false;
    }
    else if (g.N < 2) { return false; }

    int i, z;

    for (i = 0; i < g.N; i++) {

        if (getDegree(i) < g.N / 2) {
            return false;
        }
    }
    return true;
}

void exerciseTwo() {

    for (int i = 0; i < g.N; i++) {
        g.setNodeInfo(i, i+1);
    }
  
    g.addEdge(0,1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    cout << "Is the first graph hamiltonian: " << isHamiltonian() << "\n\n";

    g.addEdge(2, 3);
    g.addEdge(1,3);

    cout << "Is the second graph hamiltonian: " << isHamiltonian() << "\n\n";
}

bool isEulerian() {

    int i = 0;

    if (!isConnected()) {
        return false;
    }

    for (i; i < g.N; i++) {
        if (getDegree(i) % 2 != 0) {
            return false;
        }
    }

    return true;

}

void exerciseThree() {

    for (int i = 0; i < g.N; i++) {
        g.setNodeInfo(i, i);
    }

    g.addEdge(0,1);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout << "Is the graph Eulerian: " << isEulerian() << "\n\n";

    g.removeEdge(0, 1);

    cout << "Is the graph Eulerian: " << isEulerian() << "\n\n";

}

void exerciseFour() {

    //Testing the directed graph implementation.

    int i;

    visited = new char[g2.N];

    for (i = 0; i < g2.N; i++) {

        visited[i] = 0;
        g2.setNodeInfo(i, i + 1);
    }
    g2.addEdge(0,1);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(2, 3);
    g2.addEdge(3, 2);
    g2.addEdge(1, 3);

    dfs2(0);
    cout << "\n\n";
    
    for (i = 0; i < g2.N; i++) {

        visited[i] = 0;
      
    }

    bfs2(0);


}

void exerciseFive() {

   //Finding components of undirected graph
    int i,k;
    k = 0;
    visited = new char[g.N];

    for (i = 0; i < g.N; i++) {

        visited[i] = 0;
        g.setNodeInfo(i, i);
    }

    g.addEdge(0,1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    for (i = 0; i < g.N; i++) {

        if (!visited[i]) {

            cout << "Connected Component " << ++k << ": ";
            dfs(i);
            cout << "\n\n";
        }
    }
 }





int main() {
    

   //cout << "EXERCISE ONE: \n\n";
   //exerciseOne();

   //cout << "EXERCISE TWO: \n\n";
   //exerciseTwo();

   //cout << "EXERCISE THREE: \n\n";
   //exerciseThree();

   //cout << "EXERCISE FOUR: \n\n";
   //exerciseFour();

    cout << "EXERCISE FIVE: \n\n";
    exerciseFive();
}