#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
};

Student HigestScoreOfStudent(const vector<Student>& students, int low, int high) {
    if (low == high) return students[low];
    int mid = (low + high) / 2;
    Student left = HigestScoreOfStudent(students, low, mid);
    Student right = HigestScoreOfStudent(students, mid + 1, high);
    return (left.score > right.score) ? left : right;
}

Student LowestScoreOfStudent(const vector<Student>& students, int low, int high) {
    if (low == high) return students[low]; 
    int mid = (low + high) / 2;
    Student left = LowestScoreOfStudent(students, low, mid);
    Student right = LowestScoreOfStudent(students, mid + 1, high);
    return (left.score < right.score) ? left : right;
}



int main() {
    vector<Student> students = { {"harsh", 95}, {"umang", 92}, {"jay", 88} };
    
    Student highest = HigestScoreOfStudent(students, 0, students.size() - 1);
    Student lowest = LowestScoreOfStudent(students, 0, students.size() - 1);

    cout << "Highest: " << " name : " << highest.name << endl;
    cout << " marks : " << highest.score << endl;
    cout << "Lowest: " << " name : " << lowest.name << endl;
    cout << " marks : " << lowest.score << endl;

    return 0;
}


