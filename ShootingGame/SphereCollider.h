#pragma once

struct Location {
	float x;
	float y;
};

class SphereCollider
{
private:
	Location location;
	float radius;

public:
	bool HitSphere(Location);
	Location GetLocation();
	void SetLocation(Location);
	void SetRadius(float);
};

