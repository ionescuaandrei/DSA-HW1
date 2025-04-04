#include <iostream>
#include "HospitalmanagementSystem.h"
using namespace std;

int main() {
    HospitalManagementSystem hms;
    string name, condition;
    name = "Sergiu";
    condition = "Pneumonia";
    hms.admitPatient(name, condition);
    name = "Rares";
    condition = "broken";
    hms.admitPatient(name, condition);
    hms.displaySystem();
    cout << hms.getPatientInfo(0) << endl;
    hms.dischargePatient(0);
    hms.transferPatient(1,3);
    hms.displaySystem();
    // name = "Maria";
    // condition = "Fever";
    // hms.admitPatient(name, condition);
    // name = "John";
    // condition = "Headache";
    // hms.admitPatient(name, condition);
    // name = "Anna";
    // condition = "Flu";
    // hms.admitPatient(name, condition); // Fifth patient (starts Ward 1)


    //
    //
    // std::cout<< "\n===== Discharge Patient =====" << std::endl;
    //
    // hms.dischargePatient(3); // Remove Maria (index 2)
    //
    // hms.displaySystem();
    //
    // std::cout << "\n===== Get Info =====" << std::endl;
    // cout << hms.getPatientInfo(1) << endl;
    //
    // std::cout << "===== Initial System =====" << std::endl;
    // hms.displaySystem();
    //
    // // Test 1: Transfer from index 1 (Rares) to index 3 (John's position)
    // hms.transferPatient(1, 3);
    // std::cout << "\n===== After Transfer (1 -> 3) =====" << std::endl;
    // hms.displaySystem();
    //
    //
    //
    //
    // // Test 2: Transfer last patient (Anna at index 4) to index 0
    // hms.transferPatient(4, 0);
    // std::cout << "\n===== After Transfer (4 -> 0) =====" << std::endl;
    // hms.displaySystem();
    //
    // // Edge Case: Transfer to same index (no change)
    // hms.transferPatient(2, 2);
    // std::cout << "\n===== After Transfer (2 -> 2) =====" << std::endl;
    // hms.displaySystem();


    return 0;
}
