#include <stdio.h>
#include<stdlib.h>
#define MAX 99

typedef struct {
	char FName[20];
	char LName[20];
}StudName;

typedef struct {
	int month;
	int year;
}bday;

typedef struct{
	StudName name;
	bday birthdate;
	int age;
	int idNum;
}studentInfo;

typedef struct {
	studentInfo studList [20];
	int studCount;
}classRecord;

void insertFirst(classRecord *record, studentInfo student) {
    if (record->studCount < 20) {
        for (int i = record->studCount; i > 0; i--)
            record->studList[i] = record->studList[i - 1];
        record->studList[0] = student;
        record->studCount++;
    } else {
        printf("Class record is full. Cannot insert.\n");
    }
}

void insertLast(classRecord *record, studentInfo student) {
    if (record->studCount < 20) {
        record->studList[record->studCount++] = student;
    } else {
        printf("Class record is full. Cannot insert.\n");
    }
}

void insertAtIndex(classRecord *record, studentInfo student, int index) {
    if (index >= 0 && index <= record->studCount && record->studCount < 20) {
        for (int i = record->studCount; i > index; i--)
            record->studList[i] = record->studList[i - 1];
        record->studList[index] = student;
        record->studCount++;
    } else {
        printf("Invalid index or class record is full. Cannot insert.\n");
    }
}

void insertSorted(classRecord *record, studentInfo student){
    if (record->studCount == 0 || student.age > record->studList[record->studCount - 1].age){
        insertLast(record, student);
    } else {
        int i = 0;
        while (i < record->studCount && student.age > record->studList[i].age)
            i++;
        insertAtIndex(record, student, i);
    }
}

void deleteFirst(classRecord *record) {
    if (record->studCount > 0) {
        for (int i = 0; i < record->studCount - 1; i++)
            record->studList[i] = record->studList[i + 1];
        record->studCount--;
    } else {
        printf("Class record is empty. Cannot delete.\n");
    }
}
void deleteLast(classRecord *record) {
    if (record->studCount > 0) {
        record->studCount--;
    } else {
        printf("Class record is empty. Cannot delete.\n");
    }
}


int main (){
    
    classRecord record;
    record.studCount = 0;
    
    studentInfo student1 = {{"Rob", "Blox"}, {10, 2000}, 24, 1001};
    studentInfo student2 = {{"Sam", "Smith"}, {20, 2001}, 230, 1002};
    studentInfo student3 = {{"Jaden", "Smith"}, {17, 1999}, 25, 1003};
    studentInfo student4 = {{"Tony", "Stark"}, {4, 2002}, 23, 1004};
    
    insertFirst(&record, student1);
    insertSorted(&record, student2);
    insertSorted(&record, student3);
    insertSorted(&record, student4);
    
    printf("Class record after insertions:\n");
    for (int i = 0; i < record.studCount; i++) {
        printf("Student %d: %s %s (Age: %d)\n", i + 1, record.studList[i].name.FName, record.studList[i].name.LName, record.studList[i].age);
    }
    
    deleteFirst(&record);
    deleteLast(&record);
    
    printf("\nClass record after deletions:\n");
    for (int i = 0; i < record.studCount; i++) {
        printf("Student %d: %s %s (Age: %d)\n", i + 1, record.studList[i].name.FName, record.studList[i].name.LName, record.studList[i].age);
    }
    
    return 0;
    
}
