#include <iostream>

using namespace std;

/*
    The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order)
    from unsorted part and putting it at the beginning.
*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int k; // index of min element
    for(int i=0; i<n-1; i++)
    {
        k = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[k]){
                k = j;
            }
        }
        swap(&arr[k], &arr[i]);
    }
}



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int  main()
{

    int arr[] = {3, 5, 1, 4, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);

    printArray(arr, n); //1, 2, 3, 4, 5

    return 0;
}

