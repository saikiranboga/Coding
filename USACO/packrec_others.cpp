/*
ID: liuzeyu1
PROB: packrec
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NDEBUG
#include <assert.h>

struct Ans
{
   int w, h, s; // the width, height, square
};

int max ( int a, int b )
{
   if ( a > b )
      return a;
   else
      return b;
}

void test ( int w, int h, struct Ans * ans, int * min, int * k )
{
   assert ( w * h != 0 );
   if ( w * h <= *min )
   {
      *min = w * h;
      ans[*k].w = max (w, h);
      ans[*k].h = *min / ans[*k].w;
      ans[*k].s = *min;
      *k += 1;
   }
}

void sort ( struct Ans * ans, int n )
{
   struct Ans tmp;
   for ( int i = 0; i < n; i++ )
      for ( int j = 0; j < n - i - 1; j++ )
         if ( ans[j].h > ans[j+1].h )
         {
            tmp = ans[j];
            ans[j] = ans[j+1];
            ans[j+1] = tmp;
         }
}

int main()
{
   struct Ans ans[3000];
   int k=0, min=65536;
   int w, h, w1, h1, w2, h2, w3, h3, w4, h4;
   int input[4][2], base[4][2];
   FILE * fin = fopen ("test.in", "r");
   FILE * fout = fopen ("test.out", "w");

   fscanf (fin, "%d%d%d%d%d%d%d%d", *input, *input+1, *(input+1), *(input+1)+1, *(input+2), *(input+2)+1, *(input+3), *(input+3)+1);
   for ( int a = 0; a < 4; a++ )
      for ( int b = 0; b < 4; b++ )
      {
         if ( b ==a )  continue;
         else	for ( int c = 0; c < 4; c++ )
         {
            if ( c == b || c == a )
               continue;
            else	for ( int d = 0; d < 4; d++ )
            {
               if ( d == a || d == b || d == c )
                  continue;
               else
               {
                  memcpy ( base[0], input[a], sizeof(int)*2 );
                  memcpy ( base[1], input[b], sizeof(int)*2 );
                  memcpy ( base[2], input[c], sizeof(int)*2 );
                  memcpy ( base[3], input[d], sizeof(int)*2 );
                  for ( int i = 0; i < 16; i++ )
                  {
                     int tmp;
                     tmp	= (int)(bool)(1 & i); w1 = base[0][tmp]; h1 = base[0][1-tmp];
                     tmp = (int)(bool)(2 & i); w2 = base[1][tmp]; h2 = base[1][1-tmp];
                     tmp = (int)(bool)(4 & i); w3 = base[2][tmp]; h3 = base[2][1-tmp];
                     tmp = (int)(bool)(8 & i); w4 = base[3][tmp]; h4 = base[3][1-tmp];
                     w = w1 + w2 + w3 + w4; // situation 1
                     h = max( h1, max( h2, max(h3, h4) ) );
                     test (w, h, ans, &min, &k);
                     w = max( w1 + w2 + w3, w4 ); // situation 2
                     h = h4 + max( h1, max( h2, h3 ) );
                     test (w, h, ans, &min, &k );
                     w = max( w1 + w2, w3 ) + w4; // situation 3
                     h = max( h4, h3 + max( h1, h2 ) );
                     test (w, h, ans, &min, &k );
                     w = w3 + w4 + max( w1, w2 ); // situation 4 5
                     h = max( h1 + h2, max( h3, h4 ) );
                     test (w, h, ans, &min, &k ); 
					 // situation 6
					 h = max ( h1 + h3, h2 + h4 );
					 if ( h3 > h2 + h4 )  w = max( w1, max( w2, w4 ) + w3 );
					 else if ( h3 > h4 )  w = max( w1 + w2, max( w2, w4 ) + w3 );
					 else if ( h4 < h3 + h1 ) w = max ( w1 + w2, max( w1, w3 ) + w4 );
					 else max( w2, w4 + max( w1, w3 ) );
					 test (w, h, ans, &min, &k );
                  }
               }
            }
         }
      }
   sort (ans, k-1);
   fprintf (fout, "%d\n", min);
#ifndef NDEBUG
			printf( "%d\n", min );
			printf( "k = %d\n", k );
#endif
   for (int i = 0; i < k-1; i++)
   {
      if ( ans[i].s == min )
						{
									if ( ans[i-1].s == min && ans[i-1].h == ans[i].h ) 
												continue;
         fprintf ( fout, "%d %d\n", ans[i].h, ans[i].w );
						}
#ifndef NDEBUG
						printf( "%d %d %d\n", ans[i].h, ans[i].w, ans[i].s );
#endif
   }
   return 0;
}



/* vim: noai:ts=1:sw=3
 */
