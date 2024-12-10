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

struct muffin {
    string name;
    string order;
};

struct bracelet {
    string name;
};

struct phone {
    string name;
    string order;
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    deque<muffin> muffins;
    vector<bracelet> bracelets;
    stack<phone> phones;
    
    string names[10] = {"Austin", "Stepen", "Andrew", "Tony", "Bob", "James", "Smith", "Steve", "Amy", "Ruby"};
    string drinks[10] = {"Latte", "Mocha", "Oatmilk", "Milk", "Coffee 1", "Coffee 2", "Coffee 3", "Coffee 4", "Coffee 5", "Lemonade"};
    string muffin_name[10] = {"Chocaloate", "milk", "bluebarry", "banana", "muffin 1", "muffin 2", "muffin 3", "muffin 4", "muffin 5", "special flavor"};
    string phone_name[10] = {"Iphone 5", "Iphone 6", "Iphone 7", "Iphone 8", "Iphone 9", "Iphone 10", "Iphone 11", "Iphone 12", "Iphone 13", "Iphone 14"};
    
    coffee* head = nullptr;
    coffee* tail = nullptr;
    
    for(int i = 0; i < 3; i++){
        coffee* newNode = new coffee{names[rand() % 10], drinks[rand() % 10], nullptr};
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
            coffee* newNode = new coffee{names[rand() % 10], drinks[rand() % 10], nullptr};
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
            muffin customer_m = muffins.front();
            muffins.pop_front();
            cout<<"Now we are serving "<<customer_m.name<<" who ordered a "<<customer_m.order<<" muffin"<<endl;
        }
        
        if(rand() % 2 == 0){
            muffins.push_back({names[rand() % 10], muffin_name[rand() % 10]});
            cout<<"There is a new customer joined the line"<<endl;
        }
        
        
        
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Friendship Bracelets Booth: "<<endl;
        if(bracelets.empty()){
            cout<<"The line of friendship bracelets is empty."<<endl;
        }
        else{
            bracelet customer_b = bracelets.front();
            bracelets.erase(bracelets.begin());
            cout<<"Now we are serving "<<customer_b.name<<" who ordered a friendship bracelets"<<endl;
            
        }
        
        if(rand() % 2 == 0){
            bracelets.push_back({names[rand() % 10]});
            cout<<"There is a new customer joined the line"<<endl;
        }
        
        
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Phone Shop: "<<endl;
        if(phones.empty()){
            cout<<"The line of phone shop is empty."<<endl;
        }
        else{
            phone customer_p = phones.top();
            phones.pop();
            cout<<"Now we are serving "<<customer_p.name<<" who ordered an "<<customer_p.order<<endl;
        }
        
        if(rand() % 2 == 0){
            phones.push({names[rand() % 10], phone_name[rand() % 5]});
            cout<<"There is a new customer joined the line"<<endl;
        }
        
        cout<<"\n-----------------------------------------------\n"<<endl;
    }
    return 0;
}
