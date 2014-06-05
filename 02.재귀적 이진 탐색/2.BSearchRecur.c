/// binary search recursive  ��� ��� �Լ� ȣ���� ���� ��� 
/// �迭�� ���� ���Ұ� ���ٴ� ������ �ؾ� �Ѵ�. 

#include <stdio.h>

int BsearchRecu(int arr[], int first, int last, int target)
{
	int mid = (first+last)/2;


	if(first > last)   // Ž�������� ���ڰ� �������� �ʴ´�.
		return -1;   

	else if(arr[mid] == target)  ///������ ��
		return mid;

	else
	{
		if(arr[mid] < target)    // ����� ȣ���� �Ѵ�. 
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
		printf("Ž���� �����Ͽ����ϴ�\n");
	else 
		printf("Ÿ�� ���� �ε���: %d \n",idx);
}
