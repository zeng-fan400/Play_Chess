#define _CRT_SECURE_NO_WARNINGS 1

#include "Backgammon.h"

void menu()//��ӡ��Ϸ��ʼ����
{
	printf("��ӭ������������Ϸ\n");
	printf("1. play  0. exit             \n");
	printf("******************\n");
}

void Game()
{
	char ret = '0';
	char board[ROW][COL] = { 0 };//����һ���������ڴ��������Ϣ
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//�����̴�ӡ����
	while (1)
	{
		PlayerMove(board, ROW, COL);//�������
		DisplayBoard(board, ROW, COL);//��ʾ����µ�λ��
		ret=IsWin(board, ROW, COL);
		if (ret != 'G')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//��������
		DisplayBoard(board, ROW, COL);//��ʾ�����µ�λ��
		ret = IsWin(board, ROW, COL);
		if (ret != 'G')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("������\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

void test()//��Ϸ���в��Ժ���
{
	int x = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("����������ѡ��>\n");//ѡ���Ƿ�ʼ��Ϸ
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("��ʼ��Ϸ��\n");
			Game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������������������\n");
			break;
		}
	} while (x);
}

int main()//������
{
	test();
	return 0;
}