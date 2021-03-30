#include<iostream>
using namespace std;

void sortIt(int elements, int arr[])
{
    int i,j,save;
    for(i=1;i<elements;i++)
    {
        save=arr[i];
        for(j=i-1; j>=0 && arr[j]>save; j--)     // we can also use while loop here..
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=save;
    }
}


int main()
{
    int value;
    cout<<"Enter how many values you want to store"<<endl;
    cin>>value;
    int *arr=new int[value];
    cout<<"Enter the values:"<<endl;
    for (int i=0; i<value; i++)
    {
        cin>>arr[i];
    }
    sortIt(value,arr);
    cout<<"Sorted array "<<endl;
    for (int i=0; i<value; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}