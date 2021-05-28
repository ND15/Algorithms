#include <stdio.h>


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(int A[],int n)
{
    int i,j,flag;
    for ( i = 0; i < n-1; i++)
    {
        flag = 0;
        for (j = 0; j < n-i-1; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if (flag==0)
        {
            printf("Alreay Sorted\n");
            break;
        } 
    }
}

int main()
{
    int A[] = {5,3,8,2,1};
    int n = 5;
    BubbleSort(A,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    return 1;
}