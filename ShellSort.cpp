#include<iostream>
using namespace std;

shellSort(int arr[], int elements)
{
    int gap;
    gap=elements/2;
    for(gap; gap>0; gap/=2)  // It will check how much time we have to run our algo.... passes
    {
        /* Selecting gap index value and then go back with gap positions 
          and if we find larger value than replace */
        for(int j=gap; j<elements; j++)   
        {
            int temp = arr[j];
            int i;
            for(i=j; i>=gap && arr[i-gap]>temp; i-=gap)
            {
                arr[i]=arr[i-gap];
            }
            arr[i]=temp;
        }
    }
}

int main()
{
    int size;
    cout<<"Enter the size of array "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the array values"<<endl;
    for (int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    shellSort(arr,size);
    cout<<"After sorting"<<endl;
    for (int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}