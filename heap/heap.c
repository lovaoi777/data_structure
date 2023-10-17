#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
void menu ( ){ 
    printf("\n-------------------\n");
    printf("|  i :   노드추가   |\n");
    printf("|  d :   노드삭재   |\n");
    printf("|  p :   레벨별출력 |\n");
    printf("|  c :   종료     |\n");
    printf("\n-------------------\n");
}
typedef struct heap {
    int arr[MAX_ELEMENT];
    int size;
} heap;
 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void initHeap(heap *hp) {
    hp->size = 0;
}
void insert(heap* hp,int data,int* count) {
    int here = ++hp->size;
     
    while ((here!=1)&&(data<hp->arr[here/2])) {
        hp->arr[here] = hp->arr[here / 2];
        here /= 2;
        (*count)++;
    }
    hp->arr[here] = data;
}
 
int deleteData(heap *hp,int* count) {
    if (hp->size == 0) return -1;
    int ret = hp->arr[1];
    hp->arr[1]=hp->arr[hp->size--];
    int parent = 1;
    int child;
 
    while (1) {
        child = parent * 2;
        if (child + 1 <= hp->size && hp->arr[child]>hp->arr[child + 1])
            child++;
            (*count)++;
        if (child>hp->size||hp->arr[child] > hp->arr[parent]) break;
         
        swap(&hp->arr[parent], &hp->arr[child]);
        parent = child;
    }
     
    return ret;
     
}
int main(){
    char choice;

    heap hp;
    initHeap(&hp);	// 히프 생성
    insert(&hp, 90,0);
    insert(&hp, 89,0);
    insert(&hp, 70,0);
    insert(&hp, 36,0);
    insert(&hp, 75,0);
    insert(&hp, 63,0);
    insert(&hp, 65,0);
    insert(&hp, 21,0);
    insert(&hp, 18,0);
    insert(&hp, 15,0);

        int count = 0;
     menu();
    while(1){
        int num;
        count = 0;
        printf("\n메뉴입력 :");
        scanf("%c" ,&choice);
        switch (choice)
        {
        case 'i': 
            printf("\n 추가할 값 입력 :");
            scanf("%d" ,&num);
            insert(&hp, num,count);
            printf("방문한 노드의 수 : %d \n",count);
            break;
        case 'd': 
            printf("\n 삭제할 값 입력 :");
            scanf("%d" ,&num);
            break;
        case 'p': 
            printf("\n 검색할 값 입력 :");
            scanf("%d" ,&num);
            break;
        case 'c': 
            printf("종료");
            break;
        }
    }
    return 0;
}