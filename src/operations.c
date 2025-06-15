#include <curses.h>

#include "operations.h"

int addtask(project *proj) {
    // use current window for now
    mvprintw(2, 0, "Adding a task...");
    refresh();
    mvprintw(3, 0, "Task name: ");
    char taskName[120];
    getstr(taskName);
    mvprintw(3, 0, NULL);
    refresh();
    // count + 1 because we know current count to use as basis for ID
    task newTask = {.project = proj->name, .id = proj->count + 1, .taskName = taskName};
    addTaskToProject(proj, newTask);
    return 0;
}

int edittask() {
    mvprintw(2, 0, "Editing a task...");
    return 0;
}

int deletetask() {
    mvprintw(2, 0, "Deleting a task...");
    return 0;
}

int listtasks(project *proj) {
    int printRow = 2;
    mvprintw(printRow, 0, "Listing tasks...");
    // TODO: deal with more rows than window size i.e. scrolling
    for (size_t i = 0; i < proj->count; ++i) {
        mvprintw(printRow*2 + i, 0, "%s %i", proj->tasks[i].project, proj->tasks[i].id);
    }
    refresh();
    return 0;
}
