#include <stdio.h>
#include <stdlib.h>
#include <Header.h>
#include <time.h>

void display(char x[][10]);
void detect(int s, int p, char x[][10], char use[][10]);
void reset(char x[][10], char k);
char r[10][10];
// *代表未知  c代表地雷 
int main(void)
{
	int i, j, dx, dy, point = 0;
	char use[10][10];  //玩家螢幕
	char answer[10][10];  //答案
	int xi, yi;
	int boom = 6;  //地雷顆數
	srand(time(NULL));

	 //初始化
	reset(answer, ' ');
	reset(use, '*');
	  
	for (i = 1; i <= boom; i++)  //亂數塞炸彈
	{
		dx = rand() % 10;
		dy = rand() % 10;	
		if (answer[dx][dy] == 'c')
		{
			i = i - 1;
		}
		answer[dx][dy] = 'c';
	}

	display(use);

	for (i = 0; i <= 9; i++) //填答案
	{
		for (j = 0; j <= 9; j++)
		{
			if (answer[i][j] != 'c')
			{
				detect(i, j, answer, answer);
			}
		}
	}

	display(answer);

	while (point != (100 - boom))
	{
		printf("請輸入xy座標(左右為x,上下為y)\n");
		scanf_s("%d" "%d", &xi, &yi);
		system("cls");

		if (answer[xi][yi] == 'c')  //判別是否踩到地雷
		{
			print(2);  //顯示失敗
			printf("是否顯示最終答案???(1:是 , 2:否)");
			scanf_s("%d",&i);
			if (i == 1)
			{
				printf("上一步為:(%d %d)\n", xi, yi);
				display(use);
				display(answer);
			}
			break;
		}
		else
		{
			point = 0;
			reset(r, ' ');
			detect(xi, yi, answer, use);
			for (i = 0; i <= 9; i++)
			{
				for (j = 0; j <= 9; j++)
				{
					if (answer[i][j] == use[i][j])
					{
						point = point + 1;
					}
				}
			}
			display(use);
		}
	}
	if (point == (100 - boom))
	{
		system("cls");
		print(1);  //顯示成功
	}
}

