
#include <iostream>
#include <string>
#include <vector> // ãÕÝæÝÉ ãÊØæÑÉ ãÑäÉ ÇáÍÌã

using namespace std;

 
   //Project: Smart Student Grading System
   


string calculateGrade(float average) {
    if (average >= 90) return "A (Excellent)";
    if (average >= 80) return "B (Very Good)";
    if (average >= 70) return "C (Good)";
    if (average >= 60) return "D (Pass)";
    return "F (Fail)";
}

int main() {
    int numSubjects;
    float totalSum = 0;

    cout << "   Academic Performance Tracker " << endl;
    cout << "How many subjects do you want to enter? ";
    cin >> numSubjects;

    float grades[numSubjects];

    for (int i = 0; i < numSubjects; i++) {
        cout << "Enter grade for subject " << i + 1 << ": ";
        cin >> grades[i];
        totalSum += grades[i];
    }

    float average = totalSum / numSubjects;

    cout << "\n---------- Academic Report ----------" << endl;
    cout << "Number of Subjects: " << numSubjects << endl;
    cout << "Average Percentage: " << average << "%" << endl;
    cout << "Final GPA Grade:    " << calculateGrade(average) << endl;
    cout << "-------------------------------------" << endl;

    if (average >= 60) {
        cout << "Message: Congratulations! Keep up the great work." << endl;
    } else {
        cout << "Message: Don't give up. Practice makes perfect!" << endl;
    }

    return 0;
}