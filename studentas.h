#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>


using std::string;
using std::vector;

/*struct studentas
{
    std::string vardas, pavarde;
    int nd_kiek;
    std::vector <float> nd;
    float egz;
    float galutinis_vid, galutinis_med;
};*/

class Studentas {
    private:
        std::string vardas;
        std::string pavarde;
        double egzaminas;
        std::vector<double> nd;
        double galutinis;
    public:
        Studentas() : egzaminas(0) {};
        Studentas(std::istream& is);
        const string getVardas() const { return vardas; }
        const string getPavarde() const { return pavarde; }
        double getEgzaminas() const { return egzaminas; }
        const vector<double> getNd() const { return nd; }
        double getGalutinis() const { return galutinis; }
        void setVardas(string v) { vardas = v; }
        void setPavarde(string p) { pavarde = p; }
        void setEgzaminas(double e) { egzaminas = e; }
        void setNd(vector<double> n) { nd = n; }
        void setGalutinis(double g) { galutinis = g; }
        std::istream& readStudent(std::istream&, int);
        std::istream& readStudent(std::istream&);
};

double vidurkis(vector<double>);
double mediana(vector<double>);
bool compare_alphabet(const Studentas&, const Studentas&);
bool is_alphabetic(string);
void student_print(vector<Studentas>);
bool compare_mark(const Studentas&, const Studentas&);
bool islaike(const Studentas&);
double galutinis(Studentas, string);
