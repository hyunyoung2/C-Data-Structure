#include <stdio.h>
#include <stdlib.h>


// ���� ������ �� node Ÿ�� ����
typedef struct _node
{
	int data;
	struct _node * next;
}Node;

int main()
{
	// linked list�� ������ġ, ����, ������ ��ġ ������ ���� ���� 
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;

	int readData;

	while(1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		// �������� �޸𸮸� �Ҵ�

		newNode = (Node *)malloc(sizeof(Node));
		newNode ->data = readData;
		newNode -> next = NULL;

		/// ���� ������ ��带 ������ �ϴ� �κ�
		if(head == NULL)
			head =  newNode; 
		else 
			tail -> next = newNode;

		tail =  newNode;

	}

	// �Է��� ���� �������� ��°���
    printf("�Է� ���� ������ ��ü ���! \n");

	if(head == NULL)
	{
		printf("����� �ڿ����� ���� ���� �ʽ��ϴ�.\n");
	}
	else 
	{
		// ���� ���� ó�� �κ��� ������ �ϰ� 
		// �״��� ��� �ݺ����� ȣ����
		cur = head;
		printf("%d ", cur ->data);

		while(cur -> next != NULL)
		{
			cur = cur -> next;
			printf("%d ", cur -> data);
		}
	}

	printf("\n\n");


	// �޸� ��������///
	if(head == NULL)
		return 0;

	else 
	{

		// ���� ���� ó�� �κ��� ������ �ϰ� 
		// �״��� ��� �ݺ����� ȣ����
		Node * delNode = head;
		Node * delNextNode = head -> next;


		printf("%d�� �����մϴ�. \n", head -> data);
		free(delNode);

		while(delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode -> next;

			printf("%d�� �����մϴ�. \n", delNode -> data);
			free(delNode);
		}
	}

	return 0;
}
