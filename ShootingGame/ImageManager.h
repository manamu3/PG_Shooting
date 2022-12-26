#pragma once
class ImageManager
{
private:
	static int shogiImages[2][8];

public:
	static int LoadGraph();
	static void GetEnemyImage(int index, int image[2]) { image[0] = shogiImages[0][index]; image[1] = shogiImages[1][index]; };
};

