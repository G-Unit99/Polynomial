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
//Function to create polynomial_nodes for the linked list//
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
//Function to display the values in the linked list//
        void Display_List()
        {
            Polynomial_node *temp = new Polynomial_node;
            temp = head;

            while(temp!= nullptr)
            {
                cout << temp->Exponent << endl;
                cout << temp->Coefficient << endl;
                temp = temp->next;
            }
        }
//Functions to add polynomials//
        Polynomial_node Add_Poly(Polynomial_node one,Polynomial_node two)
        {
            Polynomial_node *sum = new Polynomial_node;

            if (one.Exponent == two.Exponent)
            {

            }

        }

        Polynomial_node Multiply_Poly(Polynomial_node one,Polynomial_node two)
        {
            Polynomial_node *sum = new Polynomial_node;

            if (one.Exponent == two.Exponent)
            {

            }

        }
};

//Define Functions//
bool Check_error(string);
int main() {

//Define Variables//
    const int Max_value = 14;
    const int Min_value = 2;
    string coefficient = "";
    string exponent = "";
    int length = 0;
    int nodes = 0;

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

//Define an array of linked list for the polynomials//
    cin.ignore();
    polynomial polynomials[length];

    for (int i = 0; i < length;i++)
    {
        int count = 0;
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
//Have user input another polynomial if error occurs//
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
//If character equals ^ do nothing//
            if (no_space[i] == '^')
            {

            }
//If character does not equal x or X parse the coefficient//
            else if (no_space[i] != 'x' && no_space[i] != 'X' && count == 0)
            {
                coefficient += no_space[i];
                if (i == no_space.length()-1)
                {
                    exponent = "1";
                    polynomials[nodes].create_polynomial_node(stoi(coefficient), stoi(exponent));
                    coefficient = "";
                    exponent = "";
                }
            }
//If character is equal to x or X increase the count and parse the exponent//
            else if (no_space[i] == 'x' || no_space[i] =='X')
            {
                count = 1;
                if (i == no_space.length()-1)
                {
                    exponent = "1";
                    if (coefficient == "" || coefficient == "+")
                    {
                        coefficient = "1";
                        polynomials[nodes].create_polynomial_node(stoi(coefficient),stoi(exponent));
                        coefficient = "";
                        exponent = "";
                    }
                    else if (coefficient == "-")
                    {
                        coefficient = "-1";
                        polynomials[nodes].create_polynomial_node(stoi(coefficient),stoi(exponent));
                        coefficient = "";
                        exponent = "";
                    }
                    else
                    {
                        polynomials[nodes].create_polynomial_node(stoi(coefficient),stoi(exponent));
                        coefficient = "";
                        exponent = "";
                    }
                }
//check if the exponent is raised to the power of 1//
                else if (no_space[i+1] != '^')
                {
                    exponent = "1";
// Check for sign instead of numeric coefficient value//
                    if (no_space[i-1] == '+')
                    {
                        coefficient = "1";
                        polynomials[nodes].create_polynomial_node(stoi(coefficient),stoi(exponent));
                        coefficient = "";
                        exponent = "";
                        count = 0;
                    }
                    else if (no_space[i-1] == '-')
                    {
                        coefficient = "-1";
                        polynomials[nodes].create_polynomial_node(stoi(coefficient),stoi(exponent));
                        coefficient = "";
                        exponent = "";
                        count = 0;
                    }
                    else
                    {
                        polynomials[nodes].create_polynomial_node(stoi(coefficient),stoi(exponent));
                        coefficient = "";
                        exponent = "";
                        count = 0;
                    }
                }
            }
//Check for operands to signal creation of polynomial node//
            else if ((no_space[i] == '+' || no_space[i] == '-') && count == 1 && no_space[i-1] != '^')
            {
                polynomials[nodes].create_polynomial_node(stoi(coefficient), stoi(exponent));
                coefficient = no_space[i];
                exponent = "";
                count = 0;
            }
//Parse exponent//
            else if (count == 1)
            {
                exponent += no_space[i];
                if (i == no_space.length()-1)
                {
                    if (coefficient == "" || coefficient == "+")
                    {
                        coefficient = "1";
                        polynomials[nodes].create_polynomial_node(stoi(coefficient),stoi(exponent));
                        coefficient = "";
                        exponent = "";
                    }
                    else if (coefficient == "-")
                    {
                        coefficient = "-1";
                        polynomials[nodes].create_polynomial_node(stoi(coefficient),stoi(exponent));
                        coefficient = "";
                        exponent = "";
                    }
                    else
                    {
                        polynomials[nodes].create_polynomial_node(stoi(coefficient),stoi(exponent));
                        coefficient = "";
                        exponent = "";
                    }
                }
            }
        }
        nodes += 1;
    }

    for (int i = 0; i < length;i++)
    {
        cout<< "yer " << i << endl;
        polynomials[i].Display_List();
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


