#include<iostream>
#include<cstring>
using namespace std;
char arr[100] = { 0 };
int StringLengthFinder(char *arr)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return i;
}
bool IsStringPalindrom(char*arr)
{
	bool isPalindrome = true;
	int length = StringLengthFinder(arr);
	for (int i = 0, j = length - 1; i<length / 2 - 1, j>length / 2 + 1; i++, j--)
	{
		if (arr[i] != arr[j])
		{
			isPalindrome = false;
		}
	}
	return isPalindrome;
}
char MostComonDigit(char* arr)
{
	int counter = 0;
	int maxCounter = 0;
	int length = StringLengthFinder(arr);
	int currentElement = 0;
	char maxElement = ' ';
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (arr[i] == arr[j])
			{
				counter++;
			}
		}
		if (counter > maxCounter)
		{
			maxCounter = counter;
			maxElement = arr[i];
		}
		else if (counter == maxCounter)
		{
			if (maxElement > arr[i])
			{
				maxElement = arr[i];
			}
		}
		counter = 0;
	}
	return maxElement;
}
char ComplexFunction(char* arr, int n, char(*MostComonDigit)(char*), bool(*IsStringPalindrom)(char*), int(*StringLengthFinder)(char*))
{
	if (IsStringPalindrom(arr) == true && StringLengthFinder(arr) % 2 == 0)
	{
		return MostComonDigit(arr);
	}
}
int main()
{
	char matrix[100][100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> matrix[n];
	}
	for (int i = 0; i < n; i++)
	{
		cout << ComplexFunction(matrix[i], n, MostComonDigit, IsStringPalindrom, StringLengthFinder) << endl;
	}
	return 0;
}