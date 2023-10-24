#include <iostream>
#include <windows.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

class Homework3 {

public:
    void ChooseTasks() {
        int taskNumber = TakeTaskNumber();

        while (taskNumber != 0) {
            StartChosenTask(taskNumber);
            taskNumber = TakeTaskNumber();
        }
    }

private:
    void LoanTask1() {
        double S, p, n, m, r;

        cout << "Введите S" << endl;
        cin >> S;
        cout << "Введите p" << endl;
        cin >> p;
        cout << "Введите n" << endl;
        cin >> n;

        if (S > 0 && p > 0 && n > 0) {
            r = p / 100.0;
            if (12 * (pow(1 + r, n) - 1 > 0)) {

                m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
                cout << "Месячная выплата m=" << m << endl;
            }
            else {
                cout << "Не возможно вычислить значение m. Знаменатель не может быть меньше или равен 0." << endl;
            }

        }
        else {
            cout << "Значения S, p, n не могут быть меньше или равны 0!" << endl;
        }
    }

private:
    void LoanTask2() {
        double m, n, M, S, r, eps, A, B;

        cout << "Введите S" << endl;
        cin >> S;
        cout << "Введите m" << endl;
        cin >> m;
        cout << "Введите n" << endl;
        cin >> n;

        eps = 0.0001;
        double step = 10;
        double p = 1.0;
        while (p < 100) {
            r = (double)p / 100;
            A = S * r * pow((1 + r), n);
            B = 12 * (pow((1 + r), n) - 1);
            M = A / B;
            if (abs(M - m) < eps) {
                cout << "Процент p = " << p << endl;
                return;
            }
            if (M > m) {
                p -= step;
                step = step / 10;
            }
            p += step;

        }

        cout << "Некорректные данные" << endl;
            }

private:
    void CopyingFilesTask3() {
        string Text;
        ofstream fout("List.txt");
        fout << "1 Алхасов Артур Михайлович 2 Биганов Давид Джамбулатович 3 Борзенков Никита Сергеевич 4 Бориков Евгений Юрьевич 5 Василяко Максим Дмитриевич 6 Ворожбицкий Александр Алексеевич 7 Золотухин Никита Александрович 8 Ичваидзе Михаил Давидович 9 Коломиец Михаил Вячеславович 10 Косенко Денис Валерьевич 11 Кричун Екатерина Витальевна 12 Лобанов Матвей Геннадьевич 13 Ломаев Вячеслав Алексеевич 14 Манохин Антон Витальевич 15 Мезиров Янис Ираклиевич 16 Михайлюк Александр Николаевич 17 Муссалиев Ержан Ерсаинович 18 Надем Мохаммад Сабер 19 Рагимов Хаган Шахсиятович 20 Ремизов Дмитрий Дмитриевич 21 Сантоян Давид Саятович 22 Сиразетдинов Даниил Рустамович 23 Слюньков Иван Алексеевич 24 Тарасов Игорь Алексеевич 25 Тиняков Андрей Геннадьевич 26 Факунин Никита Игоревич 27 Хайретдинова Эльвира Ринатовна 28 Хуссайни Фреба 29 Шадринов Глеб Сергеевич 30 Шипилова Дарья Алексеевна 31 Шорохов Глеб Игоревич";
        fout.close();
        ifstream fin("List.txt");
        while (getline(fin, Text)) {
            cout << Text;
        }
        fin.close();
    }

private:
    void FilterTask4() {
        char readline[1000];
        ifstream fin("List.txt");
        while (fin.getline(readline, 1000)) {

            for (int i = 0; i < strlen(readline); i++) {
                if (isdigit(readline[i]) or readline[i] == '-' or readline[i] == ',' or readline[i] == '.') {
                    cout << readline[i];
                }
            }

            cout << "\n";

        }
        fin.close();
    }

private:
    void LetterSortingTask5() {
        string word = "вашщпирцущшпиВЫРАОывораиGJhbdgiosdbfasiuFAISDU";
        sort(word.begin(), word.end());
        cout << word << std::endl;
    }

private:
    int TakeTaskNumber() {
        cout << "Введите номер задания. Для завершения программы введите \"0\"." << endl;

        int taskNumber;
        cin >> taskNumber;

        return taskNumber;
    }

private:
    void StartChosenTask(int taskNumber) {

        switch (taskNumber)
        {
        case 1:
            LoanTask1();
            break;
        case 2:
            LoanTask2();
            break;
        case 3:
            CopyingFilesTask3();
            break;
        case 4:
            FilterTask4();
            break;
        case 5:
            LetterSortingTask5();
            break;
        default:
            break;
        }
    }


};



int main() {
    setlocale(LC_ALL, "Russian");

    Homework3 Program = Homework3();
    Program.ChooseTasks();

    system("pause");
}