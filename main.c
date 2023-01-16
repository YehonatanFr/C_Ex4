#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void CreateLinkedList (int n, pnode *head);

void UpdateEdge (pnode *head, int sorceEdge, int EdgeTarget, int weight);

void PrintGraph(node **head);

// void build_graph_cmd(pnode *head)
// {
//     int numNode;
//     printf("Hey im in function\n");
//     if(scanf("%d",&numNode) == 1)
//     {
//         printf("Scanf numNode work\n");
//     }
//     else
//     {
//         printf("Error\n");
//     }
    
//     CreateLinkedList(numNode, head);
// }

int main()
{

    pnode *Head=(pnode*)malloc(sizeof(pnode));
    char choice;
    int sorceEdge, EdgeTarget, weight;
    int numNode;

    while(scanf("%c",&choice)!=EOF)
    {
        if(choice == 'A')
        {
            scanf("%d",&numNode);   
            CreateLinkedList(numNode, Head);
            PrintGraph(Head);
            // deleteGraph_cmd(head);
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
    
    free(Head);
    return 0;
}