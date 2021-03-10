#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include "thread_class.h"
#include "process_class.h"
#include"core_class.h"
#define beginfrom 0
#define addprocesssize 11
using namespace std;

void print_core_id(core* temp_core)
{
	cout << "Core with core ID = " << temp_core->show_core_id() << " successfully added!" << endl;
}

void add_a_core(vector<core*> &v_cores)
{
	core* temp_core = new core;
	temp_core->give_num_to_core(v_cores.size() + 1);
	v_cores.push_back(temp_core);
	print_core_id(temp_core);
}

int find_the_suitable_core(vector<core*> v_cores)
{
	int save = v_cores[0]->number_of_threads();
	int number_of_saved_core = 0;
	for (int i = 1; i < v_cores.size(); i++)
		if (v_cores[i]->number_of_threads() < save)
		{
			save = v_cores[i]->number_of_threads();
			number_of_saved_core = i;
		}
	return number_of_saved_core;
}

void remove_space(string line, string getline_string, vector<int>& process_times)
{
	istringstream string_stream_line(line.substr(12));
	while (getline(string_stream_line, getline_string, ' '))
		process_times.push_back(stoi(getline_string));
}

void manage_threads(vector<int> process_times, vector<process*> &v_processes, vector<core*> v_cores, process* temp_process)
{
	for (int i = 1; i <= process_times[0]; i++)
	{
		int current_time = process_times[i];
		thread* temp_thread = new thread();
		temp_thread->get_process_id(v_processes.size() + 1);
		temp_thread->give_num_to_thread(temp_process->number_of_threads() + 1);
		temp_thread->add_time_slice(current_time);
		temp_process->add_threads(temp_thread);
		v_cores[find_the_suitable_core(v_cores)]->add_thread(temp_thread);
	}
}

void print_process_id(process* temp_process)
{
	cout << "Process with pid = " << temp_process->show_process_id() << " added!" << endl;
}

void add_a_process(vector<process*> &v_processes, vector<core*> v_cores, string line)
{
	if (v_cores.size() != 0)
	{
		vector<int> process_times;
		string getline_string;
		process* temp_process = new process;
		temp_process->give_num_to_process(v_processes.size() + 1);
		remove_space(line, getline_string, process_times);
		manage_threads(process_times, v_processes, v_cores, temp_process);
		v_processes.push_back(temp_process);
		print_process_id(temp_process);
	}
}

void show_cores_stat(vector<core*> v_cores)
{
	for (int i = 0; i < v_cores.size(); i++)
	{
		cout << "Core number : " << v_cores[i]->show_core_id() << endl;
		for (int n = 0; n < v_cores[i]->number_of_threads(); n++)
		{
			int processid = v_cores[i]->info_of_thread(n)->show_process_id();
			cout << "Process ID : " << processid << " - Thread ID : " << v_cores[i]->info_of_thread(n)->show_thread_id() << endl;
			cout << "Number of time slots : " << v_cores[i]->info_of_thread(n)->show_time_slice() << endl;
		}
	}

}

void run_cores(vector<core*> v_cores)
{
	for (int i = 0; i < v_cores.size(); i++)
	{
		if (v_cores[i]->number_of_threads() != 0)
		{
			int processid = v_cores[i]->info_of_thread(0)->show_process_id();
			cout << "Core number : " << v_cores[i]->show_core_id() << endl;
			v_cores[i]->info_of_thread(0)->decrease_time_slice();
			cout << "Process ID : " << processid << " - Thread ID : " << v_cores[i]->info_of_thread(0)->show_thread_id() << endl;
			for (int j = 0; j < v_cores[i]->number_of_threads() - 1; j++)
				v_cores[i]->swap_threads(j, j + 1);
			if (v_cores[i]->info_of_thread(v_cores[i]->number_of_threads() - 1)->show_time_slice() < 1)
				v_cores[i]->delete_thread();
		}
	}
}

void finish_tasks(vector<core*> v_cores)
{
		int cores_counter = 0;
		int time_slice_counter = 1;
		while (cores_counter != v_cores.size())
		{
			while (v_cores[cores_counter]->number_of_threads() != 0)
			{
				cout <<"Time Slice : " <<time_slice_counter<<endl;
				run_cores(v_cores);
				time_slice_counter++;
			}
			cores_counter++;
		}
}

void get_input(vector<core*> v_cores, vector<process*> v_processes)
{
	string line;
	while (getline(cin, line))
	{
		if (line == "add_core")
			add_a_core(v_cores);
		if (line.substr(beginfrom, addprocesssize) == "add_process")
			add_a_process(v_processes, v_cores, line);
		if (line == "show_cores_stat")
			show_cores_stat(v_cores);
		if (line == "run_cores")
			run_cores(v_cores);
		if (line == "finish_tasks")
			finish_tasks(v_cores);
	}
}
