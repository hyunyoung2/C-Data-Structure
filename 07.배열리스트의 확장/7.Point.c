#include <stdio.h>
#include "7.Point.h"


void SetPointPos(Point * ppos, int xpos, int ypos)
{
	ppos -> xpos = xpos;
	ppos -> ypos = ypos;
}

void ShowPointpos(const Point *ppos)
{
	printf("xÁÂÇ¥ : %d , yÁÂÇ¥ : %d\n", ppos -> xpos, ppos -> ypos);
}


int PointComp(Point * pos1, Point * pos2)
{
	if(pos1->xpos == pos2 ->xpos && pos1->ypos == pos2 -> ypos)
		return 0;
	else if(pos1 -> xpos == pos2 -> xpos)
		return 1;
	else if(pos1 -> ypos == pos2 -> ypos)
		return 2;
	else 
		return -1;
}
