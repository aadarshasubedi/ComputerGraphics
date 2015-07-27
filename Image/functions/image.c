#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** createImageMatrix(int height,int width){
  int i,j;
  int** matrix = (int**)malloc(height*sizeof(int*));

  for(i=0;i<height;i++)
    matrix[i] = (int*)malloc(width*sizeof(int));
  
  for(i=0;i<height;i++)
    for(j=0;j<width;j++) 
      matrix[i][j] = 0;

  return matrix; 
}

void createImage(int x,int y,int** imageMatrix){
  int i,j;
  static unsigned char color[3];  
  
  FILE *f =NULL;
  f=fopen("image.ppm","w");
  
  if(f==NULL){
    printf("The file can´t be created\n");
    return;
  }

  fprintf(f,"P6\n%d %d\n255\n",x,y);
  
  srand(time(NULL));

  for(i=0;i<y;i++){
    for(j=0;j<x;j++){
      if(imageMatrix[i][j] == 1){
        color[0] = 255;
        color[1] = 255; 
        color[2] = 255; 
      }
      else{
        color[0] = 0; 
        color[1] = 0;
        color[2] = 0;
      }
      
      fwrite(color,1,3,f);
    }
  }
  
  fclose(f);
}
