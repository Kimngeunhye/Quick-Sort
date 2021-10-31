#include <stdio.h>
#include <stdint.h>
#define max 15

void QuickSort(int arr[], int initial, int final)
{
	int index;
	if (initial < final)
	{
		printf("\n");
		index = Partition(arr, initial, final);
		for (int i = 0; i < max; i++)
		{
			printf("%d\n", arr[i]);
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
	int index = initial;
	int temp;

	for (i = initial; i < final; i++)
	{
		if (arr[i] <= pivot)
		{
			printf("swap %d %d\n", arr[i], arr[index]);//indicated swap area
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	temp = arr[index];
	arr[index] = arr[final];
	arr[final] = temp;
	printf("swap %d %d\n", arr[index], arr[final]);
	return index;
}

int main()
{
	int arr[max] = { 20,30,10,50,60,90,100,40,130,120,140,150,80,70,110 };

	int i;
	printf("Before sorting\n");
	for (i = 0; i < max; i++)
	{
		printf("%d\n", arr[i]);
	}
	QuickSort(arr, 0, max - 1);

	printf("After sorting\n");
	for (i = 0; i < max; i++)
	{
		printf("%d\n", arr[i]);
	}
}