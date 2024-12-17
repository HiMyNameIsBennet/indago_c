#include "object.h"


typedef struct NodeListItem {
    struct Node* node;
    struct NodeListItem* next;
} NodeListItem;

typedef struct NodeList {
    NodeListItem* root;
} NodeList;

typedef struct Node {
    char* name;
    Object* obj;

    bool renderable;

    // Scenegraph functionality (strong)
    struct Node* parent;
    NodeList children;
    // I'm fighting between strong and weak connections here. Hear me out.
    // Either I do it strongly, and give each node references to its parents and children.
    // Or: I do it weakly, and wrap a node in a ScenegraphNode, giving the node an optional reference to its SGN
} Node;


Node CreateNode(const char* name, bool renderable);

NodeList CreateNodeList(void);

void NodeListAppend(NodeList* node_list, Node* to_append);

void NodeListRemove(NodeList* node_list, Node* to_remove);
