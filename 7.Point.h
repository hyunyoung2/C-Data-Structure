#ifndef __POINT_H__ 
#define __POINT_H__

typedef struct _point
{
	int xpos;
	int ypos;

}Point;


// Point  ���� x��ǥ, y��ǥ�� set
void SetPointPos(Point * ppos, int xpos, int ypos);


void ShowPointpos(const Point *ppos);


int PointComp(Point * pos, Point * pos2);

#endif