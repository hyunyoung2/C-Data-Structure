#include <stdlib.h>
#include <stdio.h>
#include "6.ArrayList.h"

// �迭�� ������ List�� Ȱ���� ���̴�. 
// ���� : 1. �迭�� ������ ������ ���� ������(�ε��������� ������ �ѹ��� ������ �����ϱ⶧����)
//		     �׷� �迭�� ������ ������ �ϱ� ������ �迭��� ����Ʈ�� ������ ����. 

// ���� : 1. �迭�� ���̰� �ʱ⿡ ������ �Ǿ�� �Ѵ�.  �迭�� ���� ������ �������� �Ұ���
//		  2. ������ �������� ������ �̵��� ���� �� �Ͼ� ����. 



// List �ʱ�ȭ 
// ���� ����Ʈ ���� ���� ���� 0��
// ��ġ�� ���� �迭�� �ε��� 0
// �迭 �ʱ�ȭ�� ���� �ʾҴ�. 
void ListInit(List * plist)
{
   plist -> curPosition =  -1; // �ƹ��͵� ����Ű�� �ʴ´ٴ� ���� ǥ��
   plist -> numOfData =  0;
}


void LInsert(List * plist, LData  data)
{
	if(plist -> numOfData == 100)
	{
		printf("���̻� ������ �� ������ �����ϴ�.\n");
		return;
	}

	plist -> curPosition++;
	plist ->arr[plist -> curPosition] = data;
	plist -> numOfData++;
}

// ������ ������ ó������ �ϱ� ���� �Լ� 
int LFirst(List * plist, LData * pdata)
{
	if(plist -> numOfData != 0)
	{
		plist -> curPosition  = 0; // ó�� ���� ����
		*pdata = plist -> arr[plist -> curPosition];
		return TRUE;
	}
	else
	{
		printf("List���� ���Ұ� ������ �Ǿ����� �ʽ��ϴ�.");
		return FALSE;
	}
}

// ������ ������ ���� ���������� �������� �Ѵ�. 
int LNext(List * plist, LData * pdata)
{
	if(plist -> curPosition >= (plist -> numOfData)-1)
		return FALSE;
	

	plist ->curPosition++;
	*pdata = plist->arr[plist -> curPosition];

	return TRUE;
}

/// �ֱ��� ������ �̷���� �����͸� ����� ���� �Լ� 
// ���� �Ҵ��� ����Ʈ�� ������ �޸� ������ ���� å�� ������ ����  LData
LData LRemove(List *plist)
{
	int rpos = plist -> curPosition;
	int num = plist -> numOfData;
	int i;
	LData rdata = plist -> arr[rpos];

	for(i = 0 ; i < num - rpos -1 ; i++)
	{
		plist -> arr[rpos + i] = plist -> arr[rpos + i +1]; 
	}

	plist -> numOfData--;
	plist ->curPosition--; // ������ �ϴ� ������ �ֱ� ������ ���� ��ġ�� ��Ÿ���� ���� 

	return rdata;
}

int LCount(List * plist)
{
	return plist -> numOfData;
}







