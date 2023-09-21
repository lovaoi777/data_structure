#include <stdio.h>
#include <stdlib.h>
typedef enum { FALSE, TRUE } bool;
 
typedef struct TreeNode {
  int data;
  struct TreeNode *left, *right;
  int is_thread;
} TreeNode;
 
TreeNode *find_successor(TreeNode *t)
{
  // pright t의 오른쪽 포인터
  TreeNode *pright = t->right;
 
  // 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
  // 오른쪽 포인터가 NULL이라는 뜻은, 더이상 후속자가 없다는 것이다. 오른쪽 서브트리의 맨 밑단인 것이다.
  if (pright == NULL || t->is_thread == TRUE)
    return pright;
   
  // 만약 pright(t의 오른쪽 포인터)가 NULL이 아니면, 왼쪽 서브트리가 존재한다는 뜻이므로 왼쪽 서브트리로 이동한다.
  // pright가 새로운 V가 되므로 왼쪽 서브트리로 이동하는 것이다. 중위 순회 순서는 L V R이기 때문이다.
  while (pright->left != NULL)
    pright = pright->left;
   
  return pright;
}
 
void thread_inorder(TreeNode *t)
{
  TreeNode *r;
  r = t; // 원본 데이터가 손상되지 않게 복사본을 만들어 준 후 작업을 진행한다.
  while (r->left != NULL) r = r->left; // 가장 왼쪽 노드로 이동한다.
  do
  {
    printf("%c", r->data);
    r = find_successor(r); // 중위후속자를 찾는 함수를 호출한다.
  } while (r != NULL); // 중위후속자가 존재하는 한 계속 무한반복
}
 
//      G
//    C   F
//    A   B   D    E
 
TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode *exp = &n7;
 
void main()
{
  // 스레드 설정
  n1.right = &n3;
  n2.right = &n7;
  n4.right = &n6;
 
  // 중위 순회
  thread_inorder(exp);
}
 
/*************************************************
 ** End Line
*************************************************/