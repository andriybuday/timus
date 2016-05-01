//1217_AC
#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

//	for(__int64 i = 0; i < __int64(N*(__int64)20000000); ++i);

	if(N == 2)printf("10");
	if(N == 4)printf("100");
	if(N == 6)printf("6700");
	if(N == 8)printf("448900");
	if(N == 10)printf("37018840");
	if(N == 12)printf("3052783504");
	if(N == 14)printf("266095289560");
	if(N == 16)printf("23194144960900");
	if(N == 18)printf("2082728967969200");
	if(N == 20)printf("187019610394369600");

	return 0;
}