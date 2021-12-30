#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

//------------------------------------------------
// Node implementation
//------------------------------------------------

Node* Node_alloc(int data,Node* next) {
    Node* p= (Node*)malloc(sizeof(Node));
    p->id= data;
    p->_next= next;
    return p;
}

Edge * Edge_alloc(int src,int dest, int weight,Edge * next){
    Edge * e= (Edge *)malloc(sizeof(Edge));
    e->src=src;
    e->dest=dest;
    e->weight=weight;
    e->_next= next;
    return e;
}

void Node_free(Node* node) {
    free(node);
}

graph * graph_alloc() {
    graph * p= (graph*)malloc(sizeof(Node));
    p->_head_node= NULL;
    p->_size= 0;
    return p;
}

void graph_free(graph* g) {
    if (g==NULL) return;
    Node* p1= g->_head_node;
    Node* p2;
    while(p1) {
        p2= p1;
        p1= p1->_next;
        Node_free(p2);
    }
    free(g);
}

void graph_insertFirst_node(graph * g,int data) {
    g->_head_node= Node_alloc(data,g->_head_node);
    ++(g->_size);
}


void graph_insertFirst_edge(graph * g,int src,int dest, int weight) {
    g->_head_edge= Edge_alloc(src,dest,weight,g->_head_edge);
}

void graph_print(const graph * g) {
    const Node* p= g->_head_node;
    while(p) {
        printf("(%d)->",p->id);
        p= p->_next;
    }
    printf("\t%d\n",g->_size);
    const Edge * e= g->_head_edge;
    while(e) {
        printf("(from: %d to: %d w-%d)->",e->src,e->dest,e->weight);
        e= e->_next;
    }
}

int char_to_int(char c){
    return c-'0';
}




















//void deleteGraph_cmd(pgraph g) {
//    pnode n = g->nodes;
//    while (NULL != n) {
//        delete_node_cmd(g, n->id);
//    }
//    pedge e = g->edges;
//    while (NULL != e) {
//        delete_edge_cmd(g, e->src, e->dest);
//    }
//}
//
//void delete_node_cmd(pgraph g, int id) {
//    pnode p = g->nodes;
//    if (p->id == id) {
//        pnode tmp = p->next;
//        free(p);
//        g->nodes = tmp;
//    } else {
//        while (p->next->id != id) {
//            p = p->next;
//        }
//        if (p->id == id) {
//            pnode tmp = p->next;
//            free(p);
//            g->nodes = tmp;
//        }
//    }
//    delete_edges_by_one_par(id,g);
//}
//
//void delete_edge_cmd(pgraph g, int src, int dest) {
//    pedge e = g->edges;
//    if (e->src == src && e->dest == dest) {
//        pedge tmp = e->next;
//        free(e);
//        g->edges = tmp;
//    } else {
//        while (e->next->src != src || e->next->dest != dest) {
//            e = e->next;
//        }
//        if (e->src == src && e->dest == dest) {
//            pedge tmp = e->next;
//            free(e);
//            g->edges = tmp;
//        }
//    }
//}
//
//void insert_node_cmd(int id, pgraph g) {
//    pnode p = (node *) malloc(sizeof(node));
//    if (p) {
//        p->id = id;
//        pnode tmp = g->nodes;
//        g->nodes = p;
//        p->next = tmp;
//    }
//}
//
//void insert_edge_cmd(int src, int dest, int weight, pgraph g) {
//    pedge e = (edge *) malloc(sizeof(edge));
//    e->src = src;
//    e->dest = dest;
//    e->weight = weight;
//    pedge tmp = g->edges;
//    g->edges = e;
//    e->next = tmp;
//}
//
//
//
//
//void delete_edges_by_one_par(int id, pgraph g) {
//    pedge current = g->edges; // pointer to current Node
//    pedge prev = g->edges; // pointer to previous Node
//    pedge removal = NULL; // pointer to Node we will remove
//    // go through the entire linkedList
//    while (current != NULL)
//    {
//        int src = current->src;
//        int dest = current->dest;
//        // lower <= data <= upper
//        // See note below on why use Double.compare()
//        if (src==id || dest==id)
//        {
//            removal = current;
//        }
//        // we found a Node to remove
//        if (removal != NULL)
//        {
//            // special case it was the first
//            if (removal == g->edges)
//            {
//                // change first to next
//                g->edges = removal->next;
//            }
//            else
//            {
//                // move removals previous next to removal next
//                prev->next = removal->next;
//            }
//        }
//        // advance the pointers
//        // only change previous if we didn't have a removal
//        if (removal == NULL)
//        {
//            prev = current;
//        }
//        // move current along
//        current = current->next;
//        // detached the removal
//        if (removal != NULL)
//            removal->next = NULL;
//        // reset the removal pointer
//        removal = NULL;
//    }
//}
//
//void printGraph_cmd(pgraph g){
//    pnode p=g->nodes;
//    pedge e=g->edges;
//    while (p!=NULL){
//        printf("node id: %d -->\t",p->id);
//        p=p->next;
//    }
//    while (e!=NULL){
//        printf("\nedge data: src: %d dest: %d w: %d -->\t",e->src,e->dest,e->weight);
//        e=e->next;
//    }
//}
//
//int char_to_int(char c){
//    return c-'0';
//}
//
//
