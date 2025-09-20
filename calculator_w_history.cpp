#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

std::vector<std::string> history;
std::string input;
char symbol;
double num1,num2,result;
int number = 0;
bool SecondNumber = false, valid = true;
int main() {
    while (true){
        
        std::cout << "Enter calculation (or 'exit' to quit/ 'history' for all calculation histories): ";
        std::getline(std::cin, input);
        
        if(input == "exit"){
            break;
        }
        else if(input == "history"){
            for(int i=0;i<history.size();i++)
                std::cout << history[i] << std::endl;
            continue;
        }
        else
        {
            std::istringstream iss(input);
            iss >> num1 >> symbol >> num2;
        }


        switch (symbol){
        default:
            std::cout << "Error: Invalid operator. Please use +, -, *, or /." << std::endl;
            valid = false;
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                history.push_back(input + " = Error: Division by zero");
                valid = false;
            }
            break;
         }

         if (valid) {
             std::cout << std::fixed << std::setprecision(2) << num1 << " " << symbol << " " << num2 << " = " << result << std::endl;
             history.push_back(input + " = " + std::to_string(result));
         }
         
         valid = true;
    }
}


