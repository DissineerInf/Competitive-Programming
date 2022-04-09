#include <iostream>
#include <list>

using namespace std;

void display_list(list<int> &l)
{
    for(auto it =l.begin();it!=l.end();it++)
    cout<<*it<<" ";
    cout<<endl;
}

int main(){

    // Creating the list
    list<int> l1 {10,20,30,40,50};

    // Length of the list
    int length = l1.size();

    // Insert at beginning
    l1.push_front(65);

    // Insert at end
    l1.push_back(5);

    // Insert after position n
    int n1=2; // after 2nd element
    auto it1 = l1.begin();
    advance(it1,n1);
    l1.insert(it1,{1,2,3});

    // Middle element of the list  (if even 2nd element)
    auto it2 =l1.begin();
    advance(it2,l1.size()/2);
    int middle_element = *it2;
    
    // Delete at end
    l1.pop_back();

    // Delete at beginning
    l1.pop_front();

    // Delete nth element
    int n2 =2;  // 3rd element deleted
    auto it3=l1.begin();
    advance(it3,n2);
    l1.erase(it3);

    // Reverse the list
    l1.reverse();

    // Sort the list
    l1.sort();
    
    // Merge two sorted lists
    list<int> l2 {4,4,8,8,12,24,35};
    l1.merge(l2);

    // Remove duplicates
    l1.unique();

    return 0;
}