#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"

#define max2(a,b) (((a) > (b)) ? (a) : (b))
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) (((a) < (b)) ? (a) : (b))
#define min3(a,b,c) min2(min2(a,b),c)


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
	printf("the flag is\n");
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
				
				int up_left = ((y-1<0) || (x-1<0)) ? 0 : flag[y-1][x-1];

				if(left != 0 || up != 0 || up_left != 0){
					
					if(up != 0 && left != 0 && up_left != 0){

						flag[y][x] = min3(left,up,up_left);

						//printf("(%d,%d): %d %d %d\n",y,x,left,up,flag[y][x]);
						if(admatrix[up][left] == 0){
							admatrix[up][left] = 1;
							admatrix[left][up] = 1;
						}
						if(admatrix[up][up_left] == 0){
							admatrix[up][up_left] = 1;
							admatrix[up_left][up] = 1;

						}
						if(admatrix[left][up_left] == 0){
							admatrix[left][up_left] = 1;
							admatrix[up_left][left] = 1;
						}
					}
					else if(up != 0 && up_left != 0){

						flag[y][x] = min2(up,up_left);

						//printf("(%d,%d): %d %d %d\n",y,x,left,up,flag[y][x]);

						if(admatrix[up][up_left] == 0){
							admatrix[up][up_left] = 1;
							admatrix[up_left][up] = 1;
						}
					}

					else if(left != 0 && up_left != 0){

						flag[y][x] = min2(left,up_left);

						//printf("(%d,%d): %d %d %d\n",y,x,left,up,flag[y][x]);

						if(admatrix[left][up_left] == 0){
							admatrix[left][up_left] = 1;
							admatrix[up_left][left] = 1;
						}
					}
					else if(left != 0 && up != 0){

						flag[y][x] = min2(left,up);

						//printf("(%d,%d): %d %d %d\n",y,x,left,up,flag[y][x]);

						if(admatrix[left][up] == 0){
							admatrix[left][up] = 1;
							admatrix[up][left] = 1;
						}
					}
	
					
				
					else{
						flag[y][x] = max3(left,up,up_left);
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
	/*
	print_matrix(admatrix,13,13 );
	
	//深度优先找连通分量
	int tmp[13][13];
	for(int y=1;y<=13;y++){
		for(int x=1;x<=13;x++){
			tmp[y-1][x-1] = admatrix[y][x];
		}
	}
	DFSTraverse(tmp);
	*/
	
}