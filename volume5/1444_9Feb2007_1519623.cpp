//1444_AC
#include <stdio.h>
#include <queue>
#include <math.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
double a_x[30003];
double a_y[30003];
struct Point
{
	int index;
	double angle;
	double r;
	Point(int ind = 0, double x = 1.0, double y = 1.0)
	{
		index = ind;
		angle = atan2(y, x);
		r = x*x + y*y;//r in power 2
	}
	bool operator == (const Point& p)const
	{
		if(r == p.r && angle == p.angle && index == p.index)return true;
		return false;
	}
};
Point s_1;
bool spep3sorting(Point& a , Point& b)
{
	if(a.angle < b.angle)return true;
	if(a.angle == b.angle)
		return (a.r < b.r); 
	return false;
}
inline bool front_greater_sorting(Point& a , Point& b)
{
	return a.r < b.r;
}

inline bool right_sorting(Point& a , Point& b)
{
	if(a.angle > b.angle)return true;
	if(a.angle == b.angle)
		return a.r > b.r;
	return false;
}
inline bool front_less_sorting(Point& a , Point& b)
{
	return a.r < b.r;
}
inline bool left_sorting(Point& a , Point& b)
{
	if(a.angle < b.angle)return true;
	if(a.angle == b.angle)
		return a.r < b.r;
	return false;

}
int main()
{

	int n, i;
	scanf("%d", &n);
	double x, y;
	for(i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &a_x[i], &a_y[i]);
	}
	double min_x = 1000000003.0, min_y = 1000000003.0;
	int min_i = 1000000;//index of min point

	/////////////////////////////////////
	// 1
	for(i = 1; i <= n; i++)
	{
		if(a_y[i] < min_y)
		{
			min_x = a_x[i];
			min_y = a_y[i];
			min_i = i;
		}
		else 
		if(a_y[i] == min_y)
		{
			if(a_x[i] <= min_x)
			{
				min_x = a_x[i];
				min_y = a_y[i];
				min_i = i;
			}
		}
	}
	vector<Point> vec;
	vec.reserve(30003);

	/////////////////////////////////////
	// 2
	for(i = 1; i <= n; i++)
	{
		if(i != min_i)vec.push_back(Point(i , a_x[i] - min_x, a_y[i] - min_y));
	}
	s_1 = Point(1,a_x[1] - min_x, a_y[1] - min_y);
	/////////////////////////////////////
	// 3
	if(min_i == 1)
	{
		printf("%d\n1\n", n);
		sort(vec.begin(), vec.end(), spep3sorting);
		for(int i = 0; i < vec.size(); i++)
		{
			printf("%d\n", vec[i]);
		}
		return 0;
	}
	/////////////////////////////////////
	// 4
	list<Point> right, left, front_greater, front_less;
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[i].angle < s_1.angle)
		{
			right.push_back(vec[i]);
		}
		if(vec[i].angle > s_1.angle)
		{
			left.push_back(vec[i]);
		}
		if(vec[i].angle == s_1.angle)
		{
			if(vec[i].r < s_1.r)
			{
				front_less.push_back(vec[i]);
			}
			if(vec[i].r >= s_1.r)//here will be and the first point!!!!
			{
				front_greater.push_back(vec[i]);
			}
		}
	}
	//////////////////////////////////////
	// 5
	printf("%d\n", n);
	typedef list<Point>::iterator I;
	//5.1
	front_greater.sort(front_greater_sorting);
	for (I it = front_greater.begin(); it != front_greater.end(); ++it)
	{
		printf("%d\n", (*it));
	}
	//5.2
	right.sort(right_sorting);
	for (I it = right.begin(); it != right.end(); ++it)
	{
		printf("%d\n", (*it));
	}
	printf("%d\n", min_i);
	//5.3
	front_less.sort(front_less_sorting);
	for (I it = front_less.begin(); it != front_less.end(); ++it)
	{
		printf("%d\n", (*it));
	}
	//5.4
	left.sort(left_sorting);
	for (I it = left.begin(); it != left.end(); ++it)
	{
		printf("%d\n", (*it));
	}

	return 0;
}
