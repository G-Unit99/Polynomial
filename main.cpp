#include <iostream>
#include <string>
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

    cout << "Hello, World!" << endl;

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

