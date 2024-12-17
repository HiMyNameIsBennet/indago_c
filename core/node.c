#include <string.h>

#include "node.h"


// Create a new node.
// Default: obj NULL, parent NULL
Node CreateNode(const char* name, bool renderable){
    Node node;
    
    int i = 0;
    while(name[i] != '\0'){ i++; }

    node.name = (char*) malloc(i); // i bytes. i chars.
    strcpy(node.name, name);

    node.obj = NULL;
    node.renderable = renderable;

    // Scenegraph functionality
    node.parent = NULL;
    node.children = CreateNodeList();

    return node;
}


// Create a new list of nodes (linked list)
// Default: root = null
NodeList CreateNodeList(void){
    NodeList node_list;
    
    node_list.root = NULL;

    return node_list;
}


// Append the named node to the end of the node list
// Of course, wrapped in a NodeListItem (for the next pointer)
void NodeListAppend(NodeList* node_list, Node* to_append){
    // Make a new NodeListItem
    NodeListItem* new_item = (NodeListItem*) malloc(sizeof(NodeListItem));
    new_item->next = NULL;
    new_item->node = to_append;
    
    // If our node_list's root is null, set it to the item we appended and return
    if(node_list->root == NULL){
       node_list->root = new_item;
       return;
    }

    NodeListItem* curr = node_list->root;
    
    // Run to the end
    while(curr->next != NULL){
        curr = curr->next;
    }

    // Set last NodeListItem's next pointer to wrapped to_append node
    curr->next = new_item;
}


// Remove the given node from the node list
void NodeListRemove(NodeList* node_list, Node* to_remove){
    // If our node_list is empty, return
    if(node_list->root == NULL){
        return;
    }

    // If we want to remove the anchor node, free its wrapper (not the node!)
    // And set the anchor to Null. Return.
    if(to_remove == node_list->root->node){
        free(node_list->root);
        node_list->root = NULL;
        return;
    }

    // Trust me, it's better for readability if we define this here, and not above.
    // Start at the node_list's root
    NodeListItem* curr = node_list->root; 

    // If we have a next item AND our next item's node isn't the one we want to remove
    while(curr->next != NULL && curr->next->node != to_remove){
        curr = curr->next;
    }


    // If the item behind the item we want to remove is NULL, free the item to remove,
    // and set the our next pointer to NULL (we are the new last item of the list)
    if(curr->next->next == NULL){
        free(curr->next);
        curr->next = NULL;
        return;
    }


    // Note: we do this "next item's node" check because we want curr to end up as
    // the item that holds a reference to the item we want to remove. By doing this, all
    // we have to do is to free next and then set the item's next pointer to next->next,
    // while remembering that once we free next, next->next is impossible to access, so...
    NodeListItem* new_next = curr->next->next;
    free(curr->next);
    curr->next = new_next;
}

