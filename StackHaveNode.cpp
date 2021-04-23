#include<iostream>
using namespace std;

class Node 
{
    public:        
    int key;
    int data;
    Node *next;


    Node()
    {
        key=0;
        data=0;
        next=NULL;
    }
};

class Stack
{
    public:
    Node *top;
    
    Stack()
    {
        top=NULL;
    }

    bool isEmpty()
    {
        if(top==NULL)
            return true;
        
        else
            return false;
    }

    bool checkIfNodeExist(int k)
    {
        Node *temp=top;
        bool flag=false;
        while(temp!=NULL)
        {
            if(temp->key==k)
            {
                flag=true;
                break;
            }
            else
                temp=temp->next;
        }
        return flag;
    }

    void push(Node *n)
    {
        if(isEmpty())
        {
            top=n;
            cout<<"Node has been pushed "<<endl;
        }
        else if(checkIfNodeExist(n->key))
            cout<<"Please try with a different key "<<endl; 
        
        else
        {
            Node *temp=top;
            top=n;
            top->next=temp;
            cout<<"Node has been pushed "<<endl;
        }
    }

    void pop()
    {
        if(isEmpty())
            cout<<"Stack is underflow "<<endl;
        
        else
        {
            cout<<"("<<top->key<<" "<<top->data<<")"<<endl;
            top=top->next;
            cout<<"Node has been popped "<<endl;
        }
    }

    int count()
    {
        Node *temp=top;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }

    void peek()
    {
        if(isEmpty())
            cout<<"Stack is empty "<<endl;
        
        else
        {
            cout<<"("<<top->key<<" "<<top->data<<")"<<endl;        
        }
    }

    void display()
    {
        Node *temp=top;
        if(temp==NULL)
            cout<<"Stack is empty"<<endl;
        else
        {
            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<" "<<temp->data<<")"<<endl;
                temp=temp->next;
            }
        }
    }
};


int main()
{
    int option,k,d;
    Stack s;

    while(option!=0)
    {
        cout<<"Enter your choices by writing mentioned no. "<<endl;
        cout<<"0. exit "<<endl;
        cout<<"1. isEmpty"<<endl;
        cout<<"2. push "<<endl;
        cout<<"3. pop "<<endl;
        cout<<"4. count "<<endl;
        cout<<"5. display "<<endl;
        cout<<"6. peek "<<endl;
        cin>>option;
        Node *n = new Node();
        
        switch(option)
        {
            case 0: break;

            case 1: if(s.isEmpty())
                        cout<<"Stack is empty"<<endl;
                    else
                        cout<<"Stack is not empty"<<endl; 
                    break;

            case 2: cout<<"Push option is locked"<<endl;
                    cout<<"Enter the key and data"<<endl;
                    cin>>k;
                    cin>>d;
                    n->key=k;
                    n->data=d;
                    s.push(n);
                    break;  
 
            case 3: cout<<"Pop option is locked"<<endl;
                    s.pop();
                    break;
 
            case 4: cout<<s.count()<<" Nodes are inside the stack"<<endl;
                    break;
             
            case 5: s.display();
                    break;
 
            case 6: s.peek(); 
                    break;
             
            default: cout<<"please enter a valid digit"<<endl;
        }
    }
    return 0;
}