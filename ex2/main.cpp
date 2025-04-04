#include <iostream>
#include "HospitalManagementSystem.h"
#include "Patient.h"
using namespace std;

int main() {
    HospitalManagementSystem hms;
    string name, condition;

    name = "John Doe";
    condition = "Flu";
    hms.addPatient(name, condition);

    name = "Jane Smith";
    condition = "Headache";
    hms.addPatient(name, condition);

    cout << "Current patients in the system:" << endl;
    hms.displaySystem();

    return 0;
}
