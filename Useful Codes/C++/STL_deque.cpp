#include <iostream>
#include <deque>

using namespace std;

void display_deque(deque<int> &d)
{
	for (auto it = d.begin();it!=d.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}

int main(){

	deque<int> d {10,20,30,40,50};

	// Acessing the elements
	cout<<d[3]<<endl;
	cout<<d.front()<<endl;
	cout<<d.back()<<endl;

	// Deletion
	d.pop_back();
	d.pop_front();

	display_deque(d);

	// Insertion
	d.push_back(60);
	d.push_front(5);
	
	display_deque(d);

	auto it= d.begin();
	advance(it,2);
	d.insert(it,3,7);
	
	display_deque(d);


    return 0;
}