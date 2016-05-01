//1302_AC_bad
#include <cstdio>
#include <cmath>
void swap(int& a, int &b)
{
	int temp  = a;
	a = b;
	b = temp;
}
int dist_from_one(int n)
{
	int curr_n = 1, curr_sum_n = 1, counter_n = 0;
	while (curr_sum_n <= n)
	{
		curr_sum_n += curr_n;
		curr_n += 2;
		counter_n++;
	}
	curr_n -= 2;//
	curr_sum_n -= curr_n;//max in prev row
	//curr_sum++;//first in this row
	counter_n--;
	int res_n = (counter_n)*2;
	if ((curr_sum_n%2) != (n%2))res_n--;
	return res_n;
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	//make n greater then m
	if (n < m)swap(n,m);
	//m!
	//////////////////////////////////////////////////////////////////////////
	int curr_m = 1, curr_sum_m = 1, counter_m = 0;
	while (curr_sum_m <= m)
	{
		curr_sum_m += curr_m;
		curr_m += 2;
		counter_m++;
	}
	curr_m -= 2;//
	curr_sum_m -= curr_m;//max in prev row
	//curr_sum++;//first in this row
	counter_m--;
	int res_m = (counter_m)*2;
	if ((curr_sum_m%2) != (m%2))res_m--;
//////////////////////////////////////////////////////////////////////////
	int curr_n = 1, curr_sum_n = 1, counter_n = 0;
	while (curr_sum_n <= n)
	{
		curr_sum_n += curr_n;
		curr_n += 2;
		counter_n++;
	}
	curr_n -= 2;//
	curr_sum_n -= curr_n;//max in prev row
	//curr_sum++;//first in this row
	counter_n--;
	int res_n = (counter_n)*2;
	if ((curr_sum_n%2) != (n%2))res_n--;
//////////////////////////////////////////////////////////////////////////
	
	int diff = abs(curr_sum_n - curr_sum_m);
	int left_tree = m + diff;
	int sum = 0;
	for(int y = curr_m + 2; y <= curr_n; y+=2)sum += y;
	int right_tree = m +  sum;
	int main_res = 0;
	if (n <= right_tree && n >= left_tree)main_res = res_n - res_m;
	if (n > right_tree)main_res = dist_from_one(right_tree) - res_m + (n - right_tree);
	if (n < left_tree)main_res = dist_from_one(left_tree) - res_m + (left_tree - n);
	printf("%d\n", main_res);

	//printf("curr_ = %d\ncurr_sum = %d\ncounter = %d\nres = %d\nltree = %d\nrtree = %d\n", curr_n, curr_sum_m, counter_m, res_m, left_tree, right_tree);
	
	//	printf("%d\n", abs(res_m+res_n - abs(res_m-res_n)));
	return 0;
}