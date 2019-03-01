/********************************************************************
*文 件 名:			mystring.cpp
*功能描述:			这是一个C++程序文件
*作    者:			北邮在线
*创建时间:			2018-11-28
*Copyright (C):		2018 All rights reserved
********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
class String
{
	public:
		String()
		{
			deepth = 0;
			pstr = NULL;
		}
		~String()
		{
			if(pstr != NULL)
			{
				free(pstr);
			}
		}
		int copy(const char *str);
		void show();
		int get_len();

		void operator=(const char *str);
		bool operator==(const char *str);
		/*
		bool operator>(const char *str);
		bool operator<(const char *str);
		bool operator!=(const char *str);
		bool operator+=(const char *str);
		bool operator[](int index);
		int find(char ch);
		int find(char *str);
		*/
	private:
		int deepth;//数组的元素个数
		char *pstr;
};
int String::get_len()
{
	return deepth != 0?deepth - 1:0;
}
int String::copy(const char *str)
{
	if(deepth != 0)
	{
		free(pstr);
	}
	int len = strlen(str);
	pstr = (char *)malloc(sizeof(char) * (len + 1));
	memcpy(pstr,str,len+1);
	deepth = len + 1;
	return len;
}
void String::operator=(const char *str)
{
	if(deepth != 0)
	{
		free(pstr);
	}
	int len = strlen(str);
	pstr = (char *)malloc(sizeof(char) * (len + 1));
	memcpy(pstr,str,len+1);
	deepth = len + 1;
}
bool String::operator==(const char *str)
{
	return strcmp(pstr,str) != 0?false:true;
}
void String::show()
{
	printf("%s\n",pstr);
}
int main()
{
	String account;

	account = "admin";	

	printf("len = %d\n",account.get_len());
	char acc[30];
	printf("请输入账户名:");
	scanf("%s",acc);
	if(account == acc)
	{
		printf("账户名正确\n");
	}
	else
	{
		printf("账户名错误\n");
	}
	//account.show();	
    return 0;
}
