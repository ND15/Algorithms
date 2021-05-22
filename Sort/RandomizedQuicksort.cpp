//Randomized pivot
#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] < x)
		{
			i++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[r]);
	return i + 1;
}

int Randomized_Partiton(int A[], int p, int r)
{
    int i = rand()%5;
    swap(A[i], A[r]);
    return Partition(A,p,r);
}

void Randomized_QuickSort(int A[], int p, int r)
{
	if (p < r) 
	{
		int q = Partition(A, p, r);
		Randomized_QuickSort(A, p, q - 1);
		Randomized_QuickSort(A, q + 1, r);
	}
}

int main()
{
    int n = 5;
	int *A = new int[n];
    cout << "Enter the values: " << endl; 
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

	Randomized_QuickSort(A, 0, n-1);

    cout <<"Values after Randomized Quicksort: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << A[i] << " ";
	}

	delete[] A;

	return 0;
}
