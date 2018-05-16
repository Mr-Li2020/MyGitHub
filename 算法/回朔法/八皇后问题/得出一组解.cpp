#include<stdio.h>
int col[8] = {0};//��ŵ�j���Ƿ��лʺ�  1������,0����û�� 
int left[15] = {0};//���б���Ƿ��лʺ� ��б��(i+j) 
int right[15] = {0};//���б���Ƿ��лʺ� ��б��(7+i-j) 
int Q[8];      //��ջ��Żʺ��λ��,�±�Ϊ�к�,��ŵ�ֵΪ�к� 

void Queen();

int main(void)
{
	Queen();
	for(int i = 0; i<8; i++)
	{
		for(int j =0; j<8; j++)
		{
			if(Q[i] == j){
				printf("%3d",Q[i]);
			}
			else{
				printf("%3c",'x');
			}	
		}
		printf("\n");
	}
		
}

void Queen()
{
	int top,i,j;
	i = j = 0;
	top = -1;
	//ջ���� 
	while(top!=7){  
		for(; j<8; j++)
		{
			//�ܷ� 
			if(!col[j]&&!left[i+j]&&!right[7+i-j])
			{
				//��j����Q��
				Q[++top] = j;   
				//�ı���  б�ߵ�ֵ ˵����  б���Ѿ��лʺ� 
				col[j] = left[i+j] = right[7+i-j] = 1;
				//����һ��    
				i++;
				j = 0;
				//��һ�з��˻ʺ�֮��,Ҫbreak����ѭ��,�����ڸ��к��滹������� 
				break;   
			}
		}
		//��˷,i�в��ܷ� 
		if(j==8)
		{
			i--;
			//top�ص����ܷŻʺ����һ�е���һ�� 
			j = Q[top--];
			col[j] = left[i+j] = right[7+i-j] = 0;
			j++;
		}
	}
} 


