#include<iostream>
using namespace std;
void Swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
int Partition(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = -1;//broi promeni
	for (int j = 0; j < high - 1; j++)
	{
		if (arr[j] <= pivot)// ako elementa e po- maluk ot pivota, smenqme
		{
			i++;
			Swap(arr[i], arr[j]);
		}
	}
	Swap(arr[i + 1], arr[high]);
	return(i + 1);
}
void QuickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(arr, low, high);
		QuickSort(arr, low, pivot - 1);//sortirame vlqvo
		QuickSort(arr, pivot + 1, high);//sortirame vdqsno	
	}
}
int main()
{
	int arr[4]={ 3,8,2,4 };
	QuickSort(arr, 0, 4);
	cout << arr[0] << "  " << arr[1] << "  " << arr[2] << "  " << arr[3] << endl;
	system("pause");
	return 0;
}