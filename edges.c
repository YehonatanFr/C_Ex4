#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pedge NewEdge(pnode dest, int weight, pedge next)
{

    edge *temp = (edge*) malloc (sizeof(edge));
    temp->weight = weight;
    temp->next = next;
    temp->endpoint = dest;
    
    return temp;
}

node* FindPnode(node **head, int num)
{
    node *p = *head;
    for(int i = 0; i<num; i++)
    {
        p = p->next;
    }
    p = p->next;
    return p;
}


void UpdateEdge (node **head, int sorceEdge, int EdgeTarget, int weight) 
{
    node *src = FindPnode(head, sorceEdge);
    node *dst = FindPnode(head, EdgeTarget);

    edge *newEdge = NewEdge(dst, weight, NULL);
    edge *p = NULL;

    if(src->edges == NULL)
    {
        src->edges = newEdge;
    }
    else
    {
        p = src->edges;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = newEdge;
    }

    src = NULL;
    dst = NULL;
    newEdge = NULL;
}


