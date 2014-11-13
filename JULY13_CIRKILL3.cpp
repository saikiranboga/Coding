#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
 
#define max 32
#define pr pair<int,int>
#define pl pair<ld,ld>
typedef long double ld;
 
using namespace std;
bool cnr(pr p1,pr p2,pr p3)
{
    ld x1=p1.first,x2=p2.first,y1=p1.second,y2=p2.second,x3=p3.first,y3=p3.second,eq,slope;
    slope=(y2-y1)/(x2-x1);
        eq=y3-x3*slope-y1+x1*slope;
        if(eq==0)
        return true;
        else
        return false;
}
pl calc(pr p1,pr p2,pr p3)
{
        ld x,y,x1=p1.first,x2=p2.first,x3=p3.first,y1=p1.second,y2=p2.second,y3=p3.second,s1,s2;
        s1=(x1-x2)/(y2-y1);
        s2=(x2-x3)/(y3-y2);
        x=(s1*(x1+x2)/2-s2*(x2+x3)/2+(y3-y1)/2)/(s1-s2);
        y=s1*x-s1*(x1+x2)/2+(y1+y2)/2;
        pair<ld,ld> ct;
        ct=make_pair(x,y);
        return ct;
}
 
int main()
{
        int t,n,i,j,k,l,x,y;scanf("%d",&t);
        while(t--)
        {
        vector< pair<int,int> > points(max);
        pair<ld,ld> center;
        ld radius=0,dist=0,ans,ct=0,total;
        scanf("%d",&n);
         for(i=0;i<n;i++)
         {
                scanf("%d %d",&x,&y);
                points[i].first=x;
                points[i].second=y;
         }
         for(i=0;i<n-2;i++)
         {
                for(j=i+1;j<n-1;j++)
                {       for(k=j+1;k<n;k++)
                        {       for(l=0;l<n;l++)
                                {
                                        if(l!=i && l!=j && l!=k)
                                        {
                                                if(!cnr(points[i],points[j],points[k]))
                                                {
                                                 center=calc(points[i],points[j],points[k]);
                                                 radius=sqrt((center.first-points[i].first)*(center.first-points[i].first)+(center.second-points[i].second)*(center.second-points[i].second));
                                                 dist=sqrt((center.first-points[l].first)*(center.first-points[l].first)+(center.second-points[l].second)*(center.second-points[l].second));
                                                 if(dist<=radius)
                                                 ct++;
                                                }
                                        }
                                }
                        }
                }
          }
          total=(n*(n-1)*(n-2))/6;
          ans=ct/(total*(n-3));
          printf("%.7Lf\n",ans);
        }
        return 0;
}
