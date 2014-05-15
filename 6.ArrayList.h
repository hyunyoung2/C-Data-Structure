#ifndef __ARRAY_LIST_H__
// List의 원소를 구조체로 하기 위한 준비
#include "7.Point.h"
#define __ARRAY_LIST_H__


//  c언어에서 true, false 값을 설정
#define TRUE 1
#define FALSE 0

// 순차리스트의 최대길이 설정
#define LIST_LEN 100

// 2. list 원소를 구조체로 변환
typedef Point* LData; 



// 리스트에 저장될 데이타 타입 설정
//typedef int LData;


//배열 기반 리스트의 구조체
typedef struct __ArrayList
{
	LData arr[LIST_LEN]; // 배열
	int curPosition;  // 현재 위치
	int numOfData;  // 리스트 원소 수 
}ArrayList;

typedef ArrayList List;  

void ListInit(List * plist);              // List를 생성  
// 초기화 할 리스트의 주소갑을 인자로 전달
// 리스트를 생성한 후에 제일먼저 호출이 이루어져야 한다.

void LInsert(List * plist,LData data);    // List에 데이터  삽입
// 리스트에 데이터를 저장한다. 매개변수 data에 저장된 값을 저장한다. 

int LFirst(List * plist, LData * pdata); // 첫 번째 데이터 참조 
//첫번째 데이터가 pdata가 가르키는 메모리에 저장된다. 
// 데이터의 참조를 위한 초기화가 진행된다.
/// 참조 성공 시 TRUE(1), 참조 실패시 FALSE(0)

int LNext(List * plist, LData * pdata);  // 두번째 이후 데이터 참소 
//LFirst를 통행 처음 참조 후 계속해서 마지막 원소까지 참조를 한다. 
// 순차적인 참조를 하니 반복문에 호출 
/// 참조 성공 시 TRUE(1), 참조 실패시 FALSE(0)


LData LRemove (List * plist); // 참조된 데이터를 삭제
// LFirst, LNext 함수에 의한 최근에 참조된 값을 삭제
// 삭제된 데이터는 반환한다. (메모리 해제 책임 전가)
// 마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다. 


int LCount(List * plist);   // 저장된 데이터의 수변환 
// 리스트에 저장되어 있는 데이터의 수를 반환한다. 

#endif