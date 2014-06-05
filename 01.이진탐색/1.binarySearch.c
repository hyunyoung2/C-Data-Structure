// 기본적인 binary search exercise 
// 반으로 나누어서 검색 범위를 반씩 한번에 줄이는 방식 효율적이고 
// 재귀적인 함수를 활용하지 않는 binary search 방식 
// 배열에 같은 원소는 존재하지 않는다라고 가정
#include <stdio.h>


int BinarySearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len -1;
	int mid; 

	while(first <= last) // 시작 >= 종료 while 문이 나온다.  
	{
		mid = (first+last) / 2;  // middle factor 

		if(arr[mid] == target)
			return mid;
		else
		{
			if(arr[mid] > target) // 검색 위치 조정
				last = mid -1;  
			else 
				first = mid + 1;
		}
	}

	return -1;
}


int main()
{
	int arr[]= {1, 3, 5, 7, 9};
	int idx;
	

	idx = BinarySearch(arr, sizeof(arr)/sizeof(int), 7);

 //	printf("%p %p\n", arr, &arr[0]);    /// 포인터를 비교하기 위하여 
//	printf("%d %d\n", sizeof(arr), sizeof(&arr[0])); // sizeof 를 통한 크기 비교 연습

	if(idx == -1)
		printf("발견하지 못하였습니다\n");
	else 
		printf("발견을 한 인덱스 : %d\n", idx);


	return 0;
}