#define _CRT_SECURE_NO_WARNINGS 1

#include "Backgammon.h"

void menu()//打印游戏开始界面
{
	printf("欢迎来到三子棋游戏\n");
	printf("1. play  0. exit             \n");
	printf("******************\n");
}

void Game()
{
	char ret = '0';
	char board[ROW][COL] = { 0 };//建立一个数组用于存放棋盘信息
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//将棋盘打印出来
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);//显示玩家下的位置
		ret=IsWin(board, ROW, COL);
		if (ret != 'G')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);//显示电脑下的位置
		ret = IsWin(board, ROW, COL);
		if (ret != 'G')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("您赢了\n");
	}
	else if (ret == '#')
	{
		printf("您输了\n");
	}
	else
	{
		printf("平局\n");
	}
}

void test()//游戏运行测试函数
{
	int x = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入您的选择：>\n");//选择是否开始游戏
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("开始游戏：\n");
			Game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	} while (x);
}

int main()//主函数
{
	test();
	return 0;
}