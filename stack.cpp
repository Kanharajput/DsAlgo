#include<iostream>
#include<string>

using namespace std;

class Stack
{
    private:
        int arr[5];
        int top;

    public:
        Stack()
        {
            top = -1;
            for(int i=0; i<5; i++)   
                arr[i] = 0;
            
        }

        bool isEmpty()
        {
            if(top==-1)
                return true;

            else
                return false;
        }

        bool isFull()
        {
            if(top==4)
                return true;

            else
                return false;
        }

        void push(int val)
        {
            if(isFull())
                cout<<"stack overflow";
            
            else
            {   
                top++;
                arr[top] = val;
            }
        }

        void pull()
        {
            if(isEmpty())
                cout<<"Stack underflow";
            

            else 
            {
                cout<<arr[top];
                arr[top] = 0;
                top--;
            }
        }

        void display()
        {
            for(int i=4; i>=0; i--)
            {   
                cout<<arr[i]<<endl;
            }
        }

        int count()
        {
            return top+1;
        }

        void change(int pos, int val)
        {
            arr[pos] = val;
        }

        int peek()
        {
            return arr[top];
        }
};

int main()
{
    Stack s;
    int option, value, position;

    do
    {   
        cout<<"Please select any of the optin by means of numbers"<<endl;
        cout<<"1. isEmpty()"<<endl;
        cout<<"2. isFull()"<<endl;
        cout<<"3. push()"<<endl;
        cout<<"4. pull()"<<endl;
        cout<<"5. display()"<<endl;
        cout<<"6. count()"<<endl;
        cout<<"7. change()"<<endl;
        cout<<"8. peek()"<<endl;
        cout<<"9. clear screen"<<endl;
        cin>>option;

        switch (option)
        {
        case 1: cout<<s.isEmpty()<<endl;
            break;
        
        case 2: cout<<s.isFull()<<endl;
            break;

        case 3: cout<<"Entered the value to be pushed"<<endl;
                cin>>value;
                s.push(value);
                break;

        case 4: s.pull();
             break;

        case 5: s.display();
            break;

        case 6: cout<<"total values are"<<s.count()<<endl;
            break;

        case 7: cout<<"Entered the position and value to be change respectively"<<endl;
                cin>>position;
                cin>>value;
                s.change(position, value);
            break;

        case 8: cout<<"the most value is "<<s.peek()<<endl;
            break;

        case 9: system("cls");
            break;

        default:
            cout<<"please a type a correct option. "<<endl;


        }
    } while (option!=0);

    return 0;
}