#include<iostream>
using namespace std;

int algo1(int no)  // This algo takes 3 second to sum 1000000000 numbers, so this is O(n)
{
    unsigned int sum=0;
    for(int i=1;i<=no;i++)
        sum+=i;
    return sum;
}

int algo2(int no)  // this take constant time means O(1)
{
    unsigned int sum;
    sum = (no*(no+1)/2);
    return sum;
}


int main()
{
    int num;
    cout<<"Enter the no. upto which you want to sum "<<endl;
    cin>>num;
    cout<<"Total sum is "<<algo2(num);
    return 0;
}