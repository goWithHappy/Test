//��������������⣬���ַ�
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int a[1024];
int s[1024];

int cal(int begin, int end, int pre_min)
{
	int t, min = 4, min_i;
	for (int i = begin; i < end; i++)
	{
		switch (s[i])
		{
		case '^':
			if (min>3)
				min = 3, min_i = i;
			break;
		case '*':
		case  '/':
			if (min > 2)
				min = 2, min_i = i;
			break;
		case '+':
		case '-':
			if (min > 1)
				min = 1, min_i = i;
			break;
		case '(':	//�����������ҵ���֮ƥ��������ţ������������ڵ��ַ�
			i++;
			for (t = 1; t != 0; i++)
			{
				if (s[i] == '(')
					t++;
				if (s[i] == ')')
					t--;
			}
			i--;
			break;
		}
	}

	//ȥ���Ų���
	if (min == 4)
	{
		if (s[begin] == '('&&s[end] == ')')
		{
			//�����ȥ��β���ţ��������ȥ��β���ŵ�
			t = cal(begin + 1, end - 1, 0);
			if (t > pre_min)
			{
				a[begin] = a[end] = 1;
				return t;
			}
		}
		return 4;
	}
	cal(begin, min_i - 1, min);
	if (s[min_i] == '+' || s[min_i] == '*')
	{
		cal(min_i + 1, end, min + 1);
	}
	else
		cal(min + 1, end, min + 1);
	return min;
}

