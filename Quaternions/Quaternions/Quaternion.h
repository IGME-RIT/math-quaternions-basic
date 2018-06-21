#pragma once

#include <iostream>
#include <math.h>

struct Quaternion
{
	float w, x, y, z;

	Quaternion();
	Quaternion(float w, float x, float y, float z);
};

Quaternion operator+(Quaternion l, Quaternion r);
Quaternion operator-(Quaternion l);
Quaternion operator-(Quaternion l, Quaternion r);

Quaternion operator*(Quaternion l, Quaternion r);
Quaternion operator*(float s, Quaternion l);
Quaternion operator*(Quaternion, float s);
Quaternion operator/(Quaternion l, float s);
Quaternion operator/(float s, Quaternion l);
Quaternion operator/(Quaternion l, Quaternion r);

float Norm(Quaternion l);
Quaternion Conjugate(Quaternion l);
Quaternion Inverse(Quaternion l);

std::ostream& operator<<(std::ostream& os, Quaternion l);