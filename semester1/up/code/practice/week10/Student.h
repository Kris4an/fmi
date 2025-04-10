#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
    int id;
    double averageGrade;

    Student() :id(-1), averageGrade(0) {}
    Student(int i, double ag) : id(i) {
        if(ag < 2 || ag > 6 || id<0){
            std::cout<<ag<<'\n';
            throw std::invalid_argument("Bad grade");
        }
        averageGrade = ag;
    }

    void print(){
        std::cout<<"id: "<<id<<", average grade: "<<averageGrade<<'\n';
    }
};


#endif