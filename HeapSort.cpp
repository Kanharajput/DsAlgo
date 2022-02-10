#include<iostream>
using namespace std;

class Heap 
{
  public:
    int size;
    
    
    Heap(int s)
    {
        size = s;
    }
    int *array = new array[]; 
    
    
    int insertArray()
    {
      cout<<"Eneter the values"<<endl;
      for(int i=0; i<size; i++)
        {
           cin>>array[i];
        }
        cout<<"Values inserted"<<endl;
        
        printArray(array);
    }
    
    int left(int index)
    {
       return ((2*index)+1);
    }
    
    int right(int index)
    {
       return ((2*index)+2);
    }
    
    int parent(int index)
    {
       return ((index-1)/2);
    }
    
    void heapify(int index)
    {
      int l, r, smallest = index;
      
      l = left(index);
      r = right(index);    
      smallest = index;
      
      if(l<size and array[l] < array[smallest])
          smallest = l;
        
      if(r<size and array[r] < array[smallest])
          smallest = r;
        
       if(smallest!= index)
        {
          swap(array[smallest],array[index]);
          heapify(smallest);
        }      
    }
    
    void extractMin()
    {
       int temp[size];
       
       for(int i=0; i<size; i++)
       {
          temp[i] = array[0];
          array[0] = array[--size];
          heapify(0); 
       }
       
       printArray(temp);
    }
    
    void printArray(int arr[])
    {
        for(int i=0; i<size; i++)
        {
           cout<<arr[i];
        }
    }    
    
    void heapSort()
    {
      for(int i = size/2; i>-1; i--)
      {
            heapify(i);
      }    
      extractMin();
    }
};


int main()
{
    int size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    Heap heap(size);
    heap.insertArray();
    heap.heapSort();
    return 0;
}