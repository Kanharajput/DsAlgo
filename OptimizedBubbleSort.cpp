#include<iostream>
using namespace std;

void bubbleSort(int elements, int arr[])
{
    int round=0;
    for (int i=0; i<elements; i++)
    {
        round++;
        bool flag=false;
        for (int j=0; j<elements-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=true; 
            }
        }
        if(!flag)
            break;
    }
    cout<<"No. of rounds "<<round;
}

int main()
{
    int value;
    cout<<"Enter the no. of values that you have to store "<<endl;
    cin>>value;
    int *arr=new int[value];
    cout<<"Enter the values "<<endl;
    for (int i = 0; i < value; i++)
    {
        cin>>arr[i];
    }
    bubbleSort(value,arr);
    for (int i = 0; i < value; i++)
    {
        cout<<endl<<arr[i]<<' ';
    }
    return 0;
}