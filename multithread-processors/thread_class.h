#pragma once
#include <iostream>
#include<string>
#include<vector>

using namespace std;

class thread {
public:
	void give_num_to_thread(int number) { thread_id = number; }
	int show_thread_id() { return thread_id; }
	void add_time_slice(int num) { time_slice = num; }
	int show_time_slice() { return time_slice; }
	void get_process_id(int p_id) { process_id = p_id; }
	int show_process_id() { return process_id; }
	void decrease_time_slice() { time_slice--; }
private:
	int thread_id;
	int process_id;
	int time_slice;
};
