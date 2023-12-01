#include "../headers/prompt.h"

string prompt::getSelection() const{
    return this->selection;
}

void prompt::setSelection(){
    

    string userChoice = "";
    getline(cin,userChoice);
    
    while (userChoice != "1" && userChoice != "2" && userChoice != "3" && userChoice != "4" && userChoice != "5" && userChoice != "6" && userChoice != "Task--"){ 
        cout << "INVALID INPUT: Please enter 1-6 or \"Task--\" to exit terminal: ";
        getline(cin,userChoice);
    }
        
    this->selection = userChoice;
}

void prompt::printMainMenu() {

    cout << "Task++" << endl;
    cout << "Select your option below (Number or Name)" << endl;
    cout << "1. New Task" << endl;
    cout << "2. New Task List" << endl;
    cout << "3. View Task Archive" << endl;
    cout << "4. New Upcoming Tasks" << endl;
    cout << "5. View Weekly Tasks" << endl;
    cout << "6.Reccomend Weekly Schedule" << endl;
    cout << "(Type \"Task--\" - to exit terminal)" << endl << endl;
    cout << "Please make your selection (Input corresponding numerical value): ";
    this->setSelection();
  
}

vector<string> prompt::newTaskPrompt(const Home* userHome) const {
    vector<string> userData;
    string title = "", desc = "", priority = "", dueDate = "", assignedDate = "";

    cout << "New Task" << endl << endl;

    cout << "Input Information as prompted!" << endl;
        
    cout << "Please enter the name of the new task: ";
    getline(cin, title);
    
    while(priority != "High" && priority != "Medium" && priority != "Low" && priority != "high" && priority != "medium" && priority != "low"){
        cout << "Please enter the priority of the new task (\"High\", \"Medium\",\"Low\"): ";
        getline(cin,priority);
    }

    do{
        cout << "Please enter the due date of the task in the format MM/DD/YY: "; //checks in input is in correct format at all the indices//
        getline(cin,dueDate);
    }while(dueDate.at(2) != '/' || dueDate.at(5) != '/' || !(isdigit(dueDate.at(0))) || !(isdigit(dueDate.at(1))) || !(isdigit(dueDate.at(3))) || !(isdigit(dueDate.at(4))) || !(isdigit(dueDate.at(6))) || !(isdigit(dueDate.at(7))));
    
    
    do{
        cout << "Please enter the assigned date of the task in the format MM/DD/YY: "; //checks in input is in correct format at all the indices//
        getline(cin,assignedDate);
    }while(assignedDate.at(2) != '/' || assignedDate.at(5) != '/' || !(isdigit(assignedDate.at(0))) || !(isdigit(assignedDate.at(1))) || !(isdigit(assignedDate.at(3))) || !(isdigit(assignedDate.at(4))) || !(isdigit(assignedDate.at(6))) || !(isdigit(assignedDate.at(7))));

    cout << "Please enter the description of the new task: ";
    getline(cin, desc);

    string assignToList = "";
    
    do{
        cout << "Please Enter Y for yes or N for no to assign task to a task list: ";
        getline(cin,assignToList);
    }while(assignToList != "Y" && assignToList != "N" && assignToList != "y" && assignToList != "n"); //checks if user properly enter y or n, to see if they want to assign it to a list//

    string userListChoice = "";
    if(assignToList == "Y"){ 

        userHome->viewLists(); //lists out existing task lists !!FIX NOT DISPLAYING!!
        cout << "Please select list: ";
        getline(cin,userListChoice);

        while(userHome->findTaskList(userListChoice) == nullptr){ //checks if list exist//
            cout << "Please select a existent list: "; 
            userHome->viewLists(); //lists out existing task lists !!FIX NOT DISPLAYING!!
            getline(cin,userListChoice);
        }
    }

    userData.push_back(title);
    userData.push_back(priority);
    userData.push_back(dueDate);
    userData.push_back(assignedDate);
    userData.push_back(desc);
    userData.push_back(userListChoice);
    

    return userData;
}

vector<string> prompt::newListPrompt() const { //WORKS//

    vector<string> userListData;

    string listTitle = "", listDescription = "", addTasks = "";
    cout << "New Task List" << endl << endl;

    cout << "Input Information as prompted!" << endl;

    cout << "Enter list name: ";
    getline(cin,listTitle);

    cout << "Enter list Description: ";
    getline(cin,listDescription);

    userListData.push_back(listTitle);
    userListData.push_back(listDescription);
    
   return userListData;
    
}

