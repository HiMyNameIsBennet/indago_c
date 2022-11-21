//
// Created by Bennet Weingartz on 13.02.22.
//

#include <stdio.h>

#include <GL/glew.h>

#include "test.h"
#include "buffers.h"
#include "tests/cube.h"
#include "tests/points.h"
#include "tests/waves.h"
#include "tests/mouse-ray.h"
#include "../core/render.h"

Object** (*InitFunc)(void);
void (*DestroyFunc)(void);

Object** testObject;

Object** InitTest(void){
    int test;

    printf("Please enter test number: ");
    scanf("%i", &test);

    switch(test){
        default:
        case 0:
            RenderTest = &DrawCube;
            InitFunc = &InitCube;
            DestroyFunc = &DestroyCube;
            break;
        case 1:
            RenderTest = &DrawPoints;
            InitFunc = &InitPoints;
            DestroyFunc = &DestroyPoints;
            break;
        case 2:
            RenderTest = &DrawWaves;
            InitFunc = &InitWaves;
            DestroyFunc = &DestroyWaves;
            break;
		case 3:
			RenderTest = &DrawRays;
			InitFunc = &InitRays;
			DestroyFunc = &DestroyRays;
			break;
    }

    testObject = (*InitFunc)();

    return testObject;
}

void DestroyTest(void){
    (*DestroyFunc)();
    DestroyVBO(*testObject);
}

