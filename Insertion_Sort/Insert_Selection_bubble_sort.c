#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )  //인자값 자리 변경
#define MAX_SIZE 20
void selection_sort(int list[], int n, int* count, int* CompareCount) {
    int i, j, least, temp;
    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++) {    // Finding the minimum value
            if (list[j] < list[least]) {
                least = j, (*count)++;
            }
            (*CompareCount)++;
        }
        SWAP(list[i], list[least], temp);
        
        // Print the current state of the array after each iteration
        for (int k = 0; k < n; k++) {
            printf("%d ", list[k]);
        }
        printf("\n");
    }
}

// 삽입정렬
void insertion_sort(int list[], int n ,int* count, int* CompareCount) 
{   
   int i, j, key;
   for(i=1; i<n; i++){
   	key = list[i];
	for(j=i-1; j>=0 && list[j]>key; j--) 
		list[j+1] = list[j]; 		// 레코드의 오른쪽 이동
    	list[j+1] = key;
   }
}






void main() {
	int i;
    int count= 0;
    int CompareCount= 0;
    int list[MAX_SIZE];
	srand(time(NULL));
    printf("Original List \n");
	for (i = 0; i<MAX_SIZE; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99

    //Original Code 
	for (i = 0; i<MAX_SIZE; i++)
		printf("%d ", list[i]);

    printf("\n\n Selection Sort \n");
	selection_sort(list,MAX_SIZE, &count, &CompareCount); // 선택정렬 호출 
	printf("\n");
    printf("Move Count : %d" , count);
    printf("\nCompare Count : %d" , CompareCount);




    printf("\n");
    for (i = 0; i<MAX_SIZE; i++)
		printf("%d ", list[i]);
}
