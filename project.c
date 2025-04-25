#include <curses.h>

#include "project.h"

// initialise empty project with size of 1 task
bool initialiseProject(project *proj, char* name) {
    proj->tasks = (task*)malloc(1 * sizeof(task));

    if (proj->tasks == NULL) {
        // TODO: probs don't use printw for this
        mvprintw(1, 0, "\nMemory allocation failed.");
        return false;
    }

    proj->count = 0;
    proj->capacity = 1;
    proj->name = name;

    return true;
}

// add task to dynamic array and resize if necessary
bool addTaskToProject(project *proj, task newTask) {
    if (proj->count == proj->capacity) {
        proj->capacity *= 2;
        proj->tasks = (task*)realloc(proj->tasks, proj->capacity * sizeof(task));
        if (proj->tasks == NULL) {
            // TODO: probs don't use printw for this
            mvprintw(1, 0, "\nResizing project failed.");
            return false;
        }
    }
    proj->tasks[proj->count] = newTask;
    proj->count++;
    return true;
}

void clearProject(project *proj) {
    free(proj->tasks);
    proj->tasks = NULL;
    proj->count = 0;
    proj->capacity = 0;
}
