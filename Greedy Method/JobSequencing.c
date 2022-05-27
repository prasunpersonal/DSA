#include<stdio.h>

#define MAX(a,b) ((a>b) ? a : b)
#define MIN(a,b) ((a<b) ? a : b)

typedef struct stud{
    char id;
    int profit, deadline;
}Job;

void scheduleJobs(int n, Job jobs[], int max_deadline) {
    char schedule[max_deadline];
    for(int i=0; i<max_deadline; i++) schedule[i] = '\0';

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(jobs[i].profit < jobs[j].profit) {
                Job tmp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = tmp;
            }
        }
    }

    int total_profit = 0;
    for(int i=0; i<n; i++) {
        for(int j=jobs[i].deadline-1; j>=0; j--) {
            if(schedule[j] == '\0') {
                schedule[j] = jobs[i].id;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Total profit is %d, for the sequence: ", total_profit);
    for(int i=0; i<max_deadline; i++) {
        printf("%c", schedule[i]);
        if(i != max_deadline-1) printf("->");
    }
}

int main(){
    int n, max_deadline = 0;
    printf("Enter no of jobs: ");
    scanf("%d", &n);
    
    Job arr[n];
    for(int i=0; i<n; i++) {
        printf("Enter job id: ");
        scanf(" %c", &arr[i].id);
        printf("Enter job profit: ");
        scanf(" %d", &arr[i].profit);
        printf("Enter job deadline: ");
        scanf(" %d", &arr[i].deadline);
        printf("\n");
        max_deadline = MAX(max_deadline, arr[i].deadline);
    }

    max_deadline = MIN(max_deadline, n);

    scheduleJobs(n, arr, max_deadline);
    return 0;
}