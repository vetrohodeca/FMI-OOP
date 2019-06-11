#include"String.h"
#include<iostream>
#pragma warning(disable :4996)
const int MyString::getSize()
{
	int counter=0;
	while (str[counter]!='\0')
	{
		counter++;
	}
	return counter;
}
MyString::MyString()
{
	this->str = new char[6];
	strcpy(this->str, "empty");
}
void MyString::print()
{
	std::cout << str<<std::endl;
}
 MyString::~MyString()
{
	 delete[] str;
}
 void MyString::setLen(const MyString& other)
 {

}
 void MyString::CopyFrom(const MyString& other) 
 {

	 int len = strlen(other.str);
	 this->str = new char[len + 1];
	 strcpy(this->str, other.str);
}
 MyString::MyString(const MyString& other)
 {
	 CopyFrom(other);
 }
 MyString&::MyString::operator=(const MyString& other)
 {
	 if (this != &other)
	 {
		 delete[] str;
		 CopyFrom(other);
	 }
	 return *this;
 }
 MyString::MyString(const char*str)
 {
	 int len = strlen(str);
	 this->str = new char[len + 1];
	 strcpy(this->str, str);

 }
 MyString MyString::operator+(const MyString&other)
 {
	 MyString result;
	 int currLen = this->getSize();
	 int otherLen = strlen(other.str);
	 result = new char[otherLen + currLen +1];
	 for (int i = 0;i <  currLen; i++)
	 {
		 result.str[i] = this->str[i];
	 }
	 for (int i = currLen; i < otherLen+currLen; i++)
	 {
		 result.str[i] = other.str[i-currLen];
	 }
	 result.str[currLen + otherLen] = '\0';
	 //result.print();
	 return result;
 }

 bool MyString::operator==(const MyString other)
 {

	 if (strcmp(this->str, other.str) == 0) {
		 return true;
	 }
	 return false;
 }

 bool MyString::operator!=(const MyString& other)
 {
	 return !(*this == other);
 }
 