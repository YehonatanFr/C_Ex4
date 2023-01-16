#include <stdio.h>
#include "graph.h"



pnode NewNode (int num, int *next)
{

    pnode temp = (pnode) malloc (sizeof(node));
    temp->node_num = num;
    temp->edges = NULL;
    temp->next = next;
    return temp;
}

pnode CreateLinkedList (int n)
{
    pnode head = NULL;
    pnode p = NULL;

    for(int i = 0; i<n; i++)
    {
        pnode temp = NewNode(i,NULL);

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while( p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}

void PrintGraph(pnode head)
{
    pnode p = head;
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

