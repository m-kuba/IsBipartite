#pragma once

#include <unordered_map>
#include <string>

using namespace std;

struct graph {
	struct vertex {
		unsigned int color = 0;
		vector <int> neighbors;
	};

	unordered_map <int, vertex> vertex;

	unsigned int color_quanity = 0;
};