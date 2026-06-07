#include<stdio.h>
#include<time.h>

void merge(int a[],int low, int mid, int high)
{
    int i,j,k,b[50];
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }

    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }

    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
}

void mergesort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high)/2;

        mergesort(a, low, mid);
        mergesort(a, mid+1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }

    clock_t start, end;
    start=clock();
    mergesort(a,0,n-1);
    end=clock();

    double time =(double)(end-start)/CLOCKS_PER_SEC;
    printf("Sorted elements in ascending order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nExecution time: %f\n", time);
    return 0;
}
