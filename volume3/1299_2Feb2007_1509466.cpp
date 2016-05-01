#include <stdio.h>
	int X, P, M, MP, N, NP, angle, next_angle;//X - energy, P - guns
	char behaviour;
void TL()
{
	while(true){}
}
void do_job(int energy)
{
	if(energy >= 100)printf("100\n");
	else printf("%d\n", energy);
}
//LEFT X      X  ;
void left(int energy)
{
	printf("LEFT ");
	do_job(energy);
}
//RIGHT X      X  ;
void right(int energy)
{
	printf("RIGHT ");
	do_job(energy);
}
//FRONT X      X  ;
void front(int energy)
{
	printf("FRONT ");
	do_job(energy);
}
//BACKWARD X      X  ;
void backward(int energy)
{
	printf("BACKWARD ");
	do_job(energy);
}
void fire(int guns)
{
	if(guns >= 20)printf("FIRE 20\n");
	else printf("FIRE %d\n", guns);
}
//
void G()
{
		if(M && angle >= 5)
		{
			left(X);
			return;
		}
		if(M && angle <= -5)
		{
			right(X);
			return;
		}
		if(M && angle < 5 && angle > -5)
		{
			fire(P);
			return;
		}
		if(M == 0)
		{
			printf("STOP\n");
			return;
		}
}
void A()
{
		scanf("%d%d", &N, &NP);
		if(M == 0)
		{
			front(X);
			return;
		}
		if((N*NP > M*MP*3))
		{
			if(M && angle <= 10 && angle >= -10)//???????????
			{
				fire(P);
				return;
			}
			else
			{
				front(X);
				return;
			}
		}
		else
		{
			if(M && angle <= 5 && angle >= -5)//???????????
			{
				fire(P);
				return;
			}
			else
			{
				backward(X);
				return;
			}
		}
		//return 0;
}
void D()
{
	if(M == 0)
	{
		printf("STOP\n");
		return;
	}
		if(M * 20 >= P)
		{
			if(M && angle < 5 && angle > -5)//???????????
			{
				fire(P);
				return;
			}
			else
			{
				backward(X);
				return;
			}
		}
		else G();	
		return;
}
void P_fun()
{
		scanf("%d", &next_angle);
		if(M)
		{
			G();
			return;
		}
		else
		{
			if(next_angle == 0)TL();
			else
			{
				if(next_angle >= 160)
				{
					backward(X);
					return;
				}
				if(next_angle <= -160)
				{
					backward(X);
					return;
				}
				if(next_angle <= 20 && next_angle >= -20)
				{
					front(X);
					return;
				}
				if(next_angle > 20 && next_angle < 160)
				{
					if(next_angle > 20 && next_angle < 90)
						left(X);
					if(next_angle >= 90 && next_angle < 160)
						right(X);
					return;
				}

				if((next_angle < -20) && (next_angle > -160))
				{
					if((next_angle < -20) && (next_angle > -90))
						right(X);
					if((next_angle <= -90) && (next_angle > -160))
						left(X);
					return;
				}
			}
		}
}
int main()
{
	scanf("%d%d%s%d%d%d", &X, &P, &behaviour, &M, &MP, &angle);
	////
	if(behaviour == 'G')G();
	if(behaviour == 'A')A();
	if(behaviour == 'D')D();
	if(behaviour == 'P')P_fun();
	return 0;
}