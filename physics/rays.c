//
// Created by Bennet Weingartz on 07.08.22.
//

#include <string.h>

#include "rays.h"
#include "../init/init.h"
#include "../core/camera.h"
#include "../core/vertex.h"


Ray* InitRay(vec4 startNDC, vec4 endNDC){ //initializes world space ray from NDC
	
	//this function can be made more concise if operations like
	//glm_mat4_inv(m1, m1) or glm_vec4_scale(v1, scale, v1)
	//are allowed. check for this in debugger with some test cases
	
	Ray* ray = malloc(sizeof(Ray));

	mat4 combinedMatrix, inverseMatrix;
	glm_mat4_mul(projectionMatrix, viewMatrix, combinedMatrix);
	glm_mat4_inv(combinedMatrix, inverseMatrix);

	//turning NDC coordinates into world coordinates (NDC -> cam space -> world space)
	vec4 startUnscaled, endUnscaled;
	glm_mat4_mulv(inverseMatrix, startNDC, startUnscaled);
	glm_mat4_mulv(inverseMatrix, endNDC, endUnscaled);

	//normalizing vectors by w coordinate
	glm_vec4_scale(startUnscaled, 1.0f / startUnscaled[3], ray->start);
	glm_vec4_scale(endUnscaled, 1.0f / endUnscaled[3], ray->end);

	return ray;
}


Object* WrapRay(Ray* ray){
	Vertex verts[2];
	Object* rayWrapper = InitObject(verts, 2);

	size_t coordSize = sizeof(float) * 4;

	memcpy(rayWrapper->verts[0].pos, ray->start, coordSize);
	memcpy(rayWrapper->verts[1].pos, ray->end, coordSize);

	memcpy(rayWrapper->verts[0].col, (vec4) {1.0f, 1.0f, 1.0f, 1.0f}, coordSize);
	memcpy(rayWrapper->verts[1].col, (vec4) {1.0f, 1.0f, 1.0f, 1.0f}, coordSize);

	return rayWrapper;
}

