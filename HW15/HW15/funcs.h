#pragma once

#include <iostream>
#include <algorithm>

struct Student
{
    std::string name;
    int marks[4];
};

struct Student;

double calculateAverage(const Student& student);

void sortStudentsByAverage(Student students[], int size);

Student* getTopStudent(Student students[], int size);

int countStudentsAboveAverage(Student students[], int size);

void printMenu();
