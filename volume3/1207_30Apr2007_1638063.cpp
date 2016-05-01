//1207_AC
#include <stdio.h>
#include <queue>
#include <math.h>
double a_x[10003];
double a_y[10003];
class Point
{
int index;
double x, y;
public:
	int get_index()
	{
		return index;
	}
Point(int ind = 0, double xx = 0.0, double yy = 0.0):index(ind),x(xx), y(yy){}

	bool operator < (const Point& p)const
	{
		if(atan2(y, x) < atan2(p.y, p.x))return true;
		return false;
	}
};


int main()
{

std::priority_queue<Point> points;
int n, i;
scanf("%d", &n);
double x, y;
for(i = 1; i <= n; i++)
{
	scanf("%lf%lf", &a_x[i], &a_y[i]);
}
double min_x = 1000000003.0, min_y = 1000000003.0;
int min_i = 1000000;//index of min point
for(i = 1; i <= n; i++)
{
	if(a_x[i] <= min_x)
		if(a_y[i] <= min_y)
		{
			min_x = a_x[i];
			min_y = a_y[i];
			min_i = i;
		}
}
//min_x = a_x[i];
///min_y = a_y[i];
for(i = 1; i <= n; i++)
{
	if(i != min_i)
	{
		points.push(Point(i , a_x[i] - min_x, a_y[i] - min_y));
	}
}
for(i = 1; i <= (n-2)/2; i++)
{
	points.pop();
}
Point save_index = points.top();

printf("%d %d\n", min_i, save_index.get_index());

return 0;
}
