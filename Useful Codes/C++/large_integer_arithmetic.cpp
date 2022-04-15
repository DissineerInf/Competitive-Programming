#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string large_multiplication(string a , string b)
{
	vector<int> v (a.size()+b.size());

	for (int i = a.size()-1; i>=0 ; i--)
	{
		for (int j= b.size()-1; j>=0;j--)
		{
			int product = (a[i] -'0')* (b[j] -'0');
			int sum = v[i+j+1] + product;
			
			v[i+j]+=sum/10;
			v[i+j+1]=sum%10;

		}
	}

	auto it = find_if(v.begin(),v.end(),[] (int val){return val != 0;});
	v.erase(v.begin(),it);

	string res= "";
	for(auto it = v.begin(); it != v.end();it++)
	res+=char(*it+'0');

	return res;
}

string large_addition (string a, string b)
{
	if (a.size()>b.size())
	{
		b.insert(b.begin(),a.size()-b.size(),'0');
	}
	 
	if(b.size()>a.size())
	{
		a.insert(a.begin(),b.size()-a.size(),'0');
	}

	vector<int> v (a.size()+1);

	for (int i =a.size()-1;i>=0;i--)
	{
		int sum = (a[i] -'0') + (b[i] -'0') + v[i+1];
		v[i] +=sum/10;
		v[i+1]=sum%10;
	}

	auto it = find_if(v.begin(),v.end(),[] (int val){return val != 0;});
	v.erase(v.begin(),it);

	string res= "";
	for(auto it = v.begin(); it != v.end();it++)
	res+=char(*it+'0');

	return res;
	
}

int main() {

	cout<<large_multiplication("22","28")<<endl;
	cout<<large_addition("199","99")<<endl;
	
return 0;
}