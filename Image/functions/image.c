#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createImage(int x,int y){
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
      color[0] = rand() % 256;
      color[1] = rand() % 256;
      color[2] = rand() % 256;
      fwrite(color,1,3,f);
    }
  }
  
  fclose(f);
}
