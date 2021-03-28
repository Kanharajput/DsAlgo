#include <iostream>
using namespace std;

void binSearch(int find_it,int totval,int arr[])
{
    int midpoint,start,endpoint;
    start=0;
    midpoint=-1;
    endpoint=totval-1;
    while(start<=endpoint) // my logic is arr[midpoint]!=find_it
    {
        midpoint=(start+endpoint)/2;  // some sites and developer use midpoint = start+(start-endpoint)/2.
        if(arr[midpoint]==find_it)
        {
            cout<<"Find your value at "<<midpoint+1;
            break;
        }
        else
        {
            if(arr[midpoint]<find_it)
            {
                start=midpoint+1;
            }
            else
            {
                endpoint=midpoint-1;
            }
        }
    }
    if(arr[midpoint]!=find_it)
    {
        cout<<"No match found "<<endl;
    }
}

int main()
{
    int values,find_no;
    cout<<"Enter the no. values you want to store in array"<<endl;
    cin>>values;
    int arr[values];
    cout<<"Enter the array but in ascending order"<<endl;
    for(int i=0;i<values;i++)
    {
        cin>>arr[i];
    }
    cout<<"Which no you want find"<<endl;
    cin>>find_no;
    binSearch(find_no,values,arr);
    return 0;
}
