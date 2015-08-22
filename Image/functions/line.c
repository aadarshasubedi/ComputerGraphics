#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#define ROUND_NUMBER(number) ((int)(number+0.5))

int **matrix;

void glBegin(){
  matrix = createImageMatrix(H,W);
}

int getIncrement(dx,dy){
  int increment = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
  return increment;
}

void ddaLine(unsigned int x1,unsigned int x2,unsigned int y1,unsigned int y2){
  int dy = y2-y1;
  int dx = x2-x1;
  int increment = getIncrement(dx,dy);
  float x = x1,y = y1;
  int i = 0,j=0;

  float yIncrement = dy/(float)increment;
  float xIncrement = dx/(float)increment;

  matrix[ROUND_NUMBER(y)][ROUND_NUMBER(x)] = 1;

  for(i=0;i<increment;i++){
    x+= xIncrement;
    y+= yIncrement;
    matrix[ROUND_NUMBER(y)][ROUND_NUMBER(x)] = 1;
  }

  createImage(W,H,matrix);
}

void bresenhamLine(unsigned int x1,unsigned int x2,unsigned y1,unsigned y2){
  int dy = y2-y1;
  int dx = x2-x1;

  int x = x1,y=y1,width=x2;

  int pk = 2*dy-dx;

  if(x1>x2){
    x = x2;
    y = y2;
    width = x1;
  }

  matrix[ROUND_NUMBER(x)][ROUND_NUMBER(y)] = 1;

  while(x<width){
    x++;
    if(pk<1){
      pk += 2*dy;
    }
    else{
      y++;
      pk += 2*(dy-dx);
    }
    matrix[ROUND_NUMBER(x)][ROUND_NUMBER(y)] = 1;
  }
}
