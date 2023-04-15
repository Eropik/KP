#pragma once
#include"lib.h"


struct User {
	string login;
	string password;
	bool isAdmin;
	bool isBanned;
};
extern vector <User> UserArr;

struct student {
	string name;
	int number;
	float score;
	float activityRating;
	float income;
};
extern vector <student> StudentArr;