#include <stdio.h>

/* win�Լ��� n���� ����� �������� ��� �ڽ��� ���ʸ� ������ ����� �̱����
����(�� �Ǵ� ����)�� ��ȯ�ϴ� �Լ��̴�.*/ 

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
