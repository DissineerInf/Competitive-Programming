#include <iostream>
#include <vector>
#include <set>
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

void union_method(node * a, node * b)
{
    if (find_method(a) == find_method(b)) 
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


int main() {

    int n = 5;
    vector<node *> v;
    for (int i =0;i<n; i++)
    v.push_back(new node());

    
    vector<pair<int,int>> edges = {{0,1},{0,2},{0,3},{1,2},{3,4}};

    bool cycle =false;

    for (auto it : edges)
    {
        if (find_method(v[it.first]) == find_method(v[it.second]))
            cycle = true;
        else
            union_method(v[it.first],v[it.second]);
    }

    cout<<cycle;
    
return 0;
}