#include <stdio.h>
#include <stdlib.h>
#include "6.ArrayList.h"
#include "7.Point.h"

int main(void)
{
	List list;
	Point comPos; // 비교할 좌표값
	Point * ppos;

	ListInit(&list);

	//4개의 데이터 저장 
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);


	// 저장된 데이터 출력
	printf("현재 데이터의 수 : %d\n", LCount(&list));
	if(LFirst(&list, & ppos))
	{
		ShowPointpos(ppos);

		while(LNext(&list, &ppos))
			ShowPointpos(ppos);
	}
	printf("\n");
	// xpos가 (2 , 0)인 데이터는 모두 삭제를 하자 

	comPos.xpos =2;
	comPos.ypos = 0;

	if(LFirst(&list, &ppos))
	{
		if(PointComp(ppos, &comPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while(LNext(&list, &ppos))
		{
			if(PointComp(ppos, &comPos) ==1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}


	}

	// 삭제를 하고 남아있는 데이터 수 
	printf("현재 데이터의 수 : %d\n", LCount(&list));
	if(LFirst(&list, & ppos))
	{
		ShowPointpos(ppos);

		while(LNext(&list, &ppos))
			ShowPointpos(ppos);
	}
	printf("\n");

	return 0;
}

