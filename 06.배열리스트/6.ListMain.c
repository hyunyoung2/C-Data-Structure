// List ADT
// List�� �����Ͱ� ������ ���� *** �ߺ��� ������ ���� ����
// �ϴ� �迭�� ��������
// 1. List ���� �� �ʱ�ȭ 
// 2. �ڷ� ���� -- ������ ��ġ 
// 3. �ڷ� ���� -- ������ ��ġ ����


#include <stdio.h>
#include "6.ArrayList.h"


int main(void)
{

	List list; // List ����
	int data;
	ListInit(&list); // List �ʱ�ȭ

	// List�� data ����
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);


	//List�� ������ �Ǿ��ִ� ���� �� 
	printf("���� ������ ���� ��: %d\n", LCount(&list));


	// List ��ü �˻�
	if(LFirst(&list, &data))
	{
		printf("%d " , data);

		while(LNext(&list, &data))
			printf("%d " , data);
	}

	printf("\n");
	printf("\n");
	

	// List���� ���� ���� Ư�� ���� ���� 
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


	// ������ List�� ������ �Ǿ��ִ� ���� �� 
	printf("���� ������ ���� ��: %d\n", LCount(&list));


	if(LFirst(&list, &data))
	{
		printf("%d " , data);

		while(LNext(&list, &data))
			printf("%d " , data);
	}

	printf("\n");
	printf("\n");

	// c���� list�� ���� ������ �������� Ȯ��
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

