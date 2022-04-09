#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> s1;

    // Check if stack empty
    bool b1 = s1.empty();

    // Push
    s1.push(10);
    s1.push(20);

    // Get top element
    int element = s1.top();

    // Pop
    s1.pop();

    //  Number of elements
    int count = s1.size();

    return 0;
}