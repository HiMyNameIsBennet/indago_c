#include "object.h"


typedef struct Node {
    char* name;
    Object* obj;
    struct Node* parent;
    bool renderable;
} Node;

typedef struct NodeListItem {
    Node* node;
    struct NodeListItem* next;
} NodeListItem;

typedef struct NodeList {
    NodeListItem* root;
} NodeList;


Node CreateNode(const char* name, bool renderable);

NodeList CreateNodeList(void);

void NodeListAppend(NodeList* node_list, Node* to_append);

void NodeListRemove(NodeList* node_list, Node* to_remove);

