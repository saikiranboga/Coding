#include<iostream>
using namespace std;

int* arr;
int n;
int r;

bool next_combination()
{
    int i,j;
    for(i=r-1, j=0; i>=0; i--,j++)
    if(arr[i] < n-j)
    break;
    
    if(i==-1)
    return false;
    
    ++arr[i];
    
    int k = i+1;
    for( j=1; k<r; k++,j++)
    arr[k] = arr[i]+j;

    return true;
}

void generate_combination()
{

    arr = new int[r];
    
    for(int i=0; i<r; i++)
    arr[i]=i+1;
    
    int count=0;
    do
    {
         for(int i=0; i<r; i++)
         cout<<arr[i]<<" ";
         
         cout<<"\n";
         ++count;
         
    }while(next_combination());
    
    cout<<"Total: "<<count;
}



int main()
{
    n=5;
    r=3;
    
    generate_combination();
    
    //cin>>n;
    return 0;
}
    
    