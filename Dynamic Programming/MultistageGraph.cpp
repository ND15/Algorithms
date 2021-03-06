#include <iostream>
using namespace std;

void calculatePath(int A[][9], int *Cost, int *Dest, int n)
{
	for (int i = n - 2; i >= 1; i--)
	{
		int min = 31456;
		for (int j = i ; j < n; j++)
		{
			if (A[i][j] != 0 && A[i][j] + Cost[j] < min)
			{
				min = A[i][j] + Cost[j];
				Dest[i] = j;
			}
		}
		Cost[i] = min;
	}
}

int main(int argc, char const *argv[])
{
	int A[9][9] = { {0,0,0,0,0,0,0,0,0},
					{0,0,2,3,4,0,0,0,0},
					{0,0,0,0,0,6,3,0,0},
					{0,0,0,0,0,5,0,4,0},
					{0,0,0,0,0,0,3,2,0},
					{0,0,0,0,0,0,0,0,5},
					{0,0,0,0,0,0,0,0,3},
					{0,0,0,0,0,0,0,0,4},
					{0,0,0,0,0,0,0,0,0} };
	int *Cost = new int[9];
	Cost[8] = 0;
	int *Dest = new int[9];
	calculatePath(A, Cost, Dest, 9);
	int *Path = new int[4];
	Path[1] = 1;
	for (int i = 2; i < 4; i++)
	{
		Path[i] = Dest[Path[i - 1]];
	}

	for (int i = 1; i < 4; i++)
	{
		cout << Path[i] << " ";
	}
	return 0;
}
