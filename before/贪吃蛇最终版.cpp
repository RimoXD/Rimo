#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define up 'w'
#define down 's'
#define right 'd'
#define left 'a'
#define up 'W'
#define down 'S'
#define right 'D'
#define left 'A'

void welcome();//��ʼ����//
void finish();//����//
void gotoxy(int x, int y);//���ƹ��//
void creatwall();//��ӡΧǽ//
void gotohua(int x, int y);//��ӡ//
void gotochu(int x, int y);//ɾ��//
void creatfood();//����ʳ��//
int ClickControl();//��ȡ�����źź���//
int jieshu();//�жϽ���//
void move();//�ƶ�����//
void eat();//�Ե�ʳ��//
void changebody(int a,int b);//�ı�����//
void stop();

typedef struct snakes
{
	int x;
	int y;
	struct snakes* next;
}snake;

snake* tou, * wei;

struct food
{
	int x;
	int y;
}food;

char name[20] = { 0 };
int score = 0;
char click = right;
int nandu=5; 

int main()
{
	system("color 0B");
	welcome();
	creatwall();
	creatfood();
	if (ClickControl() == 0)
	{
		finish();
		return 0;
	}
	return 0;
}

void gotoxy(int x,int y)
{
	COORD pos;        
	HANDLE hOutput;        
	pos.X = x; 
	pos.Y = y;        
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorPosition(hOutput, pos);
}

void welcome()
{
	gotoxy(30, 3);
	printf("********************************************************");
	gotoxy(43, 10);
	printf("�����ã���ӭ����̰������Ϸ��");
	gotoxy(50, 12);
	printf("���������֣�");
	gotoxy(46,17);
	printf("�������Ѷ�(��������)��");
	gotoxy(23,19);
	printf("1���׳ն���ͨ��  2��ƽ������  3��Ӵ���е�������  4���Բۣ�ţ��  5��˻���ֲ���˹");
	gotoxy(30, 26);
	printf("********************************************************");
	gotoxy(61,12) ;
	scanf("%s",&name);	
	gotoxy(67,17) ;
	scanf("%d",&nandu);
	
}

void gotohua(int x, int y)
{
	gotoxy(x, y);
	printf("*");
}

void gotochu(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
}

void creatwall()
{
	int i,j;
	for(i=0;i<30;i++)
		for(j=0;j<150;j++)
		{
			gotochu(j,i);
		}

	for (i = 0;i < 80;i+=2)
	{
		gotohua(i, 0);
		gotohua(i, 29);
	}
	for (i = 0;i < 30; i++)
	{
		gotohua(0, i);
		gotohua(80, i);
	}
	gotoxy(87, 9);
	printf("�װ���%s��ң���������ѽ��", name);
	gotoxy(84, 14);
	printf("���Ѿ����� 0 ���ˣ�ż�������⼫�ˡ�");
	gotoxy(86, 19);
	printf("����Ϸ���Ķ���������������");
	gotoxy(93,28);
	printf("wsad���Ʒ���"); 
	gotoxy(85,29);
	printf("�����������ͣ��˫��wsad�ָ�"); 
	snake* p, * q,*z;
	tou = (snake*)malloc(sizeof(snake));
	tou->x = 7;
	tou->y = 15;
	wei= (snake*)malloc(sizeof(snake));
	wei->x = 4;
	wei->y = 15;
	p= (snake*)malloc(sizeof(snake));
	p->x = 6;
	p->y = 15;
	z= (snake*)malloc(sizeof(snake));
	z->x = 5;
	z->y = 15;
	tou->next = p;
	p->next = z;
	z->next = wei;
	wei->next = NULL;
	q = tou;
	while(q != NULL) {gotohua(q->x, q->y);q = q->next; }
}

void creatfood()
{
	srand((unsigned)time(NULL));
	food.x = rand() % 80 + 1;
	food.y= rand() % 28 + 1;
	snake* p;
	p = tou;
	while (1)
	{
		if (p->x == food.x && p->y == food.y)
		{
			food.x = rand() % 80 + 1;
			food.y = rand() % 28 + 1;
			p = tou;
		}
		else 
		{
			p = p->next;
		}
		if (p == NULL)break;
	}
	gotoxy(food.x,food.y);
	printf("*");
}

int jieshu()
{
	if (tou->x == 0 || tou->x == 80 || tou->y == 0 || tou->y == 29)return 0;
	snake* p;
	p = tou->next;
	while (p != NULL)
	{
		if (p->x == tou->x && p->y == tou->y)return 0;
		p = p->next;
	}
	return 1;
}

int ClickControl()
{
	while (1)
	{
		if (jieshu() == 0)return 0;
		if (_kbhit())
		{
			click = _getch();
		}
		move();
		eat();
	}
	return 1;
}

void move()
{
	int a = tou->x, b = tou->y;
	snake* p = tou;
	while (p!=NULL)
	{
		gotochu(p->x, p->y);
		p = p->next;
	}
		switch (click)
		{
		case up:
		case '24': 
			tou->y -= 1;
			changebody(a, b);
			break;
		case down:
		case '25':
			tou->y += 1;
			changebody(a, b);
			break;
		case right:
		case '26':
			tou->x += 1;
			changebody(a, b);
			break;
		case left:
		case '27':
			tou->x -= 1;
			changebody(a, b);
			break;
		default:
			stop();
			break;
		}
		
		
		switch (nandu)//�����ٶ� 
		{
		case 1:
			Sleep(20);
			break;
		case 2:
			Sleep(50);
			break;
		case 3:
			Sleep(70);
			break;
		case 4:
			Sleep(100);
			break;
		case 5:
			Sleep(200);
			break;
		}
}

void changebody(int a, int b)
{
	snake* p = tou->next;
	int q1, q2, qq1, qq2;
	q1 = p->x, q2 = p->y;
	while (p->next!=NULL)
	{
		qq1 = p->next->x;
		qq2 = p->next->y;
		p->next->x = q1;
		p->next->y = q2;
		q1 = qq1;
		q2 = qq2;
		p = p->next;
	}
	p = tou->next;
	p->x = a;
	p->y = b;
	snake *pp;
	pp=tou;
	while(pp!=NULL)
	{
		gotohua(pp->x,pp->y);
		pp=pp->next;
	}
}

void eat()
{
	if (tou->x == food.x && tou->y == food.y)
	{
		creatfood();
		snake* _new = (snake*)malloc(sizeof(snake));
		snake* p;
		p = tou;
		while (1) 
		{ 
			if (p->next->next == NULL) break;			
			p = p->next;
		}		
		p->next = _new;		
		_new->next = wei;		
		score += 1;		
		gotoxy(95, 14);		
		printf("%d", score);
	}
}

void finish()
{
	int i,j;
	for(i=0;i<30;i++)
		for(j=0;j<150;j++)
		{
			gotochu(j,i);
		}
	gotoxy(30, 6);
	printf("********************************************************");
	gotoxy(44, 13);
	printf("ŷ���ҵ��ϵۣ�������ѷ���ˡ�");
	gotoxy(53, 15);
	printf("��Ϸ����");
	gotoxy(30, 21);
	printf("********************************************************");
	gotoxy(0,25);
}

void stop()
{
	snake *p;
	p=tou;
	while(p!=NULL)
	{
		gotohua(p->x,p->y);
		p=p->next;
	}
	getch();
}



































