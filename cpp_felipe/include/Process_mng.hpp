#ifndef PROCESS_MNG_HPP
#define PROCESS_MNG_HPP

#include <vector>
#include <thread>
#include <chrono>
#include "Process.hpp"

#define QUANTUM 1

using namespace std;

class Process_mng {
      int clock; // pode ser que a variável tenha outro tipo
      Process *current_process;
	vector<Process*> real_time_q;
	vector<Process*> user_priority_1_q;
      vector<Process*> user_priority_2_q;
      vector<Process*> user_priority_3_q;

      // For the queues, lower numbers mean higher priorities. So 1 is the highest
      // and 3 is the highest queue priority.

      Process* getCurrent_process();

      vector<Process*>* getReal_time_q();

      vector<Process*>* getUser_priority_1_q();

      vector<Process*>* getUser_priority_2_q();

      vector<Process*>* getUser_priority_3_q();

      void setCurrent_process(Process *current_process);

      // Adds the process to the appropriate queue.
      void add_process(Process *p);

      // Executes the process.
      void exec();

      // Returns the process to the appropriate queue.
      // After the process is executed for its quantum, its priority is updated
      // and the process is moved to another queue.
      void return_to_queue(Process *process);

      // Delete process.
      void del_process();


};

#endif
