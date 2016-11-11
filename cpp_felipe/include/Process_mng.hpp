#ifndef PROCESS_MNG_HPP
#define PROCESS_MNG_HPP

#include <vector>

#include "Process.hpp"

using namespace std;

class Process_mng {
      Process *current_process;
	vector<Process> real_time;
	vector<Process> user_priority_1;
      vector<Process> user_priority_2;
      vector<Process> user_priority_3;

      // Adds the process to the appropriate queue.
      void add_process();

      // Delete process;
      void del_process();


};

#endif
