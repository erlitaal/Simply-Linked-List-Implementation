#include <iostream>
using namespace std;

// Define a structure for the Assignment node in the linked list
struct Assignment {
    string subject;         // Stores the name of the subject (task)
    Assignment* next;       // Pointer to the next assignment in the list
};

// Function to add a new assignment at the end of the list
void addAtEnd(Assignment*& head, string subject) {
    // Create a new assignment node and assign the subject value
    Assignment* newAssignment = new Assignment();
    newAssignment->subject = subject;
    newAssignment->next = nullptr; // The new assignment will point to nothing initially

    // If the list is empty, make the new assignment the head
    if (head == nullptr) {
        head = newAssignment;
    } else {
        // Traverse the list to find the last assignment
        Assignment* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Link the last assignment to the new assignment
        temp->next = newAssignment;
    }
}

// Function to display all assignments in the list
void showAll(Assignment* head) {
    // If the list is empty, display a message
    if (head == nullptr) {
        cout << "No tasks." << endl;
        return;
    }
    // Otherwise, traverse the list and display each task
    Assignment* temp = head;
    int number = 1;
    while (temp != nullptr) {
        cout << number << ". " << temp->subject << endl;  // Display task number and subject
        temp = temp->next;  // Move to the next assignment
        number++;  // Increment the task number
    }
}
// Function to delete a specific assignment by its number
void deleteSubject(Assignment*& head, int number) {
    // Check if the list is empty
    if (head == nullptr) {
        cout << "The task list is empty." << endl;
        return;
    }
    // If the task to delete is the first task
    if (number == 1) {
        Assignment* temp = head;
        head = head->next;  // Move the head pointer to the next task
        delete temp;  // Delete the original first task
        cout << "Task number 1 has been deleted." << endl; // Display task number 1 has been deleted
        cout << "Task List After Deleting Tasks :" << endl; // Display task list after deleting tasks
        showAll(head);  // Show the updated task list
        return;
    }
    // Traverse the list to find the task at the specified number
    Assignment* temp = head;
    int count = 1;
    while (temp != nullptr && count < number - 1) {
        temp = temp->next;  // Move to the next task
        count++;
    }

    // If the task doesn't exist (either out of bounds or invalid number)
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Task number " << number << " not found!" << endl;
        return;
    }

    // Delete the task at the given number
    Assignment* delAssignment = temp->next;
    temp->next = temp->next->next;  // Link the previous task to the one after the deleted task
    delete delAssignment;  // Free memory of the deleted task

    cout << "Task number " << number << " has been deleted." << endl;
    cout << "Task List After Deleting Tasks :" << endl;
    showAll(head);  // Show the updated task list
}

// Main function to manage the tasks
int main() {
    // Initialize the head of the assignment list to nullptr
    Assignment* head = nullptr;

    // Adding some initial tasks to the list
    addAtEnd(head, "Calculus I");
    addAtEnd(head, "Basic Physics");
    addAtEnd(head, "Basic Programming");

    // Display the current task list
    cout << "Task List :" << endl;
    showAll(head);

    string newTask;
    // Allow the user to add tasks interactively
    cout << "Enter a new task to add (or type 'exit' to stop) : ";
    while (true) {
        cin >> newTask;  // Read user input for the task
        if (newTask == "exit") break;  // If user types "exit", stop adding tasks
        addAtEnd(head, newTask);  // Add the new task to the list
        
        // Show the updated list after adding the task
        cout << "Task List After Adding New Task :" << endl;
        showAll(head);
        cout << "Enter another task to add (or type 'exit' to stop) : ";
    }

    int choice;
    // Allow the user to delete tasks interactively by specifying their number
    cout << "Enter the task number you want to delete (or type -1 to stop) : ";
    while (true) {
        cin >> choice;  // Read user input for the task number
        if (choice == -1) break;  // If user types -1, stop deleting tasks
        deleteSubject(head, choice);  // Delete the specified task
    }

    // Display the final task list after deletions
    cout << "Task List After Deleting Tasks :";
    showAll(head);

    return 0;
}
