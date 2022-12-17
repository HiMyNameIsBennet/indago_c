#include <string.h>
#include <cglm/cglm.h>

#include "mouse-ray.h"
#include "../uniforms.h"
#include "../buffers.h"
#include "../../physics/rays.h"
#include "../../core/object.h"


Ray rays[1];
Object* rayWrappers[1];


Object** InitRays(void){
	rays[0] = *InitRay((vec4) {-.5f, -.5f, -1.f, 1.0f}, (vec4) {.0f, .0f, 1.f, 1.0f});
	size_t rayArrayLen = sizeof(rays) / sizeof(Ray);

	mat4 rayModelMatrices[rayArrayLen];
	
	for(int i = 0; i < rayArrayLen; i++){
		rayWrappers[i] = WrapRay(rays + i);
		CalcModel(rayWrappers[i], rayModelMatrices[i]);
	}

	
	//only works for singular ray (for now, bound to change to per-object model)
	glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) rayModelMatrices);

	
	printf("RAYS OK\n");

	//as above
	return rayWrappers;
}


void DestroyRays(void){
	//as above
	free(rayWrappers[0]);
	printf("RAYS DESTROYED\n");
}


void DrawRays(void){
	//as above
	glDrawArrays(GL_LINES, 0, rayWrappers[0]->vertexCount);

	//as above
	RefreshVBO(rayWrappers[0], "position");
}

