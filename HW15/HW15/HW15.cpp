#include "funcs.h"

int main()
{
    const int arraySize = 5;
    Student students[arraySize];

    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::cin >> students[i].name;

        std::cout << "Enter grades for " << students[i].name << " (4 grades): ";
        for (int j = 0; j < 4; ++j) 
        {
            std::cin >> students[i].marks[j];
        }
    }

    int choice;
    do
    {
        printMenu();
        std::cout << "Enter your choice (0-3): ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Number of students with average grade > 75%: " << countStudentsAboveAverage(students, arraySize) << "\n";
            break;
        case 2:
        {
            Student* topStudent = getTopStudent(students, arraySize);
            std::cout << "Top-performing student: " << topStudent->name << " with an average grade of " << calculateAverage(*topStudent) << "\n";
            break;
        }
        case 3:
            sortStudentsByAverage(students, arraySize);
            std::cout << "Sorted students by average grade:\n";
            for (int i = 0; i < arraySize; ++i)
            {
                std::cout << students[i].name << ": " << calculateAverage(students[i]) << "\n";
            }
            break;
        case 0:
            std::cout << "Exiting the program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
    while (choice != 0);

    return 0;
}