#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>  // for sleep

#include <curses.h>

#include "project.h"
#include "operations.h"

const char* optionSelect = "Select option: ";

void newLine() {
    printf("\n");
}

void printTitle() {
    mvprintw(0, 0, "Task Tracker");
}

int main() {
    int row, col;
    getmaxyx(stdscr, row, col);
    // start curses mode
    initscr();
    printTitle();

    // no need to press enter
    // raw();

    // enable reading of all keys not just alphanumeric
    keypad(stdscr, TRUE);
    // disable echoing of entered characters
    // noecho();

    // initialise project with no tasks
    project project;
    if (!initialiseProject(&project, "my-project")) {
        mvprintw(1, 0, "Could not initialise new project");
        return 1;
    }

    int ch;
    int ret = 0;
    while(ret == 0) {
        mvprintw(1, 0, optionSelect);
        ch = tolower(getch());

        switch(ch) {
            case 'a':
                ret = addtask(&project);
                break;
            case 'e':
                ret = edittask();
                break;
            case 'd':
                ret = deletetask();
                break;
            case 'l':
                ret = listtasks(&project);
                break;
            default:  // exit on all other input for now
                ret = 1;
                break;
        }
        // mvprintw(1, strlen(optionSelect), " ");  // replace input char with blank
        refresh();
    }

    clear();
    printTitle();
    mvprintw(2, 0, "Exiting...");
    refresh();
    sleep(1);  // actually give time for the message to display
    // end curses mode
    endwin();

    clearProject(&project);

    return 0;
}
