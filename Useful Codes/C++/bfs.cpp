#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {

    vector<vector<int>> g;
    int n;
    int source;
    vector<bool> visited;

    public:
    Graph(int n)
    {
        g.resize(n);
        this->n=n;
        source = 0;
        visited.resize(n, false);
    }


    void add_edge ( int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void bfs (int source)
    {
        this->source = source;
        visited[source]=true;
        queue<int> q;
        q.push(source);

        while(! q.empty())
        {
            int node = q.front();
            q.pop();
            cout<<node<<" ";

            for (auto it : g[node])
            {
                if (visited[it] == false)
                {
                visited [it]=true;
                q.push(it);
                }
            }
        }
    }


};

int main() {

    int n = 10;

    Graph g(n);

    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(2,5);
    g.add_edge(2,6);
    g.add_edge(2,8);
    g.add_edge(2,9);
    g.add_edge(3,7);
    g.add_edge(4,7);
    g.add_edge(5,7);
    g.add_edge(6,7);
    g.add_edge(8,9);

    g.bfs(1);


return 0;
}