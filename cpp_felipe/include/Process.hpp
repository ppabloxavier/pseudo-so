#ifndef PROCESS_HPP
#define PROCESS_HPP

class Process {
public:
      int pid;
      int init_time;
      int priority;
      int current_priority;
      int processor_time;
      int elapsed_time;
      int memory_blocks;
      int memory_offset;
      bool real_time;
      bool printer;
      bool scanner;
      bool modem;
      bool sata;

      Process();

      Process(int pid, int init_time, int priority, int processor_time, int memory_blocks,
              bool real_time, bool printer, bool scanner, bool modem, bool sata);


};

#endif
