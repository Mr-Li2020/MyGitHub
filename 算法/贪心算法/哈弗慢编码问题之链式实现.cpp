#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct node{
	char word;
	int weight;
	struct node *left,*right;
}HuffNode;

HuffNode ** CreateHuffForst(); 
HuffNode* CreateHuffNode(HuffNode **F);
void Print(HuffNode* root);

int main(void)
{
	HuffNode **F;
	HuffNode *p;
	F = CreateHuffForst();
	p = CreateHuffNode(F);
	Print(p);
}
//��������ʼ��ɭ�� 
HuffNode ** CreateHuffForst()
{
	HuffNode **F;
	char ch;
	int w;
	F = (HuffNode**)malloc(N*sizeof(HuffNode*));
	for(int i = 0; i<N ;i++)
	{
		F[i] = (HuffNode*)malloc(sizeof(HuffNode));
		F[i]->left = F[i]->right = NULL;
		printf("������һ����ĸ:");
		scanf("%c",&ch);
		F[i]->word = ch;
		printf("������һ������:");
		scanf("%d",&w);
		F[i]->weight = w;
		fflush(stdin);
	} 
	return F;
} 

//������ʵ��HuffmanTree 
HuffNode* CreateHuffNode(HuffNode **F)
{
	int loop,i,k1,k2;
	HuffNode *p;
	//n-1��ѭ��
	for(loop = 1; loop<N; loop++)
	{
		//����С �Ҵ�С  k1ָ��С  k2ָ��С
		//��k1ָ���һ�����յ�����Ԫ����
		for(k1 = 0; k1<N&&!F[k1]; k1++);
		//��k2ָ��ڶ������յ�����Ԫ����
		for(k2 = k1+1; k2<N&&!F[k2]; k2++);
		for(i = k2; i<N; i++)
		{
			if(F[i]){
				if(F[i]->weight<F[k1]->weight){
					k2 = k1;
					k1 = i;
				}
				else if(F[i]->weight<F[k2]->weight){
					k2 = i;	
				}
			}
		}
		//�����µĶ����� 
		p = (HuffNode*)malloc(sizeof(HuffNode));
		p->weight = F[k1]->weight+F[k2]->weight;
		p->word = 'x';
		p->left = F[k1];
		p->right = F[k2];
		F[k1] = p;
		F[k2] = NULL; 
	}
	return p; 
}

void Print(HuffNode* root)
{
	if(root){
		printf("%5d",root->weight);
		Print(root->left);
		Print(root->right);
	}
}


