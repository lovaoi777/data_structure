#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];
// 그래프 초기화 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r<MAX_VERTICES; r++)
		for (c = 0; c<MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}


// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g){
    for(int i=0;i<g->n;i++){
        for(int j=0;j<g->n;j++){
            printf("%2d",g->adj_mat[i][j]);
        }
        printf("\n");
    }
}
// 인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_mat(GraphType* g, int v,int finish)
{
	int w;
	visited[v] = TRUE;		// 정점 v의 방문 표시 
	printf(" %d  ", v);		// 방문한 정점 출력
	for (w = 0; w<g->n; w++) 		// 인접 정점 탐색
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w,finish);	//정점 w에서 DFS 새로 시작
}



void main()
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);
	for(int i=0;i<11;i++)
	insert_vertex(g, i);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 6);
	insert_edge(g, 0, 9);
	insert_edge(g, 0, 5);
	insert_edge(g, 0, 4);
	insert_edge(g, 2, 3);
    insert_edge(g, 2, 4);
    insert_edge(g, 3, 4);
    insert_edge(g, 3, 5);
    insert_edge(g, 6, 4);
    insert_edge(g, 6, 8);
    insert_edge(g, 9, 8);
    insert_edge(g, 8, 10);
    insert_edge(g, 6, 7);
    insert_edge(g, 1, 7);
    insert_edge(g, 4, 7);
    insert_edge(g, 7, 10);
	// print_adj_mat(g);

    	printf("깊이 우선 탐색\n");
	dfs_mat(g, 1,9);
	printf("\n");



	free(g);
}
