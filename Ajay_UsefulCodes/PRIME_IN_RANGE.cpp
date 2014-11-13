/* to generate prime between 1 and a given 'n',
  use the "PrimeGenerator" program instead...as it is more efficient.
*/

#include<iostream>
#include<math.h>
using namespace std;

int primesInRange(long long start, long long end, long long answer[])
{
            long long a = start;
            long long b = end;
            int count =0; //no. of primes in this range.
            
            
            long limit = (int)sqrt(b);
            
            int size = b-a+1;
   
            long long* solution = new long long[size];
            for(int i=0; i<size; i++)
            solution[i]= i+a;
   
            long long rem;
            for(long div = 2; div<=limit; div++)
            {
                    
                             rem = b%div;
   
                             start = (size-1)-rem;
                
               
                    for(long j=start; j>=0; j-=div)
                    {
                            if(solution[j]==0 || solution[j]==div)
                            continue;
                                     
                            solution[j] = 0;
                            ++count;
                    }
               }
           
           for(int i=0, j=0; i<size; i++)
           if(solution[i] >1)
           {
                answer[j] = solution[i];
                ++j;
           }
           
           return (size-count);
}

int main()
{
    // 78498 primes inbetween 1 and 1000,000..
    
    long long a, b, solution[100000];
    scanf("%lld",&b);
    
    a= b-300;
    
    time_t t1 = time(NULL);
    int count = primesInRange(a, b, solution); //total primes are count-1 (excluding '1')
    
    time_t t2 = time(NULL);
    cout<<"\nTotal: "<<(count-1)<<"\n";//<<" time: "<<t2-t1<<" f: "<<solution[4];
    
    
    
    cout<<solution[0]<<" ";
    
    
    cin>>a;
    return 0;
}