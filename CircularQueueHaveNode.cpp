#include<iostream>
using namespace std;

class Node 
{
    public:
    int key;
    int data;
    Node* next;

    Node()
    {
        key=0;
        data=0;
        next=NULL;
    }
};

class CircularQueue
{
    public:
    Node* front=NULL;
    Node* rear=NULL;
    int count=0;

    bool nodeExists(int k)
    {
        bool flag=false;
        Node* temp = front;
        do
        {
            if(temp->key==k)
            {
                flag=true;
                break;
            }

            else 
                temp=temp->next;
    
        } while(temp!=front);
        return flag;
    }

    bool isEmpty()
    {
        if(rear==NULL && front==NULL)
            return true;
        
        else 
            return false;
    }

    void enqueue(Node *n)
    {
        if(isEmpty())  //Enqueueing the first node in the list.
        {
            front=n;
            rear=n;
            rear->next=front;
            cout<<"Node Enqueued successfully"<<endl;
            count++;
        }

        else if(nodeExists(n->key))
            cout<<"Please use a different key"<<endl;

        else 
        {
            rear->next=n;      // Some nodes are already there in the list.
            rear=n;
            rear->next=front;
            cout<<"Node Enqueued successfully"<<endl;
            count++;
        }
    }

    Node *dequeue()
    {
        Node *temp=front;
        if(isEmpty())
            cout<<"Queue is empty"<<endl;
        
        else if(front->key==rear->key)
        {
            front=NULL;
            rear=NULL;
            count--; 
        }
        else 
        {
            while(temp->next!=front)
            {
                temp=temp->next;
            }
            temp->next=front->next;
            temp=front;     // storing front node address so we can use return data
            front=front->next;
            count--;
        }  
        return temp;
    }

    void display()
    {
        Node *temp=front;
        if(isEmpty())
            cout<<"Queue is empty"<<endl;
        
        else
        {
            do
            {
                cout<<"("<<temp->key<<" "<<temp->data<<")--->";
                temp=temp->next;
            } while (temp!=front);
        }
    }

    Node *peek()
    {
        return front;
    }






};


int main()
{
    int k,d,option;
    CircularQueue cq;
    
    while(option!=0)
    {
        cout<<endl<<"Choose from the options given"<<endl;
        cout<<"1. isEmpty"<<endl;
        cout<<"2. Enqueue"<<endl;
        cout<<"3. Dequeue"<<endl;
        cout<<"4. display"<<endl;   
        cout<<"5. No of nodes"<<endl;
        cout<<"6. peek"<<endl;
        cin>>option;

        Node *n = new Node();  // Making a node dynamically
        switch(option)
        {
        case 0: break;

        case 1: if(cq.isEmpty())
                    cout<<"Queue is empty"<<endl;
                else 
                    cout<<"Queue is not empty"<<endl;
            
                break;
        
        case 2: cout<<"Enqueue operation is locked"<<endl;
                cout<<"Enter the key and data"<<endl;
                cin>>k>>d;
                n->data=d;
                n->key=k;
                cq.enqueue(n);
                break; 

        case 3: n=cq.dequeue();
                cout<<"Node dequeued"<<endl;
                cout<<"("<<n->key<<" "<<n->data<<")"<<endl;
                break;

        case 4: cq.display();
                break;

        case 5: cout<<"Number of Nodes "<<cq.count<<endl;
                break;

        case 6: n=cq.peek();
                if(n!=NULL)
                    cout<<"("<<n->key<<" "<<n->data<<")"<<endl;   
                else
                    cout<<"Queue is empty"<<endl;
                break;

        default: cout<<"Please enter a valid choice"<<endl;
                break;
        }
    }
    return 0;
}