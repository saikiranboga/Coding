#include <iostream>
#include <cstdio>

using namespace std;
#define LIMIT 2097200

//which node in input array is at which index in Tree
long long* map; //size will be equal to input array

class Sum_Segment_Tree
{
      long long* node;
      long long size; //number of elements in the array used to construct this tree.
      
      public:
             Sum_Segment_Tree(long long arr[], long long n)
             {
				  node = new long long[LIMIT];
                  size = n;
                  construct_tree(arr,0,n-1,0);
             }
             
             long long construct_tree(long long arr[], long long ss, long long se, long long index)
             {
                  if(ss==se)
                  {
                     node[index] = arr[ss];
					 map[ss] = index;
					 //cout<<"map: "<<ss<<" "<<index<<"\n";
                     return arr[ss];
                  }
                  
                  long long mid = (ss+se)/2;
                  node[index] = get_sum(construct_tree(arr,ss, mid, index*2+1), 
                                        construct_tree(arr,mid+1, se, index*2+2));
                  return node[index];
             }
             
             long long get_sum(long long a, long long b)
             {
                  return (a+b);
             }
             
             long long RMQ(long long qs, long long qe)
             {
                  return find_RMQ(0,size-1,qs,qe,0);
             }
             
             long long find_RMQ(long long ss, long long se, long long qs, long long qe, long long index)
             {
              
                 // If the query range covers the segment of this node
                 if ( qs <= ss && qe >= se)
                     return node[index];
              
                 // If segment of this node is outside the given range
                 if (se < qs || ss > qe)
                     return 0;
                     
                 long long mid = (ss+se)/2;
                 return get_sum(find_RMQ(ss,mid, qs, qe, index*2+1), 
                                 find_RMQ(mid+1,se,qs,qe,index*2+2));
             }
			 
			 void update(long long tree_index, long long change)
			 {
				 while(tree_index > 0)
				 {
					 node[tree_index] += change;
					 tree_index = (tree_index - 1) /2;
				 }
				 
				 node[tree_index] += change;
			 }
};

int main()
{
	long long N, Q;
	cin>>N>>Q;
	
	long long* arr = new long long[N];
	map = new long long[N];
	
	for(long long i=0; i<N; i++)
		cin>>arr[i];
	
	Sum_Segment_Tree Tree(arr,N);
	
	char ch, dummy[10];
	long long a,b;
	
	//scanf("%c",&ch);
	while(Q--)
	{
		cin>>ch>>a>>b;
		if(ch == 'S')
		{
			printf("%lld\n",Tree.RMQ(a,b));
		}
		else if (ch == 'G')
		{
			Tree.update(map[a],b);
		}
		else
		{
			Tree.update(map[a],-b);
		}
	}
	
	return 0;
}