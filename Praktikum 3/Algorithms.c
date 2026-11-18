#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Maximum.h"
#include "Quicksort.h"

//
// Created by maxkn on 12.11.2026.
//

int main() {
    int a[MAX];
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        a[i] = rand() % MAX;
    }
    quicksort(a, 0, MAX - 1);
    for (int i = 0; i < MAX; i++) {
        printf("%d ", a[i]);
    }
}






