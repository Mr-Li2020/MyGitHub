/*����һ���������У�����һ��������ʹ���ֵ���
  {3��-2��5��-3��4��7��-6}
  ʱ�临�Ӷ�O(n^2+n) 
*/
#include<stdio.h>
int max,mi,mj;
void MaxSum(int a[],int s[],int n); 
int main(void)
{
	int a[7] = {3,-2,5,-3,4,7,-6};
	int s[8]={0};
	max = a[0];
	mi = mj = 0;
	MaxSum(a,s,7);
}

void MaxSum(int a[],int s[],int n)
{
	for(int i = 1; i<n+1; i++)
	{
		s[i] = s[i-1]+a[i-1];
	}
	for(int i = 1; i<n+1; i++)
	{
		for(int j = i; j<n+1; j++)
		{
			if(s[j]-s[i-1]>max)
			{
				max = s[j]-s[i-1];
				mi = i-1;
				mj = j-1;
			}
		}
	}
	printf("��ֵ���ķ�ΧΪ��%d��Ԫ�ص���%d��Ԫ��\n",mi+1,mj+1);
}
