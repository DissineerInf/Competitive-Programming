#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// n >= 2;

 void prime_factorization(int n , vector<pair<int,int>> &v)
{
    
    
    int d =2;
    int k =0;
    while(n%2 ==0)
    {
        n=n/2;
        k++;
    }
    if (k>0) v.push_back(make_pair(d,k));

    for (d=3; d<sqrt(n)+1; d=d+2)
    {
        k=0;
        while(n % d == 0)
        {
            n=n/d;
            k++;
        }
        
        if (k>0) v.push_back(make_pair(d,k));

    }

    if (n>1) v.push_back(make_pair(n,1));

}

int main() {

    int n =  1020;

    vector<pair<int,int>> factors;

    prime_factorization(n,factors);

    for (auto it : factors)
    {
        cout<<it.first<<" : "<<it.second<<endl;
    }
    
return 0;
}