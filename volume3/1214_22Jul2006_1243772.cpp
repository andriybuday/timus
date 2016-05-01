//1214
#include <stdio.h>

int main()
{
	int x, y;

	scanf("%d%d", &x, &y);

	printf("%d %d", (x<0)||(y<0)||((x+y)%2==0)?x:y,(x<0)||(y<0)||((x+y)%2==0)?y:x);	

	return 0;
}
