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

class LinkedList
{
    public:
    Node *head;
    LinkedList()
    {
        head=NULL;
    }

    Node *nodeExists(int k)
    {
        Node *temp=NULL;
        Node *ptr=head;

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
        if(head==NULL)
        {
            head=n;
            cout<<"Node appended"<<endl;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Key already exists please try a different one "<<endl;
            }
            else
            {
                Node *ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Node appended successfully"<<endl;
            }
        }
    }

    void prependNode(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"key already exists please try a different one"<<endl;
        }
        else
        {
            n->next=head;
            head=n;
            cout<<"Node prepended"<<endl;
        }
    }

    void insertNode(int k, Node *n)
    {
        Node *ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"There is no node with this key"<<endl;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"key already exists"<<endl;
            }
            else
            {
                n->next=ptr->next;
                ptr->next=n;
                cout<<"Node inserted successfully"<<endl;
            }
        }
    }

    void deleteNode(int k)
    {
        Node *ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"There is no node with this key"<<endl;
        }
        else
        {
            if(ptr->key==head->key)
            {
                head=head->next;
                cout<<"Node is unlinked"<<endl;
            }
            else
            {
                Node *previous_node=head;
                Node *current_node=head->next;

                while(current_node!=NULL)
                {
                    if(current_node->key==k)
                    {
                        previous_node->next=current_node->next;
                        cout<<"node deleted successfully"<<endl;
                        break;
                    }
                    else
                    {
                        current_node=current_node->next;
                        previous_node=previous_node->next;
                    }
                }
            }
        }
    }

    void updateNode(int k, int d)
    {
        Node *ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"There is no node with this key"<<endl;
        }
        else
        {
            ptr->data=d;
            cout<<"Node updated"<<endl;
        }
    }

    void printList()
    {
        Node *ptr=head;
        while(ptr!=NULL)
        {
            cout<<"("<<ptr->key<<" "<<ptr->data<<")"<<"---->\n";
            ptr=ptr->next;
        }

    }
};


int main()
{
    LinkedList list;
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
        list.appendNode(n1);
        break;

        case 2:
        cout<<"preppend Node "<<endl;
        cout<<"Enter the key and data "<<endl;
        cin>>key1;
        cin>>data1;
        n1->key=key1;
        n1->data=data1;
        list.prependNode(n1);
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
        list.insertNode(k,n1);
        break;

        case 4:
        cout<<"delete Node "<<endl;
        cout<<"Enter the key "<<endl;
        cin>>key1;
        list.deleteNode(key1);
        break;

        case 5:
        cout<<"update Node "<<endl;
        cout<<"Enter the key and data "<<endl;
        cin>>key1;
        cin>>data1;
        list.updateNode(key1,data1);
        break;

        case 6:
        cout<<"Print List "<<endl;
        list.printList();
        break;

        default:
            cout<<"Please enter a right option "<<endl;
    }
    }while(option!=0);
}
































