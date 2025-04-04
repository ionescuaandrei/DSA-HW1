#include "Patient.h"
#include "list1.h"
#include <string>
using namespace std;

class HospitalManagementSystem {
private:
    LinkedList<Patient> beds;

public:
    void admitPatient(string& name, string& condition);
    void dischargePatient(int bedIndex);
    void transferPatient(int sourceBedIndex, int targetBedIndex);
    void displaySystem();
    string getPatientInfo(int bedIndex);
};

void HospitalManagementSystem::admitPatient(string& name, string& condition) {
    Patient p;
    p.name = name;
    p.condition = condition;
    beds.addLast(p);
}

void HospitalManagementSystem::displaySystem() {
    Node<Patient>* displayBed = beds.pfirst;
    int wardNumber = 0;
    int bedIndex = 0;
    while (displayBed != NULL) {
        if (bedIndex % 4 == 0) {
            // if (bedIndex > 0) {
                cout << endl;
                cout << "Ward"  << wardNumber << endl;
                wardNumber++;
            // }
        }
        cout << "Bed " << bedIndex << ": " << displayBed->info.name << " (" << displayBed->info.condition << ") ";
        displayBed = displayBed->next;
        bedIndex++;
    }
    cout << endl;
}

void HospitalManagementSystem::dischargePatient(int bedIndex) {
    int size = 0;
    Node<Patient>* current = beds.pfirst;
    while (current != NULL) {
        size++;
        current = current->next;
    }

    switch (size) {
        case 0:
            cout << "nothing to discharge" << endl;
        return;
        case 1:
            cout << "discharging the only patient" << endl;
        beds.removeAt(0);
        return;
        default:
            if (bedIndex < 0 || bedIndex >= size) {
                cout << "Invalid bed index" << endl;
                return;
            }
        cout << "discharging patient from bed " << bedIndex << endl;
        beds.removeAt(bedIndex);
    }
}

void HospitalManagementSystem::transferPatient(int sourceBedIndex, int targetBedIndex) {
    if (sourceBedIndex == targetBedIndex) return;

    Node<Patient>* sourceNode = beds.pfirst;
    for (int i = 0; sourceNode != NULL && i < sourceBedIndex; i++) {
        sourceNode = sourceNode->next;
    }
    if (!sourceNode) return;

    Patient patient = sourceNode->info;

    beds.removeAt(sourceBedIndex);

    if (sourceBedIndex < targetBedIndex) targetBedIndex--;

    beds.insertAt(targetBedIndex+1 , patient);
}

string HospitalManagementSystem::getPatientInfo(int bedIndex){
    Node<Patient>* bedInfo = beds.pfirst;
    for (int i = 0; bedInfo != NULL && i < bedIndex; i++) {
        bedInfo = bedInfo->next;
    }
    if (bedInfo == NULL) return "Invalid bed index";
    return "Name: " + bedInfo->info.name + ", Condition: " + bedInfo->info.condition;
}

