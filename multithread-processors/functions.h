#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include "thread_class.h"
#include "process_class.h"
#include"core_class.h"

void print_core_id(core* temp_core);
void add_a_core(vector<core*> &v_cores);
int find_the_suitable_core(vector<core*> v_cores);
void remove_space(string line, string getline_string, vector<int>& process_times);
void manage_threads(vector<int> process_times, vector<process*> &v_processes, vector<core*> v_cores, process* temp_process);
void print_process_id(process* temp_process);
void add_a_process(vector<process*> &v_processes, vector<core*> v_cores, string line);
void show_cores_stat(vector<core*> v_cores);
void run_cores(vector<core*> v_cores);
void finish_tasks(vector<core*> v_cores);
void get_input(vector<core*> v_cores, vector<process*> v_processes);
