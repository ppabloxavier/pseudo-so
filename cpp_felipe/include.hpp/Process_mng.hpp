class Process_mng {
      Process *current_process;
	vector<Process> real_time;
	vector<Process> user_priority_1;
      vector<Process> user_priority_2;
      vector<Process> user_priority_3;

      // For the queues higher numbers mean higher priorities. So 1 is the lowest
      // and 3 is the highest queue priority.

      // Adds the process to the appropriate queue.
      add_process();

      // Executes the process.
      exec();

      // Blocks the process.
      // After the process is executed for its quantum, its priority is updated
      // and the process is moved to another queue.
      block();

      // Delete process.
      del_process();


}
