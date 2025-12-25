#pragma once
#include "Vector2.h"

struct Matrix3x3 {
	float m[3][3];
};

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);

Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height);

Matrix3x3 InverseMatrix(Matrix3x3 matrix);

Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);

Matrix3x3 MakeTranslateMatrix(Vector2 translate);

Vector2 Transform(Vector2 vector, Matrix3x3 matrix);

Matrix3x3 MakeWorldToScreenMatrix(
	Vector2 cameraPos,
	float left, float top, float right, float bottom,
	float viewportLeft, float viewportTop,
	float windowWidth, float windowHeight
);