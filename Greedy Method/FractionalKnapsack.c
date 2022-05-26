#include<stdio.h>

typedef struct stud {
    int no, value, weight;
} Item;

void KnapSack(int n, int w, Item items[]) {
    double X[n];
    for(int i=0; i<n; i++) X[i] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j){
            if (((double) items[i].value / (double) items[i].weight) < ((double) items[j].value / (double) items[j].weight)) {
                Item tmp =  items[i];
                items[i] = items[j];
                items[j] = tmp;
            }
        }
    }

    printf("\n\n\n");
    for(int i=0; i<n && w > 0; i++) {
        int tmp = items[i].no;
        if(w >= items[i].weight) {
            printf("After taking Item-%d remaining capacity = (%d - %d) = %d\n", items[i].no+1, w, items[i].weight, w-items[i].weight);
            X[tmp] = (double)1.0;
            w -= items[i].weight;
        } else {
            printf("The fractional part of Item-%d we can put = (%d / %d) = %g\n", items[i].no+1, w, items[i].weight, (double) w / (double) items[i].weight);
            X[tmp] = (double) w / (double) items[i].weight;
            w = 0;
        }
    }

    printf("\n\n\nThe 'X' array is: [");
    for(int i=0; i<n; i++) {
        printf("%g", X[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");

    double profit = 0;
    for(int i=0; i<n; i++) {
        profit += (X[(items[i].no)] * items[i].value);
    }
    printf("The optional profit is: %g", profit);
}

int main(){
    int n, w;
    printf("Enter no of items: ");
    scanf("%d", &n);
    printf("Enter capacity: ");
    scanf("%d", &w);

    Item items[n];

    for(int i=0; i<n; i++){
        Item item;
        item.no = i;
        printf("Enter weight of item-%d: ", i+1);
        scanf("%d", &item.weight);
        printf("Enter value of item-%d: ", i+1);
        scanf("%d", &item.value);
        items[i] = item;
    }

    KnapSack(n, w, items);
    return 0;
}