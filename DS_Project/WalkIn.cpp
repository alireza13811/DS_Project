#include <iostream>
#include "Patient.h"
#include "node.h"
#include "List.h"

using namespace std;




int main() {
    List mylist;
    mylist.setCapacity(10);


    Patient p1("Mohammad","9130006648","azarmoh81@gmail.com","1111111","Isfahan");
    Patient p2("Hassan", "9130009999", "hassani@gmail.com", "2222222", "Yazd");
    Patient p3("Hamid", "9130004444", "hamidi@gmail.com", "3333333", "Tehran");

    mylist.insert(p2);
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();
    
    cout << "\n----------------------------------------------\n";
    
    mylist.insert(p1);
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();
    
    cout << "\n----------------------------------------------\n";
    
    mylist.insert(p3);
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();

    cout << "\n----------------------------------------------\n";
    mylist.remove(p2);
    mylist.printList();

    cout << "\n----------------------------------------------\n";
    mylist.removeAll();
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();

    cout << "\n----------------------------------------------\n";
    Patient p4("Akbar", "9130005555", "akbariii@gmail.com", "444444", "Ahvaz");
    Patient p5("Asghar", "91300003737", "asghariii@gmail.com", "444444", "Kerman");
    mylist.insert(p4);
    mylist.insert(p5); 
    mylist.insert(p1);
    mylist.insert(p2);
    mylist.insert(p3);
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();

    cout << "\n----------------------------------------------\n";
    cout << mylist.search(p2);
    cout << "Elements Count: " << mylist.getElementCount();

    cout << "\n----------------------------------------------\n";
    mylist.removeAll();
    mylist.printList();
    cout << "Elements Count: " << mylist.getElementCount();

    return 0;
}