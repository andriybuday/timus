#include <stdio.h>
#include <ctype.h>
#include <cmath>
int main(){

char ch;

__int64 a;

scanf("%c", &ch);
a=0;
while(isdigit(ch)){
	a=(a*10+(int(ch)-48))%7;
	scanf("%c", &ch);
}
printf("%d", a);

return  0;
}