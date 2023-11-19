#include "../headers/task.h"
#include <iostream>
#include <string>

using namespace std;

//Always construct a default task when user creates a task, then prompt them
//for imformation during new task screen... only fill in what they need
Task::Task(): name(""), description(""), priority(""), fullDueDate(""), fullAssignedDate(""), dueDay(-1), dueMonth(-1), dueYear(-1),
              assignedDay(-1), assignedMonth(-1), assignedYear(-1), completed(false) {}

void Task::setFullDueDate(string dueDate) {
    fullDueDate = dueDate;

    setDueMonth(stoi(dueDate.substr(0, 2)));
    setDueDay(stoi(dueDate.substr(3, 2)));
    setDueYear(stoi(dueDate.substr(6, 2)));
}

void Task::setFullAssignedDate(string assignedDate) {
    fullAssignedDate = assignedDate;

    setAssignedeMonth(stoi(assignedDate.substr(0, 2)));
    setAssignedDay(stoi(assignedDate.substr(3, 2)));
    setAssignedYear(stoi(assignedDate.substr(6, 2)));
}

void Task::switchCompleteStatus() {
    if (completed == false) {
        completed = true;
    } else if (completed == true) {
        completed = false;
    }
}

void Task::setList() {
    //temp filler
}
