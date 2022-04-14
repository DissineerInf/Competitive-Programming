#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int check_char(char c)
{
    if ((c >= 'a'&& c <= 'z') || (c >= 'A'&& c <= 'Z')|| (c >='0' && c <= '9')) return 0;
    
    if (c == '+' || c =='-') return 1;
    
    if (c == '*' || c =='/') return 2;

    if (c == '^' ) return 3;

    return -1;
}

int check_associativity(char c)
{
    if (c=='^') return 1; // right assosiative returns true.
    
    return 0;
}

int do_operation(int op1, int op2, char opr)
{
	if (opr=='+') return op1+op2;
	if (opr=='-') return op1-op2;
	if (opr=='*') return op1*op2;
	if (opr=='/') return op1/op2;
	if (opr=='^') return pow(op1,op2);
	return -1;
}

string prefix_to_postfix(string e)
{
    stack<string> s;

    for (auto it = e.rbegin(); it != e.rend(); it ++)
    {
        if ( check_char(*it) )
        {
            string op1=s.top();
            s.pop();
            string op2 =s.top();
            s.pop();
            s.push(op1 + op2 + *it);
            
        }
        else
        {
            s.push(string(1,*it));
        }
    }

    string res;
    while (!s.empty())
    {
        res+=s.top();
        s.pop();
    }

    return res;
}

string postfix_to_prefix(string e)
{
	stack<string>s;

	for(auto it =e.begin();it !=e.end();it++)
	{
		 if ( check_char(*it) )
        {
            string op2=s.top();
            s.pop();
            string op1 =s.top();
            s.pop();
            s.push(*it+ op1 + op2);
            
        }
        else
        {
            s.push(string(1,*it));
        }

	}
	    string res;
    while (!s.empty())
    {
        res+=s.top();
        s.pop();
    }

    return res;

}

string infix_to_postfix(string e)
{
    stack<char> s;
    string res;
    for (auto it = e.begin();it!=e.end();it++)
    {
        if ( ! check_char(*it))
        res += *it;
		
        else if(check_char(*it)>= 1)
        {
            while(!s.empty() && s.top() !='(' && check_char(s.top()) > check_char(*it) )
            { 
                    res+=s.top();
                     s.pop();
            }

            while( !s.empty() && s.top() !='(' && check_char(s.top()) == check_char(*it) )
            {
                if (check_associativity(*it)) //right associative
					s.push(*it);
				else
				{
					res+=s.top();
					s.pop();
				}
            }

            s.push(*it);

        }    
        else if (*it == '(') s.push(*it);
        else if (*it == ')')
        {
            while(!s.empty()&& s.top()!='(')
            {
                res+=s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty())
    {
        res+=s.top();
        s.pop();
    }
    return res;
}

string postfix_to_infix(string e)
{
	stack<string>s;
	for (auto it = e.begin();it!=e.end();it++)
	{
		if ( !check_char(*it) )
		s.push(string(1,*it));
		else
		{
			string op2 = s.top();
			s.pop();
			string op1 = s.top();
			s.pop();
			s.push("("+op1+*it+op2+")");
		}
	}
	string res;
	while(!s.empty())
	{
		res+=s.top();
		s.pop();
		
	}
	return res;
}

int postfix_evalutation(string e)
{
	stack<int> s;
	for (auto it = e.begin();it!= e.end();it++)
	{
		if (*it>='0' && *it <= '9')
		s.push(*it-'0');
		else
		{
			int op2 = s.top();
			s.pop();
			int op1 =s.top();
			s.pop();
			s.push(do_operation(op1,op2,*it));

		}
	}
	return s.top();
}

int main(){

    // Prefix to postfix
    string prefix1= "++A/*B+CDF*DE";
    string postfix1 =prefix_to_postfix(prefix1);
    cout<<postfix1<<endl;

	// Postfix to prefix
	string postfix2 = "ABCD+*F/+DE*+";
	string prefix2 = postfix_to_prefix(postfix2);
	cout<<prefix2<<endl;

    //  Infix to postfix
    string infix3 = "(((P+Q)*(R+S))/T)+(A*(B+C))";
    string postfix3 = infix_to_postfix(infix3);
    cout<<postfix3<<endl;

	// Infix to prefix
	string infix4="F*((D-B)^(A/C))^(E+G)*H";
	string prefix4= postfix_to_prefix(infix_to_postfix(infix4));
	cout<<prefix4<<endl;

	// Postfix to infix
	string postfix5 = "ABCD+*F/+DE*+";
	string infix5=postfix_to_infix(postfix5);
	cout<<infix5<<endl;

	// Prefix to infix
	string prefix6="**f^^-db/ac+egh";
	string infix6 = postfix_to_infix(prefix_to_postfix(prefix6));
	cout<<infix6<<endl;

	// Postfix evaluation
	string postfix7 = "623+-382/+*2^3+";
	cout<<postfix_evalutation(postfix7)<<endl;

    return 0;
}