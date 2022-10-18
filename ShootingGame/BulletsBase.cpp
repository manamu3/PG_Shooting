#include "BulletsBase.h"

void BulletsBase::Disabled() {
	isEnable = false;
}

int BulletsBase::GetDamage() {
	return damage;
}

bool BulletsBase::IsEnable() {
	return isEnable;
}