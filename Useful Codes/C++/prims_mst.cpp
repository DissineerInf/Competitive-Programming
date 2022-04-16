#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Graph {

    vector<vector<pair<int,int>>> g;
    vector<int> distance ;
    vector<int> previous ;
    vector<bool>visited ;
    int n;
    int source;
    int inf;
    int mstvalue;

    public:
    Graph(int n)
    {
        this->n=n;
        inf = numeric_limits<int>::max();
        g.resize(n);
        distance.resize(n,inf);
        previous.resize(n,-1);
        visited.resize(n,false);
        source = 0;
        mstvalue =0;

    }


    void add_edge ( int u, int v, int w)
    {
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));

    }

    void prims_mst (int source)
    {
        this->source = source;
        distance[source]=0;

        set<pair<int,int>> s;
        s.insert(make_pair(0,source));

        while(!s.empty())
        {
            auto x = * (s.begin());
            s.erase(x);
            visited[x.second]= true;
            mstvalue += x.first;


            int u = x.second;
            for (auto it : g[u])
            {
                if (visited[it.first] == true ) continue;

                if (distance[it.first] > it.second )
                {
                    s.erase(make_pair(distance[it.first],it.first));
                    distance[it.first]=it.second;
                    s.insert(make_pair(distance[it.first] , it.first));
                    previous[it.first] = x.second;

                }
                
                
            }
        }

        cout<<mstvalue<<endl;
    }

};

int main() {
    int n = 9;

    Graph g(n);

    g.add_edge(0,1,4);
    g.add_edge(0,7,8);
    g.add_edge(1,2,8);
    g.add_edge(1,7,11);
    g.add_edge(2,3,7);
    g.add_edge(2,8,2);
    g.add_edge(2,5,4);
    g.add_edge(3,4,9);
    g.add_edge(3,5,14);
    g.add_edge(4,5,10);
    g.add_edge(5,6,2);
    g.add_edge(6,7,1);
    g.add_edge(6,8,6);
    g.add_edge(7,8,7);
    
    g.prims_mst(0);

return 0;
}