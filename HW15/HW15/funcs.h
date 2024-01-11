#pragma once

#include <iostream>
#include <algorithm>

const int kNumGrades = 4;

struct Student
{
    std::string name;
    int marks[kNumGrades];
    Student() : marks{} {}
};

struct Student;

double calculateAverage(const Student& student);

void sortStudentsByAverage(Student students[], int size);

Student* getTopStudent(Student students[], int size);

int countStudentsAboveAverage(Student students[], int size, double threshold = 75.0);

void printMenu();