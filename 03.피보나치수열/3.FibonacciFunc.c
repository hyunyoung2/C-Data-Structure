//  재귀 함수 이해를 위한 피보나치 수열

#include <stdio.h>

int Fibo(int n)
{
	printf("func call param %d \n\n", n); // Fibo() 함수호출 확인을 위한 추가 조건

	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else 
		return Fibo(n-1)+Fibo(n-2);
}

int main(void)
{
	//int i;
	//for(i = 1 ; i< 15 ; i++)
		//printf("%d ", Fibo(i));

	Fibo(7);
	
	return 0;
}
