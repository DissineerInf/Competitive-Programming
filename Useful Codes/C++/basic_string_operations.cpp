#include <iostream>
#include <algorithm>

using namespace std;

// Returns the reverse of the string
string reverse_string(string s)
{
    return string(s.rbegin(),s.rend());
}

// Converts the string to upper case
void string_toupper(string &s)
{
    transform(s.begin(),s.end(),s.begin(),::toupper);
}

// Converts the string to lower case
void string_tolower(string &s)
{
    transform(s.begin(),s.end(),s.begin(),::tolower);
}

int main(){

    // Testing
    
    //Reverse
    string s1 = "This is a test string";
    s1 = reverse_string(s1);
    cout<<s1<<endl;

    // Uppercase
    string s2 = "This is a test string";
    string_toupper(s2);
    cout<<s2<<endl;

    //Lowercase
    string s3 = "THIS IS a test STRING";
    string_tolower(s3);
    cout<<s3<<endl;

    return 0;
}