#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
    if(c>='a'&&c<='z' || c>='A'&&c<='Z')
        return true;
    
    else
        return false;
}

string prefixToInfix(string prefix)
{
    stack<string> s;
    for (int i=(prefix.length()-1);i>=0;i--)  // we can also manually reverse it, but that's not make any sense.
    {
        if(isOperand(prefix[i]))
        {
            string operand(1,prefix[i]);
            s.push(operand);
        }
        else
        {
            string op1,op2,exp;
            op1=s.top();
            s.pop();
            op2=s.top();
            s.pop();
            exp='('+op1+prefix[i]+op2+')';
            s.push(exp);
        }
    }
    return s.top();
}

int main()
{
    string prefix_exp,infix_exp;
    cout<<"Enter the expression "<<endl;
    cin>>prefix_exp;
    cout<<"PREFIX EXPRESSION "<<prefix_exp<<endl;
    infix_exp=prefixToInfix(prefix_exp);
    cout<<"INFIX EXPRESSION "<<infix_exp;
    return 0;
}