#include<iostream>
#include<stack>
#include<algorithm>   // One can use this to reverse a string
using namespace std;

/**  This is my way to reverse a string there are some more 
  *  ways you can check them out if there is problem with time compxity**/

/*
This is the code to reverse the string by algorithm 

reverse(infix.begin(),infix.end());

that's all our infix string is now reverse.....

*/
string reverse(string not_reverse)
{   int i,j;
    string reverse_str;
    for(i=(not_reverse.length()-1),j=0; i>=0,j<(not_reverse.length()); i--,j++)
    {
        reverse_str+=not_reverse[i];
    }
    return reverse_str;
}

// To check incoming character is a Operand..
bool isOperand(char c)
{
    if(c>='a'&& c<='z' || c>='A'&& c<='Z')
        return true;

    else
        return false;
}

//To check the incoming character is Operator or not. 
bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' ||c=='^')
        return true;
    
    else
        return false;
}

// Assigning precedence to operators 
int precedence(char c)
{
    if(c=='^')
        return 3;
    
    else if(c=='*' || c=='/')
        return 2;
    
    else if(c=='+' || c=='-')
        return 1;
    
    else
        return -1;
}

// Method to convert infix expression into prefix expression
string infixToPrefix(stack<char> s,string infix)
{
    string prefix;
    infix=reverse(infix);
    for(int i=0;i<infix.length();i++)
    {
        if(infix[i]=='(')
            infix[i]=')';
        
        else if(infix[i]==')')
            infix[i]='(';
    }

    for(int i=0;i<infix.length();i++)
    {
        if(isOperand(infix[i]))
            prefix+=infix[i];
        
        else if(infix[i]=='(')
            s.push(infix[i]);
        
        else if(infix[i]==')')
        {
            while((!s.empty()) && (s.top()!='('))
            {
                prefix+=s.top();
                s.pop();
            }
            if(s.top()=='(')
            {
                s.pop();
            }
        }
        else if(isOperator(infix[i]))
        {
            if(s.empty())
                s.push(infix[i]);

            else if(precedence(infix[i])>precedence(s.top()))
                s.push(infix[i]);
            
            else if(precedence(infix[i])==precedence(s.top()) && infix[i]=='^')
            {
                while(!s.empty() && precedence(infix[i])==precedence(s.top()))
                {
                    prefix+=s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
            else if(precedence(infix[i])==precedence(s.top()))
                s.push(infix[i]);
            
            else
            {
                while(!s.empty() && precedence(infix[i])<precedence(s.top()))
                {
                    prefix+=s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }   
        }
    }
    // Here we poping and printing all the operators remaining inside the stack 
    while(!s.empty())
    {
        prefix+=s.top();
        s.pop();
    } 
    // Again reverse the expression
    prefix=reverse(prefix);  
    return prefix;
}

int main()
{
    stack<char> stack;
    string infix_exp,prefix_exp;
    cout<<"Enter the expression "<<endl;
    cin>>infix_exp;
    cout<<"INFIX EXPRESSION ---> "<<infix_exp<<endl;
    prefix_exp=infixToPrefix(stack,infix_exp);
    cout<<"PREFIX EXPRESSION ---> "<<prefix_exp;
    return 0;
}