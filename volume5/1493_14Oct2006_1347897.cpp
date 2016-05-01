#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int n1 = n-1, n2 = n+1;
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0, i;
	for (i = 0; i < 3; i++){
		s1 += n1 % 10;
		n1 /= 10;
	}
	for (i = 0; i < 3; i++){
		s2 += n1 % 10;
		n1 /= 10;
	}

	for (i = 0; i < 3; i++){
		s3 += n2 % 10;
		n2 /= 10;
	}

	for (i = 0; i < 3; i++){
		s4 += n2 % 10;
		n2 /= 10;
	}

	if (s1 == s2 || s3 == s4) printf("Yes\n");
	else printf("No\n");

	return 0;
}