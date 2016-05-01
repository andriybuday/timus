#include <stdio.h>
#include <math.h>
const long double PI  = 3.1415926535897932384626433832795;
const __int64 BIGNUM  = 1000000000000;
const long double eps = 0.000000000000000001;
inline long double get_angle(long double x1,long double  y1,long double x2,long double y2,long double Cx)
{
	//long double Cy = 0.0;
	x2 = x2 - Cx;
	x1 = -Cx;
	long double angle2 = atan2(y2,x2);
	long double angle1 = atan2(y1,x1);
	return angle1 - angle2;
}
void TL()
{
	while(true){}
}
int main()
{
	__int64 x1, y1, x2, y2;
	scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);

	if(x1 == x2 && y1*y2 == 0)
	{
		printf("%.6lf", PI/2.0);
		return 0;
	}
	if (y1*y2 <= 0)
	{
		printf("%.6lf", PI);
		return 0;
	}
	//swapping
	if (x1 > x2)
	{
		__int64 temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	//mirror
	if (y1 < 0 && y2 < 0)
	{
		y1 = -y1;
		y2 = -y2;
	}
	//replase coordinates
	bool flag = 0;
	if(y2 < y1)
	{
		flag = 1;
		__int64 temp = y2;
		y2 = y1;
		y1 = temp;
	}
	//binary
	__int64 curr, roof, floor;
	
	floor = 0;
	x2 = abs(int(x2 - x1));
	x1 = 0;
	x2 *= BIGNUM;
	y1 *= BIGNUM;
	y2 *= BIGNUM;
	roof = 5000*BIGNUM;
	curr = 4000*BIGNUM;

	///binary search
	long double left_angle,angle,right_angle;
	while(true)
	{

		if (roof - floor < 14)
		{
			break;
		}
		left_angle = get_angle(x1, y1, x2, y2, long double(curr - (curr - floor)/2));
		angle = get_angle(x1, y1, x2, y2, long double(curr));
		right_angle  = get_angle(x1, y1, x2, y2, long double(curr + (roof - curr)/2));
		if(right_angle - angle > eps)//turn right
		{
			//right
			floor = curr;
			curr = curr + (roof-curr)/2;
			continue;
		}
		if(left_angle - angle > eps)//turn left
		{
			//left
			roof = curr;
			curr = curr - (curr - floor)/2;
			continue;
		}
		if(angle - right_angle > angle - left_angle)
		{
			//left
			roof = curr;
			curr = curr - (curr - floor)/2;
			continue;
			
		}
		else
		{
			//right
			floor = curr;
			curr = curr + (roof-curr)/2;
			continue;
		}	
	}	

	printf("%.6lf\n", angle);

	return 0;
}