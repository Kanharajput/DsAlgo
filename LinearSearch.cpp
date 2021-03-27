#include <iostream>

using namespace std;

void searchNo(int n, int values, int storage[])
{
    int i=0;
    bool flag=true;
    while(i<values)
    {
        if(storage[i]==n)
        {
            cout<<"Your input matches at "<<i+1<<endl;
            flag=false;
            break;
        }
        else
        {
            i++;
        }
    }
    if(flag)
    {
        cout<<"There is no matches found "<<endl;
    }
}

int main()
{
    int value,find_no;
    cout<<"Enter how many values you want to insert "<<endl;
    cin>>value;
    int *storage = new int[value]; // declaring the array dynamically
    for(int i=0;i<value;i++)
    {
        cout<<"Enter the "<<i+1<<" value "<<endl;
        cin>>storage[i];
    }
    cout<<"Which number you want to search "<<endl;
    cin>>find_no;
    searchNo(find_no,value,storage);
    return 0;
}















