#include <iostream>
#include "PointCpp.h"

MyPoint::MyPoint() : xpos(0), ypos(0)
{

}

MyPoint::MyPoint(int xpos, int ypos) : xpos(xpos), ypos(ypos)
{
	
}

void MyPoint::ShowPointPos()
{
	std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
}

int MyPoint::PointComp(MyPoint* compPos)
{
	if (this->xpos == compPos->xpos && this->ypos == compPos->ypos)
		return 0;
	else if (this->xpos == compPos->xpos)
		return 1;
	else if (this->ypos == compPos->ypos)
		return 2;
	else
		return -1;
}