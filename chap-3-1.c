#include <stdio.h>

int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]){
        if (x < v[mid]){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (x == v[mid]){
        return mid;
    } else {
        return -1;
    }
}

int main(void)
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 5;
    int n = 9;
    int result = binsearch(x, v, n);
    printf("Index of %d in array is %d\n", x, result);
    return 0;
}

