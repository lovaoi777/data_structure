#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define SIZE 17
typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;
void init(HeapType* h)
{
	h->heap_size = 0;
}
// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
int swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert_max_heap(HeapType *h, element item) 
 {
    int i; 
    i = ++(h->heap_size); 

    //  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while((i != 1) && (item.key > h->heap[i/2].key)) {
	   h->heap[i] = h->heap[i/2]; 
       i /= 2; 
     }
    h->heap[i] = item;     // 새로운 노드를 삽입
    

 }
element delete_max_heap(HeapType *h) 
{ 
    int parent, child; 
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;	
    child = 2;
    while( child <= h->heap_size ) {
	  // 현재 노드의 자식노드중 더 큰 자식노드를 찾는다.
	  if( ( child < h->heap_size ) && 
	      (h->heap[child].key) < h->heap[child+1].key)
	      child++;
	  if( temp.key >= h->heap[child].key ) break;
	  // 한단계 아래로 이동
	  h->heap[parent] = h->heap[child];
	  parent = child;
	  child *= 2;
    }
    h->heap[parent] = temp;
    return item;
 }

// 우선 순위 큐인 히프를 이용한 정렬
void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;
    
	h = create();
	init(h);
	for (i = 0; i<n; i++) {
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}

	free(h);
}

int main(void){
    element list[SIZE] = { 34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 34, 85, 29, 78, 41, 56, 86 };
	heap_sort(list, SIZE);
    printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
    return 0;
    };