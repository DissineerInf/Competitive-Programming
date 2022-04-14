#include <iostream>
#include <queue>

using namespace std;

struct thing 
	{
		int id;
		string msg;
		
		thing(int id, string msg) : id(id),msg(msg){}
	};

	class pq_functor
	{
		public:
		bool operator() (thing &a , thing &b)
		{
			return a.id < b.id;
		}
	};


int main(){

	// Priority queue of integers (max = highest priority) 
	priority_queue<int> p1;
	p1.push(3);
	p1.push(7);
	p1.push(2);

	cout<<p1.top()<<endl;
	p1.pop();
	cout<<p1.top()<<endl;

	// Priority queue of integers (min = highest priority) 
	priority_queue <int, vector<int>,greater<int>> p2;
	p2.push(3);
	p2.push(7);
	p2.push(2);

	cout<<p2.top()<<endl;
	p2.pop();
	cout<<p2.top()<<endl;

	// Priority queue for structure
	priority_queue<thing,vector<thing>,pq_functor> p3;

	p3.emplace(3,string("ABC"));
	p3.emplace(2,string("XYZ"));
	p3.emplace(7,string("PQR"));

	cout<<p3.top().msg<<endl;
	p3.pop();
	cout<<p3.top().msg<<endl;

    return 0;
}