#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    int finished;
};

int main() {
    int n, i, completed = 0, current_time = 0, min_index;
    struct Process p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time and Burst Time: ");
        scanf("%d %d %d", &p[i].pid, &p[i].arrival, &p[i].burst);
        p[i].finished = 0;
    }

    for(i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(p[i].arrival > p[j].arrival) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    while(completed < n) {
        int min_bt = 9999;
        min_index = -1;

        for(i = 0; i < n; i++) {
            if(p[i].arrival <= current_time && p[i].finished == 0) {
                if(p[i].burst < min_bt) {
                    min_bt = p[i].burst;
                    min_index = i;
                }
            }
        }

        if(min_index == -1) {
            current_time++;
        } else {
            p[min_index].completion = current_time + p[min_index].burst;
            p[min_index].turnaround = p[min_index].completion - p[min_index].arrival;
            p[min_index].waiting = p[min_index].turnaround - p[min_index].burst;

            current_time = p[min_index].completion;
            p[min_index].finished = 1;
            completed++;
        }
    }    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);
    }

return 0;
}
