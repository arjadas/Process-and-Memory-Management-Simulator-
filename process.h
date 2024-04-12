#ifndef PROCESS_H
#define PROCESS_H
#include "memory.h"
#define FINISHED 0
#define READY 1
#define RUNNING 2
#define INVALID -1
#define NOT_SET -2

typedef struct
{
    char *name;
    int arrival_time;
    int remaining_time;
    unsigned long int service_time; // check data type
    int completion_time;
    int turnaround_time;
    double time_overhead; // data type - double
    int memory_KB;
    int status;
    memory_t *allocation;
} process_t;

process_t *create_process();
int change_status(process_t *process, int new_status);
int get_status(process_t *process);
void free_process(process_t *process);
void print_process(process_t *process);
void print_processes(process_t **processes, int num_processes);
char *get_status_string(process_t *process);

#endif