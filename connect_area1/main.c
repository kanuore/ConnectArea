#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int data[10][10] = {
	0,0,0,1,0,0,0,1,0,0,
	0,1,1,1,0,0,1,1,0,0,
	0,0,0,1,0,1,1,1,0,0,
	0,1,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,1,0,1,0,0,0,0,0,0,
	0,1,0,1,0,0,0,1,0,0,
	0,1,1,1,1,1,1,1,0,0,
	0,1,0,0,0,1,0,0,1,0,
	1,0,1,0,0,1,0,0,0,1,
};

int admatrix[256][256];
int flag[10][10];


void print_flag(int (*ptr_data)[10],int h,int w)
{
	printf("the matrix is\n");
	for(int y=0;y<h;y++){
		for(int x=0;x<w;x++){
			printf(" %3d ", ptr_data[y][x]);
		}
		printf("\n");
	}

}

void print_matrix(int (*ptr_data)[256],int h,int w)
{
	printf("the matrix is\n");
	for(int y=1;y<=h;y++){
		for(int x=1;x<=w;x++){
			printf(" %3d ", ptr_data[y][x]);
		}
		printf("\n");
	}

}


//使用zhenzhen
int main()
{
// firstpass
	int w = 10;
	int h = 10;
	int label = 0;
	for(int y =0;y<10;y++){
		for(int x=0;x<10;x++){
			
			if(data[y][x] !=0 ){
				int up = (y - 1 < 0) ? 0 : flag[y - 1][x];
				int left  = (x - 1 < 0) ? 0 : flag[y][x - 1];
				if(left != 0 || up != 0){
					
					if(up != 0 && left != 0){

						flag[y][x] = min(left,up);
						printf("(%d,%d): %d %d %d\n",y,x,left,up,flag[y][x]);
						if(admatrix[up][left] == 0){
							admatrix[up][left] = 1;
							admatrix[left][up] = 1;
						}

					}
					else{
						flag[y][x] = max(left,up);
						//printf("(%d,%d): %d %d %d\n",y,x,left,up,flag[y][x]);
					}
				}
				else{
					flag[y][x] = ++label;
					admatrix[label][label]  = 1;
					//printf(" %d\n",flag[y][x]);
				}
				
			}
		}
	}
	printf("max_label %d\n",label);
	print_flag(flag,10,10);

	print_matrix(admatrix,13,13 );
	
	//深度优先找连通分量
	int tmp[13][13];
	for(int y=1;y<=13;y++){
		for(int x=1;x<=13;x++){
			tmp[y-1][x-1] = admatrix[y][x];
		}
	}
	DFSTraverse(tmp);

}