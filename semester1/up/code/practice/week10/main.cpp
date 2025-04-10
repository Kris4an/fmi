#include <iostream>
#include <cmath>
#include <fstream>
#include "Point.h"
#include "Time.h"
#include "Student.h"


void zad1(Point a, Point b){
    std::cout<<(sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
}
void zad2(){
    Time t1 {41, 59, 2};
    Time t2 {2, 0, 1};
    std::cout<<(t1.difference(t2));
}
int main(){
    //zad1(Point {0,0}, Point {3,4});
    std::ifstream inFile("students.txt");
    
    if(!inFile){
        std::cout<<"Could not open file!";
        return 1;
    }

    int size;
    char buffer[100];
    while (inFile.getline(buffer, 100))
    {
        ++size;
    }
    
    inFile.seekg(0, std::ios::beg);

    std::cout<<size<<'\n';

    Student** students = new Student*[size];

    for(int i = 0; i < size; ++i){
        char id;
        inFile>>id;
        std::cout<<"id: "<<id;
        double ag;
        inFile>>ag;
        std::cout<<"ag " <<ag;

        
        Student s (id, ag);
        students[i] = &s;
    }

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size-i-1; ++j){
            if(students[j]->averageGrade < students[j+1]->averageGrade){
                Student* temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < size; ++i){
        students[i]->print();
    }
}