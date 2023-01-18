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

    p = NULL;
    free(p);
}

// void PrintGraph(node **head)
// {
//     node *p = *head;
//     if(p->next != NULL)
//     {
//         printf("%d", p->node_num);
//         p = p->next;
//     }
//     while(p != NULL)
//     {
//         printf("-->%d", p->node_num);
//         p = p->next;
//     }
//     printf("\n");

//     free(p);
// }

void DeleteEdges(node **head, int NodeToDelte)
{
    node *current_edge = *head;
    edge **tempHead = NULL;

    while (current_edge != NULL ) 
    {
        tempHead = &current_edge->edges;
        DeleteSingleEdge(tempHead, NodeToDelte);
        current_edge = current_edge->next;
    }

    free(current_edge);
    tempHead = NULL;
    free(tempHead);
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

void deleteGraph_cmd(pnode* head){
    node *curr = *head;
 
    while (curr != NULL ) {
        *head = curr->next; 
        DeleteEdges(&curr,curr ->node_num);
        free(curr); 
        curr=*head;
    }

    free(curr);
}