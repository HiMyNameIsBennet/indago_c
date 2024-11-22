#include <string.h>

#include "scenegraph.h"


Scenegraph CreateScenegraph(void){
    Scenegraph graph;
    Node* root = (Node*) (malloc(sizeof(Node)));
    
    char* name = (char*) malloc(sizeof("ROOT"));
    strcpy(name, "ROOT");
    root->name = name;
    root->obj = NULL;
    root->parent = NULL;
    root->renderable = false;

    graph.root = root;

    NodeList renderable_list;
    graph.renderable_nodes = CreateNodeList();

    return graph;
}


void AddToScenegraph(Scenegraph* graph, Node* node, Node* parent){
    if(parent == NULL){
        node->parent = graph->root;
    }
    else {
        node->parent = parent;
    }

    if(node->renderable){
        NodeListAppend(&(graph->renderable_nodes), node);
    }
}


void RemoveFromScenegraph(Scenegraph* graph, Node* node){
    node->parent = NULL;

    NodeListRemove(&(graph->renderable_nodes), node);

    // TODO: the node's children and node itself are no
    // longer possible renderables and will have to be removed from the list!
    // Find a fast way to do this. Recursion?

    // Maybe give a node a nodelist containing its children after all
}


void PrintScenegraph(Scenegraph* graph){
    NodeListItem* curr_renderable = graph->renderable_nodes.root;
    
    while(curr_renderable != NULL){
        Node* curr_node = curr_renderable->node;
        printf("%s", curr_node->name);

        // In here: renderable-to-root traversal
        while(curr_node->parent != NULL){
            printf(", child of %s", curr_node->parent->name);
            curr_node = curr_node->parent;
        }

        printf(".\n");


        curr_renderable = curr_renderable->next;
    }
}

