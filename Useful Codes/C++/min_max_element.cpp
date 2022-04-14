#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int kth_smallest (vector<int> v , int k)
{
    auto n = v.begin()+(k-1);
    nth_element(v.begin(),n,v.end());

    return v[k-1];
}

int kth_largest(vector<int> v, int k)
{
    auto n = v.begin()+k-1;
    nth_element(v.begin(),n,v.end(),[](int a, int b){return a>b;});
    return v[k-1];
}


int main() {

	vector<int> v1 {20,30,10,15,89,87,12};

	auto minimum = min_element(v1.begin(),v1.end());
	auto maximum = max_element(v1.begin(),v1.end());
	auto minimum_maximum = minmax_element (v1.begin(),v1.end());

	cout<<*minimum<<endl;
	cout<<*maximum<<endl;
	cout<<*minimum_maximum.first<<" "<<*minimum_maximum.second<<endl;

    //  2nd largest and smallest elements
    cout<<kth_smallest(v1,2)<<endl;
    cout<<kth_largest(v1,2)<<endl;


	return 0;
}