/*����һ���������У�����һ��������ʹ���ֵ���
  {3��-2��5��-3��4��7��-6}
  ʱ�临�Ӷ�O(n^3) 
*/
#include<stdio.h>
int max,mi,mj;
void MaxSum(int a[],int n);
int main(void)
{
	int a[7] = {3,-2,5,-3,4,7,-6};
	max = a[0];
	mi = mj = 0;
	MaxSum(a,7);
}

void MaxSum(int a[],int n)
{
	int i,j,k;
	for(i = 0; i<n; i++)
	{
		for(j = i; j<n; j++)
		{
			int sum = 0;
			for(k = i; k<=j; k++)
			{
				sum+=a[k];
			}
			if(sum>max)
			{
				max = sum;
				mi = i;
				mj = j;
			}
		}
	}
	printf("��ֵ���ķ�ΧΪ��%d��Ԫ�ص���%d��Ԫ��\n",mi+1,mj+1);
}
