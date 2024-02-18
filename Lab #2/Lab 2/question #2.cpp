#include "string"
#include "iostream"
#include "fstream"
#include "iomanip"
using namespace std;

int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open("inData.txt");
    outFile.open("outData.txt");
    string firstName, lastName, department;
    double grossIncome, bonus, taxes, distance, travelTime, coffeeCost; 
    int coffeeSold;
    inFile >> firstName >> lastName >> department >> grossIncome >> bonus >> taxes >> distance >> travelTime >> coffeeSold >> coffeeCost;
    double bonusAmount = grossIncome * (bonus / 100);
    double beforeTaxEarning = grossIncome + bonusAmount;
    double taxAmount = beforeTaxEarning * (taxes / 100);
    double netIncome = beforeTaxEarning - taxAmount;
    outFile << fixed << showpoint << setprecision(2);
    outFile << "Name: " << firstName << " " << lastName << ", " << "Department: " << department << "\n";
    outFile << "MonthlyGrossSalary: " << grossIncome << " MonthlyBonus: " << bonus << " Taxes: " << taxes << "\n" << "Paycheck: " << netIncome << "\n\n";
    outFile << "Distance Traveled: " << distance << " miles, Travel Time: " << travelTime << " hours" << "\n";
    outFile << "Average Speed: " << distance / travelTime << " miles per hour" << "\n\n";
    outFile << "Number of Coffee Cups Sold: " << coffeeSold << " Cost Per Coffee: " << coffeeCost << "\n";
    outFile << "Sales Amount = " << coffeeCost * coffeeSold;
    inFile.close();
    outFile.close();
}
