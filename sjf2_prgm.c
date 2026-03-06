#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main() {
    int n, i, completed = 0, current_time = 0, min_index;
    int min_remaining;
    struct Process p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time and Burst Time: ");
        scanf("%d %d %d", &p[i].pid, &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
    }

    for(i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].arrival > p[j].arrival) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    while(completed < n) {
        min_remaining = 9999;
        min_index = -1;

        for(i = 0; i < n; i++) {
            if(p[i].arrival <= current_time && p[i].remaining > 0) {
                if(p[i].remaining < min_remaining) {
                    min_remaining = p[i].remaining;
                    min_index = i;
                }
            }
        }

        if(min_index == -1) {
            current_time++;
        } else {

            p[min_index].remaining--;
            current_time++;

            if(p[min_index].remaining == 0) {
                completed++;

                p[min_index].completion = current_time;
                p[min_index].turnaround = p[min_index].completion - p[min_index].arrival;
                p[min_index].waiting = p[min_index].turnaround - p[min_index].burst;
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
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
