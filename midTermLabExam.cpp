#include <iostream>
#include <iomanip>
using namespace std;

bool IsStringValid(string maritalStatInput)
{
    if(maritalStatInput == "s" || maritalStatInput == "S" 
        || maritalStatInput == "m" || maritalStatInput == "M") 
    {
        return true;
    }
    else return false;
}

bool isNumValid(double empSalary)
{
    if(empSalary > 0) 
    {
        return true;
    }
    else return false;
}

bool isSingle(string maritalStatInput)
{
    if(maritalStatInput == "S" || maritalStatInput == "s")
    {
        return true;
    }
    else return false;
}

bool isMarried(string maritalStatInput)
{
    if(maritalStatInput == "M" || maritalStatInput == "m")
    {
        return true;
    }
    else return false;
}

double checkingSingle(double empSalary)
{
    double taxRate;
    if(empSalary > 100000)
    {
        taxRate = 0.30;
    }
    else if(empSalary >= 50000 && empSalary <= 100000)
    {
        taxRate = 0.20;
    }
    else if(empSalary < 50000)
    {
        taxRate = 0.10;
    }
    return taxRate;
}

double checkingMarried(double empSalary)
{
    double taxRate;
    if(empSalary > 100000)
    {
        taxRate = 0.25;
    }
    else if(empSalary >= 50000 && empSalary <= 100000)
    {
        taxRate = 0.15;
    }
    else if(empSalary < 50000)
    {
        taxRate = 0.05; // Changed tax rate from 0.5 to 0.05 (assuming it's a mistake)
    }
    return taxRate;
}

int main()
{
    string maritalStatInput;
    string maritalStat;
    double empSalary;
    double taxRate = 0; 
    double empSalaryTax = 0; 

    //validate
    cout << "Enter marital status (S-single/M-married) : ";
    cin >> maritalStatInput;
    if(! IsStringValid(maritalStatInput))
    {
         cout << "Error: Invalid marital status. Use 'S' for Single or 'M' for Married only!" << endl;
        return 0;
    } 

    cout << "Enter monthly salary (non-negative) : ";
    cin >> empSalary;
    if(! isNumValid(empSalary)) 
    {
        cout << "Error: The salary must be a positive value only!" << endl;
        return 0;
    }

        //checking
        if (isSingle(maritalStatInput))
        {
            maritalStat = "Single";
            taxRate = checkingSingle(empSalary);
            empSalaryTax = empSalary * taxRate;
        }
        else if (isMarried(maritalStatInput))
        {
            maritalStat = "Married";
            taxRate = checkingMarried(empSalary);
            empSalaryTax = empSalary * taxRate;
        }

        // Display results
        cout << fixed << setprecision(2);
        cout << "Employee Monthly Salary: " << empSalary << endl;
        cout << "Marital Status: " << maritalStat << endl;
        cout << "Tax Rate: " << taxRate * 100 << "%" << endl;
        cout << "Salary Tax: " << empSalaryTax << endl;
    


    return 0;
}
