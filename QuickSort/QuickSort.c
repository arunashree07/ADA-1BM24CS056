#include<stdio.h>
#include<time.h>

int partition(int a[], int low, int high)
{
    int i,j, key;
    i=low+1;
    j=high;
    key=a[low];
    while(1)
    {
        while(a[i]<=key&&i<high)
        {
            i++;
        }

        while(a[j]>key)
        {
            j--;
        }

        if(i<j)
        {
            int temp = a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            int temp = a[low];
            a[low]=a[j];
            a[j]=temp;
            return j;
        }
    }
}

void quickSort(int a[], int low, int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quickSort(a,low,j-1);
        quickSort(a,j+1,high);
    }

}

int main()
{
    int n, a[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array: ");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

         clock_t start, end;

    start=clock();
    quickSort(a,0,n-1);
    end=clock();
        printf("Sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }

    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nExecution time: %f\n", time);
}
