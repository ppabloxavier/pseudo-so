#include "Process_mng.hpp"

using namespace std;

Process* Process_mng::getCurrent_process() {
      return current_process;
};

vector<Process>* Process_mng::getProcesses() {
      return &processes;
};

vector<Process*>* Process_mng::getReal_time_q() {
      return &real_time_q;
};

vector<Process*>* Process_mng::getUser_priority_1_q() {
      return &user_priority_1_q;
};

vector<Process*>* Process_mng::getUser_priority_2_q() {
      return &user_priority_2_q;
};

vector<Process*>* Process_mng::getUser_priority_3_q() {
      return &user_priority_3_q;
};

void Process_mng::setCurrent_process(Process *current_process){};

// Deve ser chamada para cada processo lido do arquivos de processos.
//
// Adiciona o processo ao vetor de processos prontos e adiciona o um ponteiro para
// o processo a fila com a prioridade apropriada.
//
// Também checa se o processo possui uma prioridade válida e se ele não passará
// do limite de 1000 processos no vetor de processos prontos.
//
// Parâmetros:
//    p: processo a ser adicionado a fila de prontos.
//
// Retorno:
//    void
void Process_mng::add_process(Process p) {
      if (processes.size() == 1000) {
            printf("O número máximo de processos é 1000. Processo não adicionado.\n");
      }
      else if (p.current_priority < 0 || p.current_priority > 3) {
            printf("Valor de prioridade não permitido (%d). O processo com pid %d não será inicializado.\n", p.priority, p.pid);
      }
      else {
            // Adiciona o processo ao vetor de processos prontos.
            processes.push_back(p);
            // Salava um iterador que aponta para o processo no vetor de processos.
            processes.back().it = processes.end() - 1;

            if (p.current_priority == 0) {
                  real_time_q.push_back(&processes.back());
            }
            else if (p.current_priority == 1) {
                  user_priority_1_q.push_back(&processes.back());
            }
            else if (p.current_priority == 2) {
                  user_priority_2_q.push_back(&processes.back());
            }
            else if (p.current_priority == 3) {
                  user_priority_3_q.push_back(&processes.back());
            }
      }

      return;
};


//
//
//
void Process_mng::exec() {
      while(1) {
            if (!real_time_q.empty())
                  current_process = real_time_q[0];
            else if (!user_priority_1_q.empty())
                  current_process = user_priority_1_q[0];
            else if (!user_priority_2_q.empty())
                  current_process = user_priority_2_q[0];
            else if (!user_priority_3_q.empty())
                  current_process = user_priority_3_q[0];

            this_thread::sleep_for(chrono::seconds(1));

            clock++;

            current_process->elapsed_time++;

            if (current_process->elapsed_time == current_process->processor_time)
                  del_process();
            else
                  return_to_queue();
      }
};


// Deve ser utilizada logo após o processo ser executado.
//
// Essa função manipula o processo apontado por "current_process". Ou seja, o último
// processo executado.
//
// Remove o ponteiro para o processo de sua antiga fila e o coloca em uma nova fila
// correspondente a sua nova prioridade.
//
// Parâmetros:
//
// Retorno:
//    void
void Process_mng::return_to_queue() {
      if (current_process->current_priority == 1) {
            current_process->current_priority = 2;
            user_priority_1_q.erase(user_priority_1_q.begin());
            user_priority_2_q.push_back(current_process);
      }
      else if (current_process->current_priority == 2) {
            current_process->current_priority = 3;
            user_priority_2_q.erase(user_priority_2_q.begin());
            user_priority_3_q.push_back(current_process);
      }
      else if (current_process->current_priority == 3) {
            user_priority_3_q.erase(user_priority_3_q.begin());

            if (current_process->priority == 1) {
                  current_process->current_priority = 1;
                  user_priority_1_q.push_back(current_process);
            }
            else if (current_process->priority == 2) {
                  current_process->current_priority = 2;
                  user_priority_2_q.push_back(current_process);
            }
            else
                  user_priority_3_q.push_back(current_process);
      }

      return;
};

void Process_mng::del_process(){
      if (current_process->priority == 0) {
            processes.erase(real_time_q[0]->it);
            real_time_q.erase(real_time_q.begin());
      }
      else if (current_process->current_priority == 1) {
            processes.erase(user_priority_1_q[0]->it);
            user_priority_1_q.erase(user_priority_1_q.begin());
      }

      else if (current_process->current_priority == 2) {
            processes.erase(user_priority_2_q[0]->it);
            user_priority_2_q.erase(user_priority_2_q.begin());
      }

      else if (current_process->current_priority == 3) {
            processes.erase(user_priority_3_q[0]->it);
            user_priority_3_q.erase(user_priority_3_q.begin());
      }
};
