#ifndef __ARRAY_LIST_H__
// List�� ���Ҹ� ����ü�� �ϱ� ���� �غ�
#include "7.Point.h"
#define __ARRAY_LIST_H__


//  c���� true, false ���� ����
#define TRUE 1
#define FALSE 0

// ��������Ʈ�� �ִ���� ����
#define LIST_LEN 100

// 2. list ���Ҹ� ����ü�� ��ȯ
typedef Point* LData; 



// ����Ʈ�� ����� ����Ÿ Ÿ�� ����
//typedef int LData;


//�迭 ��� ����Ʈ�� ����ü
typedef struct __ArrayList
{
	LData arr[LIST_LEN]; // �迭
	int curPosition;  // ���� ��ġ
	int numOfData;  // ����Ʈ ���� �� 
}ArrayList;

typedef ArrayList List;  

void ListInit(List * plist);              // List�� ����  
// �ʱ�ȭ �� ����Ʈ�� �ּҰ��� ���ڷ� ����
// ����Ʈ�� ������ �Ŀ� ���ϸ��� ȣ���� �̷������ �Ѵ�.

void LInsert(List * plist,LData data);    // List�� ������  ����
// ����Ʈ�� �����͸� �����Ѵ�. �Ű����� data�� ����� ���� �����Ѵ�. 

int LFirst(List * plist, LData * pdata); // ù ��° ������ ���� 
//ù��° �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����ȴ�. 
// �������� ������ ���� �ʱ�ȭ�� ����ȴ�.
/// ���� ���� �� TRUE(1), ���� ���н� FALSE(0)

int LNext(List * plist, LData * pdata);  // �ι�° ���� ������ ���� 
//LFirst�� ���� ó�� ���� �� ����ؼ� ������ ���ұ��� ������ �Ѵ�. 
// �������� ������ �ϴ� �ݺ����� ȣ�� 
/// ���� ���� �� TRUE(1), ���� ���н� FALSE(0)


LData LRemove (List * plist); // ������ �����͸� ����
// LFirst, LNext �Լ��� ���� �ֱٿ� ������ ���� ����
// ������ �����ʹ� ��ȯ�Ѵ�. (�޸� ���� å�� ����)
// ������ ��ȯ �����͸� �����ϹǷ� ������ �ݺ� ȣ���� ������� �ʴ´�. 


int LCount(List * plist);   // ����� �������� ����ȯ 
// ����Ʈ�� ����Ǿ� �ִ� �������� ���� ��ȯ�Ѵ�. 

#endif