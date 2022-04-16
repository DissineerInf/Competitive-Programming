#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Graph {

    vector<vector<pair<int,int>>> g;
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
        g.resize(n);
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
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }

    void dijkstras_shortest_path (int source)
    {
        this->source = source;
        distance[source]=0;
        
        set<pair<int,int>> s;

        s.insert(make_pair(0,source));

        while(! s.empty())
        {
            auto x = *s.begin();
            s.erase(x);

            for (auto it = g[x.second].begin(); it != g[x.second].end(); it ++ )
            {
                if ( distance[it->first] > distance[x.second] + it->second )
                {
                    s.erase(make_pair(distance[it->first],it->first));
                    distance[it->first] = distance[x.second] + it->second;
                    previous[it->first]=x.second;
                    s.insert(make_pair(distance[it->first],it->first));
                }
            }
                
        }

        display_shortest_distance();
        display_path();
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

    g.dijkstras_shortest_path(0);

return 0;
}