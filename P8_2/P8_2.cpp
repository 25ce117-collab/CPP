#include <iostream>
#include <cmath>
#include <exception>
using namespace std;

class NegativeNumberException : public exception {
    public:
    const char* what() const noexcept override {
        return "Negative numbers are not allowed.";
    }
};
int main()
{
    double num;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;

        try {
            if (num < 0) {
                throw NegativeNumberException();
            }
            cout << "Square root of " << num << " is " << sqrt(num) << endl;
        } catch (const NegativeNumberException& e) {
            cerr << e.what() << endl;
        }
    }

    return 0;
}
