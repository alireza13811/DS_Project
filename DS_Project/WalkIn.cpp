#include <iostream>
#include "Patient.h"
#include "node.h"
#include "List.h"

using namespace std;

int main() {
    List    mylist;
    mylist.setCapacity(10);


    Patient p1("1111111111", "Mohammad","azarmoh81@gmail.com","9130006648","Isfahan");
    Patient p2("2222222222", "Hassan", "hassani@gmail.com", "9130009999", "Yazd");
    Patient p3("3333333333", "Hamid", "hamidi@gmail.com", "9130004444", "Tehran");
    
    cout << "------------------Insert First Patient-----------------------\n";
    mylist.insert(p2);
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();
    
    cout << "\n\n-------------------Insert New Patient------------------------\n";
    
    mylist.insert(p1);
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();
    
    cout << "\n\n-------------------Insert New Patient------------------------\n";
    
    mylist.insert(p3);
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();

    cout << "\n\n---------------------Remove a Patient------------------------\n";

    mylist.remove(p2);
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();

    cout << "\n\n------------------------Remove All---------------------------\n";
    mylist.removeAll();
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();

    cout << "\n\n--------------------Insert 5 Patients------------------------\n";

    Patient p4("4444444444", "Akbar", "akbariii@gmail.com", "9130005555", "Ahvaz");
    Patient p5("4444444444", "Asghar", "asghariii@gmail.com", "91300003737", "Kerman");
    mylist.insert(p4);
    mylist.insert(p5); 
    mylist.insert(p1);
    mylist.insert(p2);
    mylist.insert(p3);
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();

    cout << "\n\n---------------------------Search-----------------------------\n";

    Patient* result = mylist.search(p2);
    cout << *result;
    cout << "Elements Count: " << mylist.getElementCount();

    cout << "\n\n-------------------------Remove All---------------------------\n";
    
    mylist.removeAll();
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();

    return 0;
}