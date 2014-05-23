#include <stdio.h>
#include <stdlib.h>
#include "11.CLinkedList.h"




void ListInit(List * plist)
{
	plist ->tail = NULL;
	plist ->numOfData = 0;

	// 아래의 두게를 구현을 해야 하는 지가 궁금하다. 
	// LinkedList 에서 참조를 하기 시작을 할때만 초기화 하는데 
	// 근데 여기서 초기화 하는 이유는 쓸데 없는 쓰레기 값이 들어 가지 못하도록 하기 위해서이다. 
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
	   newNode -> next = plist -> tail->next;  // 여기 실수로 해서 제대로 입력이 안되었다. 
	   plist -> tail -> next = newNode;
	   plist -> tail = newNode; // 이것으로 인해서 circular linked List tail에 삽입을 하는 것이다. 
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
		// newNode -> next = plist -> tail; 이 방식대로 한다면 그렇게 노드가 2개인 circular Linkedlist;
		newNode -> next = plist -> tail -> next;
	    plist -> tail -> next = newNode;
	}

	(plist -> numOfData)++;
}

int LFirst(List * plist, Data * data)
{
	// 저장된 node가 없는 경우 이경우는  plist -> numOfData == 0으로 조건을 삼아도 된다. 
	if(plist -> tail == NULL)
		return FALSE;
	
	// 아래 두개의 순서는 빠꿔도 상관이 없다.
	// 가각 CUR, BEFORE 초기화 하는 과정이기때문이다. 
		plist -> cur = plist -> tail -> next;
		plist -> before = plist -> tail; 

		*data = plist -> cur -> data;

		return TRUE;
}

int LNext(List * plist, Data * data)
{

	// 아래와 같이 구현을 한다면 한바퀴 돌고 끝이다. 
	// 그래서 circular linkedList의 특징을 반영을 한 것이 아니다. 
	/*
	if(plist -> tail == plist -> cur) 
		return FALSE;
		*/
	// 하지만 아래와 같이 구현을 한다면 원형의 특징 무한이 탐색이 가능하다. 
	if(plist -> tail == NULL)
		return FALSE;
	

	// 노드 안에 들어있는 값을 이용해서 하는 것보단 cur, before을 이용해서 하는 것이 더욱더 
	// 내가 생각을 하기에는 더 좋은 거 같다. 직관적으로 이동을 보여 준다. 
		plist -> before = plist -> cur;
		plist -> cur =  plist -> cur -> next;

		*data = plist -> cur -> data;

		return TRUE;
}


// 아래와 같은 모양이 나오는 이유는 circular linkedList tail에 더미노드르 놓아 두면 연산이 편해지지만
// 안두었기 때문에 고려해야 한다. 삭제나 삽입을 할때 연산이 약간 복잡해진다. 
// 예외적인 상황이 생기게 된다. 
// 1. 삭제할 노드를 tail이 가르키는 경우 
// 2. 삭제할 노드가 리스트에 홀로 남는 경우 
// 위와 같은 이유로 더미노드를 사용하면 더욱 간단한 구현이 된다. 
// 삭제를 해도 리스트 형식으로 되어야 한다는 것이다. 
// 그러면 여기서 질문 ?? 
// 왜 더미노드를 circular Linked list에서 사용을 안할까??
// 내 생각인데 그러면 무한 참조를 할때 또 고려를 해야 한다. 
// Linked list는 더미노드를 구현을 해도 그냥 한번 끝까지 참조만 하면 더이상 끝인데 말이다. 
Data LRemove(List * plist)
{
	Node * ref = plist -> cur;
	Data data = plist -> cur -> data;	

    // 아래의 두코드가 핵심적인 연산이다. 리스트로 구현이 되도록 유지를 해주는 
    plist -> before -> next = plist -> cur -> next;
	plist -> cur = plist -> before;
	//plist -> tail = plist -> before; 이경우는 내가 그냥 노드가 하나라고 생각을 해서 그렇다. 잘못된 코드

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