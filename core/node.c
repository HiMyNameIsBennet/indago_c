#include <string.h>

#include "node.h"


Node CreateNode(const char* name, bool renderable){
    Node node;
    
    int i = 0;
    while(name[i] != '\0'){ i++; }

    node.name = (char*) malloc(i); // i bytes. i chars.
    strcpy(node.name, name);

    node.obj = NULL;
    node.parent = NULL;
    node.renderable = renderable;

    return node;
}


NodeList CreateNodeList(void){
    NodeList node_list;
    
    node_list.root = NULL;

    return node_list;
}


void NodeListAppend(NodeList* node_list, Node* to_append){
    NodeListItem* curr = node_list->root;

    NodeListItem* new_item = (NodeListItem*) malloc(sizeof(NodeListItem));
    new_item->next = NULL;
    new_item->node = to_append;
        
    if(node_list->root == NULL){
       node_list->root = new_item;
       return;
    }

    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = new_item;
}


void NodeListRemove(NodeList* node_list, Node* to_remove){
    if(node_list->root == NULL){
        return;
    }

    if(to_remove == node_list->root->node){
        free(node_list->root);
        node_list->root = NULL;
        return;
    }

    NodeListItem* curr = node_list->root; 

    while(curr->next != NULL && curr->next->node != to_remove){
        curr = curr->next;
    }

    if(curr->next->next == NULL){
        free(curr->next);
        curr->next = NULL;
        return;
    }

    free(curr->next);
    curr->next = curr->next->next;
}

