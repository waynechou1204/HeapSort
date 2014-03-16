
#include <stdio.h>
#include <stdlib.h>

void print(int *heap, int len);

void MinHeapAddNum(int heap[], int n, int num)
{
	heap[n]=num;

	int indexFather = (n-1)/2;

	// reach the top
	if (indexFather < 0)
	{
		return;
	}

	while (heap[indexFather] > num)
	{
		int temp = heap[indexFather];
		heap[indexFather] = num;
		heap[n] = temp;

		n = indexFather;
		indexFather = (n-1)/2;
	}
}

int min(int l, int r)
{
	if (l < r)
	{
		return l;
	}
	else
	{
		return r;
	}
}

void MinHeapFixDown(int heap[], int n)	//fix it as a minHeap
{
//	int len = sizeof(heap)/sizeof(int);	

	int indexCurrent = 0;
	int indexLeft = indexCurrent*2+1;
	int indexRight = indexCurrent*2+2;

	int leftChild; 
	int rightChild;
	int current;
	int minChild;

	if (indexLeft > n)	// no child
	{
		return;
	}

	if (indexRight > n)	// only left child
	{
		minChild = heap[indexLeft];
	}
	else	// both children exist
	{
		leftChild = heap[indexLeft];
	 	rightChild = heap[indexRight];
		current = heap[indexCurrent];
		minChild = min(leftChild,rightChild);
	}
	
	while(current > minChild)
	{
		if (leftChild < rightChild)	// change to left 
		{
			heap[indexLeft] = current;
			heap[indexCurrent] = leftChild;
			indexCurrent = indexLeft;
		}
		else	// change to right
		{
			heap[indexRight] = current;
			heap[indexCurrent] = rightChild;
			indexCurrent = indexRight;
		}

		indexLeft = indexCurrent*2+1;
		indexRight = indexCurrent*2+2;

		if (indexLeft > n)	// no child
		{
			return;
		}

		if (indexRight > n)	// only left child
		{
			minChild = heap[indexLeft];
		}
		else	// both children exist
		{
			leftChild = heap[indexLeft];
		 	rightChild = heap[indexRight];
			current = heap[indexCurrent];
			minChild = min(leftChild,rightChild);
		}
	}

}



void MinHeapSort(int heap[], int n)
{
	if (n==0)
	{
		return;
	}

	int temp = heap[0];
	heap[0] = heap[n];
	heap[n] = temp;

	MinHeapFixDown(heap,n-1);
}

void print(int *heap, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%i ", heap[i]);
		/* code */
	}
	printf("\n");
}

int main()
{
	int arrayOrigin[] = {1,3,5,2,4,4,8,1,2};

	int len = sizeof(arrayOrigin) / sizeof(int); 

	int *minHeap = (int*)malloc(len * sizeof(int));

	for (int i = 0; i < len; ++i)
	{
		MinHeapAddNum(minHeap,i,arrayOrigin[i]);	//ok !
	}
	printf("%s", "Tree built: ");
	print(minHeap,len);	// tree built

	for (int i = len-1; i > 0; --i)
	{
		MinHeapSort(minHeap,i);
	}
	
	printf("Heap sorted: ");
	print(minHeap,len);

	free(minHeap);

	return 0;
}