#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



pnode NewNode (int num, pnode next)
{

    node *temp = (node*) malloc (sizeof(node));
    temp->node_num = num;
    temp->edges = NULL;
    temp->next = next;
    return temp;
}

void CreateLinkedList (int n, node **head)
{
    node *p = NULL;

    for(int i = 0; i<n; i++)
    {
        node *temp = NewNode(i,NULL);

        if(*head == NULL)
        {
            *head = temp;
        }
        else
        {
            p = *head;
            while( p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
}

void PrintGraph(node **head)
{
    node *p = *head;
    if(p->next != NULL)
    {
        printf("%d", p->node_num);
        p = p->next;
    }
    while(p != NULL)
    {
        printf("-->%d", p->node_num);
        p = p->next;
    }
    printf("\n");
}

void FreeEdge(node *sorce)
{
    sorce->edges = NULL;
}