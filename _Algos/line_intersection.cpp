#include<iostream>
#include<cstdio>

using namespace std;

struct Point
{
	double x;
	double y;
};

//finds intersection given equations of line
Point find_intersection(int A1, int B1, int C1, int A2, int B2, int C2)
{
	Point intersection;
	
	double det = A1*B2 - A2*B1;
    if(det == 0){
        //Lines are parallel
    }else{
        intersection.x = (B2*C1 - B1*C2)/det;
        intersection.y = (A1*C2 - A2*C1)/det;
    }
	return intersection;
}

//finds intersection given points
Point find_intersection(Point p1, Point p2, Point p3, Point p4)
{
	//equation of line-1 Ax + By = C
	double A1 = p2.y - p1.y;
	double B1 = p1.x - p2.x;
	double C1 = A1*p1.x + B1*p1.y;
	
	//equation of line-2 Ax + By = C
	double A2 = p4.y - p3.y;
	double B2 = p3.x - p4.x;
	double C2 = A2*p3.x + B2*p3.y;
	
	Point intersection;
	
	double det = A1*B2 - A2*B1;
    if(det == 0){
        //Lines are parallel
    }else{
        intersection.x = (B2*C1 - B1*C2)/det;
        intersection.y = (A1*C2 - A2*C1)/det;
    }
	return intersection;
}
int main()
{
	//define line-1 by two points
	Point p1 = {1,1}, p2 = {3,3};
	
	//define line-2 by two points
	Point q1 = {3,1}, q2 = {1,3};
	
	Point intersection = find_intersection(p1,p2,q1,q2);
	
	cout<<"Intersection point: "<<intersection.x<<" , "<<intersection.y<<"\n";
	return 0;
}