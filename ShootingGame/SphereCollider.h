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
	Location GetLocation() { return location; }

	void SetLocation(Location _location) { location = _location; }
	void SetRadius(float _radius) { radius = _radius; }
};

