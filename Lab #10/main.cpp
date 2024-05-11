//
//  main.cpp
//  Lab #10
//
//  Created by Bi Rong Liu on 5/9/24.
//
/*
 The history teacher at your school needs help in grading a True/False test. The students’ IDs and test answers are stored in a file. The first entry in the file contains answers to the test in the form:

 TFFTFFTTTTFFTFTFTFTT

 Every other entry in the file is the student ID, followed by a blank, followed by the student’s responses. For example, the entry:

 ABC54301 TFTFTFTT TFTFTFFTTFT

 indicates that the student ID is ABC54301 and the answer to question 1 is True, the answer to question 2 is False, and so on. The space in the student response indicates that the student did not answer question 9. The exam has 20 questions, and the class has more than 15 students. Each correct answer is awarded two points, each wrong answer gets one point deducted, and no answer gets zero points. Write a program that processes the test data. The output should be the student’s ID, followed by the answers, followed by the test score, followed by the test grade. Assume the following grade scale: 90%–100%, A; 80%–89.99%, B; 70%–79.99%, C; 60%–69.99%, D; and 0%–59.99%, F.


 Use dynamic array to implement the code.
 */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Function to calculate the score based on correct answers and student's answers

struct StudentTest {
    string id;
    double score;
    char grade;
};
int populateAnswerArray(char* &answersKeys, ifstream &inputFile);
int getSizeOfStudentArray(StudentTest* &students, ifstream &inputFile);
double calucateScore(string studentAnswers, char* &answerKeys, int answerKeySize);
void buildGrade(ifstream &inputFile, StudentTest* &students,  char* &answerKeys, int answerSize, int studentSize);
char calculateGrade(double score);

int main() {
    ifstream inputFile;
    inputFile.open("data.txt");
    if (!inputFile) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }
    char *answerKeys = nullptr;
    StudentTest *students = nullptr;
    int answerSize = populateAnswerArray(answerKeys, inputFile);
    int studentSize = getSizeOfStudentArray(students, inputFile);
    buildGrade(inputFile, students, answerKeys, answerSize, studentSize);
    for(int i = 0; i < studentSize; i++) {
        cout << "Id=" << students[i].id << " Grade= " << students[i].grade << " Score=" << students[i].score << endl;
    }
    delete[] answerKeys;
    delete[] students;
    return 0;
}

void buildGrade(ifstream &inputFile, StudentTest* &students,  char* &answerKeys, int answerSize, int studentSize) {
    inputFile.ignore(answerSize);
    string content;
    int index = 0;
    while(getline(inputFile, content) && index < studentSize) {
        string id = content.substr(0, content.find(" "));
        string answers = content.substr(content.find(" ") + 1);
        double score = calucateScore(answers, answerKeys, answerSize);
        students[index].id = id;
        students[index].grade = calculateGrade(score);
        students[index].score = score;
        index++;
    }
}

double calucateScore(string studentAnswers, char* &answerKeys, int answerKeySize) {
    double result = 0;
    for(int i = 0; i < answerKeySize; i++) {
        if(studentAnswers[i] == answerKeys[i]) {
            result+=2;
        } else if(studentAnswers[i] != answerKeys[i]) {
            result-=1;
        }
    }
    return result;
}
char calculateGrade(double score) {
    double percentage = (double)score / 40 * 100; // Max score is 40
    if (percentage >= 90) return 'A';
    if (percentage >= 80) return 'B';
    if (percentage >= 70) return 'C';
    if (percentage >= 60) return 'D';
    return 'F';
}
int getSizeOfStudentArray(StudentTest* &students, ifstream &inputFile) {
     string content;
     int count = 0;
     while (getline(inputFile, content)) count++;
     students = new StudentTest[count];
     inputFile.clear();
     inputFile.seekg(0);
     return count - 1;
}

int populateAnswerArray(char* &answersKeys, ifstream &inputFile) {
    char recurrence;
    int recurrenceCount = 0;
    while(inputFile.get(recurrence)) {
        if(recurrence == '\n') break;
        recurrenceCount++;
    }
    answersKeys = new char[recurrenceCount];
    inputFile.clear();
    inputFile.seekg(0);
    for(int i = 0; i < recurrenceCount; i++) {
        inputFile.get(answersKeys[i]);
    }
    return recurrenceCount + 1;
}

