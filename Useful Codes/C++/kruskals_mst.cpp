#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {

    node * parent;
    int rank;
    int size;

    node()
    {
        rank = 0 ;
        size =1;
        parent = this;
    }
};

node * find_method(node * t)
{
    if (t->parent != t )
        t->parent = find_method(t->parent);

    return t->parent;
}

void union_method(node * x, node * y)
{
    node * a = find_method(x);
    node * b = find_method(y); 

    if (a == b) 
    return;

    if (a->rank > b->rank)
    {
        b->parent =a;
        a->size += b->size;
    }

    else if( a->rank < b->rank)
    {
        a->parent = b;
        b->size +=a->size;

    }
    else
    {
        b->parent = a;
        a->size += b->size;
        a->rank +=1;
    }

}

class Graph {

    vector<vector<int>> g;
    int n;
    int cost;
    vector<node *> nodes;

    public:
    Graph(int n)
    {
        this->n=n;
        cost =0;
        for(int i =0;i<n;i++)
        nodes.push_back( new node() );
    }
    void add_edge ( int u, int v, int w)
    {
        g.push_back({u,v,w});
    }

    int kruskal_mst()
    {
        sort(g.begin(),g.end(),[](auto a , auto b){return a[2]<b[2];});

        for (auto it : g)
        {
            if (find_method(nodes[it[0]])== find_method(nodes[it [1]]))
            continue;
            else
            {
                union_method(nodes[it[0]],nodes[it[1]]);
                cost+= it[2];

            }
        }
        return cost;
    }


};
int main() {
    int n =9;
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

    cout<<g.kruskal_mst()<<endl;
    
return 0;
}