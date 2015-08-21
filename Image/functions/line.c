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

void glVertex4ui(unsigned int x1,unsigned int x2,unsigned int y1,unsigned int y2){
 
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
  int dy = abs(y2-y1);
  int dx = abs(x2-x1);

  double pk = 2*dy-2*dx;    

  matrix[ROUND_NUMBER(x1)][ROUND_NUMBER(y1)] = 1;


}
