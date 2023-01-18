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
    while(p != NULL) 
    {
        if(p->node_num == num)
        {
            return p;
        }
        p = p->next;
    }
    
    free(p);
    return NULL;
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

    free(src);
    free(dst);
}

// int FindMinWeight(edge **head)
// {
//     edge *temp = *head;
//     if(temp == NULL)
//     {
//         return -1;
//     }

//     int min = temp->weight;
//     temp = temp->next;

//     while(temp != NULL)
//     {
//         if(temp->weight < min)
//         {
//             min = temp->weight;
//         }
//         temp = temp->next;
//     }

//     return min;
// }

// void printMinWeight(node **head)
// {
//     node *current_edge = *head;
//     edge **tempHead;
//     int min = 0;

//     while (current_edge != NULL ) {
//         tempHead = &current_edge->edges;
//         min = FindMinWeight(tempHead);
//         if(min == -1)
//         {
//             printf("There is no edges from this %d vertex\n", current_edge->node_num);
//         }
//         else{
//             printf("The min weight of %d vertx is %d weight\n", current_edge->node_num, min);
//         }
//         current_edge = current_edge->next;
//     }
// }


