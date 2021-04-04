#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r, int elements)
{
    int k=l, j=mid+1, i=l, temp[elements];
    while(i<=mid && j<=r)     // check between two array parts and put according to our requirement
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid)  //Transfer the whole array to temp if another one is empty.
    {
        temp[k]=arr[i];
        k++;
        i++;
    } 
    while(j<=r)    //Transfer the whole array to temp if another one is empty.
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
    for (int a=l; a<=r; a++)   // copying data from temp array to our real array
    {
        arr[a]=temp[a];
    }
}

void mergeSort(int arr[], int l, int r, int elements)
{
    int mid;
    if(l<r)
    {
        mid = (l+r)/2;
        mergeSort(arr,l,mid,elements); // for left side or left halves    
        mergeSort(arr,mid+1,r,elements); // for right halves
        merge(arr,l,mid,r,elements);   // merge and sort the array parts
    }
}

int main()
{
    int value, left=0, right=-1;
    cout<<"Enter how much value you want to store "<<endl;
    cin>>value;
    int *arr=new int[value];
    cout<<"Enter the values" <<endl;
    for (int i=0; i<value; i++)
    {
        cin>>arr[i];
        right++;
    }
    mergeSort(arr,left,right,value);
    cout<<"After sorting "<<endl;
    for (int i=0; i<value; i++)
    {
        cout<<arr[i]<<" ";
    }
}
// It's time complexity is O(nlogn)