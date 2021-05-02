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

class Queue
{
    private:
        Node *front;
        Node *rear;
        int count=0;

    public:
        Queue()
        {
            front=NULL;
            rear=NULL;
        }

        // Node exists with the same key or not.
        bool sameKey(int k)
        {
            bool flag=false;
            Node *temp=front;

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

        // To check whether the list is empty or not.
        bool isEmpty()
        {
            if(rear==NULL && front==NULL)
                return true;
            
            else 
                return false;
        }        

        // Enqueue a node 
        void enqueue(Node *new_node)
        {
            if(sameKey(new_node->key))
                cout<<"Please use a different key. Your key is already exists."<<endl;

            else if(isEmpty())
            {
                rear=new_node;
                front=new_node;
                count++;
                cout<<"Node Enqueue successfully."<<endl;
            }
            else 
            {
                rear->next=new_node;
                rear=new_node;
                count++;
                cout<<"Node Enqueue successfully."<<endl;
            }
        }

        // Dequeue a node 
        void dequeue()
        {
            if(isEmpty())
                cout<<"The list is empty"<<endl; 
            
            else if(rear->key==front->key)   // Dequeueing the last node.
            {   
                cout<<"("<<front->key<<" "<<front->data<<")"<<endl;
                cout<<"Node dequeued"<<endl;
                front=NULL;
                rear=NULL;
                count--;
            }
            else
            {
                cout<<"("<<front->key<<" "<<front->data<<")"<<endl;
                cout<<"Node dequeued"<<endl;
                front=front->next;
                count--;
            }
        }

        //Return the no. of nodes in the list
        int totalNode()
        {
            return count;
        }

        // Return the top most Node data 
        Node *peek()
        {
            return front;
        }

        void display()
        {
            Node *temp=front;
            while(temp!=NULL) 
            {
                cout<<"("<<temp->key<<" "<<temp->data<<")"<<"--->";
                temp=temp->next;
            }
        }
};

int main()
{

    int k,d,option;
    Queue q;
    while(option!=0)
    {
        cout<<endl<<"Enter the choice by follwed numbers"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Total no. of Nodes"<<endl;
        cout<<"4. display"<<endl;
        cout<<"5. peek"<<endl;
        cout<<"6. isEmpty"<<endl;
        cin>>option;

        Node *n = new Node();
        switch(option)
        {
            case 0: cout<<"Closing the programme"<<endl;
                    break;

            case 1: cout<<"Enqueue operation is locked"<<endl;
                    cout<<"Enter the key and data"<<endl;
                    cin>>k;
                    cin>>d;
                    n->key=k;
                    n->data=d;
                    q.enqueue(n);
                    break;

            case 2: cout<<"Dequeue operation is locked"<<endl;
                    q.dequeue();
                    break;

            case 3: cout<<"Total no. of nodes"<<endl;
                    cout<<q.totalNode();
                    break;

            case 4: cout<<"Displaying the content inside the Queue"<<endl;
                    q.display();
                    break;

            case 5: n=q.peek();
                    if(n!=NULL)
                    {   cout<<"Showing the top most node data"<<endl;
                        cout<<n->key<<endl;
                        cout<<n->data<<endl;
                    }
                    else
                        cout<<"NULL"<<endl;
                    break;

            case 6: if(q.isEmpty())
                        cout<<"Queue is empty"<<endl;
                    
                    else 
                        cout<<"Queue is not empty"<<endl;
                    break;

            default:cout<<"Please enter a valid a choice"<<endl;
                    break;
        }
    }    
    return 0;
}