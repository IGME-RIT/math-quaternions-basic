#include "Quaternion.h"

Quaternion::Quaternion()
	: w(0), x(0), y(0), z(0)
{
}

Quaternion::Quaternion(float w, float x, float y, float z)
	: w(w), x(x), y(y), z(z)
{
}

Quaternion operator+(Quaternion l, Quaternion r)
{
	return Quaternion(l.w + r.w, l.x + r.x, l.y + r.y, l.z + r.z);
}

Quaternion operator-(Quaternion l)
{
	return Quaternion(-l.w, -l.x, -l.y, -l.z);
}

Quaternion operator-(Quaternion l, Quaternion r)
{
	return l + (-r);
}

Quaternion operator*(Quaternion l, Quaternion r)
{
	float wComp = (r.w * l.w) - (r.x * l.x) - (r.y * l.y) - (r.z * l.z);
	float xComp = (r.w * l.x) + (r.x * l.w) - (r.y * l.z) + (r.z * l.y);
	float yComp = (r.w * l.y) + (r.x * l.z) + (r.y * l.w) - (r.z * l.x);
	float zComp = (r.w * l.z) - (r.x * l.y) - (r.y * l.x) + (r.z * l.w);

	return Quaternion(wComp, xComp, yComp, zComp);
}

Quaternion operator*(float s, Quaternion l)
{
	return Quaternion(s*l.w, s*l.x, s*l.y, s*l.z);
}

Quaternion operator*(Quaternion l, float s)
{
	return s * l;
}

Quaternion operator/(Quaternion l, float s)
{
	return Quaternion(l.w / s, l.x / s, l.y / s, l.z / s);
}

Quaternion operator/(float s, Quaternion l)
{
	return l / s;
}

Quaternion operator/(Quaternion l, Quaternion r)
{
	float norm = Norm(r);

	Quaternion q = l * r;

	return Quaternion(q / norm);
}

float Norm(Quaternion l)
{
	return (l.w*l.w + l.x*l.x + l.y*l.y + l.z*l.z);
}

Quaternion Conjugate(Quaternion l)
{
	return Quaternion(l.w, -l.x, -l.y, -l.y);
}

Quaternion Inverse(Quaternion l)
{
	return(Conjugate(l) / Norm(l));
}

std::ostream& operator<<(std::ostream& os, Quaternion l)
{
	os << "(" << l.w << ", " << l.x << ", " << l.y << ", " << l.z << ")";
	return os;
}