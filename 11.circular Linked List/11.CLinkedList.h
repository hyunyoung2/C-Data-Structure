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

/// 여기서 변한 정보 꼬리에 삽입함수 머리에 삽입 함수를 따로 설정을 해 놓는다.
void LInsert(List * plist, Data data);  // 리스트 꼬리에 추가를 위한 함수 
void LInsertFront(List * plist, Data data); // 리스트 머리에 추가를 위한 함수

// 아래는 기본적으로 리스트를 생성을 해야 할데 필요한 ADT 함수 들이다. 
int LFirst(List * plist, Data * data);
int LNext(List * plist, Data * data);
Data LRemove(List * plist);
int LCount(List * plist);

#endif