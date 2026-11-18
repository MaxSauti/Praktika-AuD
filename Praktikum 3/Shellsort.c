//
// Created by maxkn on 18.11.2026.
//

#include "Shellsort.h"

void shellsort (int a[], int N)
{
    int i, j, h, v;

    for (h = 1; h <= N/3; h = 3*h + 1) ;
    for ( ; h > 0; h /= 3)
        for (i = h + 1; i <= N; i++)
        {
            v = a[i]; j = i;
            while (j > h && a[j-h] > v)
            { a[j] = a[j-h]; j -= h;}
            a[j] = v;
        }
}