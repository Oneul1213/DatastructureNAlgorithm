#ifndef __POINT_CPP_H__
#define __POINT_CPP_H__

class MyPoint
{
public:
	MyPoint();
	MyPoint(int xpos, int ypos);
	void ShowPointPos();
	int PointComp(MyPoint* compPos);
private:
	int xpos;
	int ypos;
};

#endif