void display(char x[][10])  //顯示
{
	int i, j;
	printf("  |");
	for (j = 0; j <= 9; j++)  //顯示x軸
	{
		printf("%2d  ", j);
	}
	printf("\n__|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n  |\n");
	for (i = 0; i <= 9; i++)  //顯示y軸
	{
		printf("%d |", i);
		for (j = 0; j <= 9; j++)
		{
			printf(" %c |", x[j][i]);
		}
		printf("\n  |--- --- --- --- --- --- --- --- --- ---\n");
	}
}
void detect(int xi, int yi, char x[][10], char use[][10])  //數附近有幾顆地雷
{
	int flag = 0;
	if (yi == 0 && xi <= 8 && xi >= 1)  //上邊
	{
		if (x[xi + 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi + 1][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (flag != 0)
		{
			use[xi][yi] = flag + '0';
			flag = 0;
		}
		else
		{
			use[xi][yi] = ' ';
			if (r[xi][yi] != 'r')
			{
				r[xi][yi] = 'r';
				detect(xi + 1, yi, x, use);
				detect(xi + 1, yi + 1, x, use);
				detect(xi - 1, yi, x, use);
				detect(xi, yi + 1, x, use);
				detect(xi - 1, yi + 1, x, use);
			}
		}
	}
	else if (yi == 9 && xi <= 8 && xi >= 1)  //下邊
	{
		if (x[xi + 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi + 1][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (flag != 0)
		{
			use[xi][yi] = flag + '0';
			flag = 0;
		}
		else
		{
			use[xi][yi] = ' ';
			if (r[xi][yi] != 'r')
			{
				r[xi][yi] = 'r';
				detect(xi + 1, yi, x, use);
				detect(xi - 1, yi, x, use);
				detect(xi - 1, yi - 1, x, use);
				detect(xi, yi - 1, x, use);
				detect(xi + 1, yi - 1, x, use);
			}
		}
	}
	else if (yi == 0 && xi == 0)  //左上角
	{
		if (x[xi + 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi + 1][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (flag != 0)
		{
			use[xi][yi] = flag + '0';
			flag = 0;
		}
		else
		{
			use[xi][yi] = ' ';
			if (r[xi][yi] != 'r')
			{
				r[xi][yi] = 'r';
				detect(xi + 1, yi, x, use);
				detect(xi, yi + 1, x, use);
				detect(xi + 1, yi + 1, x, use);
			}
		}
	}
	else if (yi == 0 && xi == 9)  //右上角
	{
		if (x[xi - 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (flag != 0)
		{
			use[xi][yi] = flag + '0';
			flag = 0;
		}
		else
		{
			use[xi][yi] = ' ';
			if (r[xi][yi] != 'r')
			{
				r[xi][yi] = 'r';
				detect(xi - 1, yi, x, use);
				detect(xi, yi + 1, x, use);
				detect(xi - 1, yi + 1, x, use);
			}
		}
	}
	else if (yi == 9 && xi == 0)  //左下角
	{
		if (x[xi + 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi + 1][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (flag != 0)
		{
			use[xi][yi] = flag + '0';
			flag = 0;
		}
		else
		{
			use[xi][yi] = ' ';
			if (r[xi][yi] != 'r')
			{
				r[xi][yi] = 'r';
				detect(xi + 1, yi, x, use);
				detect(xi, yi - 1, x, use);
				detect(xi + 1, yi - 1, x, use);
			}
		}
	}
	else if (yi == 9 && xi == 9)  //右下角
	{
		if (x[xi - 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (flag != 0)
		{
			use[xi][yi] = flag + '0';
			flag = 0;
		}
		else
		{
			use[xi][yi] = ' ';
			if (r[xi][yi] != 'r')
			{
				r[xi][yi] = 'r';
				detect(xi - 1, yi, x, use);
				detect(xi, yi - 1, x, use);
				detect(xi - 1, yi - 1, x, use);
			}
		}
	}
	else if (xi == 9 && yi >= 1 && yi <= 8)  //右邊
	{
		if (x[xi][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (flag != 0)
		{
			use[xi][yi] = flag + '0';
			flag = 0;
		}
		else
		{
			use[xi][yi] = ' ';
			if (r[xi][yi] != 'r')
			{
				r[xi][yi] = 'r';
				detect(xi, yi - 1, x, use);
				detect(xi - 1, yi, x, use);
				detect(xi - 1, yi - 1, x, use);
				detect(xi - 1, yi + 1, x, use);
				detect(xi, yi + 1, x, use);
			}
		}
	}
	else if (xi == 0 && yi >= 1 && yi <= 8)  //左邊
	{
		if (x[xi][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi + 1][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi + 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi + 1][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (flag != 0)
		{
			use[xi][yi] = flag + '0';
			flag = 0;
		}
		else
		{
			use[xi][yi] = ' ';
			if (r[xi][yi] != 'r')
			{
				r[xi][yi] = 'r';
				detect(xi, yi - 1, x, use);
				detect(xi + 1, yi, x, use);
				detect(xi + 1, yi - 1, x, use);
				detect(xi + 1, yi + 1, x, use);
				detect(xi, yi + 1, x, use);
			}
		}
	}
	else if (yi <= 8 && yi >= 1 && xi <= 8 && xi >= 1)  //9格掃雷
	{
		if (x[xi + 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi + 1][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi + 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi - 1][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (x[xi + 1][yi - 1] == 'c')
		{
			flag = flag + 1;
		}
		if (flag != 0)
		{
			use[xi][yi] = flag + '0';
			flag = 0;
		}
		else
		{
			use[xi][yi] = ' ';
			if (r[xi][yi] != 'r')
			{
				r[xi][yi] = 'r';
				detect(xi + 1, yi, x, use);
				detect(xi + 1, yi + 1, x, use);
				detect(xi - 1, yi, x, use);
				detect(xi, yi + 1, x, use);
				detect(xi - 1, yi + 1, x, use);
				detect(xi - 1, yi - 1, x, use);
				detect(xi, yi - 1, x, use);
				detect(xi + 1, yi - 1, x, use);
			}
		}
	}
}
void reset(char x[][10], char k)
{
	int i, j;
	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			x[i][j] = k;
		}
	}
}
