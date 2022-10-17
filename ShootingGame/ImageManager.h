#pragma once
class ImageManager
{
private:
	int shogiImages[2][8];

protected:
	ImageManager();
	int GetImage(int _x, int _y) { return shogiImages[_y][_x]; };
};

