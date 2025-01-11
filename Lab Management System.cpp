#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Department {
    string dept_code;
    string dept_name;
};

struct Laboratory {
    string lab_code;
    string lab_name;
    string dept_code;
};

struct Equipment {
    string equip_code;
    string equip_brand;
    string equip_type;
    string lab_code;
};

void addDepartment(vector<Department>& departments) {
    Department dept;
    cout << "Enter Department Code: ";
    cin >> dept.dept_code;
    cout << "Enter Department Name: ";
    cin.ignore();    
    getline(cin, dept.dept_name);
    departments.push_back(dept);
    cout << "Department added successfully.\n";
}  

void listDepartments(const vector<Department>& departments) {
    cout << "\nDepartments:\n";
    for (const auto& dept : departments) {
        cout << "Code: " << dept.dept_code << ", Name: " << dept.dept_name << endl;
    }
}


void addLaboratory(vector<Laboratory>& laboratories, const vector<Department>& departments) {
    Laboratory lab;
    cout << "Enter Lab Code: ";
    cin >> lab.lab_code;
    cout << "Enter Lab Name: ";
    cin.ignore();
    getline(cin, lab.lab_name);

    cout << "Enter Department Code for this Lab: ";
    cin >> lab.dept_code;

    bool deptFound = false;
    for (const auto& dept : departments) {
        if (dept.dept_code == lab.dept_code) {
            deptFound = true;
            break;
        }
    }

    if (deptFound) {
        laboratories.push_back(lab);
        cout << "Laboratory added successfully.\n";
    } else {
        cout << "Department not found. Laboratory not added.\n";
    }
}


void listLaboratories(const vector<Laboratory>& laboratories, const vector<Department>& departments) {
    cout << "\nLaboratories:\n";
    for (const auto& lab : laboratories) {
        string deptName;
        for (const auto& dept : departments) {
            if (dept.dept_code == lab.dept_code) {
                deptName = dept.dept_name;
                break;
            }
        }
        cout << "Lab Code: " << lab.lab_code << ", Lab Name: " << lab.lab_name << ", Department: " << deptName << endl;
    }
}

void addEquipment(vector<Equipment>& equipmentList, const vector<Laboratory>& laboratories) {
    Equipment equip;
    cout << "Enter Equipment Code: ";
    cin >> equip.equip_code;
    cout << "Enter Equipment Brand: ";
    cin.ignore();
    getline(cin, equip.equip_brand);
    cout << "Enter Equipment Type (e.g., Computer, Printer): ";
    getline(cin, equip.equip_type);
    
    cout << "Enter Lab Code to associate with this equipment: ";
    cin >> equip.lab_code;

    bool labFound = false;
    for (const auto& lab : laboratories) {
        if (lab.lab_code == equip.lab_code) {
            labFound = true;
            break;
        }
    }

    if (labFound) {
        equipmentList.push_back(equip);
        cout << "Equipment added successfully.\n";
    } else {
        cout << "Lab not found. Equipment not added.\n";
    }
}

int main() {
   vector<Department> departments;
   vector<Laboratory> laboratories;
   vector<Equipment> equipmentList;
    
    int choice;
    do {
        cout << "\nLab Management System\n";
        cout << "1. Department Management\n";
        cout << "2. Laboratory Management\n";
        cout << "3. Equipment Management\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
             
                int deptChoice;
                cout << "\nDepartment Management\n";
                cout << "1. Add Department\n";
                cout << "2. List Departments\n";
                cout << "Enter your choice: ";
                cin >> deptChoice;
                if (deptChoice == 1) addDepartment(departments);
                else if (deptChoice == 2) listDepartments(departments);
                break;
            
            case 2:
                
                int labChoice;
                cout << "\nLaboratory Management\n";
                cout << "1. Add Laboratory\n";
                cout << "2. List Laboratories\n";
                cout << "Enter your choice: ";
                cin >> labChoice;
                if (labChoice == 1) addLaboratory(laboratories, departments);
                else if (labChoice == 2) listLaboratories(laboratories, departments);
                break;

            case 3:
            
                int equipChoice;
                cout << "\nEquipment Management\n";
                cout << "1. Add Equipment\n";
                cout << "Enter your choice: ";
                cin >> equipChoice;
                if (equipChoice == 1) addEquipment(equipmentList, laboratories);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}