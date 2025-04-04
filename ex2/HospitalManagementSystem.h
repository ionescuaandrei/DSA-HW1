#ifndef HOSPITALMANAGEMENTSYSTEM_H
#define HOSPITALMANAGEMENTSYSTEM_H

#include "Patient.h"
#include "../ds/list1.h"
#include <string>
using namespace std;

class HospitalManagementSystem {
    private:
        LinkedList<Patient> beds;

    public:
        void addPatient(string& name, string& condition);
        void dischargePatient(int bedIndex);
        void transferPatient(int sourceBedIndex, int targetBedIndex);
        void displaySystem();
        string getPatientInfo(int bedIndex);
};

void HospitalManagementSystem::addPatient(string& name, string& condition) {
    Patient p;
    p.name = name;
    p.condition = condition;
    beds.addFirst(p);
}

void HospitalManagementSystem::displaySystem() {
    Node<Patient>* paux = beds.pfirst;
    while (paux != NULL) {
        cout << "Name: " << paux->info.name << ", Condition: " << paux->info.condition << endl;
        paux = paux->next;
    }
}

