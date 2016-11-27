#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <vector>

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

      // Variável utilizada para facilitar a remoção de um processo. Podem ignorar ela.
      // Ela aponta para posição do elemento no vetor.
      std::vector<Process>::iterator it;

      Process();

      Process(int pid, int init_time, int priority, int processor_time, int memory_blocks,
              bool real_time, bool printer, bool scanner, bool modem, bool sata);


};

#endif
