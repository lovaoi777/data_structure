#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
int comparisons = 0; //비교 횟수 변수 선언
int movements = 0;  //이동 횟수 변수 선언
int quick_compare[MAXSIZE], quick_move[MAXSIZE];
// 랜덤으로 난수 20개 함수
void init_list(int arr[]) {
    for (int i = 0; i < 20; i++) {
        arr[i] = 0;
    }
}



void RandomArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 100; //0부터 99까지의 난수를 생성한 후 리스트에 저장
	}
}
// 배열 출력 함수
void printArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}



void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int pivot(int list[], int start, int finish,int count ){
    int pi = list[(start+finish) / 2]; // 피봇 설정  (가운데)
        while(start<=finish){  //  start 가 finish 보다 오른쪽에 있을때까지 반복
            while(pi>list[start]){  // start가 피봇보다 큰 값을 만날때까지 반복
            comparisons++;
                start++;
            }
            while(pi<list[finish]){  // 위와 동일 하게 finish 가 피봇보다 작을때 까지 반복
            comparisons++;
                finish--;
            }
            if(start <= finish){ //start에 있는 인덱스가  finish 보다 왼쪽에 있다면 위치변경
                swap(&list[start],&list[finish]);
                movements++;
                start++; // start 오른쪽 한칸 , finish 왼쪽으로 한칸간다
                finish--;
            }
     
    }
    
       return start;
}


void Quick_Sort(int list[], int start, int finish,int count ){

    if(start<finish){
    for (int i = 0; i < MAXSIZE; i++) {
            printf("%d ", list[i]);
    }
        printf("\n");
        int p = pivot(list , start, finish,count); //피봇설정
        Quick_Sort(list,start,p-1,count);  //왼쪽 배열 재귀적 반복
        Quick_Sort(list, p , finish,count); //오른쪽 배열 재귀적 반복
    }
    quick_compare[count] = comparisons;
    quick_move[count] = movements;
}
// 비교 횟수와 이동 횟수 평균 구하는 함수
void result(int move[], int compar[]) {
    float avg_move = 0;
    float avg_compare = 0;

    for (int i = 0; i < 20; i++) {
        avg_move += move[i];
        avg_compare += compar[i];
    }

    printf("Averge Move Count : %.5f\n", (avg_move / 20));
    printf("Averge Compare Count : %.5f\n", (avg_compare / 20));
}

void main() { 
    int list[MAXSIZE];
    int count ; 
    RandomArray(list);
    printf("Original List\n");
    printArray(list);
    printf("\n");
    printf("Quick Sort\n"); 
    Quick_Sort(list,0,MAXSIZE-1,count);
    count++;
    for (int i = 0; i < 20; i++) {
        //선택 정렬
        init_list(list);
        RandomArray(list); // 랜덤 리스트 생성
        Quick_Sort(list,0,MAXSIZE-1,count);
        printf("\n");
    }

    result(quick_move,quick_compare);
}