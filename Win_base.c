#include <stdio.h>

/* win함수는 n개의 사과가 남아있을 경우 자신의 차례를 맞이한 사람이 이기는지
여부(참 또는 거짓)을 반환하는 함수이다.*/ 

int win(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==2) return 1;
	return !win(n-1) || !win(n-2) || !win(n-3);
}

int main(void)
{
	int n;
	
	for(n=0; n<=17; ++n)
		printf("w(%2d)==%d\n", n, win(n));
	return 0;
}
