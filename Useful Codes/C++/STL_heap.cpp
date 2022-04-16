#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display_vector(vector<int> &v)
{
	for (auto it = v.begin(); it!= v.end(); it++)
	cout<<*it<<" ";
	cout<<endl;
}

int main() {

    // Max heap 
    vector<int> v1 {25,32,45,7,8,6,6,6,85,64,2,89,95,48,46};
    make_heap (v1.begin(),v1.end());
    display_vector(v1);

    // Min heap  
    vector<int> v2 {25,32,45,7,8,6,6,6,85,64,2,89,95,48,46};
    make_heap(v2.begin(),v2.end(),[](int a , int b) {return a>b;});
    display_vector(v2);
    
    // Push element
    v1.push_back(100);
    push_heap(v1.begin(),v1.end());
    display_vector(v1);

    v2.push_back(1);
    push_heap(v2.begin(),v2.end(),[](int a , int b) {return a>b;});
    display_vector(v2);

    // Pop element
    pop_heap(v1.begin(),v1.end()); 
    v1.pop_back();
    display_vector(v1);

    pop_heap(v2.begin(),v2.end(),[](int a , int b) {return a>b;}); 
    v2.pop_back();
    display_vector(v2);

    // sort in ascending order
    sort_heap(v1.begin(),v1.end());
    display_vector(v1);

    //  Check if it is a heap
    cout<<is_heap(v1.begin(),v1.end())<<endl;
    cout<<is_heap(v2.begin(),v2.end(),[](int a , int b) {return a>b;})<<endl;


return 0;
}