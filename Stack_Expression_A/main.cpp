#include <iostream>
#include "stack_.h"  
using namespace std;

int main()
{
    cout << "Expressions " << endl;
    Stack<char> stack;
    string expression;
    unsigned i;
    bool valid;
    char symbol;
    int option;

    do {
        cout << "1 - New Expression" << endl;
        cout << "9 - EXIT\n";
        cout << "Select: ";
        cin >> option;
        cin.ignore();

        switch(option) {
        case 1:
            cout << "Enter the expression: ";
            getline(cin, expression);
            cout << "Input: " << expression << endl;

            unsigned size = expression.size();
            i = 0;
            valid = true;

            while (i < size) {
                symbol = expression.at(i);

                if (symbol == '{' || symbol == '[' || symbol == '(') {
                    stack.push(symbol);
                } else {
                    if (symbol == '}' || symbol == ']' || symbol == ')') {
                        if (stack.isEmpty()) {
                            valid = false;
                        } else {
                            if (symbol == '}' && stack.top() == '{') {
                                stack.pop();
                            } else if (symbol == ']' && stack.top() == '[') {
                                stack.pop();
                            } else if (symbol == ')' && stack.top() == '(') {
                                stack.pop();
                            } else {
                                break;
                            }
                        }
                    }
                }
                i++;
            }
            break;
        }
    } while (option != 9);

    if (stack.isEmpty() && valid) {
        cout << "The expression: " << expression << endl;
        cout << "Is correct!" << endl;
    } else {
        cout << "The expression: " << expression << endl;
        cout << "Is NOT correct!!!" << endl;
    }

    return 0;
}

