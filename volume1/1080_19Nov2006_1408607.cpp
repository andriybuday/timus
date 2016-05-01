#include <stdio.h>

char A[100][100];
char Colors[100];
int N;

int MyPaint(int Country, int nColor)
{
if (Colors[Country] != -1)
{
if (Colors[Country] == nColor)
{
return 1;
}
else
{
return 0;
}
}

Colors[Country] = nColor;
int NewColor = 0;
if (nColor == 0) 
{
NewColor = 1;
}

for(int i = 0; i < N; ++i)
{
if (A[Country][i] == 1)
{
if (MyPaint(i, NewColor) == 0)
{
return 0;
}
}
}
return 1;
}

int main()
{
scanf("%d", &N);
int i;
int ch;
for(i = 0; i < N; ++i)
{
Colors[i] = -1;
for(;;)
{
scanf("%d", &ch);
if (ch == 0)
{
break;
}
A[ch-1][i] = 1;
A[i][ch-1] = 1;
}
}

int Bad = 0;
for(i = 0; i < N; ++i)
{
if (Colors[i] == -1)
{
if (MyPaint(i, 0) == 0)
{
Bad = 1;
break;
}
}
}

if (Bad == 1)
{
printf("-1\n");
}
else
{
for(int j = 0; j < N; ++j)
{
printf("%d", Colors[j]);
}
printf("\n");
}
return 0;
}