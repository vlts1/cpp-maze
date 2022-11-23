#include "rand_num_generator.h"
#include <random>
int RandNumGenerator::getRandNum(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}