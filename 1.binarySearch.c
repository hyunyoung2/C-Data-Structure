// �⺻���� binary search exercise 
// ������ ����� �˻� ������ �ݾ� �ѹ��� ���̴� ��� ȿ�����̰� 
// ������� �Լ��� Ȱ������ �ʴ� binary search ��� 
// �迭�� ���� ���Ҵ� �������� �ʴ´ٶ�� ����
#include <stdio.h>


int BinarySearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len -1;
	int mid; 

	while(first <= last) // ���� >= ���� while ���� ���´�.  
	{
		mid = (first+last) / 2;  // middle factor 

		if(arr[mid] == target)
			return mid;
		else
		{
			if(arr[mid] > target) // �˻� ��ġ ����
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

 //	printf("%p %p\n", arr, &arr[0]);    /// �����͸� ���ϱ� ���Ͽ� 
//	printf("%d %d\n", sizeof(arr), sizeof(&arr[0])); // sizeof �� ���� ũ�� �� ����

	if(idx == -1)
		printf("�߰����� ���Ͽ����ϴ�\n");
	else 
		printf("�߰��� �� �ε��� : %d\n", idx);


	return 0;
}