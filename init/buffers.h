//
// Created by Bennet Weingartz on 29.10.21.
//

#ifndef INDAGO_C_BUFFERS_H
#define INDAGO_C_BUFFERS_H

#include "../core/object.h"

extern GLuint vboID;

void InitVBO(Object* object);
void RefreshVBO(Object* object, char* buffer);
void DestroyVBO(Object* object);

#endif //INDAGO_C_BUFFERS_H
