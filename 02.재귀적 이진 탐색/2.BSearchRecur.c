/// binary search recursive  방식 재귀 함수 호출을 통한 방식 
/// 배열에 같은 원소가 없다는 가정에 해야 한다. 

#include <stdio.h>

int BsearchRecu(int arr[], int first, int last, int target)
{
	int mid = (first+last)/2;


	if(first > last)   // 탐색범위에 숫자가 존재하지 않는다.
		return -1;   

	else if(arr[mid] == target)  ///맞으면 고
		return mid;

	else
	{
		if(arr[mid] < target)    // 재귀적 호출을 한다. 
			return	BsearchRecu( arr, mid+1, last, target);
		else
			return BsearchRecu( arr, first, mid-1, target);
	}
}


int main()
{

	int arr[] = {1,3, 5,6, 9,10};
	int idx;



	idx = BsearchRecu(arr, 0, sizeof(arr)/sizeof(int)-1, 10);
	if(idx == -1)
		printf("탐색이 실패하였습니다\n");
	else 
		printf("타켓 저장 인덱스: %d \n",idx);
}
