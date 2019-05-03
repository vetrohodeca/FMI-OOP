#include<iostream>
using namespace std;
struct book {
	char name[31];
	char*author;
};
struct student {
	unsigned short fn;// raboti za informatika, poneje max fn e 45600, a tipa durji do 65000
	book* studentBook;
};
int main()
{
	student st;
	student* studentlist[30];
	studentlist[0] = &st;
	book bk;
	cin.getline(bk.name, 31);
	char a_name[20] = "Author name";
	bk.author =a_name;
	st.fn = 12345;
	st.studentBook = &bk;
	cout<< studentlist[0]->studentBook->author<<endl;

		/*Дефинирайте 2 - те структури от данни.
		Дефинирайте масив от указатели към студенти(studentList) с максимален размер 30.
		Инициализирайте първия елемент на масива.
		Създайте помощна книга bk с въведено име от клавиатурата и автор - Author Name.
		Нека fn на студента е 12345.
		Изведете на екрана името на автора на книгата, която е притежание на първия студент.
		*/         
	system("pause");
	return 0;
}
