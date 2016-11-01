//寻找第k小的数
#pragma warning(disable:4996)

#include <cstdio>
#include <iostream>


#define maxn 100000
using namespace std;

int n,ans_value=-100,k;
int value[maxn];

//交换数据以及下标值
void swap(int *i, int *j)
{
	int temp = value[*i];
	value[*i] = value[*j];
	value[*j] = temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void search(int start, int end)
{
	int i, j;
	i = start;
	j = end;

	while (i != j)
	{
		if (i < j)
		{
			if (value[i]>value[j]) 
				swap(&i, &j);
			else 
				j--;
		}
		if (i > j)
		{
			if (value[i] < value[j]) swap(&i, &j);
			else j++;
		}
	}

	if (i > k) search(start, i - 1);
	else if (i == k)
	{
		ans_value = value[i];
		return;
	}
	else search(i + 1, end);
}

//int main()
//{
//	freopen("K1In.txt", "r", stdin);
//	freopen("Out.txt", "w", stdout);
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &value[i]);
//	}
//	scanf("%d", &k);
//	//便于后边k与i的比较
//	k -= 1;
//	search(0, n-1);
//	if (ans_value != -100)
//	{
//		printf("%d\n", ans_value);
//	}
//	else
//	{
//		printf("not found !\n");
//	}
//	/*system("pause");*/
//}
