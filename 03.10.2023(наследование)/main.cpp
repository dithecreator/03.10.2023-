//
//  main.cpp
//  03.10.2023(наследование)
//
//  Created by Дима on 03.10.23.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Person{
protected:
    char* name;
    int age;
public:
    Person() = default;
    Person(const char* n, int a): age(a){
        name = new char[strlen(n) + 1];
        strcpy(name, n);
//        cout << "person constructor" << endl;
    }
    void print(){
        cout << "name: " << name << "\tage: " << age << endl;
    }
    void input(){
        char buffer[20];
        cout << "enter name: ";
        cin.getline(buffer, 20);
        name = new char[strlen(buffer) + 1];
        strcpy(name, buffer);
        cout << "enter age: ";
        cin >> age;
    }
    
    ~Person(){
        delete[] name;
//        cout << "person destructor" << endl;
    }
 
};


class Student: public Person{
    char* university;
    
public:
    Student(const char* n, int a, const char* uni): Person(n, a){
        university = new char[strlen(uni) + 1];
        strcpy(university, uni);
//        cout << "student constructor" << endl;
    }
    
    void print(){
        Person:: print();
//           cout << " university: " << university << endl;
    }
    
    void input(const char* uni){
        if(university != nullptr){
            delete[] university;
        }
        university = new char[strlen(uni) + 1];
        strcpy(university, uni);
        Person:: input();
    }
    ~Student(){
        delete[] university;
//        cout << "student destructor" << endl;
    }
};

class Teacher: public Person{
    string school;
    int salary;
    string* classes;
    int size;
    
public:
    
    Teacher(){
        school = ' ';
        salary = 0;
         size = 0;
        classes = nullptr;
        
     
    }
    
    Teacher(string schl, int sal, int s){
        school = schl;
        salary = sal;
         size = s;
        classes = new string[s];
        for(int i = 0; i < s; i++){
            classes[i] = ' ';
        }
     
    }
    void input(){
        Person:: input();
        cout << "enter a school: ";
        cin >> school;
        cout << "enter a salary: ";
        cin >> salary;
        cout << "enter quantity of classes: ";
        cin >> size;
        classes = new string[size];
        for(int i = 0; i < size; i++){
            cout << "enter a subject: ";
            cin >> classes[i];
        }
    }
    
    
    void print(){
         Person:: print();
        cout << "school: " << school << endl;
        cout << "salary: " << salary << endl;
        cout << "classes: ";
        for(int i = 0; i < size; i++){
            cout << classes[i] << ", ";
        }
        
    }
    ~Teacher(){
        delete[] classes;
    }
};

class Driver: public Person{
    int number;
    int serialNum;
    string document;
    
    public:
       Driver(){
        number = 0;
        serialNum = 0;
        document = ' ';
     
    }
    
    Driver(int n, int sn, string d){
       number = n;
       serialNum = sn;
       document = d;

     
    }
    void input(){
        Person:: input();
cout << "enter the car number: ";
cin >> number;
cout << "enter the serial number: ";
cin >> serialNum;
cout << "enter the document: ";
cin >> document;
    }
    
    
    void print(){
         Person:: print();
        cout << "the car number: " << number << endl;
        cout << "the serial number: " << serialNum << endl;
        cout << "the document: " << document << endl;
      
    }
    
};

class Doctor: public Person{
    string speciality;
    double experience;
    bool home;
    
        public:
       Doctor(){
        speciality = ' ';
        experience = 0;
        home = false;
     
    }
    
    Doctor(string s, double exp, bool h){
       speciality = s;
       experience = exp;
       home = h;

     
    }
    
    void input(){
        Person:: input();
        char buffer[10];
cout << "enter the speciality: ";
cin >> speciality;
cout << "enter experience: ";
cin >> experience;
cout << "are you home doctor?: ";
cin >> buffer;
if(buffer == "yes"){
    home = true;
}
else{
    home = false;
}

    }
    
    
    void print(){
         Person:: print();
        cout << "the speciality: " << speciality << endl;
        cout << "experience: " << experience << endl;
        cout << "home doctor?: ";
        if(home == true){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
      
    }
    
};

int main() {
    Student obj("Irina", 18, "It step");
    obj.print();
//    Teacher teach1;
//    teach1.input();
//    teach1.print();
    Doctor doc;
    doc.input();
    doc.print();
}
