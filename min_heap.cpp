#include<iostream>
using namespace std;

class Heap
{
    public:
    int *h_array;
    int h_size;
    int capacity;
    
    Heap(int cap)
    {
        h_array = new int[cap];
        h_size = 0;
        capacity = cap;
    }
       
    bool linearSearch(int key)
    {
       for(int i=0; i<h_size; i++)
         {
            if(h_array[i] == key)
              {
                 return true;
               }
          }
        return false;
     }
    
     void printHeap() 
     {
        for(int i=0; i<h_size; i++)
        {
           cout<<h_array[i]<<endl;
        }    
     }
    
    int parent(int index)
    {
       return ((index-1)/2);
    }
    
     
     void insert(int key)
    {
       if(h_size == capacity)
        {
            cout<<"Heap is full";
            return;
        }
        
        else
        {
            int i;
            i = h_size;
            h_array[i] = key; 
            h_size++;
            
            while(i!=0 and h_array[parent(i)] > h_array[i])
            {
                swap(h_array[parent(i)], h_array[i]);
                i = parent(i);   
           
            }
        }
    }
    
    int left(int index)
    {
       return ((2*index)+1); 
    }
    
    int right(int index)
    {
       return ((2*index)+2); 
    }
    
    void minHeapify(int i)
    {
       int l , r , smallest;
       
       l = left(i);
       r = right(i); 
       smallest = i;
         
       if( l< h_size and h_array[smallest] > h_array[l])
            smallest = l;
        
        if( r<h_size and h_array[smallest] > h_array[r])
            smallest = r;
        
        if(smallest != i)
        {
            swap(h_array[smallest], h_array[i]);
            minHeapify(smallest);        
        }
    }
    
    int extractMin()
    {
       if(h_size == 0)
        {
           cout<<"no node inside their"<<endl;
        }   
        
        if(h_size == 1)
        {
           h_size--;
           return h_array[0];  
        }
        
        else
        {
          int root;
          root = h_array[0];
          h_array[0] = h_array[--h_size];    
          minHeapify(0);
          return root;
        }     
    }
    
    void getMini()
    {
       cout<<"Min is"<<h_array[0]<<endl;
    }
    
    void deleteKey(int i)
    {
       decreaseKey(i);
       extractMin(); 
       cout<<"key deleted successfully"<<endl;
    }
    
    void decreaseKey(int index)
    {
       h_array[index] = INT_MIN;
       
       while(index!=0 and h_array[parent(index)] > h_array[index])
        {
           swap(h_array[parent(index)],h_array[index]);
            index = parent(index);
        } 
    }
};

int main()
{
   int value, option; 
   cout<<"Enter the capacity of Heap"<<endl;
   cin>>value;
   Heap hp(value);
    
   do
   {
      cout<<"1.insert the value"<<endl;
      cout<<"2.Search a value"<<endl;
      cout<<"3.Print the Heap"<<endl;
      cout<<"4.Delete a node"<<endl;
      cout<<"5.getMini"<<endl;
      cout<<"6.Extract the min"<<endl;
      cout<<"1.insert the value"<<endl;
      cout<<"1.insert the value"<<endl;
      cout<<"1.insert the value"<<endl;
      
      cin>>option;         
    
      switch(option)
      {
         case 0: 
            break;
            
         case 1:
            cout<<"Enter the value"<<endl;
            cin>>value;
            hp.insert(value);
            break;
            
         case 2:          
            cout<<"Enter the value to saerch"<<endl;
            cin>>value;
            hp.linearSearch(value);
            break;
            
            case 3: 
              hp.printHeap();
              break;
                
             case 4: 
                cout<<"Enter the index to delete"<<endl;
                cin>>value;
                hp.deleteKey(value);
                break;
            
            case 5:
               hp.getMini();
               break;
            
            case 6:
              cout<<"Extracted min is"<<" ";  
              cout<<hp.extractMin()<<endl;
              break;
            
            default:
              cout<<"please enter a right choice"<<endl;
            break;
      } 
   }while(option!=0); 
        
   return 0;
    
}