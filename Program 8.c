#include <stdio.h>

#define MAX_SIZE 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void insertIntoHeap(int arr[], int *n, int element)
{
    if (*n == MAX_SIZE)
    {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    (*n)++;
    int i = *n - 1;
    arr[i] = element;

    while (i > 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void displayMaxHeap(int arr[], int n)
{
    printf("Max Heap Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int heap[MAX_SIZE];
    int n = 0;

    printf("Enter elements to insert into the max heap (enter -1 to stop):\n");
    int element;
    while (1)
    {
        scanf("%d", &element);
        if (element == -1)
        {
            break;
        }
        insertIntoHeap(heap, &n, element);
    }

    displayMaxHeap(heap, n);

    return 0;
}
