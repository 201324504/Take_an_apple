#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HUMAN 0
#define COMPUTER 1
#define GIVEUP -1

int x(int n,int p) // 현재 선택하지 못하는 사과의 개수 return 
{
	return p!=0? (n+p)%3+1 : 0;
}

// 승부 결과를 계산하는 알고리즘을 이용하여 승부 결과를 진리값으로 return 
int win(int n, int p) 
{
	int xv, cho;
		
	xv = x(n,p);	
	for(cho=1;cho<=3;++cho)
		if(n>=cho && xv!=cho && !win(n-cho,cho)) return 1; // trun
	return 0; // false
}

// 최선의 방법을 찾는 함수, 최선의 방법이 없을 시 0 return 
int best_choice(int n,int p) 
{
	int xv, cho;
	
	xv = x(n,p);
	
	for(cho=1;cho<=3;++cho)
		if(n>=cho && xv!=cho && !win(n-cho,cho)) return cho;
				
	return 0;
}

// 처음 턴에 제한할 사과의 개수를 random함수로 구현 
int random_choice(int n,int x)
{
	int cho;
	
	do{
		cho = rand()%3+1;	
	}while(!(cho<=n && cho!=x)) ;
	
	return cho;
}

/* 컴퓨터가 자신이 이길 수 있는 방법을 찾는 함수
best_choice, computer choice로 구현 */
int computer_choice(int n, int p)
{
	int xv, cho;
		
	xv = x(n,p);
	cho = best_choice(n,p);
	
	if(!(cho!=0 && cho!=xv))
		return random_choice(n,xv);
		
	return cho;	
}

// 사용자가 사과를 제거 
int human_choice(int n, int p)
{
	int xv,cho;
		
	xv = x(n,p);
	cho = 0;
	
	while(!(cho>=1 && cho<=3 && cho!=xv || cho==-1)){
		printf("The number of remove");
		printf("(1~3 or -1 : giving up) >> ");
		scanf("%d",&cho);		
	}
	
	return cho;
}

/* 게임이 시작하기 전 사과의 개수를 입력, 10~50 사이의 수가 아닐 경우 
다시 입력*/ 
int get_num(void)  
{
	int n=0;
		
	while(!(n>=10 && n<=50)){
		printf("The number of apples");
		printf("(10 ~ 50) >> ");
		scanf("%d",&n);
	}
	
	return n;
}

/* 입력하는 turn이 0이면 사람, 1이면 computer가 게임을 먼저 시작한다.
만약 0이나 1이 아니면 Turn을 다시 입력받는다. */ 
int get_turn(void)
{
	int turn =-1;
		
	while(!(turn==HUMAN || turn==COMPUTER)){
		printf("Turn(0-human or 1-computer) >> ");
		scanf("%d",&turn);
	}
	
	return turn;
}

// 가져갈 사과의 개수를 제어하는 함수 
int is_over(int n, int p)
{
	int i=0;

	for(i=1; (i<=3)&& !(i<=n && i!=x(n,p)); ++i)
		;
		
	return i>3;
}

/* 구현한 함수들을 이용하여 게임을 진행시킴 */
int main(void)
{
	int num,turn,cho =0, prev;	
	srand((unsigned)time(NULL));	
	num = get_num();
	turn = get_turn();
	prev = rand()%3+1;	 
	while(!(cho==GIVEUP || is_over(num,prev)) ){
		printf("\nThe current number: %d\n",num);
		printf("The x number : %d\n",x(num,prev));
		if(turn == HUMAN){
			cho = human_choice(num,prev);
			printf("Human choice : %d\n",cho);
			if(cho!=GIVEUP){						
				turn = (turn==HUMAN? COMPUTER : HUMAN);			
				num-= cho;
				prev = cho;
			}
		}
		else{			
			cho=computer_choice(num,prev);
			printf("Computer choice : %d\n",cho);			
			turn = (turn==HUMAN ? COMPUTER : HUMAN);		
			num-=cho;
			prev=cho;
		}
	}	
	if(turn==HUMAN)
		printf("\nComputer win.\n");
	else
		printf("\nHuman win.\n");
	return 0;	
}
