#ifndef _PROJECT_H
#define _PROJECT_H

#include <stdbool.h>
#include <stdlib.h>

#include "task.h"

// dynamic array
typedef struct {
    task *tasks;
    char* name;
    size_t count;
    size_t capacity;
} project;

// initialise empty project with no tasks
bool initialiseProject(project *proj, char* name);

// add task to dynamic array and resize if necessary
bool addTaskToProject(project *proj, task newTask);

// clear project (probably don't need this once actual storage exists)
void clearProject(project *proj);

#endif
