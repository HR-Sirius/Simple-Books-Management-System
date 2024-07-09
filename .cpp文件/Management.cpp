/*********************************************
	Filename:Management.cpp
	Time:2024/7/9
	Author:Haoren wang
	Description:Management��Ķ���

**********************************************/

#include"Management.h"

extern Book All_Books[50];
extern Users All_Users[50];

void Management::Bubble_sort(int N[], int M[], int length)
{
	//�������ֵ�Ӵ�С���У������ı�ԭ�����ֵ
	//��̬����ָ�����飬��ԭ�����������ָ�������н���
	int** parray = (int**)malloc(sizeof(int*) * length);
	int i, j;
	for (i = 0; i < length; i++)
	{
		parray[i] = (int*)malloc(sizeof(int));
	}

	//ָ������Ԫ����ԭ����Ԫ��һһ��Ӧ
	for (i = 0; i < length; i++)
	{
		parray[i] = &N[i];
	}

	//�Ӵ�Сð������
	int* temp = NULL;
	for (j = length - 1; j >= 0; j--)
		for (i = 0; i < j; i++)
		{
			if (*parray[i] < *parray[i + 1])
			{
				// ����ָ��ָ��,ʹparray[1]ָ�������ֵ
				temp = parray[i];
				parray[i] = parray[i + 1];
				parray[i + 1] = temp;
			}
			else;
		}

	//������������M[]��
	for (i = 0; i < length; i++)
	{
		M[i] = N[i];
	}

	//��һ�ͷſռ�
	for (i = 0; i < length; i++)
	{
		free(parray[i]);
	}
	free(parray);
}