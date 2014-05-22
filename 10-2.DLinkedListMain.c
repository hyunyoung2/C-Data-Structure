#include <stdio.h>
//#include "10.DLinkedList.h"
#include "fgag.h"

// list�� comp�� ����ϴ� ���

int WhoIsPrecede(int d1, int d2)
{
	if(d1 < d2)
		return 0;
	else 
		return 1;
}



int main()
{
	/// ����Ʈ�� ���� �� �ʱ�ȭ 
	List list;
	int data;

	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);  // ������ �� ������ ���Ѵ�. 

	// 5���� �����͸� �����Ѵ�. 
	ListInsert(&list, 11);
	ListInsert(&list, 11);
	ListInsert(&list, 22);
	ListInsert(&list, 22);
	ListInsert(&list, 33);


	printf("���� �������Ǽ� : %d \n", LCount(&list));

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

	// ������ �ϰ� ���� �ִ� ������ �� 
	printf("���� �������Ǽ� : %d \n", LCount(&list));


	
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