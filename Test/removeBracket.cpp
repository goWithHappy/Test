//解决多余括号问题，二分法
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
		case '(':	//遇到左括号找到与之匹配的右括号，并跳过括号内的字符
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

	//去括号操作
	if (min == 4)
	{
		if (s[begin] == '('&&s[end] == ')')
		{
			//求出除去首尾括号，并求出除去首尾括号的
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

