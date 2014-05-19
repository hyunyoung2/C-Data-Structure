#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__
// 자료를 일렬로 나열을 하는 구조 이고 반복적인 데이터 삽입이 가능하다. 
// 저장된 순서를 지킬 필요는 없다. 


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
	Node * head;  // LInkedList의 시작을 나타내는 변수
	Node * cur;   // 현재 참조할 수있는 Node
	Node * befor; // 삭제시 도움을 주는 노드
	/// Node * tail; 굳이 linkedList에서 tail을 몰라도 head를 통해서 차근 차근 탐색을 하면 마지막 원소를 찾을 수 있다. 
	int numOfData;
}LinkedList;

typedef LinkedList List;


void ListInit(List * plist);
// List를 생성을 하고 각각의 값들을 초기화 한다.
// List를 메모리에 할당을 하고 맨처음에 불러야 하는 함수 

void LisntInsert(List * plist, LData data);
// 아무것도 안들어 있는 List에 데이터를 넣을 함수 
// 집어넣을 데이터의 값은 data 매개변수에 넣어서 준다. 
// 넣을 방향을 설정을 잘 고려 해야 한다. 
// -- 정렬을 해서 넣을지 그냥 단순히 배치를 할지 결졍을한다. 
// -- 넣을 때 맨 앞에 넣을 지 아니면 끝에 연결을 해서 넣을 지를 결정을 한다. 

int LFirst(List * plist, LData * pdata);
// List 형태의 데이터 표현이 있는데 거기선 순서대로 항상 데이터를 찾으려고 할때 
// 맨처음으로 돌아가서 데이터를 참조하는 함수 
// 있으면 반환 값을 TRUE, 없으면 FALSE

int LNext(List * plist, LData * pdata);
// LFirst 함수 다음에 리스트에 있는 원소들을 참조을 이여서 연달아 할때 마다 호출 함수 
// 참조 성공시  반환 값을 TRUE, 없으면 FALSE

LData LRemove(List * plist);
// LFirst 나 LNext함수를 이용해서 마지막으로 참조한 데이터를 반환을 하고 제거를 한다. 

int LCount(List * plist);
// 현재 리스트 안에 노드의 갯수를 파악을 한다. 

void SetSortRule(List *plist, int (*comp)(LData n1, LData n2));
// 리스트를 정렬을 할 때 기준이 되는 함수 

#endif