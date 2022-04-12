#include <iostream>
#include <cmath>

using namespace std;

int number_of_moves_three_pegs(int disks)
{
    return pow(2,disks)-1;
}

// (source, destination, auxilary, number of disks)
void moves_three_pegs(char s,char d,char a,int n)
{
    if(n==1)
    {
    cout<<s<<" -> "<<d<<endl;
    return;
    }
    
    moves_three_pegs(s,a,d,n-1);
    cout<<s<<" -> "<<d<<endl;
    moves_three_pegs(a,d,s,n-1);
}

// (source, destination, auxilary1, auxilary 2, number of disks)
void moves_four_pegs(char s , char d, char a1, char a2, int n)
{
    if (n==1)
    {
        cout<<s<<" -> "<<d<<endl;
        return; 
    }
    if (n==2)
    {
        cout<<s<<" -> "<<a1<<endl;
        cout<<s<<" -> "<<d<<endl;
        cout<<a1<<" -> "<<d<<endl;
        return;
    }
    moves_four_pegs(s,a2,d,a1,n-2);
    cout<<s<<" -> "<<a1<<endl;
    cout<<s<<" -> "<<d<<endl;
    cout<<a1<<" -> "<<d<<endl;
    moves_four_pegs(a2,d,a1,s,n-2);    
    
}

int main(){
    // Testing
    // number of moves with 3 pegs
    cout<<number_of_moves_three_pegs(3)<<endl<<endl;

    // moves with 3 pegs
    moves_three_pegs('X','Y','Z',3);
   
    cout<<endl<<endl;

    // moves with four pegs 
    moves_four_pegs('W','X','Y','Z',5);

    return 0;
}