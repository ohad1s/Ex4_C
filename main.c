#include <stdio.h>
#include "graph.h"

int main() {
    graph g;
    g.start=NULL;
    g.sum=0;
    int arr[]={0,1,2,3,2,6,4,'n',1,2,3,7,5,3,2,'n',3,9,7,5,5,3,2,'n'};
    build_graph_cmd(&g,g.sum,3,arr);
    printGraph_cmd(g);
    return 0;
}

