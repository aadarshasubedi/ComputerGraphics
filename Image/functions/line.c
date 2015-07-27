#include <stdio.h>
#include <stdlib.h>
#define ROUND_NUMBER(number) ((int)(number+0.5))

int getIncrement(dx,dy){
  int increment = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
  return increment;
}

void glVertex4ui(unsigned int x1,unsigned int x2,unsigned int y1,unsigned int y2){
  int dy = y2-y1;
  int dx = x2-x1;
  int increment = getIncrement(dx,dy);
  unsigned int x = x1,y = y1;

  float yIncrement = dy/increment;
  float xIncrement = dx/increment;   
}

