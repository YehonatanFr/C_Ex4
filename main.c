#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pnode CreateLinkedList (int n);
void UpdateEdge (pnode *head, int sorceEdge, int EdgeTarget, int weight) ;

void build_graph_cmd(pnode *head)
{
    int numNode = 0;

    scanf("%d",&numNode);
    *head = CreateLinkedList(numNode);
}

int main()
{

    pnode *Head = NULL;
    char choice;
    int sorceEdge, EdgeTarget, weight;

    while(scanf("%c",&choice)!=EOF)
    {
        if(choice == 'A')
        {
            // deleteGraph_cmd(head);
            build_graph_cmd(Head);
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

    }
    

    

    return 0;
}