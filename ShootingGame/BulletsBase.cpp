#include "BulletsBase.h"

void BulletsBase::Disabled() {
	isActive = false;
}

int BulletsBase::GetDamage() {
	return damage;
}

bool BulletsBase::IsActive() {
	return isActive;
}