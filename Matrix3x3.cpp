#include "Matrix3x3.h"
#include <cassert>

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom) {

	Matrix3x3 orthoMatrix;

	orthoMatrix.m[0][0] = 2.0f / (right - left);
	orthoMatrix.m[0][1] = 0.0f;
	orthoMatrix.m[0][2] = 0.0f;
	orthoMatrix.m[1][0] = 0.0f;
	orthoMatrix.m[1][1] = 2.0f / (top - bottom);
	orthoMatrix.m[1][2] = 0.0f;
	orthoMatrix.m[2][0] = (left + right) / (left - right);
	orthoMatrix.m[2][1] = (top + bottom) / (bottom - top);
	orthoMatrix.m[2][2] = 1.0f;

	return orthoMatrix;

}

Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height) {

	Matrix3x3 viewportMatrix;

	viewportMatrix.m[0][0] = width / 2.0f;
	viewportMatrix.m[0][1] = 0.0f;
	viewportMatrix.m[0][2] = 0.0f;
	viewportMatrix.m[1][0] = 0.0f;
	viewportMatrix.m[1][1] = -height / 2.0f;
	viewportMatrix.m[1][2] = 0.0f;
	viewportMatrix.m[2][0] = left + width / 2.0f;
	viewportMatrix.m[2][1] = top + height / 2.0f;
	viewportMatrix.m[2][2] = 1.0f;

	return viewportMatrix;

}

Matrix3x3 InverseMatrix(Matrix3x3 matrix) {

	float inverseA = 1 / (matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] +
		matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] +
		matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] -
		matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] -
		matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] -
		matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]);

	Matrix3x3 inverseMatrix3x3A;

	inverseMatrix3x3A.m[0][0] = matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1];
	inverseMatrix3x3A.m[0][1] = -(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]);
	inverseMatrix3x3A.m[0][2] = matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1];
	inverseMatrix3x3A.m[1][0] = -(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]);
	inverseMatrix3x3A.m[1][1] = matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0];
	inverseMatrix3x3A.m[1][2] = -(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]);
	inverseMatrix3x3A.m[2][0] = matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0];
	inverseMatrix3x3A.m[2][1] = -(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]);
	inverseMatrix3x3A.m[2][2] = matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0];

	Matrix3x3 inverseMatrix3x3;

	inverseMatrix3x3.m[0][0] = inverseA * inverseMatrix3x3A.m[0][0];
	inverseMatrix3x3.m[0][1] = inverseA * inverseMatrix3x3A.m[0][1];
	inverseMatrix3x3.m[0][2] = inverseA * inverseMatrix3x3A.m[0][2];
	inverseMatrix3x3.m[1][0] = inverseA * inverseMatrix3x3A.m[1][0];
	inverseMatrix3x3.m[1][1] = inverseA * inverseMatrix3x3A.m[1][1];
	inverseMatrix3x3.m[1][2] = inverseA * inverseMatrix3x3A.m[1][2];
	inverseMatrix3x3.m[2][0] = inverseA * inverseMatrix3x3A.m[2][0];
	inverseMatrix3x3.m[2][1] = inverseA * inverseMatrix3x3A.m[2][1];
	inverseMatrix3x3.m[2][2] = inverseA * inverseMatrix3x3A.m[2][2];

	return inverseMatrix3x3;
}

Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {

	Matrix3x3 multiplyMatrix;

	multiplyMatrix.m[0][0] = matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0] + matrix1.m[0][2] * matrix2.m[2][0];
	multiplyMatrix.m[0][1] = matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1] + matrix1.m[0][2] * matrix2.m[2][1];
	multiplyMatrix.m[0][2] = matrix1.m[0][0] * matrix2.m[0][2] + matrix1.m[0][1] * matrix2.m[1][2] + matrix1.m[0][2] * matrix2.m[2][2];

	multiplyMatrix.m[1][0] = matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0] + matrix1.m[1][2] * matrix2.m[2][0];
	multiplyMatrix.m[1][1] = matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1] + matrix1.m[1][2] * matrix2.m[2][1];
	multiplyMatrix.m[1][2] = matrix1.m[1][0] * matrix2.m[0][2] + matrix1.m[1][1] * matrix2.m[1][2] + matrix1.m[1][2] * matrix2.m[2][2];

	multiplyMatrix.m[2][0] = matrix1.m[2][0] * matrix2.m[0][0] + matrix1.m[2][1] * matrix2.m[1][0] + matrix1.m[2][2] * matrix2.m[2][0];
	multiplyMatrix.m[2][1] = matrix1.m[2][0] * matrix2.m[0][1] + matrix1.m[2][1] * matrix2.m[1][1] + matrix1.m[2][2] * matrix2.m[2][1];
	multiplyMatrix.m[2][2] = matrix1.m[2][0] * matrix2.m[0][2] + matrix1.m[2][1] * matrix2.m[1][2] + matrix1.m[2][2] * matrix2.m[2][2];

	return multiplyMatrix;
}

Vector2 Transform(Vector2 vector, Matrix3x3 matrix) {
	Vector2 result;

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	return result;
}

Matrix3x3 MakeTranslateMatrix(Vector2 translate) {
	Matrix3x3 translateMatrix;

	translateMatrix.m[0][0] = 1; translateMatrix.m[0][1] = 0; translateMatrix.m[0][2] = 0;
	translateMatrix.m[1][0] = 0; translateMatrix.m[1][1] = 1; translateMatrix.m[1][2] = 0;
	translateMatrix.m[2][0] = translate.x; translateMatrix.m[2][1] = translate.y; translateMatrix.m[2][2] = 1;

	return translateMatrix;
}

Matrix3x3 MakeWorldToScreenMatrix(
	Vector2 cameraPos,
	float left, float top, float right, float bottom,
	float viewportLeft, float viewportTop,
	float windowWidth, float windowHeight
) {
	Matrix3x3 cameraWorld = MakeTranslateMatrix(cameraPos);
	Matrix3x3 view = InverseMatrix(cameraWorld);
	Matrix3x3 ortho = MakeOrthographicMatrix(left, top, right, bottom);
	Matrix3x3 viewport = MakeViewportMatrix(viewportLeft, viewportTop, windowWidth, windowHeight);

	// view → ortho → viewport の順で合成
	Matrix3x3 result = Multiply(view, ortho);
	result = Multiply(result, viewport);
	return result;
}
