
#include <iostream>
#include <cstring>   // for strlen, strcpy
#include <vector>

void addStudent(char* name, double gpa, std::vector<char*>& names, std::vector<double>& gpas, int capacity) {
    if (names.size() == capacity) {
        throw "List full";
    } else {
        char* newName = new char[strlen(name) + 1];
        std::strcpy(newName, name);
        names.push_back(newName);
        gpas.push_back(gpa);
    }
}

void updateGPA(double* gpaPtr, double newGpa) {
    if (gpaPtr != nullptr) {
        *gpaPtr = newGpa;
    }
}

void printStudent(const char* name, const double& gpa) {
    std::cout << "Name: " << name << ", GPA: " << gpa << std::endl; 
}

double averageGPA(const std::vector<double>& gpas) {
    if (gpas.empty()) {
        throw "No students";
    } else {
        double sum = 0;
        for(int i = 0; i < gpas.size(); ++i) {
            sum += gpas[i];
        }
        return sum / gpas.size();
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    std::vector<char*> names;
    std::vector<double> gpas;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                char temp[100];
                double gpa;
                std::cout << "Enter name: ";
                std::cin >> temp;

                std::cout << "Enter GPA: ";
                std::cin >> gpa;

                try {
                    addStudent(temp, gpa, names, gpas, capacity);
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2: {
                int index;
                double newGpa;
                std::cout << "Enter index: ";
                std::cin >> index;
                if (index >= 0 && index < gpas.size()) {
                    std::cout << "Enter new GPA: ";
                    std::cin >> newGpa;
                    updateGPA(&gpas[index], newGpa);
                } else {
                    std::cout << "Invalid index" << std::endl;
                }
                break;
            }
            case 3: {
                for (int i = 0; i < names.size(); i++) {
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                try {
                    double avg = averageGPA(gpas);
                    std::cout << "Average GPA = " << avg 
                              << " (int = " << static_cast<int>(avg) << ")" 
                              << std::endl;
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    for(int i = 0; i < names.size(); ++i) {
        delete[] names[i];
    }

    return 0;
}