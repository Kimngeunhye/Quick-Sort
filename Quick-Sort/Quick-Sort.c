#include <stdio.h>
#include <stdint.h>
#define max 15  //�迭�� �� ���� ���� ������ �ش�.

void QuickSort(int arr[], int initial, int final)  //�ʱⰪ initial, �� �� final ���� ����, �迭 ������ arr�� ����
{
	int index; 
	if (initial < final) //����� ȣ���� ���� �ʱⰪ�� �� �� ���� ���� ���� ����
	{
		printf("\n");
		index = Partition(arr, initial, final);  //index�� partition ���� �������� ��, �迭, �ʱⰪ, �� �� ���� ������ �ش�.
		for (int i = 0; i < max; i++) 
		{
			printf("%d\n", arr[i]);  //i �� �迭�� ���鼭 ����� ������ش�.
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
	int index = initial; //index�� for�� ��ü�� ���ƾ� �ϹǷ� �ʱⰪ���� �������ش�
	int temp;

	for (i = initial; i < final; i++)
	{
		if (arr[i] <= pivot)  //���⼭ ���� ���� ����Ʈ�� ���۵ȴ�.
		{
			printf("swap %d %d\n", arr[i], arr[index]);  //  Swap��ų �ڸ��� �����Ѵ�.
			temp = arr[i];  // index�� �迭�� ���鼭 swap�� �����ִ� �� �� �� �� ���� ���Ҹ� ���ÿ� �� �ٲٴ� �ٸ� ���Ұ� ���Ƿ� �ӹ��� ���� ���� ����� �ش�.
			arr[i] = arr[index];  // index�� ���� i�� ã����
			arr[index] = temp; //ã�� i�� temp�ڸ��� ������ �ְ�
			index++; //index�� �ٽ� ���Ҹ� ã���� ����.
		}
	}
	temp = arr[index];  // temp�ڸ��� �ִ� ���Ҹ� �ٽ� index�ڸ��� �־��ְ�
	arr[index] = arr[final];  //arr[index]�� final�ڸ��� �־��ش�.
	arr[final] = temp;  //������ final�ڸ��� ���� ��Ҹ� �ٽ�  temp�ڸ��� �ְ�
	printf("swap %d %d\n", arr[index], arr[final]); //swap ��Ų ��Ҹ� ����� �ش�.
	return index; //index ���� ��½��� �־�� �ϹǷ� index ���� ��ȯ�����ش�.
}

int main()
{
	int arr[max] = { 20,30,10,50,60,90,100,40,130,120,140,150,80,70,110 };  //arr[#define 15(���� ��)]�� �������ش�.

	int i;
	printf("Before sorting\n"); //sorting �� �迭���� ���
	for (i = 0; i < max; i++)
	{
		printf("%d\n", arr[i]);
	}
	QuickSort(arr, 0, max - 1);  

	printf("After sorting\n"); //sorting �� �迭���� ���
	for (i = 0; i < max; i++)
	{
		printf("%d\n", arr[i]);
	}
}