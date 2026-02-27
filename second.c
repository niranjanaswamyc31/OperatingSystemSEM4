#include <stdio.h>

int main() {
int n;

printf("Enter the number of elements:");
scanf("%d", &n);

int arr[n];
for (int i=0;i<n;i++){
    scanf("%d", &arr[i]);
}

int smallest = arr[0];
int position=0;

for (int i=1; i<n; i++){
    if(arr[i] < smallest){
    smallest = arr[i];
    position = i;
}
}

printf("Smallest number = %d\n", smallest);
printf("Position = %d\n", position + 1);

return 0;
}
