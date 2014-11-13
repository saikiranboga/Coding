#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Point{
public:
  double x;
  double y;
  Point(double xval = 0.0, double yval = 0.0){
    x = xval;
    y = yval;
  }
  double dist(Point *other){
    double xd = x-other->x;
    double yd = y-other->y;
    return sqrt(xd*xd + yd*yd);
  }
};

Point *circleCenter(Point *A,Point *B,Point *C){

  double ydiff_line_a = B->y - A->y;
  double xdiff_line_a = B->x - A->x;

  double ydiff_line_b = C->y - B->y;
  double xdiff_line_b = C->x - B->x;

  Point *center = new Point;

  double a_slope = ydiff_line_a/xdiff_line_a;
  double b_slope = ydiff_line_b/xdiff_line_b;

  center->x = ( a_slope*b_slope*(A->y-C->y) + b_slope*(A->x + B->x) - a_slope*(B->x + C->x) )/(2*(b_slope - a_slope));

  center->y = -1*(center->x - (A->x + B->x)/2)/a_slope + (A->y + B->y)/2;

  return center;
}

Point *circle_vvv(Point *A,Point *B,Point *C){

  Point *center = new Point;
  double w = 1.0;
  Point *v1 = A;
  Point *v2 = B;
  Point *v3 = C;
  double bx = v1->x; double by = v1->y;
  double cx = v2->x; double cy = v2->y;
  double dx = v3->x; double dy = v3->y;
  double temp = cx*cx+cy*cy;
  double bc = (bx*bx + by*by - temp)/2.0;
  double cd = (temp - dx*dx - dy*dy)/2.0;
  double det = (bx-cx)*(cy-dy)-(cx-dx)*(by-cy);
  if (fabs(det) < 1.0e-8) {
    center->x = center->y = 1.0;
    w = 0.0;
    return center;
  }
  det = 1/det;
  center->x = (bc*(cy-dy)-cd*(by-cy))*det;
  center->y = ((bx-cx)*cd-(cx-dx)*bc)*det;
  return center;
}


int main(){

  int t,i,j,k,n,N;
  double x,y;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&N);
    Point *points[31];
    Point *centers[4101];
    double radius[4101];
    for(n=1;n<=30;n++){
      points[n] = new Point;
    }
    for(n=1;n<=4100;n++){
      centers[n] = new Point;
    }
    for(n=1;n<=N;n++){
      scanf("%lf %lf",&x,&y);
      points[n]->x = x;
      points[n]->y = y;
    }
    int circles = 0,combs = 0;
    double yd_ab,yd_bc,yd_ca,xd_ab,xd_bc,xd_ca;
    Point *a,*b,*c;
    for(i=1;i<=N-2;i++)
      for(j=i+1;j<=N-1;j++)
	for(k=j+1;k<=N;k++){

	  combs++;

	  a = points[i];
	  b = points[j];
	  c = points[k];

	  yd_ab = a->y - b->y;
	  xd_ab = a->x - b->x;

	  yd_bc = b->y - c->y;
	  xd_bc = b->x - c->x;

	  yd_ca = c->y - a->y;
	  xd_ca = c->x - a->x;

	  if(xd_ab == 0){
	    if(xd_bc != 0 && xd_ca != 0){
	      circles++;
	      centers[circles] = circle_vvv(points[j],points[k],points[i]);
	      radius[circles] = centers[circles]->dist(a);
	    }
	  }
	  else if(xd_bc == 0){
	    if(xd_ab != 0 && xd_ca != 0){
	      circles++;
	      centers[circles] = circle_vvv(points[j],points[i],points[k]);
	      radius[circles] = centers[circles]->dist(a);
	    }
	  }
	  else if(xd_ca == 0){
	    if(xd_ab != 0 && xd_bc != 0){
	      circles++;
	      centers[circles] = circle_vvv(points[i],points[j],points[k]);
	      radius[circles] = centers[circles]->dist(a);
	    }
	  }
	  else{
	    if(yd_ab == 0 && yd_bc ==0 && yd_ca == 0){
	    }	      	    
	    else{
	      circles++;
	      centers[circles] = circle_vvv(points[i],points[j],points[k]);
	      radius[circles] = centers[circles]->dist(a);
	    }
	  }
	}
    int possib = combs*(N-3);
    double ans;
    double dist,rad;
    Point *cntr;
    int m,num_pts = 0;

    for(n=1;n<=circles;n++){
      cntr = centers[n];
      rad = (double)radius[n];
      for(m=1;m<=N;m++){
	dist = (double)(cntr->dist(points[m]));
	if(fabs(dist-rad) <= 0.000001 || (dist < rad) ){
	  num_pts++;
	}
      }
      num_pts -= 3;
    }
    ans = (double)num_pts/(double)possib;
    printf("%.15lf\n",ans);
  }
}
