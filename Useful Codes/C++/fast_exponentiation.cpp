#include <iostream>

using namespace std;

// Calculate x^n
int fast_exponentiation(int x, int n)
{
    if (n==0) return 1;
    if (n==1) return x;
    int y = fast_exponentiation(x,n/2);
    if (n % 2 == 0) return y*y;
    else return y*y*x;
}

int main(){

    cout<<fast_exponentiation(2,10)<<endl;
    cout<<fast_exponentiation(2,13)<<endl;
    
    return 0;
}