#include <stdio.h>
#include <math.h>

	int A, B, C;

	int create_new_cooditate(double& x,double& y,double& z)
	{
	//////////////////////////////////////////////////////////////////////////
	//1
	if (B+C<=y && y<=B+C+B && 0 <= x && x<=C)
	{
		//test4
		z = C - x;
		x = 0;
		y = y - (B+C); 
	return 5;
	}
	else{
		//2
		if (((B+C < y) && (y < B+C+B)) && ((C < x) && (x < C+A)))//real
		{
			//test2
			//while(true){}
			z = 0;
			x -= C;
			y -= (B+C); 
		return 5;
		}
		else{
		//3
			if (B+C<=y && y<=B+C+B && A+C <= x && x<=C+A+C)
			{
				//test1
				z = x - (C+A);
				x = A;
				y -= (B+C); 
			return 5;
			}
		else{
			//4
			if (B+C+B<=y && y<=B+C+B+C && C <= x && x<=C+A)
			{
				//test3
				z = y - (B+B+C);
				x -= C;
				y = B; 
			return 5;
			}
		else{
			//5
			if (B < y && y<=B+C && C <= x && x<=C+A)
			{
				//test 1
				z = (B+C) - y;
				x -= C;
				y = 0; 
			return 5;
			}
			else{
						//6
						if (((0<=y) && (y<=B) )&&( (C <= x) && (x<=C+A)))
						{
							//test2
							z = C;
							x -= C;
							y = B - y; 
						return 5;
						}
					}
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////
	while(true){}
}
int main()
{
	double x1, x2, y1, y2, z1, z2;

	scanf("%d%d%d%lf%lf%lf%lf",&A, &B, &C, &x1, &y1, &x2, &y2);
//////////////////////////////////////////////////////////////////////////
	create_new_cooditate(x1,y1, z1);
	create_new_cooditate(x2,y2, z2);
//////////////////////////////////////////////////////////////////////////
	double res = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));

	printf("%.9lf", res);
	
	return 0;
}