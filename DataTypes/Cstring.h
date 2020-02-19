#pragma once
#include<string>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>
using namespace std;
//#pragma comment(lib,"User32")
/*
��ͷ�ļ���Ҫ��ϸ��Щchuan�Ĵ洢�ṹ���ַ�ƥ�䷽����
*/

template<class T>
class fun
{
public:
	T data;
	void funcA(){::MessageBox(NULL, "���!", ("����"),MB_OK);} ;
	fun(T t):data(t){};
};

class Cstring:public string
{
public:

	Cstring(void)
	{
	}
	/*��ͳģʽ*/
	int Index(string S,string T,int pos);

	~Cstring(void)
	{
	}
	/*KMpģʽ*/
	void get_next(string T,int *next);
	void get_nextval(string T,int *next);
	int Index_KMP(string S,string T,int pos);


};
int Cstring::Index(string S,string T,int pos = 1)
{
	int i = pos;/*S���±�*/
	int j = 1;/*T���±�*/
	while(i<= int(S.length() - T.length()))
	{
		if (S[i] == T[j])
		{
			++i;++j;
		}else 
		{
			i = i-j+2;
			j= 1;
		};
	};
	if(j>int(T.length()))return i-T.length() ;else return 0;
};
void  Cstring::get_next(string T,int *next)
{
	int i,j;
	i = 1;
	j = 0;
	next[i] = 0;
	while(i<T[0])
	{
		if (j==0 || T[i] == T[j])
		{
			++i;++j;next[i] = j;
		}else
		{
			j = next[j];
		};
	};

	return ;

};

int Cstring::Index_KMP(string S,string T,int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T,next);
	while( i <= int(S.length()&&j<=T.length()))
	{
		if (j ==0 || S[i]==T[j])
		{
			++i;++j;
		}else
		{
			j = next[j];
		}/*modify*/
		if (j>T[0]){
			return i-T[0];
		}else
			return 0;
	};
	return 1;
};
void  Cstring::get_nextval(string T,int *nextval)
{
	int i,j;
	i = 1;
	j = 0;
	nextval[i] = 0;
	while(i<T[0])
	{
		if (j==0 || T[i] == T[j])
		{
			++i;++j;
			if (T[i]==T[j])nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}else
		{
			j = nextval[j];
		};
	};

	return ;
};
