// Ryan A Peguero
//CS-210
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct InvestmentMonth {
    int month;
    double openingAmount;
    double depositedAmount;
    double total;
    double interest;
    double closingBalance;
};

// Function to calculate monthly investment details with or without monthly deposits
vector<InvestmentMonth> calculateInvestmentDetails(double initialInvestment, double monthlyDeposit, double annualInterestRate, int years, bool includeDeposits) {
    vector<InvestmentMonth> investmentReport;
    double currentBalance = initialInvestment;
    double monthlyInterestRate = annualInterestRate / 100 / 12;
    int totalMonths = years * 12;

    for (int i = 1; i <= totalMonths; ++i) {
        InvestmentMonth monthDetails;
        monthDetails.month = i;
        monthDetails.openingAmount = currentBalance;
        monthDetails.depositedAmount = includeDeposits ? monthlyDeposit : 0.0;
        monthDetails.total = monthDetails.openingAmount + monthDetails.depositedAmount;
        monthDetails.interest = monthDetails.total * monthlyInterestRate;
        monthDetails.closingBalance = monthDetails.total + monthDetails.interest;

        currentBalance = monthDetails.closingBalance;

        investmentReport.push_back(monthDetails);
    }

    return investmentReport;
}

void displayInvestmentReport(const vector<InvestmentMonth>& report, const string& title) {
    cout << title << endl;
    cout << "--------------------------------------------------------------------------------\n";
    cout << setw(6) << "Month"
        << setw(18) << "Opening Amount"
        << setw(20) << "Deposited Amount"
        << setw(15) << "Total"
        << setw(15) << "Interest"
        << setw(20) << "Closing Balance\n";
    cout << "--------------------------------------------------------------------------------\n";

    for (const auto& month : report) {
        if (month.month == 1 || month.month % 12 == 0 || month.month == report.size()) {
            cout << setw(6) << month.month
                << setw(18) << fixed << setprecision(2) << month.openingAmount
                << setw(20) << month.depositedAmount
                << setw(15) << month.total
                << setw(15) << month.interest
                << setw(20) << month.closingBalance << endl;
        }
    }
    cout << endl;
}

int main() {
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int years;

    // Input section
    cout << "***********************************" << endl;
    cout << "********** Airgead Banking ********" << endl;
    cout << "***********************************" << endl;
    cout << "Enter Initial Investment Amount: ";
    cin >> initialInvestment;
    cout << "Enter Monthly Deposit: ";
    cin >> monthlyDeposit;
    cout << "Enter Annual Interest Rate (in %): ";
    cin >> annualInterestRate;
    cout << "Enter Number of Years: ";
    cin >> years;
    cout << "Press any key to continue..." << endl;
    cin.ignore();
    cin.get();

    // Calculate and display investment details without monthly deposits
    vector<InvestmentMonth> investmentReportWithoutDeposits = calculateInvestmentDetails(initialInvestment, monthlyDeposit, annualInterestRate, years, false);
    displayInvestmentReport(investmentReportWithoutDeposits, "Balance and Interest Without Additional Monthly Deposits");

    // Calculate and display investment details with monthly deposits
    vector<InvestmentMonth> investmentReportWithDeposits = calculateInvestmentDetails(initialInvestment, monthlyDeposit, annualInterestRate, years, true);
    displayInvestmentReport(investmentReportWithDeposits, "Balance and Interest With Additional Monthly Deposits");

    return 0;
}