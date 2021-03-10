#pragma once
#include <iostream>
#include<string>
#include<vector>
#include "thread_class.h"
#include "process_class.h"

using namespace std;

class core {
public:
	void give_num_to_core(int number) { core_id = number; }
	int show_core_id() { return core_id; }
	void add_thread(thread* temp_thread) { core_threads.push_back(temp_thread); }
	int number_of_threads() { return core_threads.size(); }
	thread* info_of_thread(int i) { return core_threads[i]; }
	void delete_thread() { core_threads.pop_back(); }
	void swap_threads(int first, int second) 
	{
		thread* temp_thread = core_threads[first];
		core_threads[first] = core_threads[second];
		core_threads[second] = temp_thread;
	};
private:
	int core_id;
	vector<thread*> core_threads;
};