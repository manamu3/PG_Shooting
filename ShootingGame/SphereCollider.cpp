#include "SphereCollider.h"
#include <math.h>

bool SphereCollider::HitSphere(Location pos) {
	float x = pos.x - location.x;
	float y = pos.y - location.y;

	float length = (x * x) + (y * y);

	return radius > sqrtf(length);
}

Location SphereCollider::GetLocation() {
	return location;
}

void SphereCollider::SetLocation(Location location) {
	this->location = location;
}

void SphereCollider::SetRadius(float radius) {
	this->radius = radius;
}