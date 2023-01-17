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

void DeleteEdges(node **head, int NodeToDelte)
{
    node *current_edge = *head;
    edge **tempHead;

    while (current_edge != NULL ) {
        tempHead = &current_edge->edges;
        DeleteSingleEdge(tempHead, NodeToDelte);
        current_edge = current_edge->next;
    }
}

void DeleteNode(node **head, int NodeToDelete)
{
    node *temp = *head, *prev;

    if (temp != NULL && temp->node_num == NodeToDelete) 
    {
        *head = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    while (temp != NULL && temp->node_num != NodeToDelete)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

void DeleteSingleEdge(edge **head, int NodeToDelete)
{
    edge *temp = *head, *prev;

    if (temp != NULL && temp->endpoint->node_num == NodeToDelete) 
    {
        *head = temp->next; // Changed head
        free(temp); // free old head
        temp = *head;
        return;
    }

    while (temp != NULL && temp->endpoint->node_num != NodeToDelete)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}