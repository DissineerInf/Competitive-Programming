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

	vector<int> v {25,35,32,100,7,89,6,1,45,90,35,35,87,32,6,6,6,6,7};
	
	auto it1 = find(v.begin(),v.end(),7);
	cout<<*it1<<endl;

	auto it2 = find(v.begin(),v.end(),13);
	if(it2 == v.end()) cout<<"NOT FOUND"<<endl;

	auto it3 = find_if(v.begin(),v.end(),[](int val){return val %3 ==0;});
	cout<<*it3<<endl;

	vector<int> pattern1 {89,6,1};

	auto it4 = search(v.begin(),v.end(),pattern1.begin(),pattern1.end());
	cout<<*it4<<endl;

	string s = "THIS IS A GOOD DAY";
	string pattern2 ="OOD";

	auto it5 = search(s.begin(),s.end(),pattern2.begin(),pattern2.end());
	cout<<*it5<<endl;	

	// search for 3 continuos occurance of 6
	auto it6 = search_n(v.begin(),v.end(),3,6);
	cout<<*it6<<endl;

	//  3 odd numbers are continuous. 2 passed as 4th parameter is the value of b
	auto it7= search_n(v.begin(),v.end(),3,2,[](int a, int b){return (a%b!=0);});
	cout<<*it7<<endl;


	sort(v.begin(),v.end());
	display_vector(v);

	bool b1 = binary_search(v.begin(),v.end(), 35);
	cout<<b1<<endl;

	auto p1 = equal_range(v.begin(),v.end(),35);
	cout<<*p1.first<<" -->> "<<*p1.second<<endl;

	auto it8 = lower_bound(v.begin(),v.end(),35);
	cout<<*it8<<endl;

	auto it9 = upper_bound(v.begin(),v.end(),35);
	cout<<*it9<<endl;

	
	// insert element such that it is sorted
	int element = 50;
	auto it10 =lower_bound(v.begin(),v.end(),50);
	v.insert(it10,element);

	display_vector(v);

return 0;
}