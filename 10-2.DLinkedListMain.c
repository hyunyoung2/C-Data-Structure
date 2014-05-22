#include <stdio.h>
#include "10.DLinkedList.h"


// List의 comp를 사용하는 방식

int WhoIsPrecede(int d1, int d2)  // 이 함수는 내가 정렬을 할려는 기준을 정하는거 프로그래머에게 자율성을 보장
{
	if(d1 < d2)
		return 0;
	else 
		return 1;
}



int main()
{
	/// 리스트 생성과 초기화 
	List list;
	int data;

	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);  // 리스트로 정렬을 할 기준을 넘긴다. 

	// 5개의 데이터를 삽입 
	ListInsert(&list, 11);
	ListInsert(&list, 11);
	ListInsert(&list, 22);
	ListInsert(&list, 22);
	ListInsert(&list, 33);


	printf("현재 데이터의 수  : %d \n"ㅎ, LCount(&list));

	if(LFirst(&list, &data))
	{

		printf("%d ", data);

		while(LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}


	printf("\n\n");


	if(LFirst(&list, &data))
	{

		if(data == 22)
			LRemove(&list);

		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	// 삭제하고 남아 있는 데이터의 수 
	printf("현재 데이터의 수  : %d \n", LCount(&list));


	
	if(LFirst(&list, &data))
	{

		printf("%d ", data);

		while(LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}


	printf("\n\n");

	return 0;
}
