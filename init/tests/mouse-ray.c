#include <string.h>
#include <cglm/cglm.h>

#include "mouse-ray.h"
#include "../uniforms.h"
#include "../buffers.h"
#include "../../physics/rays.h"
#include "../../core/object.h"


Ray rays[1];
Object* raysWrapper = NULL;


Object** InitRays(void){
	rays[0] = *InitRay((vec4) {-.5f, -.5f, -1.f, 1.0f}, (vec4) {.0f, .0f, 1.f, 1.0f});
	Vertex verts[(sizeof(rays) / sizeof(Ray)) * 2]; //two verts per ray
	raysWrapper = InitObject(verts, (sizeof(verts) / sizeof(Vertex)));


	size_t coordSize = sizeof(float) * 4;

	for(int i = 0; i < sizeof(rays) / sizeof(Ray); i += 2){
		memcpy(raysWrapper->verts[i].pos, rays[i].start, coordSize);
		memcpy(raysWrapper->verts[i + 1].pos, rays[i].end, coordSize);
	
		memcpy(raysWrapper->verts[i].col, (vec4) {1.0f, 1.0f, 1.0f, 1.0f}, coordSize);
		memcpy(raysWrapper->verts[i + 1].col, (vec4) {1.0f, 1.0f, 1.0f, 1.0f}, coordSize);
	}


	mat4 modelMatrix;
	CalcModel(raysWrapper, modelMatrix);

	glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) modelMatrix);

	
	printf("RAYS OK\n");

	return &raysWrapper;
}


void DestroyRays(void){
	free(raysWrapper);
	printf("RAYS DESTROYED\n");
}


void DrawRays(void){
	glDrawArrays(GL_LINES, 0, raysWrapper->vertexCount);

	RefreshVBO(raysWrapper, "position");
}

