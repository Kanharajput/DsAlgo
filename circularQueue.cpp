#include<iostream>

using namespace std;

class CircularQueue
{
    private:
        int arr[5];
        int rear=-1,front=-1;
        int countval = 0;

    public:
    CircularQueue()
    {
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }

    }

    bool isEmpty()
    {
        if(rear==-1 && front==-1)
            return true;
        
        else    
            return false;
            
    }

    bool isFull()
    {
        if((rear+1)%5==front)
            return true;
        
        else
            return false;
            
    }

    void enqueue(int val)
    {
        if(isFull())
            cout<<"Queue is full";

        else if(isEmpty())
        {
            front=0;
            rear=0;
            arr[front]=val;
            countval++;
        }

        else
        {
            rear = (rear+1)%5;
            arr[rear]=val;
            countval++;
        }
        
    }

    void dequeue()
    {
        if(isEmpty())
            cout<<"Queue is empty";

        else if(front==rear)
        {
            cout<<arr[front];
            arr[front]=0;
            front=-1;
            rear=-1;
            countval--;
        }

        else
        {
            cout<<arr[front];
            arr[front]=0;
            front = (front+1)%5;
            countval--;
        }
    }

    void display()
    {
        for (int i = 0; i<5; i++)
        {
            cout<<"value at "<<i <<" "<<arr[i]<<"\n";
        }
        
    }

    int count()
    {
        return countval;
    }

    int peek()
    {
        return arr[front];
    }

    void change(int pos, int val)
    {
        arr[pos] = val;
    }
    
};

int main()
{
    CircularQueue cq;
    int position, value, option;

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

        case 1: if(cq.isEmpty())
                    cout<<"true"<<endl;

                else
                    cout<<"false"<<endl;
                break;
        
        case 2: if(cq.isFull())
                    cout<<"true"<<endl;

                else
                    cout<<"false"<<endl;
            break;
        
        case 3: cout<<"Enqueue function is locked:"<<endl;
                cout<<"please give an value to insert in queue"<<endl;
                cin>>value;
                cq.enqueue(value);
            break;

        case 4: cout<<"value is dequeued!!!!!!"<<endl ;
                cq.dequeue();
                break;

        case 5: cout<<"displaying the content:"<<endl;
                cq.display();
                break;

        case 6: cout<<"Insert position where you want to change"<<endl;
                cin>>position;
                cout<<"Insert the value"<<endl;
                cin>>value;
                cq.change(position,value);
                cout<<"value is changed"<<endl;
                break;

        case 7: cout<<"value at the top:";
                cout<<cq.peek()<<endl;
                break;

        case 8: cout<<"Total no. of values are: ";
                cout<<cq.count()<<endl;
                break;

        default: cout<<"wrong choice please input a valid choice:"<<endl;
            break;
        }

    } while (option!=0);



}