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

    cin.ignore();
    string polynomials[length];

    for (int i = 0; i < length;i++)
    {
        string check;
        string no_space;

        cout << "Input polynomial " << i+1 << " -> ";
        getline(cin,check);
        cout << endl;
//Ignore spaces and copy values into another string//
        for (int i = 0; i < check.length();i++)
        {
            if (!isspace(check[i]))
            {
                no_space += check[i];
            }
        }

        while(Check_error(no_space))
        {
            no_space = "";
            cout << "Input Error: please input a correct polynomial" << endl;
            cout << "Input polynomial " << i+1 << " -> ";
            getline(cin,check);
            cout << endl;

            for (int i = 0; i < check.length();i++)
            {
                if (!isspace(check[i]))
                {
                    no_space += check[i];
                }
            }
        }
            polynomials[i] = no_space;
    }
    for (int i = 0; i < length;i++)
    {
        cout << i << " " << polynomials[i] << endl;
    }

}

bool Check_error(string polynomial)
{
    bool error;
    int length;
    length = polynomial.length();
//Check terminal cases that do not require iterating through the string//
    if (polynomial[0] == '^' || polynomial[0] == '*' || polynomial[length - 1] == '*' || polynomial[length - 1] == '^')
    {
        cout << "case 1";
        return !error;
    }
//Check terminal cases that require iterating through the string//
    for (int i = 0; i < length;i++)
    {
        if (!isdigit(polynomial[i]) && polynomial[i] != 'x' && polynomial[i] != 'X' && polynomial[i]!= '^' && polynomial[i] != '+' && polynomial[i] != '-')
        {
            cout << "case 2";
            return !error;
        }
//Check that carat is properly connected as an exponent
        else if (polynomial[i] == '^')
        {
            if (polynomial[i - 1] != 'X' && polynomial[i -1] != 'x')
            {
                cout << "case 3";
                return !error;
            }
//Check for incorrect values as an exponent
            else if (!isdigit(polynomial[i + 1]) && polynomial[ i+ 1]!= '-')
            {
                cout << "case 4";
                return !error;
            }
//Check for negative exponents
            else if (polynomial[i +1] == '-' && !isdigit(polynomial[i +2]))
            {
                cout << "Case 5";
                return !error;
            }

        }
    }

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

