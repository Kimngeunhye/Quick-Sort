#include <stdio.h>
#include <stdint.h>
#define max 15  //배열에 들어갈 원소 수를 지정해 준다.

void QuickSort(int arr[], int initial, int final)  //초기값 initial, 끝 값 final 으로 설정, 배열 변수는 arr로 지정
{
	int index; 
	if (initial < final) //재귀적 호출을 위해 초기값이 끝 값 보다 작은 경우로 설정
	{
		printf("\n");
		index = Partition(arr, initial, final);  //index는 partition 으로 나누었을 때, 배열, 초기값, 끝 값 으로 지정해 준다.
		for (int i = 0; i < max; i++) 
		{
			printf("%d\n", arr[i]);  //i 가 배열을 돌면서 배들을 출력해준다.
		}
		printf("\n");
		QuickSort(arr, initial, index - 1);
		QuickSort(arr, index + 1, final);
	}
	else {
		return;
	}
}

int Partition(int arr[], int initial, int final)
{
	int pivot = arr[final]; 
	int i;
	int index = initial; //index는 for문 전체를 돌아야 하므로 초기값으로 지정해준다
	int temp;

	for (i = initial; i < final; i++)
	{
		if (arr[i] <= pivot)  //여기서 부터 분할 리스트가 시작된다.
		{
			printf("swap %d %d\n", arr[i], arr[index]);  //  Swap시킬 자리를 지시한다.
			temp = arr[i];  // index가 배열을 돌면서 swap을 시켜주는 데 이 때 두 개의 원소를 동시에 못 바꾸니 다른 원소가 임의로 머물러 있을 곳을 만들어 준다.
			arr[i] = arr[index];  // index가 원소 i를 찾으면
			arr[index] = temp; //찾은 i를 temp자리에 보관해 주고
			index++; //index는 다시 원소를 찾으러 간다.
		}
	}
	temp = arr[index];  // temp자리에 있는 원소를 다시 index자리에 넣어주고
	arr[index] = arr[final];  //arr[index]를 final자리에 넣어준다.
	arr[final] = temp;  //위에서 final자리에 넣은 요소를 다시  temp자리에 넣고
	printf("swap %d %d\n", arr[index], arr[final]); //swap 시킨 요소를 출력해 준다.
	return index; //index 값을 출력시켜 주어야 하므로 index 값을 반환시켜준다.
}

int main()
{
	int arr[max] = { 20,30,10,50,60,90,100,40,130,120,140,150,80,70,110 };  //arr[#define 15(원소 수)]로 선언해준다.

	int i;
	printf("Before sorting\n"); //sorting 전 배열상태 출력
	for (i = 0; i < max; i++)
	{
		printf("%d\n", arr[i]);
	}
	QuickSort(arr, 0, max - 1);  

	printf("After sorting\n"); //sorting 후 배열상태 출력
	for (i = 0; i < max; i++)
	{
		printf("%d\n", arr[i]);
	}
}