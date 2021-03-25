#include <iostream>

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

class CircularLinkedList
{
    public:
    Node *head;

    CircularLinkedList()
    {
        head=NULL;
    }

    Node *nodeExists(int k)
    {
        Node *ptr=head;
        Node *temp=NULL;

        if(ptr==NULL)
        {
            return temp;
        }
        else
        {
            do
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
            }while(ptr!=head);
            return temp;
        }
    }

    void appendNode(Node *n)
    {
        Node *ptr=nodeExists(n->key);
        if(head==NULL)
        {
            head=n;
            head->next=head;
        }
        else
        {
            if(ptr!=NULL)
            {
                cout<<"There is a Node with the same key "<<endl;
            }
            else
            {
                ptr=head;
                while(ptr->next!=head)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->next=head;
                cout<<"Node appended "<<endl;
            }
        }
    }

    void prependNode(Node *n)
    {
        Node *ptr=head;
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"The is already used please try a different one "<<endl;
        }
        else
        {
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next=n;
            n->next=head;
            head=n;
            cout<<"Node prepended "<<endl;
        }
    }

    void insertNode(int k, Node *n)
    {
        if(nodeExists(k)==NULL)
        {
            cout<<"There is no node with this key "<<endl;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"There is a node with this key please try a another one "<<endl;
            }
            else
            {
                Node *ptr=head;
                bool flag=true;
                while(ptr->next!=head)
                {
                    if(ptr->key==k)
                    {
                        n->next=ptr->next;
                        ptr->next=n;
                        flag=false;
                        break;
                    }
                    else
                    {
                        ptr=ptr->next;
                    }
                }
                if(flag)
                {
                    n->next=head;
                    ptr->next=n;
                }
                cout<<"Node inserted successfully "<<endl;
            }
        }
    }

    void deleteNode(int k)
    {
        if(nodeExists(k)==NULL)
        {
            cout<<"There is no node with this key "<<endl;
        }
        else
        {
            if(head->key==k)
            {
                Node *ptr=head;
                while(ptr->next!=head)
                {
                    ptr=ptr->next;
                }
                ptr->next=head->next;
                head=head->next;
                cout<<"Deleted "<<endl;

            }
            else
            {
                Node *previous_node=head;
                Node *current_node=head->next;
                while(current_node!=head)
                {
                    if(current_node->key==k)
                    {
                        previous_node->next=current_node->next;
                        cout<<"Node deleted successfully "<<endl;
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
        bool flag=true;
        if(nodeExists(k)==NULL)
        {
            cout<<"There is no node with this key "<<endl;
        }
        else
        {
            Node *ptr=head;
            while(ptr->next!=head)
            {
                if(ptr->key==k)
                {
                    ptr->data=d;
                    cout<<"Node updated "<<endl;
                    flag=false;
                    break;
                }
                else
                {
                    ptr=ptr->next;
                }
            }
            if(flag)
            {
              ptr->data=d;
              cout<<"Node updated "<<endl;
            }
        }
    }

    void printList()
    {   Node *ptr=head->next;
        cout<<"("<<head->key<<" "<<head->data<<")"<<"---->"<<endl;
        while(ptr!=head)
        {
            cout<<"("<<ptr->key<<" "<<ptr->data<<")"<<"---->"<<endl;
            ptr=ptr->next;
        }
    }
};

int main()
{
    int key1, data1, option, k;
    CircularLinkedList clist;
    do
    {
        cout<<"0. exit "<<endl;
        cout<<"1. appnedNode "<<endl;
        cout<<"2. prependNode "<<endl;
        cout<<"3. insertNode "<<endl;
        cout<<"4. deleteNode "<<endl;
        cout<<"5. updateNode "<<endl;
        cout<<"6. printlist "<<endl;
        cin>>option;

        Node *n1 = new Node();
        switch(option)
        {
            case 0:
                break;

            case 1:
                cout<<"append node "<<endl;
                cout<<"Enter the key and data "<<endl;
                cin>>key1;
                cin>>data1;
                n1->data=data1;
                n1->key=key1;
                clist.appendNode(n1);
                break;

            case 2:
                cout<<"prepend node "<<endl;
                cout<<"Enter the key and data "<<endl;
                cin>>key1;
                cin>>data1;
                n1->data=data1;
                n1->key=key1;
                clist.prependNode(n1);
                break;

            case 3:
                cout<<"insert node "<<endl;
                cout<<"Enter the key of node after which you want to insert new node "<<endl;
                cin>>k;
                cout<<"Enter the key and data "<<endl;
                cin>>key1;
                cin>>data1;
                n1->data=data1;
                n1->key=key1;
                clist.insertNode(k,n1);
                break;

            case 4:
                cout<<"delete node "<<endl;
                cout<<"Enter the key"<<endl;
                cin>>key1;
                clist.deleteNode(key1);
                break;

            case 5:
                cout<<"update node "<<endl;
                cout<<"Enter the key and data "<<endl;
                cin>>key1;
                cin>>data1;
                clist.updateNode(key1,data1);
                break;

            case 6:
                cout<<"print list of nodes "<<endl;
                clist.printList();
                break;

            default:
                cout<<"Please enter a valid option "<<endl;
                break;

        }
    }while(option!=0);
    return 0;
}
