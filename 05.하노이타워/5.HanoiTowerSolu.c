// �ϳ��� ž�� ������� ���� ���
// ������� �Լ��� �����ϴµ� ��� ���ذ� �켱 

#include <stdio.h>


void HonoiTowerMove(int num, char from, char by, char to)
{
	if(num == 1)
	{
		printf("����1�� %c���� %c�� �̵� \n", from, to); 
	}
	else
	{
		HonoiTowerMove(num-1, from, to, by);
		printf("���� %d�� %c���� %c�� �̵� \n", num, from, to);
		HonoiTowerMove(num-1, by, from, to);
	}
}

int main(void)
{
	// ���  3���������� a���� c�� �ű�� 
	HonoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}