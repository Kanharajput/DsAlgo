#include<iostream>
using namespace std;

void radixSort(int arr[], int elements, int div)
{
    int out_arr[elements];
    int count[10];   // its index start from 0 and end to 9
    for (int i=0; i<10; i++)
    {
        count[i]=0;
    }
    for (int i=0; i<elements; i++)
    {
        ++count[(arr[i]/div)%10];
    }
    for (int i=1; i<10; i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for (int i=elements-1; i>=0; i--)
    {
        out_arr[--count[(arr[i]/div)%10]]=arr[i];
    }
    for (int i=0; i<elements; i++)
    {
        arr[i]=out_arr[i];
    }
}

int main()
{
    int size;
    cout<<"Enter the size of array ";
    cin>>size;
    int *arr = new int[size];
    for (int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    // For finding maximum number
    int max;
    max=arr[0];
    for (int i=1; i<size; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    // This loop work as counting passes for our list
    for (int div=1; max/div>0; div*=10)
    {
        radixSort(arr,size,div); 
    }
    // Print sorted array
    for (int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}