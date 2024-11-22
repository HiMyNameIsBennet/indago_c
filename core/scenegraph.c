#include <string.h>

#include "scenegraph.h"


// Create the scene graph
Scenegraph CreateScenegraph(void){
    Scenegraph graph;
    Node* root = (Node*) (malloc(sizeof(Node)));
    
    *root = CreateNode("ROOT", false);

    graph.root = root;

    graph.renderable_nodes = CreateNodeList();

    return graph;
}


// Add a node to the scene graph, can specify parent note (default (null): root)
void AddToScenegraph(Scenegraph* graph, Node* node, Node* parent){
    // By default, parent == NULL, so node's parent is the scene graph's root.
    // If parent is non-NULL, the parent from the parameter is specified
    node->parent = (parent == NULL ? graph->root : parent);

    if(node->renderable){
        NodeListAppend(&(graph->renderable_nodes), node);
    }
}


// Remove a node from the scene graph
void RemoveFromScenegraph(Scenegraph* graph, Node* node){
    // This is all we have to change for the scene graph itself, and...
    node->parent = NULL;

    // ...for the renderables, we remove it from the renderable_nodes
    NodeListRemove(&(graph->renderable_nodes), node);

    // TODO: the node's children and node itself are no
    // longer possible renderables and will have to be removed from the list!
    // Find a fast way to do this. Recursion?

    // Maybe give a node a nodelist containing its children after all
}


// Print the scene graph to stdout, mostly for debug purposes
// Should be relatively self explanatory with the hint that
// we print from "leaves" to root
void PrintScenegraph(Scenegraph* graph){
    // Set our first renderable
    NodeListItem* curr_renderable = graph->renderable_nodes.root;
    
    // If we are null in the first step (no renderables) already, no action
    while(curr_renderable != NULL){
        // Get node for current randerable
        Node* curr_node = curr_renderable->node;
        printf("%s", curr_node->name);

        // In here: renderable-to-root traversal
        // Print node's ancestry
        while(curr_node->parent != NULL){
            printf(", child of %s", curr_node->parent->name);
            curr_node = curr_node->parent;
        }

        printf(".\n");


        curr_renderable = curr_renderable->next;
    }
}

