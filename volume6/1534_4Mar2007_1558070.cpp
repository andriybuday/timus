#include <cstdio>

__int64 inline min2i(__int64 x, __int64 y){
	return (x < y) ? x : y;
}
__int64 inline min3i(__int64 x, __int64 y, __int64 z){
	return min2i(min2i(x, y), z);
}
int main()
{
	__int64 i, j, k, l, n, max = 0, min = 0, min2 = 0;

	scanf("%I64d%I64d%I64d",&k, &l, &n);
	__int64 an1, an2;
	char ch;

	__int64 mink = k, minl = l, maxk = k, maxl = l,min2k = k, min2l = l;

	--n;
	if(maxk <= n)
	{
		max += 3*maxk;
		max += (n-maxk);
		maxk = 0;
	}
	else
	{
		max += 3*n;
		maxk -= n;
	}
	if(minl <= n)
	{
		min += (n-minl);
		minl = 0;
	}
	else
	{
		minl = minl - n;
	}

	//=====cycle translation by forensic:
	__int64 ost1 = n - min3i(min2l, min2k, n);
	__int64 c1 = min3i(min2l, min2k, n);
	min2 += c1;
	min2l -= c1;
	min2k -= c1;
	__int64 c2 = min2i(ost1, min2l);
	ost1 -= min2l;
	if (ost1 > 0) min2 += ost1;
	min2l -= c2;


	if(maxk > maxl)max+=3;
	if(maxk == maxl)++max;
	if(mink > minl)
	{
			min+=3;
	}
	if(mink == minl)++min;
	if(min2k > min2l)
	{
			min2+=3;
	}
	if(min2k == min2l)++min2;
	if(min2 < min)min = min2;

	printf("%I64d %I64d\n", max, min);
	return 0;
}
