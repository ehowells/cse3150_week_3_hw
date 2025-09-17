
#include <iostream>
#include <cstring>   // for strlen, strcpy

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
    if (size == capacity) {
        throw std::string("List full");
    } else {
        names[size] = new char[strlen(name) + 1];
        std::strcpy(names[size], name);
        gpas[size] = gpa;
        ++size;
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

double averageGPA(const double gpas[], int size) {
    if (size == 0) {
        throw std::string("No students");
    } else {
        double sum = 0;
        for(int i = 0; i <= size; ++i) {
            sum += gpas[i];
        }
        return sum / size;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

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
                    addStudent(temp, gpa, names, gpas, size, capacity);
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2: {
                int index, newGpa;
                std::cout << "Enter index: ";
                std::cin >> index;
                if (index >= 0 && index < size) {
                    std::cout << "Enter new GPA: ";
                    std::cin >> newGpa;
                    updateGPA(&gpas[index], newGpa);
                } else {
                    std::cout << "Invalid index" << std::endl;
                }
                break;
            }
            case 3: {
                // TODO: implement menu logic
                break;
            }
            case 4: {
                // TODO: implement menu logic
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

    for(int i = 0; i < size; ++i) {
        delete[] names[i];
    }

    return 0;
}