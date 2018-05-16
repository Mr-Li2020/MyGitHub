#include<stdio.h>
#include<stdlib.h>
#define V 35
#define N 5
//��Ʒ��Ϣ
typedef struct{
	int gnum;//��Ʒ��� 
	int gv;//��Ʒ��� 
}ElemG; 

//��Ʒ��� 
typedef struct node{
	int gnum;
	struct node *next;
}GoodsLink; 

//���ӽ��
typedef struct box{
	int remainder;  //�������ʣ�����
	GoodsLink *hg;
	struct box *next; 
}BoxLink;
ElemG *CreateG();
ElemG *BuddleSont(ElemG *g);
BoxLink * Enchase(ElemG *g);
void Print(BoxLink *hbox);


int main(void)
{
	ElemG *g;
	BoxLink *hbox;
	g = CreateG();
	g = BuddleSont(g);
	hbox = Enchase(g);
	Print(hbox);	
}
//������Ʒ��Ϣ����,Ȼ���ʼ�� 
ElemG *CreateG()
{
	ElemG *g;
	int vol = 0; 
	g = (ElemG*)malloc(N*sizeof(ElemG));
	for(int i = 0; i<N; i++)
	{
		g[i].gnum = i+1;
		printf("���������:");
		scanf("%d",&vol);
		g[i].gv = vol;
	}
	return g;
}
//�����е���Ʒ������������� 
ElemG* BuddleSont(ElemG *g)
{
	int i,j;
	ElemG t;
	int tag = 1;  //��־���� 
	for(i = 0; tag&&i<N-1; i++)
	{
		
		tag = 0;
		for(j = N-1; j>i; j--)
		{
			if(g[j-1].gv<g[j].gv)
			{
				t = g[j-1];
				g[j-1] = g[j];
				g[j] = t;
				tag = 1;
			}
		}
	}
	return g;
}

//װ���� 
BoxLink* Enchase(ElemG *g)
{
	BoxLink *p,*hbox = NULL,*tail; 
	GoodsLink *newGoods,*q; 
 
	for(int i = 0; i<N; i++)
	{
		//���������� 
		for(p = hbox; p&&p->remainder<g[i].gv; p = p->next);
		if(!p){
			//�������� 
			p = (BoxLink*)malloc(sizeof(BoxLink));
			//��ʼ������
			p->remainder = V;
			p->next = NULL;
			p->hg = NULL;
			//������	
			if(!hbox){
				hbox = tail = p;
			} 
			else{
				tail = tail->next = p;
			}
		}
		p->remainder -=g[i].gv;
		//����Ʒ
		newGoods = (GoodsLink*)malloc(sizeof(GoodsLink));
		newGoods->gnum = g[i].gnum;
		newGoods->next = NULL;
		if(!p->hg){  //������ 
			p->hg = newGoods;
		}
		else{  //������    
			for(q=p->hg;q->next;q = q->next);
				q->next = newGoods;
		}
	}
	return hbox;
}

void Print(BoxLink *hbox)
{
	BoxLink *p;
	GoodsLink *q;
	int cut = 0;
	for(p = hbox; p; p = p->next)
	{
		printf("��%d������",++cut);
		for(q = p->hg; q; q = q->next)
			printf("��ű��Ϊ%d����Ʒ,",q->gnum);
		printf("\n");
	}
}

