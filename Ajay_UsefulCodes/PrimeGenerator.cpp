/* Using these generated primes, u can further check for new primes or 
  create prime factor of a given number.
*/

#include<iostream>
#include<cmath>
  using namespace std;

  void generatePrime(int n)
  {
   int* numbers = new int[n+1];
   
   for(int i=1; i<=n; i++)
     numbers[i] = i;
   
   int limit = sqrt(n);
   for(int i=2; i<=limit; i++)
   {
     for(int j=i+i; j<=n; j+=i)
       numbers[j] = 0;
   }
   
   int count=0,max=0;
   for(int i=2; i<=n; i++)
   {
     if(numbers[i])
     {
       cout<<i<<" ";
       ++count;
       if(max<i)
         max=i;
     }
     
     
   }
   
   
     cout<<"\ntotal: "<<count<<" max: "<<max; //excluding '1'
   }


   int main()
   {
    int n;
    
    do
    {
      cin>>n;
      time_t t1 = time(NULL);
      generatePrime(n);
      time_t t2 = time(NULL);
      cout<<"\ntime: "<<t2-t1;
    }while(n);
    
    return 0;
    
    
  }