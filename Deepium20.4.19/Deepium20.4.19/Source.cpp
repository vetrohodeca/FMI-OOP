#include<iostream>
#include<cmath>
using namespace std;
//int recBinarySearch(int*arr, int n, int element, int minIndex, int maxIndex)
//{
//	int midIndex=(maxIndex+minIndex)/2
//	if(arr[midIndex]==)
//}
int binarySearch(int*arr, int n, int element)
{
	int firstIndex = 0;
	int i = 0;
	int lastIndex =n - 1;
	int midIndex = (n - 1) / 2;
	 while (firstIndex != lastIndex)
	{
		if (arr[midIndex]== element)
		{
			return midIndex;
		}
		else if (element > arr[midIndex])
		{
			firstIndex = midIndex;
			midIndex = (firstIndex + lastIndex+1) / 2;
			
		}
		else if (element < arr[midIndex])
		{
		
			lastIndex = midIndex;
			midIndex = (firstIndex + lastIndex) / 2;
			
		}
		if (i>log2(n))
		{
			return -1;
		}
	}
	return -1;
}

int main()
{
	int arr[5] = { 2,2,2,2,2 };
	cout << binarySearch(arr, 5,3) << endl;
	system("pause");
	return 0;

}