#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__
// �ڷḦ �Ϸķ� ������ �ϴ� ���� �̰� �ݺ����� ������ ������ �����ϴ�. 
// ����� ������ ��ų �ʿ�� ����. 


#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
}Node;

typedef struct _linkedList
{
	Node * head;  // LInkedList�� ������ ��Ÿ���� ����
	Node * cur;   // ���� ������ ���ִ� Node
	Node * befor; // ������ ������ �ִ� ���
	/// Node * tail; ���� linkedList���� tail�� ���� head�� ���ؼ� ���� ���� Ž���� �ϸ� ������ ���Ҹ� ã�� �� �ִ�. 
	int numOfData;
}LinkedList;

typedef LinkedList List;


void ListInit(List * plist);
// List�� ������ �ϰ� ������ ������ �ʱ�ȭ �Ѵ�.
// List�� �޸𸮿� �Ҵ��� �ϰ� ��ó���� �ҷ��� �ϴ� �Լ� 

void LisntInsert(List * plist, LData data);
// �ƹ��͵� �ȵ�� �ִ� List�� �����͸� ���� �Լ� 
// ������� �������� ���� data �Ű������� �־ �ش�. 
// ���� ������ ������ �� ��� �ؾ� �Ѵ�. 
// -- ������ �ؼ� ������ �׳� �ܼ��� ��ġ�� ���� �������Ѵ�. 
// -- ���� �� �� �տ� ���� �� �ƴϸ� ���� ������ �ؼ� ���� ���� ������ �Ѵ�. 

int LFirst(List * plist, LData * pdata);
// List ������ ������ ǥ���� �ִµ� �ű⼱ ������� �׻� �����͸� ã������ �Ҷ� 
// ��ó������ ���ư��� �����͸� �����ϴ� �Լ� 
// ������ ��ȯ ���� TRUE, ������ FALSE

int LNext(List * plist, LData * pdata);
// LFirst �Լ� ������ ����Ʈ�� �ִ� ���ҵ��� ������ �̿��� ���޾� �Ҷ� ���� ȣ�� �Լ� 
// ���� ������  ��ȯ ���� TRUE, ������ FALSE

LData LRemove(List * plist);
// LFirst �� LNext�Լ��� �̿��ؼ� ���������� ������ �����͸� ��ȯ�� �ϰ� ���Ÿ� �Ѵ�. 

int LCount(List * plist);
// ���� ����Ʈ �ȿ� ����� ������ �ľ��� �Ѵ�. 

void SetSortRule(List *plist, int (*comp)(LData n1, LData n2));
// ����Ʈ�� ������ �� �� ������ �Ǵ� �Լ� 

#endif