#include<stdio.h>

#define N 8
void SelectedSont(int a[]);

int main(void)
{
	int a[N] = {3,2,5,8,4,7,6,9};
	SelectedSont(a);
}

void SelectedSont(int a[])
{
	int t,kmin;  //t�������� 
	
	for(int i = 0; i<N-1; i++) 
	{
		kmin = i;   
		
		//��������  Ѱ����������Сֵ���±� 
		for(int j = i+1; j<N; j++)
		{
			if(a[j]<a[kmin])
				kmin = j;
			
		}
		//�ж���Сֵ�ǲ��ǵ�i��  �����ʲôҲ����  �������  �ͽ��� 
		if(i - kmin)
			{
				t = a[i];
				a[i] = a[kmin];
				a[kmin] = t;
			}
	}
	
	for(int i = 0; i<N; i++)
		printf("%5d",a[i]);
}
