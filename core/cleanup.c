//
// Created by Bennet Weingartz on 29.10.21.
//

#include "cleanup.h"
#include "../init/shaders.h"
#include "../init/buffers.h"
#include "../init/test.h"

void Cleanup(void){ // have to make this modular. testing mode or not?
    DestroyTest();
    DestroyTestShaders();
}