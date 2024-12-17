#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "functions.h"
#include "structures.h"

pair <string, string> get_params (int how_many, char* params[]) {
	if (how_many == 3) {
		string input { params[1] };
		string output { params[2] };

		return { input, output };
	}

	return {}; 
}

graph get_graph(const string& input_file_name) {
	graph load;

	ifstream inFile(input_file_name);

	int left, right;

	while (inFile >> left >> right) {
		load.vertex[left].neighbors.push_back(right);
		load.vertex[right].neighbors.push_back(left);
	}

	return load;
}