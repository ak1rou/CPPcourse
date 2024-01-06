#include "funcs.h"

double calculateAverage(const Student& student)
{
    int sum = 0;
    for (int i = 0; i < kNumGrades; ++i)
    {
        sum += student.marks[i];
    }
    return static_cast<double>(sum) / kNumGrades;
}

void sortStudentsByAverage(Student students[], int size)
{
    std::sort(students, students + size, [](const Student& a, const Student& b)
        {
            return calculateAverage(a) > calculateAverage(b);
        });
}

Student* getTopStudent(Student students[], int size)
{
    if (size == 0)
    {
        return nullptr;
    }

    double topAverage = calculateAverage(students[0]);
    Student* topStudent = &students[0];

    for (int i = 1; i < size; ++i)
    {
        double currentAverage = calculateAverage(students[i]);
        if (currentAverage > topAverage)
        {
            topAverage = currentAverage;
            topStudent = &students[i];
        }
    }

    return topStudent;
}

int countStudentsAboveAverage(Student students[], int size, double threshold)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (calculateAverage(students[i]) > threshold)
        {
            ++count;
        }
    }
    return count;
}

void printMenu()
{
    std::cout << "\nMenu:\n";
    std::cout << "1. Count students with average grade > 75%\n";
    std::cout << "2. Get information about the top-performing student\n";
    std::cout << "3. Sort students by average grade\n";
    std::cout << "0. Exit\n";
}
