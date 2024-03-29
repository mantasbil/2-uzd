#include "studentas.h"
#include <numeric>
#include <algorithm>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;


Studentas::Studentas(const Studentas& s) {
	vardas = s.vardas;
	pavarde = s.pavarde;
	nd = s.nd;
	egzaminas = s.egzaminas;
	galutinis = s.galutinis;
}

std::istream& Studentas::readStudent(std::istream& in, int n) {
	int paz;
	Studentas stud;
	in >> vardas >> pavarde;
	stud.setVardas(vardas);
	stud.setPavarde(pavarde);
	nd.clear();
	nd.reserve(n);
	for (int i = 0; i < n; i++) {
		in >> paz;
		nd.push_back(paz);
	}
	stud.setNd(nd);
	in >> egzaminas;
	stud.setEgzaminas(egzaminas);
	return in;
}


Studentas& Studentas::operator=(const Studentas& s) {
	if (&s == this) return *this;
	vardas = s.vardas;
	pavarde = s.pavarde;
	nd = s.nd;
	egzaminas = s.egzaminas;
	galutinis = s.galutinis;
	return *this;
}

double vidurkis(vector<double> pazymiai) {
	if (pazymiai.size() == 0) throw std::exception("Namu darbu kiekis turi buti didesnis uz 0");
	return std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
}

double mediana(vector<double> pazymiai) {
	if (pazymiai.size() == 0) throw std::exception("Namu darbu kiekis turi buti didesnis uz 0");
	float median;
	int n = pazymiai.size();
	std::sort(pazymiai.begin(), pazymiai.end());
	if (n % 2 == 0) median = (pazymiai[n / 2] + pazymiai[n / 2 + 1]) / 2.0;
	else median = pazymiai[n / 2];
	return median;
}

double galutinis(Studentas a, string type) {
	if (type == "v" || type == "V") 
		return (0.4 * vidurkis(a.getNd()) + 0.6 * a.getEgzaminas());
	if (type == "m" || type == "M")
		return (0.4 * mediana(a.getNd()) + 0.6 * a.getEgzaminas());
}

bool compare_alphabet(const Studentas& a, const Studentas& b) {
	if (a.getPavarde() != b.getPavarde()) return a.getPavarde() < b.getPavarde();
	else return a.getVardas() < b.getVardas();
}

bool is_alphabetic(string x) {
	return std::all_of(x.begin(), x.end(), isalpha);
}

void student_print(vector<Studentas> grupe) {
	std::sort(grupe.begin(), grupe.end(), compare_alphabet);
	cout << endl;
	cout << setw(30) << left << "Vardas" << setw(30) << left << "Pavarde" << setw(20) << left << "Galutinis" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	for (int i = 0; i < grupe.size(); i++)
	{
		cout << setw(30) << left << grupe[i].getVardas() << setw(30) << left << grupe[i].getPavarde()
			<< setw(20) << fixed << setprecision(2) << left << grupe[i].getGalutinis() << endl;
	}
}

bool islaike(const Studentas& a) {
	return a >= 5;
}