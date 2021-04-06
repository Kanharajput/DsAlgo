#include<iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int temp, pindex=s,pivot=arr[e];
    for (int i=s; i<e; i++)
    {
        if(arr[i]<pivot)
        {
            temp = arr[pindex];
            arr[pindex]=arr[i];
            arr[i]=temp;
            pindex++;
        }    
    }
    temp=arr[pindex];
    arr[pindex]=pivot;
    arr[e]=temp;
    return pindex;
}

void quickSort(int arr[], int s, int e)
{
    if(s<e)
    {
        int p = partition(arr,s,e);
        quickSort(arr,s,p-1);
        quickSort(arr,p+1,e);
    }
}

int main()
{
    int start=0,value;
    cout<<"Enter how much value you want to store "<<endl;
    cin>>value;
    int *arr=new int[value];
    int end=value-1;
    cout<<"Enter the values" <<endl;
    for (int i=0; i<value; i++)
    {
        cin>>arr[i];
    }
    quickSort(arr,start,end);
    cout<<"After sorting "<<endl;
    for (int i=0; i<value; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}