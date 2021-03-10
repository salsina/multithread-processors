#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include "thread_class.h"
#include "process_class.h"
#include"core_class.h"
#include"functions.h"
using namespace std;

int main()
{
	vector<core*> v_cores;
	vector<process*> v_processes;
	get_input(v_cores, v_processes);
	return 0;
}