#include<iostream>
using namespace std;

void sortByBubble(int elements, int arr[])
{
    for (int i=0; i<elements; i++)
    {
        for (int j=0; j<elements-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }   
}

int main()
{
    int value;
    cout<<"Enter the number of element you want to store "<<endl;
    cin>>value;
    int *arr=new int[value]; 
    cout<<"Enter the elements "<<endl;
    for(int i=0; i<value; i++)
    {
        cin>>arr[i];
    }
    o ytreswa    sortByBubble(value,arr);
    cout<<"Sorted array "<<endl;
    for(int i=0; i<value; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
