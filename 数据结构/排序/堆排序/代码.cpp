#include<stdio.h>
#include<stdlib.h>
#define N 9
typedef struct node{
	int data;
	struct node *left,*right;
}BTNode;

BTNode* CreateBTree(int a[]);
void HeapSort(BTNode* root);


int main(void)
{
	int a[N] = {3,2,5,8,4,7,6,9,1};
	BTNode *root;
	//������ȫ������
	root = CreateBTree(a);
	//������ 
	HeapSort(root);	

}
//������ȫ������
BTNode* CreateBTree(int a[])
{
	BTNode* root,*pa,*p;
	BTNode** Q;
	int front,rear;
	front = rear = 0;
	Q = (BTNode**)malloc((N+2)*sizeof(BTNode*));
	//�������ڵ�
	pa = root = (BTNode*)malloc(sizeof(BTNode));
	root->data = a[0];
	root->left = root->right = NULL;
	//���������ڵ�
	for(int i = 1; i<N; i++)
	{
		p = (BTNode*)malloc(sizeof(BTNode));
		p->data = a[i];
		p->left = p->right = NULL;
		Q[++rear] = p;
		if(pa->left == NULL)
			pa->left = p;
		else{
			pa->right = p;
			pa = Q[++front];
		}
	}
	free(Q); 
	return root;
}

//������ 
void HeapSort(BTNode* root)
{
	//���ɶ��� 
	BTNode** Q;
	Q = (BTNode**)malloc((N+1)*sizeof(BTNode*));
	int front,rear;
	front = rear = 0; 
	BTNode* p,*pmin;
	p = pmin = NULL;
	/*
	  t���ڽ���˫�׽�����Ů����Сֵ��
	  s�������һ��Ҷ�ӽڵ�����ڵ�Ľ���
	  tagΪ��־�����������Ƿ�ɶ�
	*/ 
	int t,s,tag;
	//����ȫ��������������� 
	Q[++rear] = root;
	while(1){
		p = Q[++front];
		if(p->left == NULL&&p->right == NULL)
		{
			break;
		}
		else {
			if(p->left){
				Q[++rear] = p->left;
			}
			if(p->right){
				Q[++rear] = p->right;
			}
		}
	}
	//�鿴����Ƿ���ȷ,˫�׽�������Ҷ�ӽڵ��λ�� 
	printf("rear:%d  front:%d\n",rear,front);
	//end������֤�����ҵ����� 
	int end = rear;
	//�����ɶ� 
	while(front >1){
		/*һ��С�����γ�֮�󣬽����������һ��Ҷ�ӽ���data֮��,
		����Ҫ���µ����ɶ� */ 
		tag = 1;
		while(tag){
			//û��ֵ���� ˵���Ѿ��ɶ� 
			tag = 0;
			for(int k = front-1; k>0; k--)
			{
				//����Ԫ��-˫�׽�� 
				p = Q[k];
				//�ҳ���Сֵ��� 
				pmin = p;
				if(p->left->data < pmin->data){
					pmin = p->left;
				}
				if(p->right&&p->right->data < pmin->data){
					pmin = p->right;
				}
				//��pmin����˫�׽��,�򽻻� 
				if(p-pmin){
					t = p->data;
					p->data = pmin->data;
					pmin->data = t;
					tag = 1;
				}	
			}
		}
		//�������ڵ������һ��Ҷ�ӽ�� 
		s = root->data;
		root->data = Q[rear]->data;
		Q[rear]->data = s;
		rear--;
		//�������һ��Ҷ��
		if(Q[front-1]->right){
			Q[front-1]->right = NULL;
		}	
		else{
			Q[front-1]->left = NULL;
			front--;
		} 
		
	}
	while(end)
		printf("%5d",Q[end--]->data);
}



