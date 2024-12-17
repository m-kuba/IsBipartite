#include <iostream>
#include <string>

#include "functions.h";
#include "structures.h";

int main (int how_many, char* params[]) {

	auto [input_file_name, output_file_name] = get_params(how_many, params);

	if (not input_file_name.empty() and not output_file_name.empty()) {
		get_graph(input_file_name);
	}

	return 0;
}