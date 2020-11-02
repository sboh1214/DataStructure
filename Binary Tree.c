#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode{
	char data;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode)
{
	
}
void preorder(treeNode* root)
{
	
}
void inorder(treeNode* root)
{
	
}
void postorder(treeNode* root)
{
	
}
int main()
{
	treeNode* n9 = makeRootNode('I', NULL, NULL);
	treeNode* n8 = makeRootNode('F', NULL, NULL);
	treeNode* n7 = makeRootNode('E', NULL, NULL);
	treeNode* n6 = makeRootNode('H', n9, NULL);
	treeNode* n5 = makeRootNode('D', n7, n8);
	treeNode* n4 = makeRootNode('C', NULL, NULL);
	treeNode* n3 = makeRootNode('G', NULL, n6);
	treeNode* n2 = makeRootNode('B', n4, n5);
	treeNode* n1 = makeRootNode('A', n2, n3);
	
	printf("\n preorder : ");
	preorder(n1);
	printf("\n inorder : ");
	inorder(n1);
	printf("\n postorder : ");
	postorder(n1);
}
