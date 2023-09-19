#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;


// TreeNode n11 = {NULL, 11, NULL};
// TreeNode n10 = {NULL, 10, NULL};
// TreeNode n9 = {NULL, 5, NULL};
// TreeNode n8 = {NULL, 4, NULL};
// TreeNode n7 = { &n10,9,&n11 };
// TreeNode n6 = { NULL,8,NULL };
// TreeNode n5 = { NULL,6,NULL };
// TreeNode n4 = { &n8,3,&n9 };
// TreeNode n3 = { &n6,7,&n7 };
// TreeNode n2 = { &n4,2,&n5 };
// TreeNode n1 = { &n2,1,&n3 };
TreeNode n1 = {4.00, NULL, NULL};
TreeNode n2 = {5.00, NULL, NULL};
TreeNode n3 = {(float)'*', &n1, &n2};
TreeNode n4 = {3.00, NULL, NULL};
TreeNode n5 = {(float)'+',&n4, &n3};
TreeNode n6 = {2.00, NULL, NULL};
TreeNode n7 = {(float)'+', &n6,&n5};
TreeNode n8 = {6.00, NULL, NULL};
TreeNode n9 = {7.00, NULL, NULL};
TreeNode n10 = {(float)'/',&n8, &n9};
TreeNode n11 = {(float)'-', &n7,&n10};
TreeNode n12 = {9.00, NULL, NULL};
TreeNode n13 = {(float)'+', &n11,&n12};
TreeNode* root = &n13;



float evaluate(TreeNode *root)
{
	if (root == NULL)	return 0;
	if (root->left == NULL && root->right == NULL)return root->data;
	else {	float op1 = evaluate(root->left);
		float op2 = evaluate(root->right);
		// printf("%.2d %c %.2d = %.2f \n", op1, root->data, op2 );
		switch (root->data) {
		case '+':	printf("%.2f %c %.2f = %.2f\n", op1, root->data, op2 , op1+op2);
        return op1 + op2;
		case '-':	printf("%.2f %c %.2f = %.2f\n", op1, root->data, op2 , op1-op2);  return op1 - op2;
		case '*':	printf("%.2f %c %.2f = %.2f\n", op1, root->data, op2 , op1*op2);  return op1 * op2;
		case '/':	printf("%.2f %c %.2f = %.2f\n", op1, root->data, op2 , op1/op2); 
        return op1 / op2;
		}
	}
	return 0;
}
int get_node_count(TreeNode *node){
      int count=0;
  if( node != NULL )
    count = 1 + get_node_count(node->left)+ 
	get_node_count(node->right);
  return count;

}


// 
int main(void)
{
	printf("수식의 값은 %.2f입니다. \n", evaluate(root));
    printf("\n총 노드의 수는 %d개입니다. ", get_node_count(root));
	return 0;
}
