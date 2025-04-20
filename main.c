#include <stdio.h>
#include <ctype.h>
#include <unistd.h>  // for sleep

#include <curses.h>

#include "operations.h"


struct task {
    char* project;
    unsigned int id;
};

void newLine() {
    printf("\n");
}

int main() {
    // struct task myTask = { .project = "test-project", .id = 1 };
    // printw("Task created from project %s with id %i.", myTask.project, myTask.id);

    int ch;

    // initialise with no tasks
    struct task taskArray[0];

    // start curses mode
    initscr();
    printw("Task Tracker\n");

    // Initialise input stuff
    // no need to press enter
    // raw();

    // enable reading of all keys not just alphanumeric
    keypad(stdscr, TRUE);
    // noecho();
    bool exit = false;
    while(!exit) {
        printw("\nSelect option: ");
        ch = tolower(getch());

        int ret = 0;

        switch(ch) {
            case 'a':
                printw("\nAdding new task...");
                ret = addtask();
                break;
            case 'e':
                printw("\nEditing existing task...");
                ret = edittask();
                break;
            case 'd':
                printw("\nDeleting task...");
                ret = deletetask();
                break;
            case 'l':
                printw("\nListing all tasks...");
                ret = listtasks();
                break;
            default:  // exit on all other input for now
                exit = true;
                break;
        }

        refresh();
    }

    printw("\nExiting...");
    refresh();
    sleep(1);  // actually give time for the message to display
    // end curses mode
    endwin();

    return 0;
}
