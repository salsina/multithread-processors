#pragma once
#include <iostream>
#include<string>
#include<vector>
#include "thread_class.h"

using namespace std;

class process {
public:
	void give_num_to_process(int number) { process_id = number; }
	int show_process_id() { return process_id; }
	void add_threads(thread*  temp_thread) { process_threads.push_back(temp_thread); }
	int number_of_threads() { return process_threads.size(); }
	thread* info_of_thread(int i) { return process_threads[i]; }
private:
	int process_id;
	vector<thread*> process_threads;
};
