#include "PowerUpItem.h"
#include "DxLib.h"

PowerUpItem::PowerUpItem(float _x, float _y) {
	x = _x;
	y = _y;
	type = ITEM_TYPE::POWER_UP;
	speed = 3;
	isActive = true;
	image = LoadGraph("images/item.png");
	SetRadius(20);
}

void PowerUpItem::Update() {
	y += speed;
	Location pos = { x, y };
	SetLocation(pos);
	if (x < 0 || x > 640 || y < 0 || y > 480) Disabled();
}

void PowerUpItem::Draw() const {
	DrawRotaGraph(x, y, 0.8, 0.0, image, TRUE);
	SetFontSize(25);
	DrawString(x - 13, y - 10, "—Í", 0x0000FF);
}