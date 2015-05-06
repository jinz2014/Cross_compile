  #define GRIDX 16
  #define GRIDY 16
  #define ITERATIONS 100

  #define GRID_TOP     5000
  #define GRID_LEFT    3000
  #define GRID_RIGHT   6000
  #define GRID_BOTTOM 10000

  short int GRID[GRIDX][GRIDY];

  void fill_grid() {
     int x,y;

     for(x=0;x<GRIDX;x++) for (y=0;y<GRIDY;y++) {
        if (y==0) GRID[x][y]=GRID_TOP;
        else if (x==0) GRID[x][y]=GRID_LEFT;
        else if (x==(GRIDX-1)) GRID[x][y]=GRID_RIGHT;
        else if (y==(GRIDY-1)) GRID[x][y]=GRID_BOTTOM;
        else GRID[x][y]=0;
     }
  }
  
  int main() {

     int i,x,y;

     fill_grid();
     for(i=0;i<ITERATIONS;i++) {
        for(x=1;x<GRIDX-1;x++)
  	     for(y=1;y<GRIDY-1;y++)
	        GRID[x][y]= (GRID[x-1][y]+GRID[x+1][y]+GRID[x][y-1]+GRID[x][y+1])/4;
     }

     return 0;
  }

