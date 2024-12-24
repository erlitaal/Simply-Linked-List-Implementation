#include <iostream>
using namespace std;

// Define the structure for an assignment (task)
struct Assignment {
    string subject;  // The name of the assignment (subject)
    Assignment* next;  // Pointer to the next assignment in the linked list
};

// Function to add a new task at the end of the list
void addAtEnd(Assignment*& head, string subject) {
    // Create a new assignment node
    Assignment* newAssignment = new Assignment();
    newAssignment->subject = subject;
    newAssignment->next = nullptr;

    // If the list is empty, the new assignment becomes the head
    if (head == nullptr) {
        head = newAssignment;
    } else {
        // If the list is not empty, find the last node and add the new task there
        Assignment* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newAssignment;
    }
}

// Function to display all tasks in the list
void showAll(Assignment* head) {
    if (head == nullptr) {
        // If the list is empty, display "No tasks"
        cout << "No tasks." << endl;
        return;
    }

    // Traverse the list and display each task
    Assignment* temp = head;
    int number = 1;
    while (temp != nullptr) {
        cout << number << ". " << temp->subject << endl;  // Display task number and subject
        temp = temp->next;  // Move to the next task in the list
        number++;  // Increment task number
    }
}

// Function to delete a task by its number in the list
void deleteSubject(Assignment*& head, int number) {
    // If the list is empty, print a message and return
    if (head == nullptr) {
        cout << "The task list is empty." << endl;
        return;
    }

    // If the task to be deleted is the first task (head of the list)
    if (number == 1) {
        Assignment* temp = head;  // Store the current head node
        head = head->next;  // Move the head to the next task
        delete temp;  // Delete the original head task
        cout << "Task number 1 has been deleted." << endl;
        showAll(head);  // Display the updated list
        return;
    }

    // Traverse the list to find the task before the one to be deleted
    Assignment* temp = head;
    int count = 1;
    while (temp != nullptr && count < number - 1) {
        temp = temp->next;  // Move to the next task
        count++;  // Increment the counter
    }

    // If the task number is invalid or the task is not found
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Task number " << number << " not found!" << endl;
        return;
    }

    // Delete the task and update the list
    Assignment* delAssignment = temp->next;  // Store the task to be deleted
    temp->next = temp->next->next;  // Link the previous task to the next task
    delete delAssignment;  // Delete the task
    cout << "Task number " << number << " has been deleted." << endl;
    showAll(head);  // Display the updated list
}

int main() {
    Assignment* head = nullptr;  // Initialize the head of the list to nullptr

    // Adding initial tasks to the list
    addAtEnd(head, "Calculus I");
    addAtEnd(head, "Basic Physics");
    addAtEnd(head, "Basic Programming");

    // Display the current task list
    cout << "Task List :" << endl;
    showAll(head);

    // Prompt user to add new tasks
    string newTask;
    cout << "Enter a new task to add (or type 'exit' to stop) : ";
    while (true) {
        cin >> newTask;  // Get the new task input from the user
        if (newTask == "exit") break;  // If the user types 'exit', stop adding tasks
        addAtEnd(head, newTask);  // Add the task to the list
        
        // Display the updated list after adding a new task
        cout << "Task List After Adding New Task : " << endl;
        showAll(head);
        cout << "Enter another task to add (or type 'exit' to stop) : ";
    }

    // Prompt user to delete a task by its number
    int choice;
    cout << "Enter the task number you want to delete (or type -1 to stop) : ";
    while (true) {
        cin >> choice;  // Get the task number input from the user
        if (choice == -1) break;  // If the user types -1, stop deleting tasks
        deleteSubject(head, choice);  // Delete the task with the specified number
    }

    // Display the final task list after deletion
    cout << "Task List After Deleting Tasks :";
    showAll(head);

    return 0;  // Return 0 to indicate successful execution
}
