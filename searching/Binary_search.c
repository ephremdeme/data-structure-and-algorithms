#include <stdio.h>

int main()
{
	int array[100], i, n, search, temp, j;
	printf("\n Enter the size of array: \n");
	scanf("%d", &n);
	
	printf("\n Enter %d array elements: \n", n);
	for (i =0; i< n; i++)
	{
		scanf("%d", &array[i]);
	}
	
	printf("\n Enter the element you want to search via binary Search \n");
	scanf("%d", &search);
	
	int first = 0, last = n-1, middle;
	middle = (first + last)/2;
	
	//sorting the array
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			temp = array[i];
			array[i] = array[j];
		}
	}
	
	while (first <= last)
	{
		if (array[middle] < search)
		{
			first = middle + 1;
		}
		else if (array[middle] == search)
		{
			printf("\n %d found at %d position", search, middle+1);
			break;
		}
		else
		{
			last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if (first > last)
	{
		printf("\n %d is not present in the array \n", search);
	}
	return 0;
}
