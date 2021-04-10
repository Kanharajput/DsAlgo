#include<iostream>
using namespace std;

void countSort(int in_arr[], int size, int ran)
{
    int out_arr[size];
    int count_arr[ran];
    for (int i=0; i<ran; i++)
    {
        count_arr[i]=0;
    }
    for (int i=0; i<size; i++)
    {
        ++count_arr[in_arr[i]];
    }
    for (int i=1; i<ran; i++)
    {
        count_arr[i]=count_arr[i]+count_arr[i-1];
    }
    for (int i=0; i<size ; i++)
    {
        out_arr[--count_arr[in_arr[i]]]=in_arr[i];
    }
    for (int i=0; i<size; i++)
    {
        in_arr[i]=out_arr[i];
    }
}

int main()
{
    int value, range;
    cout<<"Enter the size of array "<<endl;
    cin>>value;
    cout<<"Enter the range of array "<<endl;
    cin>>range;
    int arr[value];
    cout<<"Enter the array's values "<<endl;
    for (int i=0; i<value; i++)
    {
        cin>>arr[i];
    }
    countSort(arr,value,range);

    cout<<"After sorting "<<endl;
    for (int i=0; i<value; i++)
    {
        cout<<arr[i]<<" ";
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    return 0;
}