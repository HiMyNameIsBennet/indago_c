//
// Created by Bennet Weingartz on 29.10.21.
//

#include "cleanup.h"
#include "../init/shaders.h"
#include "../init/buffers.h"

void Cleanup(void){
    DestroyShaders();
    DestroyVBO();
}