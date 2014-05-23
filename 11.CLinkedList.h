#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;


typedef struct  _node
{
	Data data;
	struct _node * next;
}Node;

typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List * plist);

/// ���⼭ ���� ���� ������ �����Լ� �Ӹ��� ���� �Լ��� ���� ������ �� ���´�.
void LInsert(List * plist, Data data);  // ����Ʈ ������ �߰��� ���� �Լ� 
void LInsertFront(List * plist, Data data); // ����Ʈ �Ӹ��� �߰��� ���� �Լ�

// �Ʒ��� �⺻������ ����Ʈ�� ������ �ؾ� �ҵ� �ʿ��� ADT �Լ� ���̴�. 
int LFirst(List * plist, Data * data);
int LNext(List * plist, Data * data);
Data LRemove(List * plist);
int LCount(List * plist);

#endif