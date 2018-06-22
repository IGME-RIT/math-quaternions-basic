#include "Quaternion.h"

Quaternion::Quaternion()
	: w(0), x(0), y(0), z(0)
{
}

Quaternion::Quaternion(float w, float x, float y, float z)
	: w(w), x(x), y(y), z(z)
{
}

Quaternion::Quaternion(float w, Vector3D v)
	: w(w), x(v.x), y(v.y), z(v.z)
{
}

Quaternion operator+(Quaternion q, Quaternion r)
{
	return Quaternion(q.w + r.w, q.x + r.x, q.y + r.y, q.z + r.z);
}

Quaternion operator-(Quaternion q)
{
	return Quaternion(-q.w, -q.x, -q.y, -q.z);
}

Quaternion operator-(Quaternion q, Quaternion r)
{
	return q + (-r);
}

Quaternion operator*(Quaternion q, Quaternion r)
{
	float wComp = (q.w * r.w) - (q.x * r.x) - (q.y * r.y) - (q.z * r.z);
	float xComp = (q.w * r.x) + (q.x * r.w) - (q.y * r.z) + (q.z * r.y);
	float yComp = (q.w * r.y) + (q.x * r.z) + (q.y * r.w) - (q.z * r.x);
	float zComp = (q.w * r.z) - (q.x * r.y) - (q.y * r.x) + (q.z * r.w);

	return Quaternion(wComp, xComp, yComp, zComp);
}

Quaternion operator*(float s, Quaternion q)
{
	return Quaternion(s*q.w, s*q.x, s*q.y, s*q.z);
}

Quaternion operator*(Quaternion q, float s)
{
	return s * q;
}

float Norm(Quaternion q)
{
	return (q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z);
}

float Magnitude(Quaternion q)
{
	return (sqrt(Norm(q)));
}

Quaternion operator/(Quaternion q, float s)
{
	return Quaternion(q.w / s, q.x / s, q.y / s, q.z / s);
}

Quaternion operator/(Quaternion q, Quaternion r)
{
	float norm = Norm(r);

	Quaternion q = q * r;

	return Quaternion(q / norm);
}

Quaternion Normalize(Quaternion q)
{
	return (q / Magnitude(q));
}

Quaternion Conjugate(Quaternion q)
{
	return Quaternion(q.w, -q.x, -q.y, -q.y);
}

Quaternion Inverse(Quaternion q)
{
	return(Conjugate(q) / Norm(q));
}

float Dot(Quaternion q, Quaternion r)
{
	return ((q.w*r.w) + (q.x*r.x) + (q.y*r.y) + (q.z*r.z));
}

float AngleBetweenQuaternions(Quaternion q, Quaternion r)
{
	float cosOfAngle = Dot(q, r) / (Magnitude(q) * Magnitude(r));

	return (acos(cosOfAngle));
}

std::ostream& operator<<(std::ostream& os, Quaternion q)
{
	os << "(" << q.w << ", " << q.x << ", " << q.y << ", " << q.z << ")";
	return os;
}