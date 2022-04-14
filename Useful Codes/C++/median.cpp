#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int median (vector<int> v)
{
        auto n1 = v.begin() + (v.size()-1)/2;
        nth_element(v.begin(),n1,v.end());

        return (v[(v.size()-1)/2]);

}


int main() {

    vector<int> v {3,15,1,7,125,31,100,250,62,800,2000} ;
    cout<<median(v)<<endl;
}