#include "ItemBase.h"

bool ItemBase::Hit(Location player) {
	if (HitSphere(player)) {
		Disabled();
		return true;
	}
	return false;
}