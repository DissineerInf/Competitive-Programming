#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int test;
	cin>>test;
	for(int t=0;t<test;t++)
	{
		int n;
		cin>>n;
		
		map<int,int> m;

		for(int i=0; i<n ; i++)
		{
			int temp;
			cin>>temp;
			m[temp]++;
		}

		auto res = minmax_element(m.begin(),m.end(),[](auto a, auto b){return a.second < b.second;});
		int final =abs(res.second->second - res.first->second);

		if (final)
		cout<<final<<endl;
		else
		cout<<-1<<endl;



	
	}
}