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

void QuickSort(int A[], int p, int r)
{
	if (p < r) 
	{
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
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

	QuickSort(A, 0, n-1);

    cout <<"Values after quicksort: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << A[i] << " ";
	}

	delete[] A;

	return 0;
}
