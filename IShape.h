#pragma once
#include <stdio.h>

class IShape {
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;
protected:
	const char* name;
	float radius = 4;   // 円の半径
	int wide = 2;       // 長方形の幅
	int height = 3;     // 長方形の高さ
};
