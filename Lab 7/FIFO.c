#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j;
    int pageFaults = 0;
    int next = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames to -1
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\n--- FIFO Page Replacement ---\n");

    for(i = 0; i < n; i++) {

        found = 0;

        // Check if page already exists
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If not found, replace using FIFO
        if(found == 0) {
            frames[next] = pages[i];
            next = (next + 1) % f;
            pageFaults++;
        }

        // Print current frame status
        printf("Page %d -> [", pages[i]);

        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d", frames[j]);
            else
                printf(" ");

            if(j != f - 1)
                printf(" ");
        }

        printf("]\n");
    }

    printf("\nTotal Page Faults (FIFO): %d\n", pageFaults);

    return 0;
}