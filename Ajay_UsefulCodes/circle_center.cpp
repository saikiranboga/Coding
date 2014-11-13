#include<iostream>
#include<cstdio>
using namespace std;

struct Point
{
	double x;
	double y;
};

//finds intersection given equations of line
Point find_intersection(double A1, double B1, double C1, double A2, double B2, double C2)
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

Point find_center(Point p1, Point p2, Point p3)
{
	//equation of line-1 Ax + By = C
	double A1 = p2.y - p1.y;
	double B1 = p1.x - p2.x;
	double C1 = A1*p1.x + B1*p1.y;
	
	//equation of line-2 Ax + By = C
	double A2 = p3.y - p2.y;
	double B2 = p2.x - p3.x;
	double C2 = A2*p2.x + B2*p2.y;
	
	//find eq of perpendicular bisector of line-1
	Point mid1 = {(p1.x + p2.x)/2 , (p1.y + p2.y)/2};
	double D1 = -B1*mid1.x + A1*mid1.y;
		//eq is: -B1x + A1y = D1
	
	//find eq of perpendicular bisector of line-2
	Point mid2 = {(p2.x + p3.x)/2 , (p2.y + p3.y)/2};
	double D2 = -B2*mid2.x + A2*mid2.y;
		//eq is: -B1x + A1y = D1
		
	cout<<A1<<" "<<B1<<" "<<D1<<" "<<mid1.x<<" "<<mid1.y<<"\n";
	cout<<A2<<" "<<B2<<" "<<D2<<" "<<mid2.x<<" "<<mid2.y<<"\n";
	Point center = find_intersection(-B1, A1, D1, -B2, A2, D2);
	return center;
}
int main()
{
	//given three points on the circumference of the circle
	//Point p1 = {9,25}, p2 = {-2,-30}, p3 = {-5,-45};
	Point p1 = {2,1}, p2 = {0,5}, p3 = {-1,2};
	Point center = find_center(p1, p2, p3);
	
	cout<<"Center: "<<center.x<<" , "<<center.y<<"\n";
	
	return 0;
	
}