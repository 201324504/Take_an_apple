#include <stdio.h>

/* win �Լ��� ���� ���ʿ� ��밡 p���� ����� ������ ���¿��� n���� �����
���� ���� ��� �ڽ��� ���ʸ� ������ ����� �̱���� ����(�� �Ǵ� ����)�� ��ȯ�ϴ�
�Լ��̴�.*/ 

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
