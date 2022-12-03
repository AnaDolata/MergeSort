#include <stdio.h>
#include <stdlib.h>

#define CUT_OFF 2

void swap(int *a, int i, int j) {
    int swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

void insertion_sort(int *a, int l, int r) {
    int aux;
    for (int i = l; i <= r; i++)
        for (int j = i; j > l && a[j] < a[j - 1]; j--)
            swap(a, j, j-1);
}

void merge(int *src, int *dst, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    for (int k = l; k <= r; k++) {
        if (i > m) dst[k] = src[j++];
        else if (j > r) dst[k] = src[i++];
        else if (src[j] < src[i]) dst[k] = src[j++];
        else dst[k] = src[i++];
    }
}


void mergesort(int *src, int *dst, int l, int r) {

    if (r <= l + CUT_OFF) {
        insertion_sort(dst, l, r);
        return;
    }

    int m = l + (r - l) / 2;

    mergesort(dst, src, l, m);
    mergesort(dst, src, m + 1, r);

    if (src[m + 1] >= src[m]) {
        for (int i = l; i <= r; i++)
            dst[i] = src[i];
        return;
    }

    merge(src, dst, l, m, r);

}

int main() {
    int a[] = {12, 11, 13, 5, 6, 7, 8, 9, 9, 1};
    int aux[] = {12, 11, 13, 5, 6, 7, 8, 9, 9, 1};
    int size = 10;

    mergesort(a, aux, 0, 9);

    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("%d ", aux[i]);
}
