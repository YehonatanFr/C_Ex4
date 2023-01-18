#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void printGraph(pnode head)
{
    printf("Graph representation [src]--(weight)-->[dest]\n");
    while(head != NULL)
    {
        pedge current_edge = head->edges;
        if(current_edge == NULL)
        {
            printf("[%d]\n", head->node_num);
        }
        while(current_edge != NULL)
        {
            printf("[%d]--(%d)-->[%d]\n", head->node_num, current_edge->weight, current_edge->endpoint->node_num);
            current_edge = current_edge->next;
        }
        head = head->next;
    }
}

void Do_B (node **Head, node *sorce)
{
    int sorceEdge, EdgeTarget, weight;
    node *temp = NULL;

    scanf("%d",&sorceEdge);
    sorce = FindPnode(Head, sorceEdge);
    if( sorce != NULL)
    {
        DeleteEdges(Head, sorce->node_num);

        while(scanf("%d",&EdgeTarget) == 1)
        {
            scanf("%d",&weight);
            UpdateEdge (Head, sorceEdge, EdgeTarget, weight);
        }
    }
    else
    {
        node *newEdge = NewNode(sorceEdge, NULL);
        temp = *Head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEdge;
        while(scanf("%d",&EdgeTarget) == 1)
        {
            scanf("%d",&weight);
            UpdateEdge (Head, sorceEdge, EdgeTarget, weight);
        }
    }

    temp = NULL;
    free(temp);
    
}

int main()
{
    pnode *Head=(pnode*)malloc(sizeof(pnode));
    node *sorce =(node*)malloc(sizeof(node));

    char choice;
    int sorceEdge, EdgeTarget, weight;
    int numNode;
    int NodeToDelet;

    while(scanf("%c",&choice)!=EOF)
    {
        if(choice == 'A')
        {   
            deleteGraph_cmd(Head);
            scanf("%d",&numNode);   
            CreateLinkedList(numNode, Head);
            // PrintGraph(Head);
            //deleteGraph_cmd(head);
        }
        
        if(choice == 'n')
        {
            scanf("%d",&sorceEdge);
            while(scanf("%d",&EdgeTarget) == 1)
            {
                scanf("%d",&weight);
                UpdateEdge (Head, sorceEdge, EdgeTarget, weight);
            }
        }

        if(choice == 'B')
        {
            // printGraph(*Head);
            Do_B(Head, sorce);
        }

        if(choice == 'D')
        {
            // printGraph(*Head);
            scanf("%d",&NodeToDelet);
            DeleteEdges(Head, NodeToDelet);
            DeleteNode(Head, NodeToDelet);
        }
        
        if(choice == 'S')
        {
            // printGraph(*Head);
            int dest, src;
            scanf("%d %d", &src, &dest);
            printf("Dijsktra shortest path: ");
            dijkstra(Head, src, dest, 1);
        }

        if(choice == 'T')
        {
            // printGraph(*Head);
            TSP(Head);
        }
    }

    // printGraph(*Head);
    // printMinWeight(Head);

    deleteGraph_cmd(Head);

    free(Head);
    free(sorce);
    return 0;
}