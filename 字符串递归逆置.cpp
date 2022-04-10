#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//计算字符串长度
int  my_strlen(char str[])
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
//字符串逆置
void reverse_string(char* str)
{
	int len = my_strlen(str);//求长度
	int i = len - 1;//i为下标
	char tmp = *str;//定义一个中间变量替换首元素
	*str = *(str + i);//把最后一个元素放到首元素位置
	*(str + i) = '\0';//把最后一个元素放入\0,
	if (my_strlen(str+1) >= 2)//如果字符串长度大于等于2，则继续递归实现逆置
	{
		reverse_string(str + 1);//截取中间的字符串，进行下一轮递归逆置
	}
	*(str + i) = tmp;//把\0修改回tmp
}

int main()
{
	char str[] = "abcdef";
	reverse_string(str);
	printf("%s\n", str);
	return 0;
}