//
// Created by Bennet Weingartz on 29.10.21.
//

#ifndef INDAGO_C_RENDER_H
#define INDAGO_C_RENDER_H


#include "../core/scenegraph.h"


extern void (*RenderTest)(void);
void (*RenderTest)(void);

void Render(Scenegraph* graph);
void DrawRenderable(Scenegraph* graph, Node* node);

#endif //INDAGO_C_RENDER_H
