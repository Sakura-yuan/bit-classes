#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�����ַ�������
int  my_strlen(char str[])
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
//�ַ�������
void reverse_string(char* str)
{
	int len = my_strlen(str);//�󳤶�
	int i = len - 1;//iΪ�±�
	char tmp = *str;//����һ���м�����滻��Ԫ��
	*str = *(str + i);//�����һ��Ԫ�طŵ���Ԫ��λ��
	*(str + i) = '\0';//�����һ��Ԫ�ط���\0,
	if (my_strlen(str+1) >= 2)//����ַ������ȴ��ڵ���2��������ݹ�ʵ������
	{
		reverse_string(str + 1);//��ȡ�м���ַ�����������һ�ֵݹ�����
	}
	*(str + i) = tmp;//��\0�޸Ļ�tmp
}

int main()
{
	char str[] = "abcdef";
	reverse_string(str);
	printf("%s\n", str);
	return 0;
}