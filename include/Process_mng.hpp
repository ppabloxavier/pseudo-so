#ifndef PROCESS_MNG_HPP
#define PROCESS_MNG_HPP

#include <vector>
#include <thread>
#include <chrono>
#include "../include/Process.hpp"

#define QUANTUM 1

using namespace std;

class Process_mng {
      static uint64_t pid_counter;
      static Process *current_process;
      static uint64_t executing_counter;
	vector<Process*> real_time_q;
	vector<Process*> user_priority_1_q;
      vector<Process*> user_priority_2_q;
      vector<Process*> user_priority_3_q;

      // For the queues, lower numbers mean higher priorities. So 1 is the highest
      // and 3 is the highest queue priority.

private:
      Process_mng() {};

public:
      // Singleton
      static Process_mng& getInstance() {
            static Process_mng instance;
            return instance;
      };

      uint64_t getPid_counter();

      Process* getCurrent_process();

      uint64_t getExecuting_counter();

      vector<Process*>* getReal_time_q();

      vector<Process*>* getUser_priority_1_q();

      vector<Process*>* getUser_priority_2_q();

      vector<Process*>* getUser_priority_3_q();

      void setCurrent_process(Process *current_process);

      // Adds the process to the appropriate queue.
      int add_process(Process *p);

      // Executes the process.
      int exec();

      // Returns the process to the appropriate queue.
      // After the process is executed for its quantum, its priority is updated
      // and the process is moved to another queue.
      void return_to_queue();

      // Delete process.
      void del_process();


};

#endif
