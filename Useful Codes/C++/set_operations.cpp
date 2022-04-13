#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void display_vector(vector<int> &v)
{
	for (auto it = v.begin();it!= v.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}

int main() {

	vector<int> v1{10,10,20,30,40,50};
	vector<int> v2 {10,20,60,70,80};

	// If duplicate not needed 
	auto it =unique(v1.begin(),v1.end());
	v1.resize(it - v1.begin());
	display_vector(v1);

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	vector <int >v3(v1.size()+v2.size());
	vector <int >v4(v1.size());
	vector <int >v5(v1.size());
	
	auto it1 = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	auto it2 = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v4.begin());
	auto it3 = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v5.begin());
	v3.resize(it1-v3.begin());
	v4.resize(it2-v4.begin());
	v5.resize(it3-v5.begin());

	display_vector(v3);
	display_vector(v4);
	display_vector(v5);
		
	return 0;
}