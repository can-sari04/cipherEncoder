#include <iostream>
#include <string>
using namespace std;

//by Can Sarı , Batuhan Arda Bekar

//Cipher Decrypter Function
void Decrypt(int a, int b, int* m, int* n)
{
	while ((a * (*m) - 1) % 26 != 0)
		++*m;
	while ((a * (*n) + b) % 26 != 0)
		++*n;
}

int main()
{
	int a = 0, b = 0; // f(p) = a.p + b
	int m = 0, n = 0; // f^-1(p) = m.p + n

	string text;

	cout << "Decrypt Or Encrypt? (D / E) :";
	cin >> text;

	cout << "Enter a [ f(p) = a.p + b ] :";
	cin >> a;
	cout << "Enter b [ f(p) = a.p + b ] :";
	cin >> b;

	if (text == "D")
	{
		Decrypt(a, b, &m, &n);
		a = m;
		b = n;
	}
	

	cout << "Enter Text: ";
	cin >> text;

	cout << '\n';

	char alphabetIndex[26];
	char cipherIndex[26];

	for (int i = 65; i < 91; i++) {

		alphabetIndex[i - 65] = i;
		int temp = alphabetIndex[i - 65] - 65;
		cipherIndex[i - 65] = (temp * a + b) % 26 + 65;
	}

	for (int i = 0; i < text.size(); i++)
	{
		text[i] = toupper(text[i]);
		int temp = text[i] - 65;
		for (int j = 0; j < 26; j++) {
			if (temp == j)
				cout << cipherIndex[j];

		}
	}
}
