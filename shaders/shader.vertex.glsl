//
// Created by Bennet Weingartz on 29.10.21.
//

#version 410
layout(location=0) in vec4 vPosition;
layout(location=1) in vec4 vColor;
out vec4 eColor;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void){
    gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vPosition;
    eColor = vColor;
}