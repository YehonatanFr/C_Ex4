#include <stdio.h>
#include "graph.h"

int main()
{
    int numNode = 0;
    pnode *Head = NULL;
    char choice;

    while((scanf("%c",&choice)!=EOF)
    {
        if(choice=='A')
        {
            scanf("%d",&numNode);   
            // deleteGraph_cmd(head);
            // build_graph_cmd(head);
        }

    }
    *Head = CreateLinkedList(numNode);
    PrintGraph(*Head);

    

    return 0;
}