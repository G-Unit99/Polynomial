#include <iostream>
#include <string>
#include <cctype>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

struct ATerm
{
    int Coefficient;
    int Exponent;
    ATerm* Next;
};
typedef ATerm* Polynomial;

bool Check_error(string);
Polynomial Add_Poly(Polynomial);
Polynomial Multiply_Poly(Polynomial);

int main() {

    const int Max = 14;
    const int Min = 2;
    int length = 0;

    while (length > Max || length < Min || (isdigit(length)))
    {
        cout << "Number of polynomials -> ";
        cin >> length;
        cout << endl;

        if (length > Max || length < Min || isdigit(length) || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout <<"Input Error: please enter a number greater than 2 and less than 14"<<endl;
        }
    }

    string polynomials[length];
}

bool Check_error(string)
{
    bool error;
    return error;
}

Polynomial Add_Poly(Polynomial)
{
    return nullptr;
}

Polynomial Multiply_Poly(Polynomial)
{
    return nullptr;
}

