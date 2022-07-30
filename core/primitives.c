//
// Created by Bennet Weingartz on 29.07.22.
//

#include <cglm/cglm.h>

#include "primitives.h"
#include "vertex.h"

Vertex* Quad(vec3 upLeft, vec3 upRight, vec3 downLeft, vec3 downRight, int* size){//temporary colours until textures implemented
    const vec4 sushi = {52.0f / 255, 238.0f / 255, 218.0f / 255};
    const vec4 sand = {235.0f / 255, 248.0f / 255, 175.0f / 255};

    *size = 6;

    Vertex verts[6] = {
        {{upLeft[0], upLeft[1], upLeft[2], 1.0f}, {sushi[0], sushi[1], sushi[2], 1.0f}},
        {{downLeft[0], downLeft[1], downLeft[2], 1.0f}, {sushi[0], sushi[1], sushi[2], 1.0f}},
        {{downRight[0], downRight[1], downRight[2], 1.0f}, {sand[0], sand[1], sand[2], 1.0f}},
        {{upLeft[0], upLeft[1], upLeft[2], 1.0f}, {sushi[0], sushi[1], sushi[2], 1.0f}},
        {{downRight[0], downRight[1], downRight[2], 1.0f}, {sand[0], sand[1], sand[2], 1.0f}},
        {{upRight[0], upRight[1], upRight[2], 1.0f}, {sand[0], sand[1], sand[2], 1.0f}}
    };

    static Vertex vertsPersist[6];

    for(int i = 0; i < *size; i++) vertsPersist[i] = verts[i];

    return vertsPersist;
}

