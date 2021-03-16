#include<iostream>

using namespace std;

class Queue
{
    private:
        int front =-1;
        int rear =-1;
        int arr[5];

    public:

        Queue()
        {
            for (int i=0; i<5; i++)
            {
                arr[i]=0;
            }

        }

        bool isEmpty()
        {
            if(front==-1 && rear==-1)
                return true;

            else
                return false;

        }

        bool isFull()
        {
            int k = sizeof(arr)/sizeof(arr[0]);
            if (rear==k-1)
                return true;

            else
                return false;
        
        }

        void enqueue(int val)
        {
            if(isFull())
                cout<<"queue overflow"<<endl;

            else if(isEmpty())
            {
                rear++;
                front++;
                arr[rear] = val;
            }
                
            else
            {
                rear++;
                arr[rear] = val;
            }
        }

        void dequeue()
        {
            if(isEmpty())
                cout<<"Queue Underflow"<<endl;

            else if(front==rear)
            {
                arr[front]=0;
                front=-1;
                rear=-1;
            }

            else
            {
                arr[front] = 0;
                front++;
            }
        }

        void display()
        {
            for(int i=0;i<5;i++)
                cout<<arr[i]<<endl;

        }

        int peek()
        {
            return arr[front];
        }

        void change(int pos,int val)
        {
            arr[pos] = val; 
        }

        int count()
        {
            return(rear-front+1);
        }
};

int main()
{
    Queue q;
    int option;
    int value;
    int position;
    do
    {
        cout<<"1. isEmpty()"<<endl;
        cout<<"2. isFull()"<<endl;
        cout<<"3. enqueue()"<<endl;
        cout<<"4. dequeue()"<<endl;
        cout<<"5. display()"<<endl;
        cout<<"6. change()"<<endl;
        cout<<"7. peek()"<<endl;
        cout<<"8. count()"<<endl;
        cout<<"put your choice here and write 0 to exit"<<endl;
        cin>>option;

        switch (option)
        {
        case 0: break;

        case 1: if(q.isEmpty())
                    cout<<"true"<<endl;

                else
                    cout<<"false"<<endl;
                break;
        
        case 2: if(q.isFull())
                    cout<<"true"<<endl;

                else
                    cout<<"false"<<endl;
            break;
        
        case 3: cout<<"Enqueue function is locked:"<<endl;
                cout<<"please give an value to insert in queue"<<endl;
                cin>>value;
                q.enqueue(value);
            break;

        case 4: cout<<"value is dequeued!!!!!!"<<endl ;
                q.dequeue();
                break;

        case 5: cout<<"displaying the content:"<<endl;
                q.display();
                break;

        case 6: cout<<"Insert position where you want to change"<<endl;
                cin>>position;
                cout<<"Insert the value"<<endl;
                cin>>value;
                q.change(position,value);
                cout<<"value is changed"<<endl;
                break;

        case 7: cout<<"value at the top:";
                cout<<q.peek()<<endl;
                break;

        case 8: cout<<"Total no. of values are: ";
                cout<<q.count()<<endl;
                break;

        default: cout<<"wrong choice please input a valid choice:"<<endl;
            break;
        }

    } while (option!=0);
    
}