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

string postfixToPrefix(string postfix)
{
    stack<string> s;
    for(int i=0; i<postfix.length(); i++)
    {
        if(isOperand(postfix[i]))
        {
            string operand(1,postfix[i]);
            s.push(operand);
        }
        else
        {
            string operand1,operand2,exp;
            operand1=s.top();
            s.pop();
            operand2=s.top();
            s.pop();
            exp=postfix[i]+operand2+operand1;
            s.push(exp);
        }
    }
    return s.top();
}

int main()
{
    string postfix_exp,prefix_exp;
    cout<<"Enter the expression "<<endl;
    cin>>postfix_exp;
    cout<<"POSTFIX EXPRESSION "<<postfix_exp<<endl;
    prefix_exp=postfixToPrefix(postfix_exp);
    cout<<"PREFIX EXPRESSION "<<prefix_exp;
    return 0;
}