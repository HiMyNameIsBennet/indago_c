//
// Created by Bennet Weingartz on 07.08.22.
//

#ifndef INDAGO_C_RAYS_H
#define INDAGO_C_RAYS_H


#include <cglm/cglm.h>

#include "../core/object.h"


typedef struct {
	vec4 start;
	vec4 end;
} Ray;


Ray* InitRay(vec4 startNDC, vec4 endNDC);
Object* WrapRay(Ray*);


#endif //INDAGO_C_RAYS_H