void prompt::taskEditorPrompt(TaskList* userList){ //UNTESTED//
    vector<string> userChanges;
    string targetTask = "", action = "", newVal = "";
    string choice = "";

    cout << "Task Editor" << endl;
    cout << "Edit your task below!" << endl;

    userList->viewTasks();

    cout << "Select a task to edit: ";
    getline(cin,targetTask);

    while(userList->findTask(targetTask) == nullptr){
        userList->viewTasks();
        cout << "Please enter valid task: ";
        getline(cin,targetTask);
    }
    
    cout << "1) " << userList->findTask(targetTask)->getName() << endl; //target task name//
    cout << "2) " << userList->findTask(targetTask)->getPriority() << endl; //target task priority//
    cout << "3) " << userList->findTask(targetTask)->getFullDueDate() << endl; //target task FULL due date//
    cout << "4) " << userList->findTask(targetTask)->getFullAssignedDate() << endl; //target task assigned date//
    cout << "5) " << userList->findTask(targetTask)->getDescription() << endl; //target task description//

    do{
        cout << "Please action of what you want to edit (enter numerical value): ";
        getline(cin,choice);
    }while(choice!= "1" && choice != "2" && choice != "3" && choice != "4" && choice !="5");

    if(choice =="1"){
        action = "Name";
        cout << "Enter new name: ";
        getline(cin,newVal); 

    }
    else if(choice =="2"){
        action = "Priority";
        do{
            cout << "Enter new priority(\"High\", \"Medium\",\"Low\"): "; //checks if valid priority//
            getline(cin,newVal);
        }while(newVal != "High" && newVal != "Medium" && newVal != "Low" && newVal != "high" && newVal != "medium" && newVal != "low");
        

    }
    else if(choice =="3"){
        action = "Full Due Date";

        do{
            cout << "Enter new date (format mm/dd/yy): ";
            getline(cin,newVal);
        }while(newVal.at(2) != '/' || newVal.at(5) != '/' || !(isdigit(newVal.at(0))) || !(isdigit(newVal.at(1))) || !(isdigit(newVal.at(3))) || !(isdigit(newVal.at(4))) || !(isdigit(newVal.at(6))) || !(isdigit(newVal.at(7))));

    }
    else if(choice =="4"){
        action = "Full Assigned Date";

        do{
            cout << "Enter new assigned date (format mm//dd/yy): ";
            getline(cin,newVal);
        }while(newVal.at(2) != '/' || newVal.at(5) != '/' || !(isdigit(newVal.at(0))) || !(isdigit(newVal.at(1))) || !(isdigit(newVal.at(3))) || !(isdigit(newVal.at(4))) || !(isdigit(newVal.at(6))) || !(isdigit(newVal.at(7))));
    }

    else if(choice == "5"){
        action = "Description";
        cout << "Enter new description: ";
        getline(cin,newVal);
    }
    
    userList->editTask(targetTask, action, newVal);
}

void prompt::listEditorPrompt(TaskList* userList){ //untested//
    string choice = "";
    string action = "";
    string payload = "";
    cout << "List Editor" << endl;
    cout << "Edit the List Below!" << endl;

    cout << "1) " << userList->getListName() << endl;
    cout << "2) " << userList->getListDescription() << endl;

    do{
        cout << "Please Type 1 to edit your list name or Type 2 to edit your list description: ";
        getline(cin,choice);
    }while(choice != "1" && choice != "2");

    if(choice == "1"){
        action = "Name";
        cout << "Enter new Title: ";
        getline(cin,payload);
    }
    else{
        action = "Description";
        cout << "Enter new description: ";
        getline(cin,payload);
    }

    userList->editL(userList->getListName(),action,payload);

}


void prompt::viewWeekly() const {
    //fill out with prompt


    // calls the function from weekly view class (outputs and calcs all days of week)
    // then this function will take input for if they want to select a task or back out
    // then this function will check if their task actually exists
    // then the user can choose to edit the task mark it as complete or delete the task
    // if they chose to edit then we call edit task prompt

}

void prompt::viewPriority() const{
    //fill out with prompt
}

