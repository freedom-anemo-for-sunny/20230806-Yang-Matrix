#define  _CRT_SECURE_NO_WARNINGS  1
#pragma  warning(disable:6031)

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
////练习1-旋转字符串
//void spin(char* str1, int length)
//{
//	char tmp = 0;
//	int i = 0;
//	tmp = str1[length - 1];
//	for (i = length - 2; i >= 0; i--)
//		str1[i + 1] = str1[i];
//	str1[0] = tmp;
//}
//
//int main()
//{
//	char str1[20] = { 0 };
//	int i = 0;
//	printf("请输入第1个字符串(不带空格等)");
//	scanf("%s", str1);
//	assert(strlen(str1) < 20);
//	char str2[20] = { 0 };
//	printf("请输入第2个字符串(不带空格等)");
//	scanf("%s", str2);
//	assert(strlen(str2) < 20);
//	if (strlen(str1) != strlen(str2))
//		printf("这两个字符串不互为旋转字符串");
//	else
//	{
//		for (i = 0; i < strlen(str1) - 2; i++)
//		{
//			if (!(strcmp(str1, str2)))
//				break;
//			spin(str1, strlen(str1));
//		}
//		if (i == strlen(str1) - 2)
//		{
//			if (!(strcmp(str1, str2)))
//				printf("这两个字符串互为旋转字符串，旋转了%d次", i);
//			else
//				printf("这两个字符串不互为旋转字符串");
//		}
//		else
//			printf("这两个字符串互为旋转字符串，旋转了%d次", i);
//	}
//}//编译器会对str2报错，之后再改
// //之前报错的原因是没有对arr2的范围进行控制

//练习2-杨氏矩阵
#define ROW 10
#define COLUMN 10

int search(int matrix[ROW][COLUMN], int s)
{
	int rowleft = 0, rowright = ROW - 1;
	int colleft = 0, colright = COLUMN - 1;
	int rowmiddle, colmiddle;
	while ((rowright - rowleft) | (colright - colleft))
	{
		rowmiddle = (rowleft + rowright) / 2;
		colmiddle = (colleft + colright) / 2;
		if (s < matrix[rowmiddle][colmiddle])
		{
			rowright = rowmiddle;
			colright = colmiddle;
		}
		else if (s > matrix[rowmiddle][colmiddle])
		{
			rowleft = rowmiddle;
			colleft = colmiddle;
		}
		else
		{
			printf("找到了，下标是[%d][%d]", rowmiddle, colmiddle);
			return 1;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int matrix[ROW][COLUMN] = { 0 };
	int s = 0;
	int i = 0, j = 0;
	int f = 0;
	for (i = 0; i < ROW; i++)
	{
		if (!i)
		{
			if (!j)
			{
				matrix[i][j] = rand() % 1024;
				printf("%5d ", matrix[i][j]);
			}
			for (j = 1; j < COLUMN; j++)
			{
				matrix[i][j] = matrix[i][j - 1] + rand() % 1024;
				printf("%5d ", matrix[i][j]);
			}
		}
		else
			for(j=0;j<COLUMN;j++)
			{
				if (!j)
				{
					matrix[i][j] = matrix[i - 1][j] + rand() % 1024;
					printf("%5d ", matrix[i][j]);
				}
				else
				{
					int max = max(matrix[i - 1][j], matrix[i][j - 1]);
					matrix[i][j] = max + rand() % 1024;
					printf("%5d ", matrix[i][j]);
				}
			}
		printf("\n");
	}
	printf("以上为杨氏矩阵，请输入需要在矩阵中查找的数");
	scanf("%d", &s);
	if (!search(matrix, s))
		printf("没有找到该数");
	return 0;
}
//该练习不会做