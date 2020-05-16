#include "flower.h"

Flower::Flower(){}
Flower::~Flower(){}

void Flower::setID(int id) {flowerID = id;}
void Flower::setName(string name) {flowerName = name;}
void Flower::setPerson(vector<float> per) { flowerPerson = normalize(per); }
void Flower::setEmo(vector<float> emo) { flowerEmo = normalize(emo); }
void Flower::setCol(vector<string> col) { flowerColor = col; }
void Flower::setDry(int dry) { flowerDry = dry; }

int Flower::getID() { return flowerID; }
string Flower::getName() { return flowerName; }
vector<float> Flower::getPerson() { return flowerPerson; }
vector<float> Flower::getEmo() { return flowerEmo; }
vector<string> Flower::getCol() { return flowerColor; }
int Flower::getDry() { return flowerDry; }

vector<float> Flower::normalize(vector<float> vec) {
	vector<float> rvec;
	float sum = 0;
	for (int i = 0; i < vec.size(); i++) sum += pow(vec[i],2);
	float size = sqrt(sum);
	for (int i = 0; i < vec.size(); i++) rvec.push_back((10.0f / size)*vec[i]);
	return rvec;
}