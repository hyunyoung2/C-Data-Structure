#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__
// linkedList  headefile
// 여기 LinkedList 에서 그냥 dummy node를 사용하는 list 
/// 참조하는 거산 삽입을 하는 방식에 있어서 일관성을 유지 하기 위한 dummy node 활용


// c 언어에서 참과 거짓을 표현을 하는 방식
#define TRUE 1
#define FALSE 0

typedef int LData;
// 노드이 데이터 영역을 설정을 간단히 바꾸기 위한 조치 


typedef struct _node
{
	LData data;
	struct _node* next;
}Node;
// 리스트 안에 들어가 노드를 설정


typedef struct _linkedList
{
	Node * head;  // 리스트 처음 나타내는 부분
	Node * cur;   // 리스트 원소를 참조를 할때 필요한 부분
	Node * before; // 리스트 삭제 할때 필요한 부분
	/// Node * tail; //리스트의 끝을 나타내는 부분 인데 그냥 여기서 맨앞에 삽입 하는 방식이 되면 필요가 없다. 
	int numOfData;
	int comp(LData d1 , LData d2 );  // 이값을 NULL로 초기화 한다면 head 에 삽입을 하는 방시긍로 구현을 하겠다는 것이다. 
	// d1, d2라고 붙인 이유는 변수를 사용을 하기 위함이다. 
}LinkedList;
// 리스트라는 자료구조 표현 


typedef LinkedList List;
// 리스트는 자료을 선형으로 나열을 하는 방식인데 그것을 표현하는 방식이 배열과 동적할당 방식이 있다. 그것을 표현을 하기 위해서 

void ListInit(List * plist);
// 항상 리스트 생성을 하고 나서 초기화 할때 사용 하는 함수 
// 리스트를 생서을 하고 나면 항사 초기화를 해주어야 한다. 

void ListInsert(List * plist, LData data);
// 이 삽입을 하는데  comp 가 NULL이므로 그냥 head에 삽입을 한다. 

int LFirst(List * plist, LData * pdata);
// List는 참조를 한다고 하면 뒤로 가지 못하는 방식이라 현재 리스트는 
// 그냥 처음부터 차근 차근 참조를 하기 위한 함수 
// parameter 의 두번째는 지금 참조를 한 데이터를 호출한 함수 영역으로 전달을 하기 위한 변수 
// 반환영힝 정의 가 되어 있는 이유는 참조 성공 / 실패를 나타내기 위해서 

int LNext(List * plist, LData * pdata);
// 첫번째 노드를 참조를 하는 것은 좋은데 거기서 계속 진행을 하기 위한 함수 
// 여기서 parameter 역확은 처 번째 노드를 참조하는 함수와 같은 역활
// 반환형을 주는 이유는 성공 실패를 나타내기 위해서 

LData LRemove(List * plist);
// 만약에 내가 리스트에서 지우고 싶은 원소를 선택을 해서 보내고 싶으면 
// parameter로 지우고자 하는 데이터를 추가하면 된다. 
// 지우고자 하는 데이터를 반환을 하고 있는데 그이유는 그 데이터 처리 권한을 넘기기 위해서 이다. 
// 그리도 여기서 parameter로  넘기는 게 하나 인거는 그냥 최근에 참조한 노드를 삭제를 하겠다는 의미이다. 

int LCount(List * plist);
// 그리고 리스트에 항상 보너스 함수 노드의 갯수는 몇 개인가를 나나태는 함수 

void SetSortRule(List *plist, int (*comp)(LData n1, LData n2));
// 그리고 여기 리스트에 노드를 첨가를 할때 정렬을 하기위한 함수 
// 함수 포인터를 쓰는 이유는 오름 차순, 내림 차순으로 할지를 자유롭게 하기 위해서 

#endif