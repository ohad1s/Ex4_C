#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

void build_graph_cmd(pgraph g, int sum, int to_add,int arr_nodes[]){
    deleteGraph_cmd(g);
    pnode head = (node*) malloc (sizeof(node));
    g->start=head;
    pnode p1=head;
    for (int i=1; i<sum; i++){
        pnode p2 = (node*) malloc (sizeof(node));
        p1->next=p2;
        p1=p1->next;
    }
    int id=arr_nodes[0];
    for (int j=0; j<to_add; j++){
        int counter_edges=0;
        int sum_edges;
        while(arr_nodes[id+1]!='n'){
            counter_edges++;
        }
        sum_edges=counter_edges/2;
        insert_node_cmd(g,arr_nodes[id],sum_edges,(arr_nodes+id+1));
        id=id+counter_edges+1;
    }
}


void deleteGraph_cmd(pgraph g){
    pnode start = g->start;
    while (NULL != start)
    {
        delete_node_cmd(g->start->node_num,g);
    }
}

void delete_node_cmd(int id,pgraph g){
    pnode s=g->start;
    for (int i=0; i<g->sum; i++){
        pedge to_check=s->edges;
        while(to_check->next!=NULL){
            if (to_check->next->endpoint==id){
                pedge tmp=to_check->next;
                to_check->next=tmp->next;
                free(tmp);
            }
        }
        s=s->next;
    }

    pnode p=g->start;
    while(p->node_num!=id){
        p=p->next;
    }
    pedge e=p->edges;
    while(e!=NULL){
        pedge tmp = e;
        e = e->next;
        free(tmp);
    }
    pnode p2=g->start;
//    יש מצב ששכחתי לבדוק אם הראשון הוא למחיקה--- מה קורה
    while(p2->next->node_num!=id){
        p2=p2->next;
    }
    pnode tmp=p2->next;
    p2->next=tmp->next;
    free(tmp);
}

void insert_node_cmd(pgraph g, int id, int sum_edges, int arr[]){
    pnode p = (node*) malloc (sizeof(node));
    p->node_num=id;
    pnode tmp=g->start;
    g->start=p;
    p->next=tmp;
    int j=0;
    for (int i=0; i<sum_edges; i++){
        insert_edge_cmd(arr[j],arr[j+1],p->edges);
        j=j+2;
    }
}

void insert_edge_cmd(int weight, int endpoint, pedge edges){
    pedge e = (edge*) malloc (sizeof(edge));
    e->weight=weight;
    e->endpoint=endpoint;
    e->next=NULL;
    pedge tmp=edges;
    edges->next=e;
    e->next=tmp;
}

void printGraph_cmd(graph g){
    pnode p=g.start;
    for (int i = 0; i < g.sum; i++) {
        printf("node id:, %d, have nothing edges", p->node_num);
    }
}

