#include "BiTree.h"
void main (void){
	BiTreeNode *root, *p;
	//��ʼ��������һ��������
	Initiate(&root,'A');
	p = InsertLeftNode(root,'B');
	p = InsertLeftNode(p,'D');
	p = InsertRightNode(p,'G');
	p = InsertRightNode(root,'C');
	InsertLeftNode(p,'E');
	InsertRightNode(p,'F');
	//           A
	//		    / \
	//         B   C
	//        /   / \
	//       D   E   F
	//        \
	//         G
	//ǰ�к��������ӡ������
	printf("ǰ�������");
	PreOrder(root,print);
	printf("\n���������");
	InOrder(root,print);
	printf("\n���������");
	PostOrder(root,print);
	printf("\n");
	//���Ϊǰ��ABDGCEF �У�DGBAECF ��:GDBEFCA 

	//�������
	printf("���������");
	SeqOrder(root,print);
	printf("\n");
	//���Ϊ��ABCDEFG
	printf("�������Ϊ��%d\n",GetBiTreeDepth(root));

	//ɾ��'G'
	DeleteRightTree(&root->leftChild->leftChild);
	//           A
	//		    / \
	//         B   C
	//        /   / \
	//       D   E   F
	//�ٴ�ǰ�к��������ӡ������
	printf("ɾ��'G'��\nǰ�������");
	PreOrder(root,print);
	printf("\n���������");
	InOrder(root,print);
	printf("\n���������");
	PostOrder(root,print);
	printf("\n");
	//���Ϊǰ��ABDCEF �У�DBAECF ��DBEFCA

	//�������
	printf("���������");
	SeqOrder(root,print);
	printf("\n");
	//���Ϊ��ABCDEF

	printf("ɾ��'G'���������Ϊ��%d\n",GetBiTreeDepth(root));

	PrinfLeafNodeAndNonLeafNode(root);

	Destroy(&root);//�ͷ��ڴ�
}