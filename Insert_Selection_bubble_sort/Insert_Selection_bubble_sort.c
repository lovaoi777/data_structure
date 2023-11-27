#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
//각 정렬의 비교와 이동 횟수를 넣은 리스트와 몇번 돌리는 지 확인하는 변수 선언
int count = 0;
// 선택 정렬
int selection_compare[MAX], selection_move[MAX];
// 삽입 정렬
int insert_compare[MAX], insert_move[MAX];
//버블 정렬
int bubble_compare[MAX], bubble_move[MAX];

//리스트 초기화 함수
void init_list(int arr[]) {
    for (int i = 0; i < 20; i++) {
        arr[i] = 0;
    }
}

// 랜덤으로 난수 20개 함수
void RandomArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 100; //0부터 99까지의 난수를 생성한 후 리스트에 저장
	}
}


// 비교 횟수와 이동 횟수 평균 구하는 함수
void result(int move[], int compar[]) {
    int avg_move = 0;
    int avg_compare = 0;

    for (int i = 0; i < 20; i++) {
        avg_move += move[i];
        avg_compare += compar[i];
    }

    printf("평균 이동 횟수 : %d\n", (avg_move / 20));
    printf("평균 비교 횟수 : %d\n", (avg_compare / 20));
}

// 선택 정렬 함수
void selectionSort(int arr[], int count) {
    int comparisons = 0; //비교 횟수 변수
    int movements = 0; //이동 횟수 변수

    if(count == 0)
        printf("Selection Sort\n");

    for (int i = 0; i < 19; i++) {
        int min_idx = i;
        //최솟값 비교
        for (int j = i + 1; j < 20; j++) {
            comparisons++; //비교 횟수 증가
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 값 교환
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        movements++; //이동 횟수 증가

        if (count == 0) {
            for (int i = 0; i < 20; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

    selection_compare[count] = comparisons;
    selection_move[count] = movements;

    if (count == 0) {
        printf("\n");
        printf("Move Count : %d\n", movements);
        printf("Compare Count : %d\n", comparisons);
    }
}

// 삽입 정렬 함수
void insertionSort(int arr[], int count) {
    int comparisons = 0; //비교 횟수 변수 선언
    int movements = 0;  //이동 횟수 변수 선언

    if(count == 0)
        printf("Insertion Sort\n");

    for (int i = 1; i < 20; i++) {
        int key = arr[i];
        int j = i - 1;
        // 첫번째 값과 현재 인덱스의 값을 비교
        while (j >= 0 && arr[j] > key) {
            comparisons++; //비교 횟수 증가
            arr[j + 1] = arr[j]; //값 교환
            j = j - 1;
            movements++; //이동 횟수 증가
        }
        //값 교환
        arr[j + 1] = key;
        movements++;
        //배열 값 출력
        if (count == 0) {
            for (int i = 0; i < 20; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

    insert_move[count] = movements;
    insert_compare[count] = comparisons;

    if (count == 0) {
        printf("\n");
        printf("Move Count : %d\n", movements);     //이동 횟수 출력
        printf("Compare Count : %d\n", comparisons);//비교 횟수 출력
    }
}

//버블 정렬 함수
void bubblesort(int arr[], int count) {
    int comparisons = 0; //비교 횟수 변수 선언
    int movements = 0;  //이동 횟수 변수 선언

    if (count == 0)
        printf("Bubble Sort\n");

    for (int i = 0; i < 20 - 1; i++) {
        for (int j = 0; j < 20 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                comparisons++; //비교 횟수 증가
                // 현재 요소와 다음 요소를 비교하여 순서가 올바르지 않으면 위치를 교환
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                movements++; //이동 횟수 증가
            }
        }
        //배열 값 출력
        if (count == 0) {
            for (int i = 0; i < 20; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

    bubble_move[count] = movements;
    bubble_compare[count] = comparisons;

    if (count == 0) {
        printf("\n");
        printf("Move Count : %d\n", movements);     //이동 횟수 출력
        printf("Compare Count : %d\n", comparisons);//비교 횟수 출력
    }
}
// 배열 출력 함수
void printArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main() {

    int Selection_list[MAX]; //선택 정렬 배열
    int Insert_list[MAX]; //삽입 정렬 배열
    int Bubble_list[MAX]; //버블 정렬 
    int count = 0;
    
    //선택 정렬 첫번째 배열 정렬 출력
    RandomArray(Selection_list);
    printf("Original List\n");
    printArray(Selection_list);
    selectionSort(Selection_list,count);

    printf("\n");

    //삽입 정렬 첫번째 배열 정렬 출력
    RandomArray(Insert_list);
    printf("Original List\n");
    printArray(Insert_list);
    insertionSort(Insert_list, count);

    printf("\n");

    //버블 정렬 첫번째 배열 정렬 출력
    RandomArray(Bubble_list);
    printf("Original List\n");
    printArray(Bubble_list);
    bubblesort(Bubble_list, count);

    count++;

    for (int i = 1; i < 20; i++) {
        //선택 정렬
        init_list(Selection_list);
        RandomArray(Selection_list); // 랜덤 리스트 생성
        selectionSort(Selection_list, count); // 선택 정렬 실행
        
        //삽입 정렬
        init_list(Insert_list);
        RandomArray(Insert_list); // 랜덤 리스트 생성
        insertionSort(Insert_list, count); // 삽입 정렬 실행

        //버블 정렬
        init_list(Bubble_list);
        RandomArray(Bubble_list); // 랜덤 리스트 생성
        bubblesort(Bubble_list, count); // 삽입 정렬 실행

        count++;
    }

    printf("\n정렬들의 평균 횟수 출력\n");
    printf("\n<선택 정렬의 평균 횟수 출력>\n");
    result(selection_move, selection_compare);

    printf("\n<삽입 정렬의 평균 횟수 출력>\n");
    result(insert_move, insert_compare);
   
    printf("\n<버블 정렬의 평균 횟수 출력>\n");
    result(bubble_move, bubble_compare);

	return 0;
}