#include "PowerUpItem.h"
#include "DxLib.h"

PowerUpItem::PowerUpItem(float _x, float _y) {
	x = _x;
	y = _y;
	type = ITEM_TYPE::POWER_UP;
	speed = 3;
	isActive = true;
	SetRadius(20);
}

void PowerUpItem::Update() {
	y += speed;
	Location pos = { x, y };
	SetLocation(pos);
	if (x < 0 || x > 640 || y < 0 || y > 480) Disabled();
}

void PowerUpItem::Draw() const {
	DrawCircle(x, y, 10, 0x0000FF, TRUE);
}