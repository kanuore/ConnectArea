#include <stdio.h>
#include <stdlib.h>
int visited[13];


/*邻接矩阵的深度优先递归算法*/
void DFS(int (*G)[13], int i) 
{
    /*代表i结点已经被访问了*/
	visited[i] = 1; 

	//printf("%c\n", G.vexs[i]);
    
    for (int j = 0; j < 13; ++j) 
    {
    	if (G[i][j] == 1 && !visited[j])
    	{

    		printf(" %d ",j);
    		/*对未访问的邻接顶点递归调用*/
    		DFS(G, j);

    	}
    }

}
/*对邻接矩阵的深度优先遍历操作*/
void DFSTraverse(int G[13][13])
{
	printf("G\n");
	for(int i=0;i<13;i++){
		for(int j=0;j<13;j++){
			printf(" %d ",G[i][j]);
		}
		printf("\n");
	}
	int numVertexes = 13;
	/*初始化，定义访问标志数组*/
	for (int i = 0; i < numVertexes; ++i)
	{
		visited[i] = 0;
	}

	for (int i = 0; i < numVertexes; ++i)
	{
		/*对未访问的顶点调用DFS,若是连通图，只需要遍历一次*/
		if (!visited[i])
		{
			printf(" %d ",i);
			DFS(G, i);
		}
		printf("\n");
	}
}
