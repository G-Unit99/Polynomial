#include <iostream>
#include <string>
#include <cctype>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

//Define Node//
struct Polynomial_node
{
    int Coefficient;
    int Exponent;
    Polynomial_node *next;
};

//Define linked list of polynomials//
class polynomial
{
    private:
        Polynomial_node *head,*tail;
    public:
        polynomial()
        {
            head = nullptr;
            tail = nullptr;
        }

        void create_polynomial_node(int coefficient,int exponent)
        {
            Polynomial_node *temp = new Polynomial_node;
            temp->Coefficient = coefficient;
            temp->Exponent = exponent;
            temp->next = nullptr;

            if (head == nullptr)
            {
                head = temp;
                tail = temp;
                temp = nullptr;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }

        Polynomial_node Add_Poly(Polynomial_node,Polynomial_node)
        {

        }

        Polynomial_node Multiply_Poly(Polynomial_node,Polynomial_node)
        {

        }
};

//Define Functions//
bool Check_error(string);
int main() {

//Define Variables//
    const int Max_value = 14;
    const int Min_value = 2;
    int length = 0;

// Beginning prompt//
    cout << "This is a program that Adds and Multiplies at least two, and up to fourteen polynomials." << endl;
    cout << endl;

//Get user input and check that the input is correct//
    while (length > Max_value || length < Min_value || (isdigit(length)))
    {
        cout << "Number of polynomials -> ";
        cin >> length;
        cout << endl;

        if (length > Max_value || length < Min_value || isdigit(length) || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout <<"Input Error: please enter a number greater than 2 and less than 14" << endl;
        }
    }

//Define an array of linked list for polynomials//
    cin.ignore();
    polynomial polynomials[length];

    for (int i = 0; i < length;i++)
    {
        string check = "";
        string no_space = "";

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
//Check for errors in user input//
        while (Check_error(no_space))
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
// Parse through error checked input to place values in linked list array//
        for (int i = 0; i < no_space.length();i++)
        {
            polynomials[i] = no_space;
        }
    }
    for (int i = 0; i < length;i++)
    {
        cout << i << " " << polynomials[i] << endl;
    }

}

bool Check_error(string polynomial)
{
    bool is_error = false;
    int length = 0;
    length = polynomial.length();

//Check terminal cases that do not require iterating through the string//
    if (polynomial[0] == '+' || polynomial[0] == '^' || polynomial[0] == '*' || polynomial[length - 1] == '*' || polynomial[length - 1] == '^'|| polynomial[length -1] =='-' || polynomial[length -1] == '+')
    {
        cout << "case 1";
        return !is_error;
    }
//Check terminal cases that require iterating through the string//
    for (int i = 0; i < length;i++)
    {
//Checks that the input is a number x, X, ^, or +/- //
        if (!isdigit(polynomial[i]) && polynomial[i] != 'x' && polynomial[i] != 'X' && polynomial[i]!= '^' && polynomial[i] != '+' && polynomial[i] != '-')
        {
            cout << "case 2";
            return !is_error;
        }
//Check x's //
        else if ( polynomial[i] == 'x' || polynomial[i] == 'X')
        {
            if (polynomial[i+1] == 'x' || polynomial[i+1] =='X')
            {
                cout << "Case 3" << endl;
                return !is_error;
            }
            else if (polynomial[i+1] != ' ' && polynomial[i+1] != '^' && polynomial[i+1] != '+' && polynomial[i+1] != '-' && (i+1) != length)
            {
                cout << "Case 4" <<endl;
                return !is_error;
            }
        }
//Check that carat is properly connected as an exponent//
        else if (polynomial[i] == '^')
        {
            if (polynomial[i - 1] != 'X' && polynomial[i -1] != 'x')
            {
                cout << "case 5";
                return !is_error;
            }
//Check for incorrect values as an exponent//
            else if (!isdigit(polynomial[i + 1]) && polynomial[i+ 1]!= '-')
            {
                cout << "case 6";
                return !is_error;
            }
//Check for negative exponents//
            else if (polynomial[i +1] == '-' && !isdigit(polynomial[i +2]))
            {
                cout << "Case 7";
                return !is_error;
            }
        }
    }
    return is_error;
}


