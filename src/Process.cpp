#include "../include/Process.hpp"

Process::Process()
{
      this->pid = -1;
      this->init_time = -1;
      this->priority = -1;
      this->processor_time = -1;
      this->memory_blocks = -1;
      this->memory_offset = -1;
      this->real_time = false;
      this->printer = false;
      this->scanner = false;
      this->modem = false;
      this->sata = false;
}

Process::Process(int pid, int init_time, int priority, int processor_time, int memory_blocks,
        bool real_time, bool printer, bool scanner, bool modem, bool sata)
{
      this->pid = pid;
      this->init_time = init_time;
      this->priority = priority;
      this->current_priority = priority;
      this->processor_time = processor_time;
      this->elapsed_time = 0;
      this->memory_blocks = memory_blocks;
      this->memory_offset = -1;
      this->real_time = real_time;
      this->printer = printer;
      this->scanner = scanner;
      this->modem = modem;
      this->sata = sata;
}
