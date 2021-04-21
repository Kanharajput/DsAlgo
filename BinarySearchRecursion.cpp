// Binary search using recursion.
#include<iostream>
using namespace std;

int binarySearch(int arr[],int search,int start,int end)
{
    int mid;
    if(start<=end)
    {
        mid=((start+end)/2);
        if(arr[mid]==search)
            return mid;

        else if(search<arr[mid])
        {
            binarySearch(arr,search,start,mid-1);
        }
        else
        {
            binarySearch(arr,search,mid+1,end);  
        }
    }
}

int main()
{
    int arr[5],search_it;
    cout<<"Enter the array of size 5 "<<endl;
    for (int i=0;i<5;i++)
    {
        cin>>arr[i];    
    }
    cout<<"Enter the which you want to search "<<endl;
    cin>>search_it;
    search_it=binarySearch(arr,search_it,0,4); // we are taking the index of input no. in search_it because space complexity.
    cout<<"Your input element is at "<<search_it;
    return 0;
}