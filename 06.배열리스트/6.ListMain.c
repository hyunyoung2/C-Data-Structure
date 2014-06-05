// List ADT
// List는 데이터가 나란히 저장 *** 중복된 데이터 저장 가능
// 일단 배열로 구현예정
// 1. List 생성 및 초기화 
// 2. 자료 삽입 -- 삽입할 위치 
// 3. 자료 삭제 -- 삽입할 위치 설정


#include <stdio.h>
#include "6.ArrayList.h"


int main(void)
{

	List list; // List 생성
	int data;
	ListInit(&list); // List 초기화

	// List에 data 저장
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);


	//List에 저장이 되어있는 원소 수 
	printf("현재 테이터 저장 수: %d\n", LCount(&list));


	// List 전체 검사
	if(LFirst(&list, &data))
	{
		printf("%d " , data);

		while(LNext(&list, &data))
			printf("%d " , data);
	}

	printf("\n");
	printf("\n");
	

	// List에서 원소 삭제 특정 원소 삭제 
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


	// 삭제후 List에 저장이 되어있는 원소 수 
	printf("현재 테이터 저장 수: %d\n", LCount(&list));


	if(LFirst(&list, &data))
	{
		printf("%d " , data);

		while(LNext(&list, &data))
			printf("%d " , data);
	}

	printf("\n");
	printf("\n");

	// c언어에서 list의 대입 연산이 가능한지 확인
	{
		List l =list;

		if(LFirst(&l, &data))
		{
			printf("%d " , data);

			while(LNext(&l, &data))
				printf("%d " , data);
		}
	}

	return 0;
}

