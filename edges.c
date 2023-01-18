#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"


void swap(int *x, int *y) 
{
    int c;
    c = *x;
    *x = *y;
    *y = c;
}

int factorial(int size)
{
    if(size < 0) return 0;
    if(size == 0) return 1;
    return factorial(size-1)*size;
}

int min(const int arr[],int n)
{
    int index = 0;

    for (int i = 1; i <n; ++i) 
    {
        if(arr[i]<arr[index]){index = i;}
    }

    return index;
}

int FindShortestPath(node **head, int values[], int len)
{
    int dst = 0;
    for (int i = 0; i < len-1; ++i) {
        int dijk = dijkstra(head,values[i],values[i+1],0);
        if(dijk == INT_MAX){
            return INT_MAX;
        }
        dst += dijk;
    }
    return dst;
}




void per(node **head, int *values, int right, int left ,int *permutat, int *n)
{
    if(right == left)
    {
        permutat[(*n)++] = FindShortestPath(head, values, left+1);
        return;
    }

    for (int i = right; i <=left; ++i) 
    {
        swap((values + i), (values + right));
        per(head,values,right+1,left,permutat,n);
        swap((values+i),(values+right));
    }
}


