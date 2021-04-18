#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
    if(c>='a'&&c<='z' || c<='A'&&c>='Z')
        return true;
    
    else 
        return false;
}

string prefixToPostfix(string prefix)
{
    stack<string> s;
    for( int i=(prefix.length()-1); i>=0; i--)
    {
        if(isOperand(prefix[i]))
        {
            string operand(1,prefix[i]);
            s.push(operand);
        }
        else
        {
            string operand1,operand2,exp;
            operand1=s.top();
            s.pop();
            operand2=s.top();
            s.pop();
            exp=operand1+operand2+prefix[i];
            s.push(exp);
        }
    }
    return s.top();
}

int main()
{
    string postfix_exp,prefix_exp;
    cout<<"Enter the expression" <<endl;
    cin>>prefix_exp;
    cout<<"PREFIX EXPRESSION "<<prefix_exp<<endl;
    postfix_exp=prefixToPostfix(prefix_exp);
    cout<<"POSTFIX EXPRESSION "<<postfix_exp;
    return 0;

}