//1135
#include <stdio.h>
void TL(int n)
{
for(__int64 i = 0; i < (__int64)n*10000; ++i){}
}
int main()
{
	int i,n ,right = 0,left = 0;
	char ch = '3';
	scanf("%d", &n);
TL(n);
	for(i = 0; i < n; ++i)
	{
		ch = getchar();
		while(!(ch == '<' || ch == '>'))
			ch = getchar();
		if(ch == '>')left++;
		if(ch == '<')right += left;
	}
	printf("%d", right);
	return 0;
}

/*
for i:=1 to n do
begin
	read(ch);
	while not(ch in ['<','>']) do
			read(ch);
	case ch of
	'>':inc(R);
	'<':inc(L,R);
	end;
end;
writeln(L);
end.
*/