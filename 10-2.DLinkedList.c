#include <stdio.h>
#include <stdlib.h>
//#include "10.DLinkedList.h"
#include "fgag.h"

void ListInit(List * plist)
{
	plist -> head = (Node *)malloc(sizeof(Node));
	plist -> head -> next = NULL;
	plist -> numOfData = 0;
	//plist -> comp = NULL;
}

// comp �� NULL �̹Ƿ� head ������ �ٷ� ��带 ������ �Ѵ�. 
void ListInsert(List *plist, LData data)
{
	/*
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode -> data = data;

	newNode -> next = plist -> head -> next;
	plist -> head ->next = newNode;

	plist->numOfData++;*/

	Node * newNode = (Node *)malloc(sizeof(Node));
	Node * preNode = plist -> head;
	int d;

	newNode -> data = data;

	// c�� ���� �񱳿��꿡�� ���� ���� ���� ���̸� �׳� �Ѿ��. 
	while(preNode -> next && (d = plist->comp(data, preNode -> next -> data)) != 0)
	{
		preNode = preNode->next;
	}

	newNode -> next = preNode -> next;
	preNode -> next = newNode;

	plist->numOfData++;
}

int LFirst(List * plist, LData * data)
{
	if(plist -> head -> next == NULL)
		return FALSE;

	plist -> cur = plist -> head -> next;
	plist -> before = plist -> head;

	(*data) =  plist -> cur -> data;

	return TRUE;
}


int LNext(List * plist, LData * data)
{
	if(plist ->cur -> next == NULL)
		return FALSE;

	plist -> before = plist -> cur;
	plist -> cur = plist -> cur -> next;

	*data = plist -> cur -> data;

	return TRUE;
}

LData LRemove(List * plist)
{
	Node * ref = plist -> cur;
	LData data = plist -> cur -> data;

	plist -> before -> next = plist -> cur -> next;
	plist -> cur = plist -> before;

	free(ref);
	plist -> numOfData--;

	return data;
}

int LCount(List * plist)
{
	return plist -> numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist -> comp  = comp;
}