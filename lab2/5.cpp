#include<iostream>
#include<cstring>
using namespace std;
char* memoryall(int len){
	char* str=new char[len+1];
	return str;
}
void input(char* string,int len)
{
	cout<<"Enter string: "<<endl;
	cin.getline(string,len+1);	
}
void length(char *string)
{
	cout<<"length of string 1 "<<string<<" is "<<strlen(string)<<endl;
}
void checking(char* string1,char* string2)
{
	int check=strcmp(string1,string2);
	if(check==0)
	{
		cout<<"String 1 and 2 are equal."<<endl;
	}
	else if(check>0)
	{
		cout<<"String 1 is greater than string 2."<<endl;
	}
	else if(check<0)
	{
		cout<<"String 2 is greater than string 1."<<endl;
	}
}
void concating(char*concatstr,char*str1,char*str2)
{
	strcpy(concatstr,str1);
	strcat(concatstr,str2);
	cout<<"THE concatenated string is "<<concatstr<<endl;
}
void memdel(char*concatstr,char*str1,char*str2)
{
	delete[]str1;
	delete[] str2;
	delete[] concatstr;
}
int main()
{
	int len1,len2;
	cout<<"Enter the length of string 1: ";
	cin>>len1;
	cout<<"\nEnter the length of string 2: ";
	cin>>len2;
	cin.ignore();
	char* str1=memoryall(len1);
	char* str2=memoryall(len2);
	
	input(str1,len1);
	input(str2,len2);
	
	length(str1);
	length(str2);
	
	checking(str1,str2);
	int len=len1+len2+1;
	char* concatstr=memoryall(len);
	concating(concatstr,str1,str2);
	
	memdel(concatstr,str1,str2);
	return 0;
}