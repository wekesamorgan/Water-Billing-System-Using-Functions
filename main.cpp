#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// constant water rate
const double RATE_PER_UNIT = 3.50;

// function prototypes
void getCustomerDetail(string &name, double &units);
double calculateBill(double units);
double applyDiscount(double units, double totalBill);
void displayBill(string name, double units, double totalBill, double discount, double finalAmount);

int main()
{
    string name;
    double units;

    cout << "..........Water Billing System.........." << endl;

    getCustomerDetail(name, units);

    double totalBill = calculateBill(units);
    double discount = applyDiscount(units, totalBill);
    double finalAmount = totalBill - discount;

    displayBill(name, units, totalBill, discount, finalAmount);
    return 0;
}

// get details
void getCustomerDetail(string &name, double &units)
{
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter units consumed: ";
    cin >> units;
}

// compute water bill before discount
double calculateBill(double units)
{
    return units * RATE_PER_UNIT;
}

// 10% discount if over 100 units
double applyDiscount(double units, double totalBill)
{
    if (units > 100)
    {
        return totalBill * 0.10;
    }
    return 0;
}

// full bill summary
void displayBill(string name, double units, double totalBill, double discount, double finalAmount)
{
    cout << fixed << setprecision(2);
    cout << "\n..........Water Billing System.........." << endl;
    cout << "Name: " << name << endl;
    cout << "Units: " << units << endl;
    cout << "Total bill before discount: " << totalBill << endl;
    cout << "Discount: " << discount << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Total bill after discount: " << finalAmount << endl;
}