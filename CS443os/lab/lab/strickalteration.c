#include <stdio.h> 
int isStrictlyAlternating(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            return 0;  
        }
    }
    return 1;  
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isStrictlyAlternating(arr, n)) {
        printf("The array is strictly alternating.\n");
    } else {
        printf("The array is NOT strictly alternating.\n");
    }

    return 0;
}
