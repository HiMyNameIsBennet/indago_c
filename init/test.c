//
// Created by Bennet Weingartz on 13.02.22.
//

#include <stdio.h>

#include "test.h"
#include "tests/cube.h"
#include "../core/render.h"

void (*InitFunc)(void), (*DestroyFunc)(void);

void InitTest(void){
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
    }

    (*InitFunc)();
}

void DestroyTest(void){
    (*DestroyFunc)();
}