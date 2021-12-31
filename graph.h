#ifndef GRAPH_
#define GRAPH_
#define INFINITY 2147483647;
struct _graph;
typedef struct _graph graph;

typedef struct _node {
    int id;
    int tag;
    struct _node *_next;
} Node;

typedef struct _edge {
    int src;
    int dest;
    int weight;
    struct _edge *_next;
} Edge;


struct _graph {
    Node *_head_node;
    Edge *_head_edge;
    int _size;
};

Node *Node_alloc(int data, Node *next);

Edge *Edge_alloc(int src, int dest, int weight, Edge *next);

graph *graph_alloc();

void Node_free(Node *node);

void Edge_free(Edge *edge);

void graph_free_elements(graph *graph);

void graph_insertFirst_node(graph *graph, int data);

void graph_print(const graph *g);

void graph_insertFirst_edge(graph *graph, int src, int dest, int weight);

int char_to_int(char c);

int is_in(graph *g, int id);

void free_edge_by_src(graph *g, int src);

void free_node_by_id(graph *g, int id);

void free_edge_by_id(graph *g, int id);


typedef struct _queue_node {
    int id;
    struct _queue_node *_next;
} queue_node;

typedef struct _queue {
    struct _queue_node *_head_node;
    int _size;
}Queue;


void queue_insert(Queue *q, int node);
void queue_pop(Queue *q, int data);



#endif
