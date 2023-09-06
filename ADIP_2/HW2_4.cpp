#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "a_star_algorithm.h"
using namespace std;

class HW2_4 {
private:
	AStar::Generator generator;
	
	
public:
	HW2_4() {
		generator.setWorldSize({ 100, 100 });
	}
	unsigned char* CalD4(unsigned char* map100x100, unsigned char* D4) {

		unsigned char walls_arr[100][100];
		int index = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				walls_arr[i][j] = *(map100x100 + index);
				if (walls_arr[i][j] == 255) {
					generator.addCollision({ i,j });
					//printf("[%d,%d]\n", i, j);
				}
				index++;
			}
		}
		index = 0;
		generator.setHeuristic(AStar::Heuristic::D4);
		generator.setDiagonalMovement(false);
		std::cout << "Generate D4 path\n";
		auto path = generator.findPath({ 14, 0 }, { 93, 34 }, 1, map100x100);
		int count = -1;
		for (auto& coordinate : path) {
			//std::cout << coordinate.x << " " << coordinate.y << "\n";
			count += 1;
		}
		printf("The path of D4 is:%d\n", count);
		for (int i = 0; i < 100 * 100; i++) {
			*(D4 + i) = 255;
		}
		for (auto& coordinate : path) {
			for (int r = 0; r < 100; r++) {
				for (int c = 0; c < 100; c++) {
					if (r == coordinate.x && c == coordinate.y) {
						*(D4 + r * 100 + c) = 0;
					}
				}
			}
		}
		return D4;
	}
	unsigned char* CalD8(unsigned char* map100x100, unsigned char* D8){
		unsigned char walls_arr[100][100];
		int index = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				walls_arr[i][j] = *(map100x100 + index);
				if (walls_arr[i][j] == 255) {
					generator.addCollision({ i,j });
					//printf("[%d,%d]\n", i, j);
				}
				index++;
			}
		}
		index = 0;
		generator.setHeuristic(AStar::Heuristic::D8);
		generator.setDiagonalMovement(true);
		std::cout << "Generate D8 path\n";
		auto path = generator.findPath({ 14, 0 }, { 93, 34 }, 2, map100x100);

		int count = -1;
		for (auto& coordinate : path) {
			//std::cout << coordinate.x << " " << coordinate.y << "\n";
			count += 1;
		}
		printf("The path of D8 is:%d\n", count);
		for (int i = 0; i < 100 * 100; i++) {
			*(D8 + i) = 255;
		}
		for (auto& coordinate : path) {
			for (int r = 0; r < 100; r++) {
				for (int c = 0; c < 100; c++) {
					if (r == coordinate.x && c == coordinate.y) {
						*(D8 + r * 100 + c) = 0;
					}
				}
			}
		}
		return D8;

	}
	unsigned char* CalDm(unsigned char* map100x100, unsigned char* Dm) {
		unsigned char walls_arr[100][100];
		int index = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				walls_arr[i][j] = *(map100x100 + index);
				if (walls_arr[i][j] == 255) {
					generator.addCollision({ i,j });
					//printf("[%d,%d]\n", i, j);
				}
				index++;
			}
		}
		index = 0;
		generator.setHeuristic(AStar::Heuristic::Dm);
		generator.setDiagonalMovement(false);
		std::cout << "Generate Dm path\n";
		auto path = generator.findPath({ 14, 0 }, { 93, 34 }, 3, map100x100);
		int count = -1;
		for (auto& coordinate : path) {
			//std::cout << coordinate.x << " " << coordinate.y << "\n";
			count += 1;
		}
		printf("The path of Dm is:%d\n", count);
		for (int i = 0; i < 100 * 100; i++) {
			*(Dm + i) = 255;
		}
		for (auto& coordinate : path) {
			for (int r = 0; r < 100; r++) {
				for (int c = 0; c < 100; c++) {
					if (r == coordinate.x && c == coordinate.y) {
						*(Dm + r * 100 + c) = 0;
					}
				}
			}
		}
		return Dm;

	}
};