#include<time.h>
struct Item {
    int value, weight;
    float ratio;
};
void swap(struct Item a[], int i, int j) {
    struct Item temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void sort(struct Item a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j].ratio < a[j + 1].ratio) {
                swap(a, j, j + 1);
            }
        }
    }
}
float fractionalKnapsack(struct Item a[], int n, int capacity) {
    float total = 0.0;

    for(int i = 0; i < n; i++) {
        if(capacity >= a[i].weight) {
            total += a[i].value;
            capacity -= a[i].weight;
        } else {
            total += a[i].ratio * capacity;
            break;
        }
    }

    return total;
}
int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item a[n];
    for(int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &a[i].value, &a[i].weight);
        a[i].ratio = (float)a[i].value / a[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    sort(a, n);
    float maxVal = fractionalKnapsack(a, n, capacity);
    printf("Maximum value = %.2f\n", maxVal);

    clock_t start, end;
    start=clock();
    fractionalKnapsack(a,n,capacity);
    end=clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Execution time:%f",time);
        return 0;

}
