#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

void deleteGraph_cmd(pgraph g) {
    pnode n = g->nodes;
    while (NULL != n) {
        delete_node_cmd(g, n->id);
    }
    pedge e = g->edges;
    while (NULL != e) {
        delete_edge_cmd(g, e->src, e->dest);
    }
}

void delete_node_cmd(pgraph g, int id) {
    pnode p = g->nodes;
    if (p->id == id) {
        pnode tmp = p->next;
        free(p);
        g->nodes = tmp;
    } else {
        while (p->next->id != id) {
            p = p->next;
        }
        if (p->id == id) {
            pnode tmp = p->next;
            free(p);
            g->nodes = tmp;
        }
    }
    delete_edges_by_one_par(id,g);
}

void delete_edge_cmd(pgraph g, int src, int dest) {
    pedge e = g->edges;
    if (e->src == src && e->dest == dest) {
        pedge tmp = e->next;
        free(e);
        g->edges = tmp;
    } else {
        while (e->next->src != src || e->next->dest != dest) {
            e = e->next;
        }
        if (e->src == src && e->dest == dest) {
            pedge tmp = e->next;
            free(e);
            g->edges = tmp;
        }
    }
}

void insert_node_cmd(int id, pgraph g) {
    pnode p = (node *) malloc(sizeof(node));
    if (p) {
        p->id = id;
        pnode tmp = g->nodes;
        g->nodes = p;
        p->next = tmp;
    }
}

void insert_edge_cmd(int src, int dest, int weight, pgraph g) {
    pedge e = (edge *) malloc(sizeof(edge));
    e->src = src;
    e->dest = dest;
    e->weight = weight;
    pedge tmp = g->edges;
    g->edges = e;
    e->next = tmp;
}




void delete_edges_by_one_par(int id, pgraph g) {
    pedge current = g->edges; // pointer to current Node
    pedge prev = g->edges; // pointer to previous Node
    pedge removal = NULL; // pointer to Node we will remove
    // go through the entire linkedList
    while (current != NULL)
    {
        int src = current->src;
        int dest = current->dest;
        // lower <= data <= upper
        // See note below on why use Double.compare()
        if (src==id || dest==id)
        {
            removal = current;
        }
        // we found a Node to remove
        if (removal != NULL)
        {
            // special case it was the first
            if (removal == g->edges)
            {
                // change first to next
                g->edges = removal->next;
            }
            else
            {
                // move removals previous next to removal next
                prev->next = removal->next;
            }
        }
        // advance the pointers
        // only change previous if we didn't have a removal
        if (removal == NULL)
        {
            prev = current;
        }
        // move current along
        current = current->next;
        // detached the removal
        if (removal != NULL)
            removal->next = NULL;
        // reset the removal pointer
        removal = NULL;
    }
}

void printGraph_cmd(pgraph g){
    pnode p=g->nodes;
    pedge e=g->edges;
    while (p!=NULL){
        printf("node id: %d -->\t",p->id);
        p=p->next;
    }
    while (e!=NULL){
        printf("\nedge data: src: %d dest: %d w: %d -->\t",e->src,e->dest,e->weight);
        e=e->next;
    }
}

int char_to_int(char c){
    return c-'0';
}


