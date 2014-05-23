#include <stdio.h>
#include <stdlib.h>
#include "11.CLinkedList.h"




void ListInit(List * plist)
{
	plist ->tail = NULL;
	plist ->numOfData = 0;

	// �Ʒ��� �ΰԸ� ������ �ؾ� �ϴ� ���� �ñ��ϴ�. 
	// LinkedList ���� ������ �ϱ� ������ �Ҷ��� �ʱ�ȭ �ϴµ� 
	// �ٵ� ���⼭ �ʱ�ȭ �ϴ� ������ ���� ���� ������ ���� ��� ���� ���ϵ��� �ϱ� ���ؼ��̴�. 
	plist -> cur = NULL; 
	plist -> before = NULL;
}


void LInsert(List * plist, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode -> data = data;

	if(plist-> tail == NULL)
	{
		plist -> tail = newNode;
		newNode -> next = newNode;
	}
	else
	{
	   newNode -> next = plist -> tail->next;  // ���� �Ǽ��� �ؼ� ����� �Է��� �ȵǾ���. 
	   plist -> tail -> next = newNode;
	   plist -> tail = newNode; // �̰����� ���ؼ� circular linked List tail�� ������ �ϴ� ���̴�. 
	}

	(plist -> numOfData)++;
}

void LInsertFront(List * plist, Data data)
{
	
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode -> data = data;

	if(plist-> tail == NULL)
	{
		newNode -> next = newNode;
		plist -> tail = newNode;
	}
	else
	{
		// newNode -> next = plist -> tail; �� ��Ĵ�� �Ѵٸ� �׷��� ��尡 2���� circular Linkedlist;
		newNode -> next = plist -> tail -> next;
	    plist -> tail -> next = newNode;
	}

	(plist -> numOfData)++;
}

int LFirst(List * plist, Data * data)
{
	// ����� node�� ���� ��� �̰���  plist -> numOfData == 0���� ������ ��Ƶ� �ȴ�. 
	if(plist -> tail == NULL)
		return FALSE;
	
	// �Ʒ� �ΰ��� ������ ���㵵 ����� ����.
	// ���� CUR, BEFORE �ʱ�ȭ �ϴ� �����̱⶧���̴�. 
		plist -> cur = plist -> tail -> next;
		plist -> before = plist -> tail; 

		*data = plist -> cur -> data;

		return TRUE;
}

int LNext(List * plist, Data * data)
{

	// �Ʒ��� ���� ������ �Ѵٸ� �ѹ��� ���� ���̴�. 
	// �׷��� circular linkedList�� Ư¡�� �ݿ��� �� ���� �ƴϴ�. 
	/*
	if(plist -> tail == plist -> cur) 
		return FALSE;
		*/
	// ������ �Ʒ��� ���� ������ �Ѵٸ� ������ Ư¡ ������ Ž���� �����ϴ�. 
	if(plist -> tail == NULL)
		return FALSE;
	

	// ��� �ȿ� ����ִ� ���� �̿��ؼ� �ϴ� �ͺ��� cur, before�� �̿��ؼ� �ϴ� ���� ����� 
	// ���� ������ �ϱ⿡�� �� ���� �� ����. ���������� �̵��� ���� �ش�. 
		plist -> before = plist -> cur;
		plist -> cur =  plist -> cur -> next;

		*data = plist -> cur -> data;

		return TRUE;
}


// �Ʒ��� ���� ����� ������ ������ circular linkedList tail�� ���̳�帣 ���� �θ� ������ ����������
// �ȵξ��� ������ ����ؾ� �Ѵ�. ������ ������ �Ҷ� ������ �ణ ����������. 
// �������� ��Ȳ�� ����� �ȴ�. 
// 1. ������ ��带 tail�� ����Ű�� ��� 
// 2. ������ ��尡 ����Ʈ�� Ȧ�� ���� ��� 
// ���� ���� ������ ���̳�带 ����ϸ� ���� ������ ������ �ȴ�. 
// ������ �ص� ����Ʈ �������� �Ǿ�� �Ѵٴ� ���̴�. 
// �׷��� ���⼭ ���� ?? 
// �� ���̳�带 circular Linked list���� ����� ���ұ�??
// �� �����ε� �׷��� ���� ������ �Ҷ� �� ����� �ؾ� �Ѵ�. 
// Linked list�� ���̳�带 ������ �ص� �׳� �ѹ� ������ ������ �ϸ� ���̻� ���ε� ���̴�. 
Data LRemove(List * plist)
{
	Node * ref = plist -> cur;
	Data data = plist -> cur -> data;	

    // �Ʒ��� ���ڵ尡 �ٽ����� �����̴�. ����Ʈ�� ������ �ǵ��� ������ ���ִ� 
    plist -> before -> next = plist -> cur -> next;
	plist -> cur = plist -> before;
	//plist -> tail = plist -> before; �̰��� ���� �׳� ��尡 �ϳ���� ������ �ؼ� �׷���. �߸��� �ڵ�

	if(ref == plist -> tail)
	{
	  if(plist -> tail == plist -> tail -> next)
		  plist -> tail = NULL;
	  else
		plist -> tail = plist -> before;
	}
	
	free(ref);
	(plist -> numOfData)--;
	return data;
}

int LCount(List * plist)
{
	return plist ->numOfData;
}