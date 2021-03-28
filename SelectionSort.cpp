#include <iostream>
using namespace std;

void sortArray(int elements, int sortarr[])
{
    int minimum;
    int i;
    for(i=0;i<elements-1;i++)
    {
        minimum=i;
        // Another for loop to compare values and find the index of minimum element
        for(int j=i+1;j<elements;j++)
        {
            if(sortarr[j]<sortarr[minimum])
            {
                minimum=j;
            }
        }
        if(minimum!=i)
        {
            int temp=sortarr[minimum];
            sortarr[minimum]=sortarr[i];
            sortarr[i]=temp;
        }
    }
}

int main()
{
    int value;
    cout<<"How much element you want to store "<<endl;
    cin>>value;
    int arr[value];
    cout<<"Enter the element "<<endl;
    for(int i=0;i<value;i++)
    {
        cin>>arr[i];
    }
    sortArray(value,arr);
    cout<<"This is the sorted list "<<endl;
    for(int i=0;i<value;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
