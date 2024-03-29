#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>


using std::string;
using std::vector;

class Zmogus {
    protected:
        string vardas;
        string pavarde;
    public:
        Zmogus(): vardas(""), pavarde("") {};
        virtual const string getVardas() const = 0;
        virtual const string getPavarde() const = 0;
};

class Studentas : public Zmogus {
    private:
        string vardas;
        string pavarde;
        double egzaminas;
        vector<double> nd;
        double galutinis;
    public:
        Studentas() : Zmogus(), egzaminas(0) { nd.clear(); };
        ~Studentas() {};
        Studentas(const Studentas& s);
        Studentas& operator=(const Studentas& s);
        const string getVardas() const override { return vardas; }
        const string getPavarde() const override { return pavarde; }
        double getEgzaminas() const { return egzaminas; }
        const vector<double> getNd() const { return nd; }
        double getGalutinis() const { return galutinis; }
        void setVardas(string v) { vardas = v; }
        void setPavarde(string p) { pavarde = p; }
        void setEgzaminas(double e) { egzaminas = e; }
        void setNd(vector<double> n) { nd = n; }
        void setGalutinis(double g) { galutinis = g; }
        std::istream& readStudent(std::istream&, int);

        bool operator<(const Studentas& s) const {
            return galutinis < s.galutinis;
        }

        bool operator>(const Studentas& s) const {
            return galutinis > s.galutinis;
        }

        bool operator<=(const Studentas& s) const {
            return galutinis <= s.galutinis;
        }

        bool operator>=(const Studentas& s) const {
            return galutinis >= s.galutinis;
        }

        bool operator==(const Studentas& s) const {
            return galutinis == s.galutinis;
        }

        bool operator!=(const Studentas& s) const {
            return galutinis != s.galutinis;
        }

        bool operator<(const double x) const {
            return galutinis < x;
        }

        bool operator>(const double x) const {
            return galutinis > x;
        }

        bool operator<=(const double x) const {
            return galutinis <= x;
        }

        bool operator>=(const double x) const {
            return galutinis >= x;
        }

        bool operator==(const double x) const {
            return galutinis == x;
        }

        bool operator!=(const double x) const {
            return galutinis != x;
        }
};

double vidurkis(vector<double>);
double mediana(vector<double>);
bool compare_alphabet(const Studentas&, const Studentas&);
bool is_alphabetic(string);
void student_print(vector<Studentas>);
bool compare_mark(const Studentas&, const Studentas&);
bool islaike(const Studentas&);
double galutinis(Studentas, string);
