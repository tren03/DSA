// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int,vector<int>[]);

int main() {
    int n = 10;
    
    vector<int> graph[n]; // array of vectors
    graph[0] = {1, 2, 3};
    graph[1] = {0, 4, 5};
    graph[2] = {0};
    graph[3] = {0, 6, 7};
    graph[4] = {1};
    graph[5] = {1, 8};
    graph[6] = {3, 9};
    graph[7] = {3};
    graph[8] = {5};
    graph[9] = {6};
    
    bfs(n,graph);
    
    return 0;
    
}

void bfs(int n,vector<int> adj[])
{
    vector<int> vis(n,0);
    queue<int> b;
    b.push(0);
    vis[0] = 1;
    while(!b.empty())
    {
        int top = b.front();
        cout<<top;
        b.pop();
        for(auto i : adj[top])
        {
            if(vis[i] == 0)
            {
                 b.push(i);
                 vis[i] = 1;
            }
            
        }
        
        
        
    }
    
    return;
}

// tc = node goes once in queue and we traverse all neighbours ( degree ) => tc = o(N) + o(2E),,, 2e is total degree of graph