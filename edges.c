#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pedge NewEdge(pnode dest, int weight, int *next)
{

    pedge temp = (pedge) malloc (sizeof(edge));
    temp->weight = weight;
    temp->next = next;
    temp->endpoint = dest;
    return temp;
}

pnode FindPnode(pnode *head, int num)
{
    pnode p = *head ;
    for(int i = 0; i<num; i++)
    {
        p = p->next;
    }
    p = p->next;
    return p;
}


void UpdateEdge (pnode *head, int sorceEdge, int EdgeTarget, int weight) 
{
    pnode src = FindPnode(head, sorceEdge);
    pnode dst = FindPnode(head, EdgeTarget);

    pedge newEdge = NewEdge(dst, weight, NULL);
    pedge p = NULL;

    if(src->edges == NULL)
    {
        src->edges = newEdge;
    }
    else
    {
        p = src->edges->next;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = newEdge;
    }
}


