#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

void displayMenu();
void addTask(vector<string> &tasks, const string &task);
void viewTasks(const vector<string> &tasks);
void deleteTask(vector<string> &tasks, int index);
void loadTasks(vector<string> &tasks);
void saveTasks(const vector<string> &tasks);

int main()
{
    vector<string> tasks;
    int choice = 0;
    int taskNumber = 0;
    string task;
    loadTasks(tasks);

    displayMenu();

    while (true)
    {

        cout << "\nEnter your choice: ";
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            cout << "Enter task : ";
            getline(cin, task);
            if (task.empty())
            {
                cout << "Task cannot be empty." << endl;
            }
            else
            {
                addTask(tasks, task);
                saveTasks(tasks);
            }
            break;
        }

        case 2:
        {
            viewTasks(tasks);
            break;
        }

        case 3:
        {
            cout << "Enter task number : ";
            if (!(cin >> taskNumber))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number." << endl;
                continue;
            }
            cin.ignore();
            deleteTask(tasks, taskNumber);
            saveTasks(tasks);
            break;
        }

        case 4:
        {
            cout << "Exiting the task management system. Goodbye!" << endl;
            return 0;
        }

        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
    return 0;
}

void displayMenu()
{
    cout << "Welcome to the task management system" << endl;
    cout << "\nPlease select an option from the menu below: " << endl;
    cout << "1. Add a task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete a task" << endl;
    cout << "4. Exit" << endl;
}

//<-----------------Task adding function----------------->

void addTask(vector<string> &tasks, const string &task)
{
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}

//<-----------------Task viewing function----------------->

void viewTasks(const vector<string> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "Current tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

//<-----------------Task deleting function----------------->

void deleteTask(vector<string> &tasks, int index)
{
    if (index < 1 || index > static_cast<int>(tasks.size()))
    {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task deleted successfully!" << endl;
}

//<-----------------Task loading function----------------->

void loadTasks(vector<string> &tasks)
{
    ifstream file("tasks.txt");
    string line;
    while (getline(file,line))
    {
        if (!line.empty())
        {
            tasks.push_back(line);
        }
    }
}

//<-----------------Task saving function----------------->

void saveTasks(const vector<string> &tasks)
{
    ofstream file("tasks.txt");
    for (const auto &task : tasks)
    {
        file << task << endl;
    }
}