#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Graph {

    vector<vector<int>> g;
    vector<int> distance ;
    vector<int> previous ;
    int n;
    int source;
    int inf;

    public:
    Graph(int n)
    {
        this->n=n;
        inf = numeric_limits<int>::max();
        distance.resize(n,inf);
        previous.resize(n,-1);
        source = 0;

    }


    void display_shortest_distance( )
    {
        for (auto it = distance.begin(); it!= distance.end(); it++)
        {
            if (*it!= inf)
            cout<<*it<<" ";
            else cout<<"NO ";
        }

        cout<<endl;

    }

    void display_path ()
    {
         for(int i = 0 ; i < n;i++)
        {
            if(distance[i]!=inf)
            cout<<distance[i]<< " : ";
            else cout<<"NO";
            
            int start = previous[i];
            vector<int> path;
            while(start != -1)
            {
                path.push_back(start);
                start = previous[start];
            }

           for (auto it = path.rbegin(); it!= path.rend(); it++)
                cout<<*it<<" ";
                
                cout<<endl;
            
        }
    }

    void add_edge ( int u, int v, int w)
    {
        g.push_back({u,v,w});
    }

    void bellmanford_shortest_path (int source)
    {
        this->source = source;
        distance[source]=0;
        bool change =false;

        for (int x =0 ; x < n; x++)
        {
            for (int it = 0; it <g.size() ; it++)
            {
                int u = g[it][0];
                int v = g[it][1];
                int w = g[it][2];

                if (distance[v] > distance[u] + w)
                {
                    distance[v] = distance[u] + w;
                    previous[v]=u;
                    change = true;

                }
            }

            if (change == false) break;
            
        }
        display_shortest_distance();
        display_path();
    }

};

int main() {
    int n = 5;

    Graph g(n);

    g.add_edge(0,1,-1);
    g.add_edge(0,2,4);
    g.add_edge(1,2,3);
    g.add_edge(1,3,2);
    g.add_edge(1,4,2);
    g.add_edge(3,2,5);
    g.add_edge(3,1,1);
    g.add_edge(4,3,-3);
    
    g.bellmanford_shortest_path(0);

return 0;
}