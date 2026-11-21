#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Maximum.h"
#include "Quicksort.h"
#include "Heapsort.h"
#include "Insertionsort.h"
#include "Mergesort.h"
#include "Selectionsort.h"
#include "Shellsort.h"
#include <sys/resource.h>
int a[MAX];
int copy[MAX];
void runSortsRandom(int arr[]);
void runSortsAscending(int arr[]);
void runSortsDescending(int arr[]);
//
// Created by maxkn on 12.11.2026.
//
void increaseStackSize() {
    const rlim_t kStackSize = 64 * 1024 * 1024; // 64 MB
    struct rlimit rl;
    if (getrlimit(RLIMIT_STACK, &rl) == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            if (setrlimit(RLIMIT_STACK, &rl) != 0) {
                perror("setrlimit");
            }
        }
    }
}

int main() {
    increaseStackSize();
    runSortsRandom(a);
    runSortsDescending(a);
    runSortsAscending(a);
    //quicksort(a, 0, MAX - 1);
    //heapsort(a, MAX);
    //insertion(a, MAX-1);
    //mergesort(a, 0, MAX - 1);
    //shellsort(a,MAX - 1);
}

void copyArray(int a[], int b[]) {
    memcpy(a, b, MAX * sizeof(int));
}

void runSorts(int arr[]) {
    copyArray(copy, arr);

    clock_t startHeap = clock();
    heapsort(arr, MAX);
    clock_t endHeap = clock();
    clock_t timeHeap = endHeap-startHeap;
    printf("Heapsort: %ld\n", timeHeap);

    copyArray(arr, copy);
    clock_t startInsertion = clock();
    insertion(arr, MAX);
    clock_t endInsertion = clock();
    clock_t timeInsertion = endInsertion-startInsertion;
    printf("Insertionsort: %ld\n", timeInsertion);

    copyArray(arr, copy);
    clock_t startMerge = clock();
    mergesort(arr, 1, MAX-1);
    clock_t endMerge = clock();
    clock_t timeMerge = endMerge-startMerge;
    printf("Mergesort: %ld\n", timeMerge);

    copyArray(arr, copy);
    clock_t startQuick = clock();
    quicksort(arr, 1, MAX-1);
    clock_t endQuick = clock();
    clock_t timeQuick = endQuick-startQuick;
    printf("Quicksort: %ld\n", timeQuick);

    copyArray(arr, copy);
    clock_t startSelection = clock();
    selection(arr, MAX);
    clock_t endSelection = clock();
    clock_t timeSelection = endSelection-startSelection;
    printf("Selectionsort: %ld\n", timeSelection);

    copyArray(arr, copy);
    clock_t startShell = clock();
    shellsort(arr, MAX);
    clock_t endShell = clock();
    clock_t timeShell = endShell-startShell;
    printf("Shellsort: %ld\n", timeShell);
}

void runSortsRandom(int arr[]) {
    printf("\n\nRandom Gernerierung\n");
    arr[0] = -INT_MAX;
    srand(time(NULL));
    for (int i = 1; i < MAX; i++) {
        arr[i] = rand() % (MAX);
    }
    runSorts(arr);
}

void runSortsAscending(int arr[]) {
    arr[0] = -INT_MAX;
    printf("\n\nAufsteigend sortiert\n");
    for (int i = 1; i < MAX; i++) {
        arr[i] = i;
    }
    runSorts(arr);
}

void runSortsDescending(int arr[]) {
    printf("\n\nAbsteigend sortiert\n");
    arr[0] = -INT_MAX;
    for (int i = 1; i < MAX; i++) {
        arr[i] = MAX-i;
    }
    runSorts(arr);
}






