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
    graph *p = (graph *) malloc(sizeof(Queue));
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
                current = current->_next;
                free(removal);
                removal = NULL;
            } else {
                prev->_next = current->_next;
                removal = current;
                current = current->_next;
                free(removal);
                removal = NULL;
            }
        } else {
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
        g->_size = g->_size - 1;
    } else {
        while (p1->id != id) {
            prev = p1;
            p1 = p1->_next;
        }
        prev->_next = p1->_next;
        free(p1);
        g->_size = g->_size - 1;
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
                current = current->_next;
                free(removal);
                removal = NULL;
            } else {
                prev->_next = current->_next;
                removal = current;
                current = current->_next;
                free(removal);
                removal = NULL;
            }
        } else {
            prev = current;
            current = current->_next;
        }
    }
}

Queue *queue_alloc() {
    Queue *p = (Queue *) malloc(sizeof(Queue));
    p->_head_node = NULL;
    p->_size = 0;
    return p;
}

queue_node *queue_node_alloc(int data, queue_node *next) {
    queue_node *p = (queue_node *) malloc(sizeof(queue_node));
    p->id = data;
    p->_next = next;
    return p;
}

void queue_insert_first(Queue *q, int data) {
    q->_head_node = queue_node_alloc(data, q->_head_node);
    (q->_size=q->_size+1);
}

int queue_pop_last(Queue *q) {
    printf("im in pop last func\n");
//    queue_print(q);
    queue_node *prev=q->_head_node;
    queue_node *p = q->_head_node;
    while (p->_next != NULL) {
//        printf("prev is: %d", prev->id);
//        printf("curr is: %d", p->id);
        prev=p;
        p = p->_next;
//        printf("but why???\n");
    }
    int id = p->id;
    free(p);
    printf("free from func\n");
    prev->_next=NULL;
    printf("id to pop from the function: %d\n",id);
    return id;
}

int shortestPathDist(graph *g, int src, int dest) {
    printf("im in\n");
    if (src == dest) {
        return 0;
    }
    Queue *to_visit = queue_alloc();
//    Queue *visited = queue_alloc();
    queue_insert_first(to_visit, src);
    Node *p = g->_head_node;
    while (p->id != src) {
        printf("found\n");
        p = p->_next;
    }
    p->tag = 0;
    while (to_visit->_head_node!=NULL) {
//        queue_print(to_visit);
        printf("call in big while\n");
        int to_check = queue_pop_last(to_visit);
        printf("poped: %d\n",to_check);
//        queue_insert_first(visited, to_check);
        Node *p2 = g->_head_node;
        while (p2->id != to_check) {
            p2 = p2->_next;
        }
        int tag = p2->tag;
        Edge *e = g->_head_edge;
        while (e!= NULL) {
            if (e->src == to_check) {
                queue_insert_first(to_visit, e->dest);
                printf("insert: %d\n",e->dest);
                int w = e->weight;
                Node *p3 = g->_head_node;
                while (p3->id != e->dest) {
                    p3 = p3->_next;
                }
                if (w + tag < p3->tag) {
                    p3->tag = w + tag;
                }
            }
            printf("++next edge\n");
            e = e->_next;
        }

    }
    free(to_visit);
    printf("out of big while- to visit free\n");
    Node *p4 = g->_head_node;
    while (p4->id != dest) {
        p4 = p4->_next;
    }
    if (p4->tag==INFINITY){
        return -1;
    }
    return p4->tag;
}


void queue_print(const Queue *q) {
    const queue_node *p = q->_head_node;
    while (p!= NULL) {
        printf("(%d)->", p->id);
        p = p->_next;
    }
    printf("\t%d\n", q->_size);
}

