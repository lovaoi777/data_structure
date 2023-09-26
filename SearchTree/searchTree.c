#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    	int data;
	struct TreeNode* left;
	struct TreeNode* right;
    int key;
} TreeNode;

TreeNode* search(TreeNode  *node,  int  key)
{
      if ( node == NULL )  return NULL;
      if ( key == node->key ) return node;
      else if ( key < node->key )
            return  search(node->left, key);  
      else
            return  search(node->right, key);
} 
TreeNode* new_node(int item)  {
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode * insert_node(TreeNode * node, int key){
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

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
TreeNode * delete_node(TreeNode * root, int key)  { // key 노드 삭제 후 루트 반환
	if (root == NULL) return root;
	if (key < root->key) 			// 키가 루트보다 작으면 왼쪽 서브 트리에 있음
		root->left = delete_node(root->left, key);
	else if (key > root->key) 		// 키가 루트보다 크면 오른쪽 서브 트리에 있음
		root->right = delete_node(root->right, key);
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
		root->right = delete_node(root->right, temp->key); 	// 직후 노드 삭제
	}
	return root;
}
int main(void) {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	root = insert_node(root, 16);
	root = insert_node(root, 25);
	root = insert_node(root, 41);
	root = insert_node(root, 42);
	root = insert_node(root, 46);
	root = insert_node(root, 53);
	root = insert_node(root, 55);
	root = insert_node(root, 60);
	root = insert_node(root, 62);
	root = insert_node(root, 63);
	root = insert_node(root, 64);
    root = insert_node(root, 65);
    root = insert_node(root, 70);
    root = insert_node(root, 64);
    search(root,16);
        return 0;
}