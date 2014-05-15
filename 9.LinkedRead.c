#include <stdio.h>
#include <stdlib.h>


// 내가 생성을 할 node 타입 설정
typedef struct _node
{
	int data;
	struct _node * next;
}Node;

int main()
{
	// linked list의 시작위치, 현재, 마지막 위치 설정을 위한 변수 
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;

	int readData;

	while(1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		// 힙영역에 메모리를 할당

		newNode = (Node *)malloc(sizeof(Node));
		newNode ->data = readData;
		newNode -> next = NULL;

		/// 각각 생성된 노드를 연결을 하는 부분
		if(head == NULL)
			head =  newNode; 
		else 
			tail -> next = newNode;

		tail =  newNode;

	}

	// 입력을 받은 데이터의 출력과정
    printf("입력 받은 데이터 전체 출력! \n");

	if(head == NULL)
	{
		printf("저장된 자연수가 존재 하지 않습니다.\n");
	}
	else 
	{
		// 여기 서도 처음 부분은 설정을 하고 
		// 그다음 계속 반복적인 호출방식
		cur = head;
		printf("%d ", cur ->data);

		while(cur -> next != NULL)
		{
			cur = cur -> next;
			printf("%d ", cur -> data);
		}
	}

	printf("\n\n");


	// 메모리 해제과정///
	if(head == NULL)
		return 0;

	else 
	{

		// 여기 서도 처음 부분은 설정을 하고 
		// 그다음 계속 반복적인 호출방식
		Node * delNode = head;
		Node * delNextNode = head -> next;


		printf("%d를 삭제합니다. \n", head -> data);
		free(delNode);

		while(delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode -> next;

			printf("%d를 삭제합니다. \n", delNode -> data);
			free(delNode);
		}
	}

	return 0;
}
