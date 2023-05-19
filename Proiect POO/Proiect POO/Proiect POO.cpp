#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Elev {
private:
    string nume;
    string prenume;
    vector<int> note;

public:
    Elev(string nume, string prenume, vector<int> note) : nume(nume), prenume(prenume), note(note) {
        cout << "Elevul " << nume << " " << prenume << " a fost adaugat." << endl;
    }

    ~Elev() {
        cout << "Elevul " << nume << " " << prenume << " a fost sters." << endl;
    }

    string getNume() const {
        return nume;
    }

    string getPrenume() const {
        return prenume;
    }

    vector<int> getNote() const {
        return note;
    }

    void afisare() const {
        cout << "Nume: " << nume << endl;
        cout << "Prenume: " << prenume << endl;
        cout << "Note: ";
        for (int nota : note) {
            cout << nota << " ";
        }
        cout << endl;
    }

    float calculeazaMedie() const {
        int suma = 0;
        for (int nota : note) {
            suma += nota;
        }
        return static_cast<float>(suma) / note.size();
    }

    void setNote(const vector<int>& noiNote) {
        note = noiNote;
        cout << "Notele pentru elevul " << nume << " " << prenume << " au fost actualizate." << endl;
    }
};

int main() {
    vector<Elev> elevi;

    int numarElevi;
    cout << "Introduceti numarul de elevi: ";
    cin >> numarElevi;

    for (int i = 0; i < numarElevi; ++i) {
        string nume, prenume;
        vector<int> note;

        cout << "Introduceti numele elevului: ";
        cin >> nume;
        cout << "Introduceti prenumele elevului: ";
        cin >> prenume;

        for (int j = 0; j < 3; ++j) {
            int nota;
            cout << "Introduceti nota " << j + 1 << ": ";
            cin >> nota;
            note.push_back(nota);
        }

        elevi.push_back(Elev(nume, prenume, note));
    }

    bool continua = true;
    while (continua) {
        cout << "\nOptiuni disponibile:\n";
        cout << "1. Schimba nota pentru un elev\n";
        cout << "2. Afiseaza elevii in ordine dupa nume\n";
        cout << "3. Afiseaza elevii in ordine dupa medie\n";
        cout << "4. Iesire\n";
        cout << "Introduceti optiunea dorita: ";

        int optiune;
        cin >> optiune;

        switch (optiune) {
        case 1: {
            cout << "\nIntroduceti numele si prenumele elevului pentru care doriti sa schimbati nota:\n";
            string nume, prenume;
            cout << "Nume: ";
            cin >> nume;
            cout << "Prenume: ";
            cin >> prenume;

            bool gasit = false;
            for (Elev& elev : elevi) {
                if (elev.getNume() == nume && elev.getPrenume() == prenume) {
                    vector<int> noteNoi;
                    for (int i = 0; i < 3; ++i) {
                        int nota;
                        cout << "Introduceti noua nota " << i + 1 << ": ";
                        cin >> nota;
                        noteNoi.push_back(nota);
                    }
                    elev.setNote(noteNoi);
                    gasit = true;
                    break;
                }
            }

            if (!gasit) {
                cout << "Elevul " << nume << " " << prenume << " nu a fost gasit." << endl;
            }
            break;
        }

        case 2: {
            cout << "\nElevii in ordine alfabetica dupa nume:\n";
            sort(elevi.begin(), elevi.end(), [](const Elev& a, const Elev& b) {
                return a.getNume() < b.getNume();
                });
            for (const Elev& elev : elevi) {
                elev.afisare();
            }
            break;
        }

        case 3: {
            cout << "\nElevii in ordine crescatoare dupa medie:\n";
            sort(elevi.begin(), elevi.end(), [](const Elev& a, const Elev& b) {
                return a.calculeazaMedie() < b.calculeazaMedie();
                });
            for (const Elev& elev : elevi) {
                elev.afisare();
            }
            break;
        }

        case 4: {
            continua = false;
            break;
        }

        default: {
            cout << "Optiune invalida. Va rugam selectati o optiune valida.\n";
            break;
        }
        }
    }

    return 0;
}