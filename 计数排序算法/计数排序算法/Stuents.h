#pragma once
#include<iostream>
#include<string>
using namespace std;
class Stuents
{
public:
	Stuents(string n, int s) {
		this->name = n;
		this->score = s;
	}
	Stuents() {
	}
	string get_name() {
		return this->name;
	}
	int get_score() {
		return this->score;
	}
	void show() {
		cout << name << ":";
		cout << this->score << endl;
	}
private:
	string name;
	int score;
};

