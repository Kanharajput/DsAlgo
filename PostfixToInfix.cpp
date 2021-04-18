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

string postfixToInfix(string postfix)
{
    stack<string> s; 
    for(int i=0;i<postfix.length();i++)
    {
        if(isOperand(postfix[i]))
        {
            string operand(1,postfix[i]); // Converting character to string so we can push it inside stack
            s.push(operand);
        }
        else
        {
            string op1,op2,exp;  // Making two variables to store operators
            op1=s.top();
            s.pop();
            op2=s.top();
            s.pop();
            exp='('+op2+postfix[i]+op1+')';  // Last operator is at top and previous(before that operator) is behing it
            s.push(exp);
        }
    }
    return s.top();
}

int main()
{
    string postfix_exp,infix_exp;
    cout<<"Enter the expression "<<endl;
    cin>>postfix_exp;
    cout<<"POSTFIX EXPRESSION "<<postfix_exp<<endl;
    infix_exp=postfixToInfix(postfix_exp);
    cout<<"INFIX EXPRESSION "<<infix_exp;
    return 0;
}