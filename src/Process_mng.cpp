#include "Process_mng.hpp"

using namespace std;

// Inicializando variáveis de classe
uint64_t Process_mng::pid_counter = 0;
Process *Process_mng::current_process = NULL;
uint64_t Process_mng::executing_counter = 0;

uint64_t Process_mng::getPid_counter() {
      return Process_mng::pid_counter;
};

Process* Process_mng::getCurrent_process() {
      return Process_mng::current_process;
};

uint64_t Process_mng::getExecuting_counter() {
      return Process_mng::executing_counter;
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
//    int: 1 se o processo foi adicionado com sucesso.
//         0 se o processo não foi adicionado a fila de prontos.
int Process_mng::add_process(Process *p) {
      if (executing_counter == 1000) {
            printf("O número máximo de processos é 1000. Processo não adicionado.\n");
            return 0;
      }
      else if (p->current_priority < 0 || p->current_priority > 3) {
            printf("Valor de prioridade não permitido (%d). O processo com pid %d não será inicializado.\n", p->priority, p->pid);
            return 0;
      }
      else {
            executing_counter++;

            p->pid = Process_mng::pid_counter;
            Process_mng::pid_counter++;

            if (p->current_priority == 0) {
                  real_time_q.push_back(p);
            }
            else if (p->current_priority == 1) {
                  user_priority_1_q.push_back(p);
            }
            else if (p->current_priority == 2) {
                  user_priority_2_q.push_back(p);
            }
            else if (p->current_priority == 3) {
                  user_priority_3_q.push_back(p);
            }
      }

      return 1;
};


// Executa o processo e, caso o processo tenha acabado de executar, avisa o
// dispatcher, para que ele chames as funções necessárias para deletar o processo.
//
// Parâmetros:
//    void
//
// Retorno:
//    1 se o processo tiver acabado de executar.
//    0 se ele ainda precisa de tempo de cpu.
int Process_mng::exec() {
      while(1) {
            if (!real_time_q.empty())
                  current_process = real_time_q[0];
            else if (!user_priority_1_q.empty())
                  current_process = user_priority_1_q[0];
            else if (!user_priority_2_q.empty())
                  current_process = user_priority_2_q[0];
            else if (!user_priority_3_q.empty())
                  current_process = user_priority_3_q[0];

            current_process->elapsed_time++;

            cout << "P " << current_process->pid << " -- executando -- ";
            cout << "instrução " << current_process->elapsed_time << endl;

            if (current_process->elapsed_time == current_process->processor_time)
                  return 1;
            else
                  return_to_queue();
                  return 0;
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
            real_time_q.erase(real_time_q.begin());
      }
      else if (current_process->current_priority == 1) {
            user_priority_1_q.erase(user_priority_1_q.begin());
      }

      else if (current_process->current_priority == 2) {
            user_priority_2_q.erase(user_priority_2_q.begin());
      }

      else if (current_process->current_priority == 3) {
            user_priority_3_q.erase(user_priority_3_q.begin());
      }

      executing_counter--;
};
