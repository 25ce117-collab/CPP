#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Loan {
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    Loan() {
        loanID = 0;
        applicantName = "Default";
        loanAmount = 100000;
        annualInterestRate = 10;
        tenureMonths = 12;
    }

    Loan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    double calculateEMI() {
        double R = annualInterestRate / (12 * 100);
        double T = tenureMonths;
        double emi = (loanAmount * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
        return emi;
    }

    void displayDetails() {
        cout << fixed << setprecision(2);
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Annual Interest Rate (%): " << annualInterestRate << endl;
        cout << "Tenure (Months): " << tenureMonths << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
    }
};

int main() {
    Loan defaultLoan;
    cout << "Default Loan Details:" << endl;
    defaultLoan.displayDetails();

    cout << endl;

    int id, tenure;
    string name;
    double amount, rate;

    cout << "Enter Loan ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Applicant Name: ";
    getline(cin, name);
    cout << "Enter Loan Amount: ";
    cin >> amount;
    cout << "Enter Annual Interest Rate (%): ";
    cin >> rate;
    cout << "Enter Tenure (Months): ";
    cin >> tenure;

    Loan customerLoan(id, name, amount, rate, tenure);

    cout << endl << "Customer Loan Details:" << endl;
    customerLoan.displayDetails();

    return 0;
}
