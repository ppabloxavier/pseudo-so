#include "Process_mng.hpp"

using namespace std;

Process* Process_mng::getCurrent_process() {
      return this->current_process;
};

vector<Process*>* Process_mng::getReal_time_q() {
      return &this->real_time_q;
};

vector<Process*>* Process_mng::getUser_priority_1_q() {
      return &this->user_priority_1_q;
};

vector<Process*>* Process_mng::getUser_priority_2_q() {
      return &this->user_priority_2_q;
};

vector<Process*>* Process_mng::getUser_priority_3_q() {
      return &this->user_priority_3_q;
};

void Process_mng::setCurrent_process(Process *current_process){};

void Process_mng::add_process(Process *p) {
      if (p->current_priority < 0 || p->current_priority > 3) {
            printf("Valor de prioridade não permitido (%d). O processo com pid %d não será inicializado.\n", p->priority, p->pid);
      }
      else if (p->current_priority == 0) {
            this->real_time_q.push_back(p);
      }
      else if (p->current_priority == 1) {
            this->user_priority_1_q.push_back(p);
      }
      else if (p->current_priority == 2) {
            this->user_priority_2_q.push_back(p);
      }
      else if (p->current_priority == 3) {
            this->user_priority_3_q.push_back(p);
      }

      return;
};

void Process_mng::exec() {
      while(1) {
            if (!this->real_time_q.empty())
                  this->current_process = this->real_time_q[0];
            else if (!this->user_priority_1_q.empty())
                  this->current_process = this->user_priority_1_q[0];
            else if (!this->user_priority_2_q.empty())
                  this->current_process = this->user_priority_2_q[0];
            else if (!this->user_priority_3_q.empty())
                  this->current_process = this->user_priority_3_q[0];

            this_thread::sleep_for(chrono::seconds(1));

            this->clock++;

            this->current_process->elapsed_time++;

            if (this->current_process->elapsed_time == this->current_process->processor_time)
                  del_process();
            else
                  return_to_queue(this->current_process);
      }
};

void Process_mng::return_to_queue(Process *p) {
      if (this->current_process->current_priority == 1) {
            this->current_process->current_priority = 2;
            this->user_priority_1_q.erase(this->user_priority_1_q.begin());
            this->add_process(p);
      }
      else if (this->current_process->current_priority == 2) {
            this->current_process->current_priority = 3;
            this->user_priority_2_q.erase(this->user_priority_2_q.begin());
            this->add_process(p);
      }
      else if (this->current_process->current_priority == 3) {
            if (this->current_process->priority == 1)
                  this->current_process->current_priority = 1;
            else if (this->current_process->priority == 2)
                  this->current_process->current_priority = 2;

            this->user_priority_3_q.erase(this->user_priority_3_q.begin());
            this->add_process(p);
      }
};

void Process_mng::del_process(){};
// 2 queues: real time (priority 0 - FIFO) and user processes (priorities 1, 2 and 3.)

// maximum of 1000 processes for both queues
