#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void longest_common_subsequence(string &a , string &b )
{
    int n = a.size();
    int m = b.size();

    vector<vector<int>> lcs (n+1, vector<int>(m+1,0));
    vector<vector<int>> path (n+1, vector<int>(m+1,0));

    for( int i=1; i<=n ; i ++)
    {
        for (int j =1; j<=m ; j++)
        {
            if(a[i-1]==b[j-1])
            {
                lcs[i][j]= 1+ lcs[i-1][j-1];
                path[i][j]=3;

            }
            else if (lcs[i-1][j] > lcs[i][j-1])
            {
                lcs [i][j] = lcs[i-1][j];
                path[i][j] = 2;
            }

            else
            {   
                lcs[i][j] = lcs[i][j-1];
                path [i][j] =1;

            }
        }
    }

    cout<<lcs[n][m]<<endl;

    string res=" ";

    while (n!=0 && m!=0)
    {
        if (path[n][m]==3)
        {
            res+=string(1,a[n-1]);
            n--;
            m--;
        }
        else if (path [n][m]==2)
            n--;
        else 
            m--;

    }
    
    cout<<string(res.rbegin(),res.rend());
}

 
int main() {

    string a = "ABCBDAB";
    string b = "BDCABAB";

    longest_common_subsequence(a,b);

return 0;
}