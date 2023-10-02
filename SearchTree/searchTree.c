#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    	int data;
	struct TreeNode* left;
	struct TreeNode* right;
    int key;
} TreeNode;
//순환적 표현
TreeNode* search(TreeNode  *node,  int  key , int* count)
{
      if ( node == NULL )  return NULL;
     (*count)++;
      if ( key == node->key ) return node;
      else if ( key < node->key )
            return  search(node->left, key,count);  
      else
            return  search(node->right, key,count);
} 
TreeNode* new_node(int item)  {
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


TreeNode * insert_node(TreeNode * node, int key , int* count){
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);
    (*count)++;
	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key,count);
	else if (key > node->key)
		node->right = insert_node(node->right, key,count);
	// 변경된 루트 포인터를 반환한다. 
	return node;
}


TreeNode* min_value_node(TreeNode * node)
{
	TreeNode * current = node;
	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode * delete_node(TreeNode * root, int key , int* count)  { // key 노드 삭제 후 루트 반환
	if (root == NULL) return root;
    (*count)++;
	if (key < root->key) 			// 키가 루트보다 작으면 왼쪽 서브 트리에 있음
		root->left = delete_node(root->left, key ,count);
	else if (key > root->key) 		// 키가 루트보다 크면 오른쪽 서브 트리에 있음
		root->right = delete_node(root->right, key,count);
	else {				// 키가 루트와 같으면 이 노드를 삭제함
		if (root->left == NULL) {	// (1) or (2)
			TreeNode * temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {	// (1) or (2)
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}

		TreeNode * temp = min_value_node(root->right); 		// (3)
		root->key = temp->key; 				// 직후 키 복사
		root->right = delete_node(root->right, temp->key,count); 	// 직후 노드 삭제
	}
	return root;
}

//반복적 삽입 
TreeNode* insert_iterative(TreeNode* root, int key, int* count) {
	TreeNode* newnode = new_node(key);
	if (root == NULL) {
		(*count)++;
		return newnode;
	}

	TreeNode* current = root;
	TreeNode* parent = NULL;

	while (current != NULL) {
		parent = current;
		if (key < current->key) {
		(*count)++;
			current = current->left;
		}
		else if (key > current->key) {
		(*count)++;
			current = current->right;
		}
		else {
			// 중복된 값은 여기에서 처리할 수 있습니다.
			free(newnode); // 중복 값은 무시하고 메모리 해제
			return root; // 기존 루트를 반환
		}
	}

	if (key < parent->key) {
		parent->left = newnode;
	}
	else {
		parent->right = newnode;
	}

	return root;
}
//반복적 삭제 
TreeNode* delete_iterative(TreeNode* root, int key, int* count) {
	TreeNode* current = root;
	TreeNode* parent = NULL;
	TreeNode* parent_stack[100]; // 부모 노드를 저장하는 스택 (충분한 크기로 조절)

	// 노드를 찾아가며 스택에 부모 노드 저장
	while (current != NULL && current->key != key) {
		parent = current;
		parent_stack[*count] = parent;
		(*count)++;

		if (key < current->key) {
			current = current->key;
		}
		else {
			current = current->right;
		}
	}

	if (current == NULL) {
		// 삭제할 노드가 존재하지 않음
		return root;
	}

	// 삭제할 노드를 찾았을 경우
	if (current->left == NULL) {
		// 왼쪽 자식이 없는 경우
		if (parent == NULL) {
			// 루트 노드를 삭제하는 경우
			TreeNode* temp = current->right;
			free(current);
			return temp;
		}
		if (parent->left == current) {
			parent->left = current->right;
		}
		else {
			parent->right = current->right;
		}
		free(current);
	}
	else if (current->right == NULL) {
		// 오른쪽 자식이 없는 경우
		if (parent == NULL) {
			// 루트 노드를 삭제하는 경우
			TreeNode* temp = current->left;
			free(current);
			return temp;
		}
		if (parent->left == current) {
			parent->left = current->left;
		}
		else {
			parent->right = current->left;
		}
		free(current);
	}
	else {
		TreeNode * temp = min_value_node(root->right); 		// (3)
		root->key = temp->key; 				// 직후 키 복사
		root->right = delete_iterative(root->right, temp->key,count); 	
	}

	return root;
}


void menu(){
    printf("\n-----------------\n");
    printf("| s :  검색      |\n");
    printf("| i : 노드추가    |\n");
    printf("| d : 노드삭제    |\n");
    printf("| t : 중위순회    |\n");
    printf("| I :노드추가(반복)|\n");
    printf("| D :노드삭제(반복)|\n");
    printf("| c :종료        |\n");
    printf("--------------\n");
}
void Inorder(TreeNode* root){
    if(root){
        Inorder(root->left);
        printf("%d ",root->key);
        Inorder(root->right); 
    }
}
void Inorder2(TreeNode* root,int* count){

    if(root){
        Inorder2(root->left,count);
        (*count)++;
        printf("%d ",root->key);
        Inorder2(root->right,count); 
    }
}

int main(void) {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
    int count= 0;
	root = insert_node(root, 16,&count);
	root = insert_node(root, 25,&count);
	root = insert_node(root, 41,&count);
	root = insert_node(root, 42,&count);
	root = insert_node(root, 46,&count);
	root = insert_node(root, 53,&count);
	root = insert_node(root, 55,&count);
	root = insert_node(root, 60,&count);
	root = insert_node(root, 62,&count);
	root = insert_node(root, 63,&count);
	root = insert_node(root, 64,&count);
    root = insert_node(root, 65,&count);
    root = insert_node(root, 70,&count);
    root = insert_node(root, 74,&count);
    
    char choice;
    int num;
  
    menu();
    while(1){
        count=0;
        printf("\n메뉴입력 :");
        scanf("%c" ,&choice);
        switch (choice)
        {
        case 's': 
            printf("\n 검색할 값 입력 :");
            scanf("%d" ,&num);
            if(search(root, num,&count) != NULL)
                printf("검색 성공 : %d \n", num );
            else 
                printf("검색 실패 : %d \n", num );
            printf("방문한 노드의 수 : %d \n",count);
            Inorder(root);
            break;
        case 'i': 
            printf("\n 추가할 값 입력 :");
            scanf("%d" ,&num);
            insert_node(root,num,&count);
            printf("방문한 노드의 수 : %d \n",count);
            Inorder(root);
            break;
        case 'd': 
            printf("\n 삭제할 값 입력 :");
            scanf("%d" ,&num);
            delete_node(root, num,&count);
            printf("방문한 노드의 수 : %d \n",count);
            Inorder(root);
            break;
        case 't': 
            Inorder2(root,&count);
            printf("\n방문한 노드의 수 : %d \n",count);
            break;
        case 'I': 
            printf("\n 추가할 값 입력 :");
            scanf("%d" ,&num);
            insert_iterative(root,num,&count);
            printf("방문한 노드의 수 : %d \n",count);
            Inorder(root);
            break;
        case 'D': 
            printf("\n 삭제할 값 입력 :");
            scanf("%d" ,&num);
            delete_iterative(root, num,&count);
            printf("방문한 노드의 수 : %d \n",count);
            Inorder(root);
            break;
        case 'c': 
            printf("종료");
            break;
        }

    }
        return 0;
}