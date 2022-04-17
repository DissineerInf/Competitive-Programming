#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {

    vector<vector<int>> g;
    int n;
    int count;
    vector<int> indegree;

    public:
    Graph(int n)
    {
        g.resize(n);
        this->n=n;
        count =0;
        indegree.resize(n,0);
        
    }


    void add_edge ( int u, int v)
    {
        g[u].push_back(v);
        indegree[v]+=1;
    }

    bool iscycle ()
    {
        queue<int> q;
        for (int i =0 ;i<n ; i++)
        {
            if (indegree[i]==0)
            q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count+=1;

            for (auto it : g[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                q.push(it);

            }

        }

        if (count == n) return false;
        else return true;
    }


};

int main() {

    int n = 4;
    Graph g(n);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 0);
    g.add_edge(3, 3);

    cout<<g.iscycle()<<endl;

return 0;
}

