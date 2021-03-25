#include <iostream>

using namespace std;

class Node
{
    public:
        int key;
        int data;
        Node *next;
        Node *previous;

        Node()
        {
            key=0;
            data=0;
            next=NULL;
            previous=NULL;
        }
};

class DoubleLinkedList
{
    public:
    Node *head;

    DoubleLinkedList()
    {
        head=NULL;
    }

    Node *nodeExists(int k)
    {
        Node *ptr=head;
        Node *temp=NULL;

        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp=ptr;
                break;
            }
            else
            {
                ptr=ptr->next;
            }
        }
        return temp;
    }

    void appendNode(Node *n)
    {
        Node *ptr=head;
        if(head==NULL)
        {
            head=n;
            cout<<"Node appended successfully "<<endl;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"key is already exists please try a different one "<<endl;
            }
            else
            {
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->previous=ptr;
                cout<<"Node appended "<<endl;
            }
        }
    }

    void prependNode(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node already exists with this key "<<endl;
        }
        else
        {
            n->next=head;
            head->previous=n;
            head=n;
            cout<<"Node prepended "<<endl;
        }
    }

    void insertNode(int k, Node *n)
    {
        Node *ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"There is no node with this key "<<endl;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"There is already a key with this value "<<endl;
            }
            else
            {
                if(ptr->next==NULL)
                {
                    ptr->next=n;
                    n->previous=ptr;
                }
                else
                {
                    n->next=ptr->next;
                    ptr->next=n;
                    n->previous=ptr;
                    n->next->previous=n;
                }
                cout<<"Node inserted "<<endl;
            }
        }
    }

    void deleteNode(int k)
    {
        Node *ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"There is no Node with this key "<<endl;
        }
        else
        {
            if(head->key==k)
            {
                head=head->next;
                cout<<"Node deleted "<<endl;
            }
            else
            {
                if(ptr->next==NULL)
                {
                    ptr->previous->next=NULL;
                    cout<<"Node deleted successfully "<<endl;
                }
                else
                {
                    ptr->previous->next=ptr->next;
                    ptr->next->previous=ptr->previous;
                    cout<<"Node deleted successfully "<<endl;
                }
            }
        }
    }

    void updateNode(int k , int d)
    {
        Node *ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"There is no node with this key "<<endl;
        }
        else
        {
            ptr->data=d;
            cout<<"Node updated "<<endl;
        }
    }

    void printList()
    {
        Node *ptr=head;
        while(ptr!=NULL)
        {
            cout<<"("<<ptr->key<<" "<<ptr->data<<")"<<"----->"<<endl;
            ptr=ptr->next;
        }
    }


};

int main()
{
    DoubleLinkedList dlist;

    int k, key1, data1, option;
    do
    {
        cout<<"0. To exit"<<endl;
        cout<<"1. append Node "<<endl;
        cout<<"2. preped Node "<<endl;
        cout<<"3. insert Node "<<endl;
        cout<<"4. delete Node "<<endl;
        cout<<"5. update Node "<<endl;
        cout<<"6. print List" <<endl;
        cin>>option;
        Node *n1 = new Node();

        switch(option)
        {
            case 0:
                break;

            case 1:
            cout<<"append Node "<<endl;
            cout<<"Enter the key and data "<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            dlist.appendNode(n1);
            break;

            case 2:
            cout<<"preppend Node "<<endl;
            cout<<"Enter the key and data "<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            dlist.prependNode(n1);
            break;

            case 3:
            cout<<"insert Node "<<endl;
            cout<<"Enter the key of Node after which you want insert a new Node "<<endl;
            cin>>k;
            cout<<"Enter the key and data "<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            dlist.insertNode(k,n1);
            break;

            case 4:
            cout<<"delete Node "<<endl;
            cout<<"Enter the key "<<endl;
            cin>>key1;
            dlist.deleteNode(key1);
            break;

            case 5:
            cout<<"update Node "<<endl;
            cout<<"Enter the key and data "<<endl;
            cin>>key1;
            cin>>data1;
            dlist.updateNode(key1,data1);
            break;

            case 6:
            cout<<"Print List "<<endl;
            dlist.printList();
            break;

            default:
                cout<<"Please enter a right option "<<endl;
        }
    }while(option!=0);
}

