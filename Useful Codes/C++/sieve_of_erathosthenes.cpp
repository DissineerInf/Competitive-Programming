#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

 void sieve_of_eratosthenes(int n)
{
    vector<bool> v (n, true);

    for (int i =2 ; i<=n/2; i++)
    {
        if (v[i] == true)
        {
            for (int j=i*2; j<= n; j=j+i)
            v[j]=false;
        }
    }

    for (int i =2; i<=n; i++)
    if (v[i]==true)
    cout<<i<<" ";
    
    cout<<endl;

}

int main() {

    int n =100;
    sieve_of_eratosthenes(100);
    
return 0;
}