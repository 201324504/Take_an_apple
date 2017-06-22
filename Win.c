#include <stdio.h>

/* win 함수는 이전 차례에 상대가 p개의 사과를 가져간 상태에서 n개의 사과가
남아 있을 경우 자신의 차례를 맞이한 사람이 이기는지 여부(참 또는 거짓)을 반환하는
함수이다.*/ 

int win(int n, int p)
{
	int x, cho;
	
	x = (n+p)%3+1;
	for(cho=1;cho<=3;++cho)
		if(n>=cho && x!=cho && !win(n-cho,cho)) return 1;	
	return 0;
}

int main(void)
{
	int n, p;
	
	for(n=0; n<=12; ++n) {
		for(p=0;p<=3;++p)
			printf("w(%2d,%d)==%d  ", n, p, win(n,p));
		printf("\n");
	}
	return 0;
}
