#include<iostream>
using namespace std;
class Person {
public:
	int a;
	int b;
	char* c;
	Person() {
		this->a = 0;
		this->b = 0;
		this->c = new char[1000];
		this->c[0] = 'a';
		this->c[1] = '\0';
	}
	Person(Person p) {
		this->a = p.a;
		this->b = p.b;
		this->c = new char[1000];
		for (size_t i = 0; i < strlen(p.c)+1; i++) {
			this->c[i] = p.c[i];
		}
	}
};
void modify(Person p) {
	p.c[0] = 'b';
	cout << p.c << endl;
}
int main() {
	Person p = Person();
	cout << p.c << endl;
	modify(p);
	cout << p.c << endl;
	system("pause");
	return 0;
}