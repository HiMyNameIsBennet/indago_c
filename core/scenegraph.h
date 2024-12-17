#include "node.h"


typedef struct Scenegraph {
   Node* root; 
   NodeList renderable_nodes; // Nodes that contain something that will be rendered
   // Eventually replace the renderable_nodes thing with a BFS/DFS traversal. It's confusing...
} Scenegraph;


Scenegraph CreateScenegraph(void);

void AddToScenegraph(Scenegraph* graph, Node* node, Node* parent);

void RemoveFromScenegraph(Scenegraph* graph, Node* node);

void PrintScenegraph(Scenegraph* graph);

