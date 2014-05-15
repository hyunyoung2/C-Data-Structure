#ifndef __POINT_H__ 
#define __POINT_H__

typedef struct _point
{
	int xpos;
	int ypos;

}Point;


// Point  º¯¼ö xÁÂÇ¥, yÁÂÇ¥¸¦ set
void SetPointPos(Point * ppos, int xpos, int ypos);


void ShowPointpos(const Point *ppos);


int PointComp(Point * pos, Point * pos2);

#endif