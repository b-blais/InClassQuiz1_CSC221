/*
Title: CSC221 In Class Quiz 1 - Project 1
File Name : InClassQuiz1_CSC221
Programmer : Brion Blais
Date : 10 / 2024
Requirements :
    
    Crazy Al’s Computer Emporium is a retail seller of home computers. The sales staff at Crazy Al’s works strictly on commission. At the end of the month, each salesperson’s commission
    is calculated according to Table 1.
    Table 1 Commission rates
    Sales This Month Commission Rate
    Less than $10,000 5%
    $10,000–$14,999 10%
    $15,000–$17,999 12%
    $18,000–$21,999 14%
    $22,000 or more 16%


    For example, a salesperson with $16,000 in monthly sales will earn a 12 percent commission ($1,920.00).

    Another salesperson with $20,000 in monthly sales will earn a 14 percent 
    commission ($2,800.00).Because the staff only gets paid once per month, Crazy Al’s allows each employee to take
    up to $1,500 per month in advance. When sales commissions are calculated, the amount of each employee’s
    advanced pay is subtracted from the commission. If any salesperson’s
    commissions are less than the amount of their advance, they must reimburse Crazy Al’s for the difference.


    Here are two examples: Beverly and John have $21,400 and $12,600 in sales, respectively. 
    Beverly’s commission is $2,996 and John’s commission is $1,260. Both Beverly and John
    took $1,500 in advance pay. At the end of the month, Beverly gets a check for $1,496, but
    John must pay $240 back to Crazy Al’s.

    Example output

    Program Output with Example Input Shown in Bold
    Enter the salesperson's monthly sales: 19600 
    Enter the amount of advanced pay for this salesperson: 1000

    Pay Results
    -----------
    Sales: $19600.00
    Commission Rate: 0.14
    Commission: $2744.00
    Advanced Pay: $1000.00
    Remaining Pay: $1744.

 

    You do NOT need to make the program repeatable to allow for 

    multiple sales agents. However, you will receive an extra 5 points if you

    can do so.

 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double sales;
    double commissionRate;
    double commission;
    string answer = "No";
    bool advancePay = 0;
    double advancePayAmount = 0;
    double remainingPay;
    bool makingEntries = 1;

    while (makingEntries == 1) {
        cout << "Please enter the salesperson's month sales.\n" << endl;
        cin >> sales;
        cout << "Did the salesperson take any advance pay this month?  Yes or No\n" << endl;
        cin >> answer;
        if (answer == "Yes") {
            advancePay = 1;
            cout << "How much of an advance on thier commission did they take?\n Enter 0 if you made a mistake and they did not take an advance.\n" << endl;
            cin >> advancePayAmount;
            while ((advancePayAmount < 0) || (advancePayAmount > 1500.00)) {
                cout << "Please enter a value between 1 and 1500.";
                cin >> advancePayAmount;
                if (advancePayAmount == 0) {
                    break;
                }
            }
        }
        answer = "No";

        if (sales < 10000.00) {
            commissionRate = .05;
        }
        else if (sales >= 10000.00 && sales < 15000.00) {
            commissionRate = .10;
        }
        else if (sales >= 15000.00 && sales < 18000.00) {
            commissionRate = .12;
        }
        else if (sales >= 18000.00 && sales < 22000.00) {
            commissionRate = .14;
        }
        else if (sales >= 22000.00) {
            commissionRate = .16;
        }

        commission = sales * commissionRate;
        remainingPay = commission - advancePayAmount;

        cout << setprecision(2) << fixed;
        cout << "Pay Results" << endl;
        cout << "----------" << endl;
        cout << "Sales : $" << right << sales << endl;
        cout << "Commission Rate : $" << commissionRate << endl;
        cout << "Commission : $" << right << commission << endl;
        cout << "Advanced Pay : $" << right << advancePayAmount << endl;
        cout << "Remaining Pay : $" << remainingPay << endl;

        cout << "Would you like to make another calculation? Yes or No\n" << endl;
        cin >> answer;
        
        if (answer == "Yes") {
            makingEntries = 1;
        }
        else { 
            makingEntries = 0; 
        }
    }

    return 0;
}
