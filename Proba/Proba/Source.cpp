#include<iostream>
using namespace std;
int main()
{
	ostream& put(char);// kakva e razlikata sus i bez &
	cout.put('A').put('B').put('C').put('D') << endl;
	ostream write(char* str, streamsize size);
	{
		cout.write("ABCD", 3).write("ABCD", 2) << endl;
	}
	istream& get(char& ch);
	char c1 = 'a',c2 = 'b', c3 = 'c', c4 = 'd';
	cin.get(c1).get(c2).get(c3).get(c4);// vzimame po simvolche

	char str[10] = "abcdefghi";
	cin.getline(str, 10, '.');
	istream& putback(char ch);
	char c11, c22;
	cin.get(c11).get(c22); 
	cin.putback('9').putback('5');
	cin.get(c11).get(c22); 
	cout << c11 << c22; 
	system("pause");
	return 0;
}

//kakva e razlikata mejdu streamsize i size_t tipove