#pragma once
#include "ofMain.h"

class Tree {
	float xLoc, yLoc, direction, length;
	int depth;
	ofPolyline* line;

	Tree* childA,* childB;

	const static int MAX_DEPTH;

public:

	Tree(float x, float y, float theta, float len, int dep);
	~Tree();

	void draw();

};
