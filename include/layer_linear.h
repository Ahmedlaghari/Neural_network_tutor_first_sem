#pragma once

float linear_forward(float x, float w, float b);
void linear_backward(float x, float dL_dz, float &dL_dw, float &dL_db, float &dL_dx);
