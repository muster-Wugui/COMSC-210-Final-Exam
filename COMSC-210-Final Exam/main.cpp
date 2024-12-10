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
#include <vector>
#include <stack>
using namespace std;

struct coffee {
    string name;
    string order;
    coffee* next;
    
};


int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    deque<pair<string, string>> muffins;
    vector<string> bracelets;
    stack<pair<string, string>> phones;
    
    string names[10] = {"Austin", "Stepen", "Andrew", "Tony", "Bob", "James", "Smith", "Steve", "Amy", "Ruby"};
    string drinks[10] = {"Latte", "Mocha", "Oatmilk", "Milk", "Coffee 1", "Coffee 2", "Coffee 3", "Coffee 4", "Coffee 5", "Lemonade"};
    string muffin[10] = {"Chocaloate", "milk", "bluebarry", "banana", "muffin 1", "muffin 2", "muffin 3", "muffin 4", "muffin 5", "special flavor"};
    string phone[10] = {"Iphone 5", "Iphone 6", "Iphone 7", "Iphone 8", "Iphone 9", "Iphone 10", "Iphone 11", "Iphone 12", "Iphone 13", "Iphone 14"};
    
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

    
    for (int round = 1; round <= 10; round++){
        cout<<"Round "<<round<<": "<<endl;
        cout<<"Coffee Booth: "<<endl;
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
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Muffin Booth: "<<endl;
        if(muffins.empty()){
            cout<<"The line of muffin booth is empty."<<endl;
        }
        else{
            cout<<"Now we are serving "<<muffins.front().first<<" who ordered a "<<muffins.front().second<<" muffin"<<endl;
            muffins.pop_back();
        }
        
        if(rand() % 2){
            muffins.push_back(make_pair(names[rand() % 5], muffin[rand() % 5]));
            cout<<"There is a new customer joined the line"<<endl;
        }
        
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Friendship Bracelets Booth: "<<endl;
        if(bracelets.empty()){
            cout<<"The line of friendship bracelets is empty."<<endl;
        }
        else{
            cout<<"Now we are serving "<<bracelets[0]<<" who ordered a friendship bracelets"<<endl;
            bracelets.erase();
        }
        
        if(rand() % 2){
            bracelets.push_back(names[rand() % 5]);
            cout<<"There is a new customer joined the line"<<endl;
        }
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Phone Shop: "<<endl;
    }
    return 0;
}
