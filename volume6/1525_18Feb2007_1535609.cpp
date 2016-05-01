//problem D_AC
//#include <iostream>
#include <stdio.h>
//using namespace std;

__int64 inline md(__int64 x){
	return (x < 0) ? -x : x;
}

int main()
{
	__int64 n, m, k;
	scanf("%I64d %I64d %I64d", &n, &m, &k);
	__int64 n1 = 1, n2 = n, m1 = 1, m2 = m, k1 = 1, k2 = k;
	char c;
	while ((c = getchar()) != EOF){
		if (c == 13 || c == 10) continue;
		switch (c){
			case 'l': 
				--n1;
				if (n1 < 1) n1 = 1;
				--n2;
				if (n2 < 1) n2 = 1;
				break;
			case 'r':
				++n1;
				if (n1 > n) n1 = n;
				++n2;
				if (n2 > n) n2 = n;
				break;
			case 'u':
				++m1;
				if (m1 > m) m1 = m;
				++m2;
				if (m2 > m) m2 = m;
				break;
			case 'd':
				--m1;
				if (m1 < 1) m1 = 1;
				--m2;
				if (m2 < 1) m2 = 1;
				break;
			case 'f':
				++k1;
				if (k1 > k) k1 = k;
				++k2;
				if (k2 > k) k2 = k;
				break;
			case 'b':
				--k1;
				if (k1 < 1) k1 = 1;
				--k2;
				if (k2 < 1) k2 = 1;
				break;
		}
	}

	printf("%I64d\n", md( (n2 - n1 + 1) * (m2 - m1 + 1) * (k2 - k1 + 1) ));
	return 0;
}