//
// Created by Bennet Weingartz on 13.02.22.
//

#ifndef INDAGO_C_UNIFORMS_H
#define INDAGO_C_UNIFORMS_H

extern GLuint projectionMatrixUniformLocation,
        viewMatrixUniformLocation,
        modelMatrixUniformLocation;

void InitUniforms(void);
void UpdateUniforms(void);

#endif //INDAGO_C_UNIFORMS_H
