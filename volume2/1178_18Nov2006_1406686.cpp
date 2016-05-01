//1178
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct town
{
	int index;
	double x;
	double y;
	town(int ind = 0, double xx = 0, double yy = 0):index(ind),x(xx),y(yy){}

	bool operator < (const town& tw)const
	{
		
		double dist = sqrt(double(x*x + y*y));
		double dist_tw = sqrt(tw.x*tw.x + tw.y*tw.y);
		double alpha = atan2(y, x);
		double alpha_tw = atan2(tw.y, tw.x);
		
		if(alpha < alpha_tw)return true;
		else
		{
			if(alpha == alpha_tw)
			{
				return (dist < dist_tw);
			}
		}
		return false;
	}
};
int main()
{
	priority_queue<town> towns;

	int n, i, x, y;
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		towns.push(town(i, x, y));
	}

	int index;
	while(!towns.empty())
	{
		index = towns.top().index;
		printf("%d ", index);
		towns.pop();
		index = towns.top().index;
		printf("%d\n", index);
		towns.pop();
	}

	return 0;
}