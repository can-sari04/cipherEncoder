#include <iostream>
#include <string>
using namespace std;

//by Can Sarı , Batuhan Arda Bekar
int main()
{
    int a, b; // f(p) = a.p + b

    cout << "Enter a [ f(p) = a.p + b ] :";
    cin >> a;
    cout << "Enter b [ f(p) = a.p + b ] :";
    cin >> b;

    string text;
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
