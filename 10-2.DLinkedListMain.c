#include <stdio.h>
//#include "10.DLinkedList.h"
#include "fgag.h"

// list의 comp를 사용하는 방식

int WhoIsPrecede(int d1, int d2)
{
	if(d1 < d2)
		return 0;
	else 
		return 1;
}



int main()
{
	/// 리스트의 생성 과 초기화 
	List list;
	int data;

	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);  // 정렬을 할 기준을 정한다. 

	// 5개의 데이터를 저장한다. 
	ListInsert(&list, 11);
	ListInsert(&list, 11);
	ListInsert(&list, 22);
	ListInsert(&list, 22);
	ListInsert(&list, 33);


	printf("현재 데이터의수 : %d \n", LCount(&list));

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

	// 삭제를 하고 남아 있는 데이터 수 
	printf("현재 데이터의수 : %d \n", LCount(&list));


	
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