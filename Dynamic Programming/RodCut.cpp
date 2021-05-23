#include <iostream>
#define minVl -31456

using namespace std;

int max(int x, int y)
{
	return x > y ? x : y;
}

/*
This function takes exponential time
to find the maximum possible price for
the splits
*/
int RodCut(int Price[], int length)
{
	if (length == 0)
	{
		return 0;
	}
	int temp;
	temp = minVl;
	for (int i = 1; i <= length; i++)
	{
		temp = max(temp, Price[i] + RodCut(Price, length - i));
	}
	return temp;
}

/*
Dynamic Top-down approah
*/
int RodCut_V2(int Price[], int length, int Table[]);

int init_Rod_Cut(int Price[], int length)
{
	int *Table = new int[length];
	Table[0] = 0;
	for (int i = 1; i < length; i++)
	{
		Table[i] = minVl;
	}
	int x = RodCut_V2(Price, length, Table);
//	delete[] Table;
	return x;
}

int RodCut_V2(int Price[], int length, int Table[])
{
	int temp = minVl;
	if (Table[length] >= 0)
	{
		return Table[length];
	}
	if (length == 0)
	{
		temp = 0;
	}
	else if(temp == minVl)
	{
		for (int i = 1; i <= length; i++)
		{
			temp = Price[i] + RodCut_V2(Price, length - i, Table);
			if (temp > Table[length])
			{
				Table[length] = temp;
			}
		}
	}
	return Table[length];
}

/*
iterative bottom up approach
*/
int Rod_Cut_V3(int Price[], int length)
{
	int *Table = new int[length];
	Table[0] = 0;
	for (int j = 1; j <= length; j++)
	{
		int temp = minVl;
		for (int i = 1; i <= j; i++)
		{
			temp = Price[i] + Table[j - i];
			if (temp > Table[j])
			{
				Table[j] = temp;
			} 
		}
	}
	return Table[length];
}


int main()
{
	int P[6] = { 0, 1,5,8,9,10 };
	cout << Rod_Cut_V3(P, 5) << endl;
	return 0;
}