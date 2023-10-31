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
            m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
            if (m > 0 && !isnan(m) && !isinf(m)) {
               
                cout << "Месячная выплата m=" << m << endl;
            }
            else {
                cout << "Некорректное значение" << endl;
            }

        }
        else {
            cout << "Значения S, p, n не могут быть меньше или равны 0" << endl;
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
        string filename, input;
        cout << "Введите имя файла" << endl;
        cin >> filename;
        ofstream file(filename + ".txt");
        cout << "Введите содеражние файла (Для окончания ввода нажмите Enter)" << endl;
        cin >> input;
        while (input != "")
        {
            file << input << "\n";
            getline(cin, input);
        }
        file.close();
        cout << "Файл успешно записан и создан" << endl;
        ifstream file2(filename + ".txt");
        while (file2)
        {
            getline(file2, input);
            cout << input << endl;
        }
        file2.close();
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
        const int N = 30;
        string input;
        char arr[N];
        bool sorted;
        int l;

        cout << "Введите строку (Отсортируются " << N << " символов):" << endl;
        cin >> input;

        for (int i = 0; i < N; i++) {
            arr[i] = input[i];
        }

        while (true) {
            sorted = true;
            l = (int)arr[0];

            for (int i = 1; i < N; i++) {
                if (l > (int)arr[i])
                    sorted = false;
                l = (int)arr[i];
            }

            if (sorted)
                break;

            int temp, r;
            for (int i = 0; i < N; i++) {
                temp = arr[i];
                r = rand() % N;
                arr[i] = arr[r];
                arr[r] = temp;
            }
        }

        for (int i = 0; i < N; i++) {
            cout << arr[i];
        }
        cout << endl;
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Homework3 Program = Homework3();
    Program.ChooseTasks();

    system("pause");
}