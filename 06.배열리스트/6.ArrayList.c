#include <stdlib.h>
#include <stdio.h>
#include "6.ArrayList.h"

// 배열을 가지고 List로 활용한 예이다. 
// 장점 : 1. 배열의 데이터 참조는 쉽기 때문에(인덱스값으로 어디든지 한번에 참조가 가능하기때문에)
//		     그런 배열을 가지고 참조를 하기 때문에 배열기반 리스트는 참조가 쉽다. 

// 단점 : 1. 배열의 길이가 초기에 결정이 되어야 한다.  배열의 길이 변경을 동적으로 불가능
//		  2. 삭제의 과정에서 데이터 이동이 번번 히 일어 난다. 



// List 초기화 
// 현재 리스트 안의 원소 갯수 0개
// 위치도 현재 배열을 인덱스 0
// 배열 초기화는 하지 않았다. 
void ListInit(List * plist)
{
   plist -> curPosition =  -1; // 아무것도 가리키지 않는다는 것을 표현
   plist -> numOfData =  0;
}


void LInsert(List * plist, LData  data)
{
	if(plist -> numOfData == 100)
	{
		printf("더이상 저장을 할 공간이 없습니다.\n");
		return;
	}

	plist -> curPosition++;
	plist ->arr[plist -> curPosition] = data;
	plist -> numOfData++;
}

// 데이터 참조을 처음부터 하기 위한 함수 
int LFirst(List * plist, LData * pdata)
{
	if(plist -> numOfData != 0)
	{
		plist -> curPosition  = 0; // 처음 부터 참조
		*pdata = plist -> arr[plist -> curPosition];
		return TRUE;
	}
	else
	{
		printf("List에는 원소가 저장이 되어있지 않습니다.");
		return FALSE;
	}
}

// 데이터 참조를 차근 순차적으로 다음것을 한다. 
int LNext(List * plist, LData * pdata)
{
	if(plist -> curPosition >= (plist -> numOfData)-1)
		return FALSE;
	

	plist ->curPosition++;
	*pdata = plist->arr[plist -> curPosition];

	return TRUE;
}

/// 최근의 참조가 이루어진 데이터를 지우기 위한 함수 
// 동적 할당한 리스트의 원소의 메모리 해제에 대한 책임 전가를 위한  LData
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
	plist ->curPosition--; // 삭제를 하는 이유는 최근 참조한 값의 위치를 나타내기 위해 

	return rdata;
}

int LCount(List * plist)
{
	return plist -> numOfData;
}







