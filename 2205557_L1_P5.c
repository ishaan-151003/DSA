#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, searchElem;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &searchElem);
    int f= 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchElem) {
            f = 1;
            index = i;
            break;
        }
    }
    if (f) {
        printf("%d exists at index %d\n", searchElem, index);
    } else {
        printf("%d does not exist in the array\n", searchElem);
    }
    free(arr);
    return 0;
}