#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "read.h"
#include "process.h"
#include "queue.h"
#include "roundrobin.h"
#include "task2.h"

int main(int argc, char const *argv[])
{
    /*
        main function
    */

    int num_processes = 0;
    int makespan = 0;

    read_t *inputs = process_arguments(argc, argv);
    process_t **processes = read_processes(inputs, &num_processes);
    print_processes(processes, num_processes);
    queue_t *queue = createQueue();

    if (inputs->memory == INFINITE) 
    {
        // task 1
        round_robin(processes, queue, num_processes, inputs->quantum, &makespan);
        print_statistics(processes, num_processes, makespan);
    }
    else if (inputs->memory == FIRST_FIT)
    {
        // task 2 code
        bitmap_t bitmap = make_bitmap();
        initial_memory_allocation(processes, &num_processes, bitmap);
        printf("made it to line 36 main\n");
        printf("quantum = %d, queue = %p, bitmap = %p, num_processes = %p, processes = %p\n", inputs->quantum, queue, bitmap, &num_processes, processes);
        scheduler(inputs->quantum, queue, bitmap, &num_processes, processes);
    }
    else if (inputs->memory == PAGED)
    {
        /* code */
    }
    else if (inputs->memory == VIRTUAL)
    {
        /* code */
    }
    

    //free(queue);

    return 0;
}
