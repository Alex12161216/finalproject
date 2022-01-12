#include <stdio.h>
#include <stdlib.h>
#include <Header.h>
#include <time.h>

void display(char x[][10]);
void detect(int s, int p, char x[][10], char use[][10]);
void reset(char x[][10], char k);
char r[10][10];
// *�N����  c�N��a�p 
int main(void)
{
	int i, j, dx, dy, point = 0;
	char use[10][10];  //���a�ù�
	char answer[10][10];  //����
	int xi, yi;
	int boom = 6;  //�a�p����
	srand(time(NULL));

	 //��l��
	reset(answer, ' ');
	reset(use, '*');
	  
	for (i = 1; i <= boom; i++)  //�üƶ묵�u
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

	for (i = 0; i <= 9; i++) //�񵪮�
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
		printf("�п�Jxy�y��(���k��x,�W�U��y)\n");
		scanf_s("%d" "%d", &xi, &yi);
		system("cls");

		if (answer[xi][yi] == 'c')  //�P�O�O�_���a�p
		{
			print(2);  //��ܥ���
			printf("�O�_��̲ܳ׵���???(1:�O , 2:�_)");
			scanf_s("%d",&i);
			if (i == 1)
			{
				printf("�W�@�B��:(%d %d)\n", xi, yi);
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
		print(1);  //��ܦ��\
	}
}

void display(char x[][10])  //���
{
	int i, j;
	printf("  |");
	for (j = 0; j <= 9; j++)  //���x�b
	{
		printf("%2d  ", j);
	}
	printf("\n__|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n  |\n");
	for (i = 0; i <= 9; i++)  //���y�b
	{
		printf("%d |", i);
		for (j = 0; j <= 9; j++)
		{
			printf(" %c |", x[j][i]);
		}
		printf("\n  |--- --- --- --- --- --- --- --- --- ---\n");
	}
}
void detect(int xi, int yi, char x[][10], char use[][10])  //�ƪ��񦳴X���a�p
{
	int flag = 0;
	if (yi == 0 && xi <= 8 && xi >= 1)  //�W��
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
	else if (yi == 9 && xi <= 8 && xi >= 1)  //�U��
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
	else if (yi == 0 && xi == 0)  //���W��
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
	else if (yi == 0 && xi == 9)  //�k�W��
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
	else if (yi == 9 && xi == 0)  //���U��
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
	else if (yi == 9 && xi == 9)  //�k�U��
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
	else if (xi == 9 && yi >= 1 && yi <= 8)  //�k��
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
	else if (xi == 0 && yi >= 1 && yi <= 8)  //����
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
	else if (yi <= 8 && yi >= 1 && xi <= 8 && xi >= 1)  //9�汽�p
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
