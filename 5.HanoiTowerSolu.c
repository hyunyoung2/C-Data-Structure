// 하노이 탑의 재귀적인 접근 방식
// 재귀적인 함수를 구현하는데 방식 이해가 우선 

#include <stdio.h>


void HonoiTowerMove(int num, char from, char by, char to)
{
	if(num == 1)
	{
		printf("원반1을 %c에서 %c로 이동 \n", from, to); 
	}
	else
	{
		HonoiTowerMove(num-1, from, to, by);
		printf("원반 %d을 %c에서 %c로 이동 \n", num, from, to);
		HonoiTowerMove(num-1, by, from, to);
	}
}

int main(void)
{
	// 기둥  3개를가지고 a에서 c로 옮기기 
	HonoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}