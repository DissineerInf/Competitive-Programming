#include <iostream>
#include <queue>

using namespace std;


int main(){

	queue<int> q;
	
	// Insertion
	q.push(10);
	q.push(20);
	q.push(30);

	//  Deletion
	q.pop();

	// Next Element
	int next = q.front();

	// Last Element
	int last =q.back();

	// check if empty
	bool empty = q.empty();

    return 0;
}