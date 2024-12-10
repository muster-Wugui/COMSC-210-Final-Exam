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
#include <deque>
using namespace std;

struct coffee {
    string name;
    string order;
    coffee* next;
    
};

struct muffin {
    string name;
    string muffin;
    
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    string names[10] = {"Austin", "Stepen", "Andrew", "Tony", "Bob", "James", "Smith", "Steve", "Amy", "Ruby"};
    string drinks[10] = {"Latte", "Mocha", "Oatmilk", "Milk", "Coffee 1", "Coffee 2", "Coffee 3", "Coffee 4", "Coffee 5", "Lemonade"};
    
    coffee* head = nullptr;
    coffee* tail = nullptr;
    
    for(int i = 0; i < 3; i++){
        coffee* newNode = new coffee{names[rand() % 5], drinks[rand() % 5], nullptr};
        if (!head){
            head = newNode;
        }
        else{
            tail->next = newNode;
        }
        tail = newNode;
    }
    
    deque<muffin> muffindeque;
    
    for (int round = 1; round <= 10; round++){
        cout<<"Round "<<round<<": "<<endl;
        if(head){
            coffee* temp = head;
            cout<<"Now we are serving "<<head->name<<" who ordered the drink: "<<head->order<<endl;
            head = head->next;
            delete temp;
            if(!head){
                tail = nullptr;
            }
        }
        if(rand() % 2 == 0){
            coffee* newNode = new coffee{names[rand() % 5], drinks[rand() % 5], nullptr};
            if (!head){
                head = newNode;
            }
            else{
                tail->next = newNode;
            }
            tail = newNode;
            
            cout<<"There is a new customer joined the line"<<endl;
        }
    }
    return 0;
}
