/**********************************************************
Author: Amy Lim
Program: Mixed Number Calculator
Purpose: To do multiple operations on two mixed numbers or
         fractions.
Notes: None.
**********************************************************/
#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include "fraction.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Fraction first, second, answer;
    char repeat, op, op2;
    do
    {
        cout << "Enter two fractions or mixed numbers separated by an operator:" << endl;
        //-----------------Input--------------
        cin >> first;
        cin.ignore(50, ' ');
        cin.get(op);
        if(op == ' ')
            cin.get(op);
        cin.get(op2);
        if(op2 != '=')
        {
            cin.putback(op2);
            op2 = '\0';
        }
        cin.ignore(50, ' ');
        cin >> second;
        fflush(stdin);
        //-----------------END Input--------------
        switch(op)
        {
        case '+':
            answer = first + second;
            cout << first << " " << op << " " << second << " = " << answer << endl;
            break;
        case '-':
            answer = first - second;
            cout << first << " " << op << " " << second << " = " << answer << endl;
            break;
        case '*':
            answer = first * second;
            cout << first << " " << op << " " << second << " = " << answer << endl;
            break;
        case '/':
            answer = first / second;
            cout << first << " " << op << " " << second << " = " << answer << endl;
            break;
        case '<':
            if(op2 == '=')
            {
                if(first <= second)
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            }
            else
            {
                if(first < second)
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            }
            break;
        case '>':
            if(op2 == '=')
            {
                if(first >= second)
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            }
            else
            {
                if(first > second)
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            }
            break;
        case '=':
            if(op2 == '=')
            {
                if(first == second)
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            }
            else
                cout << "Unknown operator!" << endl;
            break;
        case '!':
            if(op2 == '=')
            {
                if(first != second)
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            }
            else
                cout << "Unknown operator!" << endl;
            break;
        default:
            cout << "Unknown operator!" << endl;
        }
        cout << "Would you like to repeat? ";
        cin >> repeat;
        fflush(stdin);
        cout << endl;
    }while(toupper(repeat) != 'N');
    cout << "\nThank you for using the Mixed Number program!\n";
    return a.exec();
}
