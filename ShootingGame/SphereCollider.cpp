#include "SphereCollider.h"
#include <math.h>

bool SphereCollider::HitSphere(Location pos) {
	float x = pos.x - location.x;
	float y = pos.y - location.y;

	float length = (x * x) + (y * y);

	return radius > sqrtf(length);
}