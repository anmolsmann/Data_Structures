#include <bits/stdc++.h> 
using namespace std; 

int MatrixChainOrder(int p[], int n) 
{ 
    int m[n][n]; 
  
    for (int i = 1; i < n; i++) 
        m[i][i] = 0; 
  
    for (int L = 2; L < n; L++) { 
        for (int i = 1; i < n - L + 1; i++) { 
            int j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (int k = i; k <= j - 1; k++) { 
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
    return m[1][n - 1]; 
} 

int main() 
{ 
    int arr[] = { 1, 2, 3, 4 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, size); 
  
    return 0; 
}


/////

#include <bits/stdc++.h> 
using namespace std; 
  
bool isSafe(int** board, int row, int col, int N) 
{ 
    int i, j; 
  
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  
bool solveNQueenUtil(int** board, int col, int N) 
{ 
    if (col == N) 
        return true; 
  
    for (int i = 0; i < N; i++) { 
        if (isSafe(board, i, col, N)) { 
            board[i][col] = 1; 
  
            if (solveNQueenUtil(board, col + 1, N)) 
                return true; 
  
            board[i][col] = 0; 
        } 
    } 
    return false; 
} 
  
bool solveNQueen(int N) 
{ 
    int** board = new int*[N]; 
    for (int i = 0; i < N; i++) { 
        board[i] = new int[N]; 
        memset(board[i], 0, N * sizeof(int)); 
    } 
  
    if (solveNQueenUtil(board, 0, N) == false) { 
        cout << "Solution does not exist"; 
        return false; 
    } 
  
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            cout << board[i][j] << " "; 
        cout << endl; 
    } 
    return true; 
} 
  
int main() 
{ 
    int N = 4; 
    solveNQueen(N); 
    return 0; 
}

/////

#include <iostream>
#include <list>
#include <vector>
#include <cstring>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void greedyColoring()
    {
        vector<int> result(V, -1);
        result[0] = 0;

        bool available[V];
        memset(available, true, sizeof(available));

        for (int u = 1; u < V; u++)
        {
            list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (result[*i] != -1)
                    available[result[*i]] = false;

            int cr;
            for (cr = 0; cr < V; cr++)
                if (available[cr])
                    break;

            result[u] = cr;
            memset(available, true, sizeof(available));
        }

        for (int u = 0; u < V; u++)
            cout << "Vertex " << u << " ---> Color "
                 << result[u] << endl;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    cout << "Coloring of the graph using greedy algorithm:\n";
    g.greedyColoring();
    return 0;
}

/////

#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum value that can be obtained is " << knapsack(W, wt, val, n) << endl;
    return 0;
}