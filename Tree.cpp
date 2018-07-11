#include "Tree.h"

const int Tree::MAX_DEPTH = 8;

Tree::Tree(float x, float y, float theta, float len, int dep) {
	xLoc = x;
	yLoc = y;
	direction = theta;
	length = len;
	depth = dep;

	float endX = len * cos(theta) + x;
	float endY = len * sin(theta) + y;

	line = new ofPolyline();
	line->addVertex(ofVec3f(xLoc, yLoc,0));
	line->addVertex(ofVec3f(endX, endY, 0));

	if (depth < MAX_DEPTH) {
		childA = new Tree(endX, endY, theta - PI / 4, length / 2, depth + 1);
		childB = new Tree(endX, endY, theta + PI / 4, length / 2, depth + 1);
	}
	else {
		childA = nullptr;
		childB = nullptr;
	}
}

void Tree::draw() {

	line->draw();

	if (childA != nullptr) childA->draw();
	if (childB != nullptr) childB->draw();
}
