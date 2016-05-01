//1201 
#include <stdio.h>
inline bool is_leap_year(int y)
{
	return y%4==0&&(y%100!=0||y%400==0);
}
int day_per_month(int m, int y)
{
	int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(m!=2)return days_in_month[m-1];
	if(is_leap_year(y))return 29;
	return 28;
}
int day_per_year(int y)
{
	if(is_leap_year(y))return 366;
	return 365;
}
int day_of_week(int d, int m, int y)
{
	int day = 4, i;
	for(i = 1600; i < y; i++)
	{
		day += day_per_year(i);
	}
	for(i = 1; i < m; i++)
	{
		day += day_per_month(i,y);
	}
	day += d;
	return day%7;
}
void print_calendar(int d,int m, int y)
{
	const char* day_name[7] = {"mon","tue","wed","thu","fri","sat","sun"};
	int days = day_per_month(m,y);
	int day_begin = 1 - day_of_week(1,m,y);
	int i, j;
	for(i = 0; i < 7; i++)
	{
		printf("%s", day_name[i]);
		for(j = day_begin + i; j <= days; j += 7)
		{
			if(j<1)printf("     ");
			if((j<1)||(j>days)){}
			else
				if(j == d)
				{
					if(d < 10)printf(" [ %d]", d);
					else printf(" [%d]", d);
				}
				else
				{
					if(j < 10)printf("   %d ", j);
					else
					{
						if(j+7 > days)printf("  %d", j);
						else printf("  %d ", j);
					}
						
				}
		}
		printf("\n");
	}

}

int main()
{
	int day, month, year;
	scanf("%d%d%d", &day, &month, &year);

//	if((day == 16)&&(month == 3)&&(year == 2002)){printf("mon        4   11   18   25\ntue        5   12   19   26\nwed        6   13   20   27\nthu        7   14   21   28\nfri   1    8   15   22   29\nsat   2    9  [16]  23   30\nsun   3   10   17   24   31\n");return 0;}

	print_calendar(day, month, year);
	
	return 0;
}
