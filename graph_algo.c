#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

Node *Node_alloc(int data, Node *next) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->id = data;
    p->_next = next;
    p->tag = INFINITY;
    return p;
}

Edge *Edge_alloc(int src, int dest, int weight, Edge *next) {
    Edge *e = (Edge *) malloc(sizeof(Edge));
    e->src = src;
    e->dest = dest;
    e->weight = weight;
    e->_next = next;
    return e;
}

void Node_free(Node *node) {
    free(node);
}

void Edge_free(Edge *edge) {
    free(edge);
}

graph *graph_alloc() {
    graph *p = (graph *) malloc(sizeof(Node));
    p->_head_node = NULL;
    p->_size = 0;
    return p;
}

void graph_free_elements(graph *g) {
    if (g->_head_node == NULL) return;
    Node *p1 = g->_head_node;
    Node *p2;
    while (p1) {
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    Edge *e1 = g->_head_edge;
    Edge *e2;
    while (e1) {
        e2 = e1;
        e1 = e1->_next;
        Edge_free(e2);
    }
}

void graph_insertFirst_node(graph *g, int data) {
    g->_head_node = Node_alloc(data, g->_head_node);
    ++(g->_size);
}


void graph_insertFirst_edge(graph *g, int src, int dest, int weight) {
    g->_head_edge = Edge_alloc(src, dest, weight, g->_head_edge);
}

void graph_print(const graph *g) {
    const Node *p = g->_head_node;
    while (p) {
        printf("(%d)->", p->id);
        p = p->_next;
    }
    printf("\t%d\n", g->_size);
    const Edge *e = g->_head_edge;
    while (e) {
        printf("(from: %d to: %d w-%d)->", e->src, e->dest, e->weight);
        e = e->_next;
    }
}

int char_to_int(char c) {
    return c - '0';
}

int is_in(graph *g, int id) {
    if (g->_head_node == NULL) return 0;
    Node *p1 = g->_head_node;
    while (p1) {
        if (p1->id == id) {
            return 1;
        }
        p1 = p1->_next;
    }
    return 0;
}

void free_edge_by_src(graph *g, int src) {
    Edge *current = g->_head_edge; // pointer to current Node
    Edge *prev = g->_head_edge; // pointer to previous Node
    Edge *removal = NULL; // pointer to Node we will remove
    while (current != NULL) {
        if (current->src == src) {
            if (current == g->_head_edge) {
                g->_head_edge = current->_next;
                removal = current;
                current=current->_next;
                free(removal);
                removal= NULL;
            } else {
                prev->_next = current->_next;
                removal = current;
                current=current->_next;
                free(removal);
                removal= NULL;
            }
        }
        else {
            prev = current;
            current = current->_next;
        }
    }
}

void free_node_by_id(graph *g, int id) {
    Node *p1 = g->_head_node;
    Node *prev = g->_head_node;
    if (p1->id == id) {
        g->_head_node = g->_head_node->_next;
        free(p1);
        g->_size=g->_size-1;
    } else {
        while (p1->id != id) {
            prev = p1;
            p1 = p1->_next;
        }
        prev->_next = p1->_next;
        free(p1);
        g->_size=g->_size-1;
    }
}

void free_edge_by_id(graph *g, int id) {
    Edge *current = g->_head_edge; // pointer to current Node
    Edge *prev = g->_head_edge; // pointer to previous Node
    Edge *removal = NULL; // pointer to Node we will remove
    while (current != NULL) {
        if (current->src == id || current->dest == id) {
            if (current == g->_head_edge) {
                g->_head_edge = current->_next;
                removal = current;
                current=current->_next;
                free(removal);
                removal=NULL;
            } else {
                prev->_next = current->_next;
                removal = current;
                current=current->_next;
                free(removal);
                removal=NULL;
            }
        }
        else {
            prev = current;
            current = current->_next;
        }
    }
}

Node *queue_node_alloc(int data, queue_node *next) {
    queue_node *p = (queue_node *) malloc(sizeof(queue_node));
    p->id = data;
    p->_next = next;
    return p;
}

void queue_insert_first(Queue *q, int data) {
    q->_head_node = queue_node_alloc(data, q->_head_node);
    ++(q->_size);
}
void queue_pop_last(Queue *q, int data) {
//    delete him from the queue and return his pointer- i must do the pop on the last element of the queue
}

//int shortestPathDist(int src, int dest) {
//    if (src == dest) {
//        return 0;
//    }
//    return calculateShortestPath(src);
//}
//
//void calculateShortestPath(int src) {
//
//}



