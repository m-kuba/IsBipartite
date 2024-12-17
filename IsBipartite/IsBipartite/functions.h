#pragma once

#include <iostream>
#include <fstream>

#include "structures.h"

pair <string, string> get_params (int how_many, char* params[]);

graph get_graph(const string& input_file_name);