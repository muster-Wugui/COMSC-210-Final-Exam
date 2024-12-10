//
//  main.cpp
//  COMSC-210-Final Exam
//
//  Created by Xiao Zhang on 12/9/24.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct coffee {
    string name;
    string order;
    coffee* next;
    
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    string names[10] = {"Austin", "Stepen", "Andrew", "Tony", "Bob", "James", "Smith", "Steve", "Amy", "Ruby"};
    string drinks[10] = {"Latte", "Mocha", "Oatmilk", "Milk", "Coffee 1", "Coffee 2", "Coffee 3", "Coffee 4", "Coffee 5", "Lemonade"};
    
    coffee* head = nullptr;
    coffee* tail = nullptr;
    
    for(int i = 0; i < 3; i++){
        coffee* newNode = new coffee{names[reand() % 5], drinks}
    }
    
    return 0;
}
