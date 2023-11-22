#define _USE_MATH_DEFINES
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Dz2 {

public:
    void ChooseTasks() {
        int taskNumber = TakeTaskNumber();

        while (taskNumber != 0) {
            StartChosenTask(taskNumber);
            taskNumber = TakeTaskNumber();
        }
    }

private:

    void Task1() {
        string path, buff, res;
        const int size = 10;
        double numbers[size];
        int activeSize = 0;
        double input = 0, sum = 0;
        cout << "Введите " << size << " чисел, разделяя их через перенос строки" << endl;

        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }

        for (int i = 0; i < size; i++) {
            res += to_string(numbers[i]) + "\n";
        }

        cout << "Введите путь до файла" << endl;
        cin >> path;

        ofstream fout(path);
        if (fout.is_open()) {
            fout << res;
        }
        else {
            cout << "Ошибка создания файла" << endl;
            return;
        }
        fout.close();

        cout << "Файл создан" << endl;

        ifstream fin(path);
        while (getline(fin, buff)) {
            sum += stoi(buff);
        }
        fin.close();

        cout << "Сумма равна " << setprecision(8) << sum << endl;
    }

    int func(double x) {
        if (x == 0) {
            return 0;
        }
        return x > 0 ? 1 : -1;
    }

private:
    void Task2() {
        double x;

        cout << "Введите х " << endl;
        cin >> x;

        cout << "Знак числа равен " << func(x) << endl;
    }


    double P() {
        double a, b;

        cout << "Площадь по сторонам" << endl;

        cout << "Введите a" << endl;
        cin >> a;
        cout << "Введите b" << endl;
        cin >> b;

        return a * b;
    }

    double T() {
        double a, b, c, p;

        cout << "Площадь по сторонам(s)" << endl;

        cout << "Введите a" << endl;
        cin >> a;
        cout << "Введите b" << endl;
        cin >> b;
        cout << "Введите c" << endl;
        cin >> c;

        if (a >= b + c || b >= a + c || c > b + a)
            return 0;

        p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double C() {
        double r;

        cout << "Введите r" << endl;
        cin >> r;
        if (r <= 0)
            return 0;
        return M_PI * pow(r, 2);
    }

private:
    void Task3() {
        char choice;
        double S;

        cout << "Площадь прямоугольника(p), треугольника(t), круга(c)" << endl;
        cin >> choice;
        try {
            switch (choice) {
            case 'p':
                S = P();
                break;
            case 't':
                S = T();
                break;
            case 'c':
                S = C();
                break;
            default:
                cout << "Некорректный ввод" << endl;
                return;
            }
        }
        catch (...) {
            cout << "Некорректный ввод" << endl;
            return;
        }
        if (S <= 0 || isnan(S) || isinf(S)) {
            cout << "Некорректный ввод" << endl;
            return;
        }
        cout << "S = " << S << endl;
    }

    void drawLine() {
        for (int i = 0; i < 100; i++)
            cout << "#";
    }

private:
    void Task4() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleCursorPos;
        COORD cPos;
        const int idRed = 4 * 17;
        const int idWhite = 255;

        GetConsoleScreenBufferInfo(hConsole, &consoleCursorPos);
        cPos.X = consoleCursorPos.dwCursorPosition.X;
        cPos.Y = consoleCursorPos.dwCursorPosition.Y;

        for (int i = 0; i < 14; i++) {
            SetConsoleTextAttribute(hConsole, idWhite);
            drawLine();
            SetConsoleTextAttribute(hConsole, 15);
            cout << endl;
            cPos.Y++;
            SetConsoleCursorPosition(hConsole, cPos);
        }

        for (int i = 0; i < 14; i++) {
            SetConsoleTextAttribute(hConsole, idRed);
            drawLine();
            SetConsoleTextAttribute(hConsole, 15);
            cout << endl;
            cPos.Y++;
            SetConsoleCursorPosition(hConsole, cPos);
        }

        SetConsoleTextAttribute(hConsole, 15);
    }

    BOOL DrawLine(HDC hdc, int x1, int y1, int x2, int y2) {
        MoveToEx(hdc, x1, y1, NULL);
        return LineTo(hdc, x2, y2);
    }

private:
    void Task5() {
        int MaxX, MaxY, currentX, currentY;
        double amplitude, period;
        const int PIXELCOUNT = 16;
        const int indentation = 10;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleCursorPos;
        COORD cPos;
        COLORREF color = RGB(255, 255, 255);

        cout << "Введите max X" << endl;
        cin >> MaxX;
        MaxX *= PIXELCOUNT;
        cout << "Введите max Y" << endl;
        cin >> MaxY;
        MaxY *= PIXELCOUNT;
        cout << "Введите amplitude" << endl;
        cin >> amplitude;
        cout << "Введите period" << endl;
        cin >> period;

        HWND hWnd = GetConsoleWindow();
        HDC hDc = GetDC(hWnd);
        GetConsoleScreenBufferInfo(hConsole, &consoleCursorPos);
        currentX = consoleCursorPos.dwCursorPosition.X * PIXELCOUNT;
        currentY = consoleCursorPos.dwCursorPosition.Y * PIXELCOUNT;

        HPEN pen = CreatePen(PS_SOLID, 1, color);
        SelectObject(hDc, pen);
        for (int i = currentY; i < currentY + MaxY * 2; ++i)
            DrawLine(hDc, currentX, i, currentX + MaxX * 2, i);

        color = RGB(0, 0, 0);
        for (double x1 = currentY; x1 < currentY + (MaxY - indentation) * 2; x1 += 0.001)
            SetPixel(hDc, MaxX, indentation + x1, color);
        for (double x1 = currentX + indentation; x1 < (MaxX - indentation) * 2; x1 += 0.001)
            SetPixel(hDc, x1, currentY + MaxY, color);
        color = RGB(0, 0, 255);
        for (double x1 = -MaxX + indentation; x1 < MaxX - indentation * 2; x1 += 0.001) {
            int y1 = sin(M_PI * 2 / period * x1) * amplitude * pow(M_E, -0.003 * x1);
            SetPixel(hDc, x1 + MaxX, currentY + MaxY - y1, color);
        }

        GetConsoleScreenBufferInfo(hConsole, &consoleCursorPos);
        cPos.X = consoleCursorPos.dwCursorPosition.X;
        cPos.Y = consoleCursorPos.dwCursorPosition.Y + MaxY / 8;

        SetConsoleCursorPosition(hConsole, cPos);
    }

    int numFromR(char n) {
        if (n == 'I') {
            return 1;
        }
        if (n == 'V') {
            return 5;
        }
        if (n == 'X') {
            return 10;
        }
        if (n == 'L') {
            return 50;
        }
        if (n == 'C') {
            return 100;
        }
        if (n == 'D') {
            return 500;
        }
        if (n == 'M') {
            return 1000;
        }
        return 0;
    }

private:
    void Task6() {
        int num{};
        string input;

        cout << "Введите число в римской сс: " << endl;
        cin >> input;

        int lastN = 0;
        int n = 0;

        for (int i = input.length() - 1; i >= 0; i--) {
            n = numFromR(input[i]);
            if (n == 0) {
                cout << "Некорректные данные" << endl;
                return;
            }
            if (n < lastN) {
                num -= n;
            }
            else {
                num += n;
            }
            lastN = n;
        }

        int N[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
        string I[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };

        string res = "";
        int i = 12;
        int checkNum = num;
        while (checkNum > 0) {
            while (N[i] > checkNum) {
                i--;
            }
            res += I[i];
            checkNum -= N[i];
        }

        if (res != input) {
            cout << "Некорректные данные" << endl;
            return;
        }

        cout << "Число равно: " << num << endl;
    }

private:
    void Task7() {
        int m, i, c;
        char choice;
        const int size = 20;
        int numbers[size];

        cout << "Использовать вариант 1(1), 2(2)" << endl;
        cin >> choice;

        switch (choice)
        {
        case '1':
            m = 37;
            i = 3;
            c = 64;
            break;
        case '2':
            m = 25173;
            i = 13849;
            c = 65537;
            break;
        default:
            cout << "Некорректный ввод" << endl;
            return;
        }

        numbers[0] = i;

        for (int j = 1; j < size; j++)
        {
            numbers[j] = (m * numbers[j - 1] + (i + j)) % c;
        }

        for (int i = 0; i < size; i++) {
            cout << numbers[i] << endl;
        }
    }

private:
    void Task8() {
        const int ProductsCount = 4;
        const int MerchantsCount = 3;
        const int ProductsInfoCount = 2;
        double A[MerchantsCount][ProductsCount]{};
        double B[ProductsCount][ProductsInfoCount]{};
        int MerchantsShapes = ProductsCount * MerchantsCount;

        cout << "Введите матрицу A(числа вводятся через перенос строки, начиная с элемента i=0 j=0, заполняются строки)" << endl;
        for (int i = 0; i < MerchantsCount; i++) {
            for (int j = 0; j < ProductsCount; j++) {
                cin >> A[i][j];
            }
        }
        cout << "Введите матрицу B(числа вводятся через перенос строки, начиная с элемента i=0 j=0, заполняются строки)" << endl;
        for (int i = 0; i < ProductsCount; i++) {
            for (int j = 0; j < ProductsInfoCount; j++) {
                cin >> B[i][j];
            }
        }


        double C[MerchantsCount][ProductsInfoCount];
        double val = 0;

        for (int i = 0; i < MerchantsCount; i++) {
            for (int j = 0; j < ProductsInfoCount; j++) {
                val = 0;
                for (int I = 0; I < ProductsCount; I++)
                    val += A[i][I] * B[I][j];
                C[i][j] = val;
            }
        }

        double maxSum = 0, minSum = 100000, sum{};
        int maxMerchantId{}, minMerchantId{};

        for (int i = 0; i < MerchantsCount; i++) {
            sum = C[i][0];
            if (maxSum < sum) {
                maxSum = sum;
                maxMerchantId = i;
            }
            if (minSum > sum) {
                minSum = sum;
                minMerchantId = i;
            }
        }

        cout << "1) Больше всего (" << maxSum << ") выручил: " << maxMerchantId + 1 <<
            ". Меньше всего (" << minSum << ") выручил: " << minMerchantId + 1 << endl;

        maxSum = 0;
        minSum = 100000;

        for (int i = 0; i < MerchantsCount; i++) {
            sum = C[i][1];
            if (maxSum < sum) {
                maxSum = sum;
                maxMerchantId = i;
            }
            if (minSum > sum) {
                minSum = sum;
                minMerchantId = i;
            }
        }

        cout << "2) Больше всего (" << maxSum << ") получил: " << maxMerchantId + 1 <<
            ". Меньше всего (" << minSum << ") получил: " << minMerchantId + 1 << endl;

        sum = 0;
        for (int i = 0; i < MerchantsCount; i++)
            sum += C[i][0];

        cout << "3) Общая сумма денег, вырученных за проданные товары = " << sum << endl;

        sum = 0;
        for (int i = 0; i < MerchantsCount; i++)
            sum += C[i][1];

        cout << "4) Общая сумма комисионных = " << sum << endl;

        sum = 0;
        for (int i = 0; i < MerchantsCount; i++) {
            for (int j = 0; j < ProductsInfoCount; j++) {
                sum += C[i][j];
            }
        }

        cout << "5) Общая сумма денег, прошедших через руки = " << sum << endl;


    }

private:
    void Task9() {
        int oldS, newS, buff{}, mod, i, len;
        string input, result;
        bool isM{};

        cout << "Введите старое основание" << endl;
        cin >> oldS;
        cout << "Введите новое основание" << endl;
        cin >> newS;
        cout << "Введите исходное число" << endl;
        cin >> input;

        if (input[0] == '-') {
            isM = true;
            input[0] = '0';
        }

        if (newS <= 0 || oldS <= 0) {
            cout << "Некорректная СС" << endl;
            return;
        }

        len = input.length();
        i = 1;

        for (char c : input) {
            if (48 <= c && c <= 57) {
                if ((c - 48) >= oldS) {
                    cout << "Исходное число не может быть представленно в заданной начальной СС" << endl;
                    return;
                }
                buff += (c - 48) * pow(oldS, len - i);
            }
            else if (65 <= c && c <= 90) {
                if ((c - 55) >= oldS) {
                    cout << "Исходное число не может быть представленно в заданной начальной СС" << endl;
                    return;
                }
                buff += (c - 55) * pow(oldS, len - i);
            }
            else {
                cout << "Неверно введено число" << endl;
                return;
            }
            i++;
        }
        while (buff > 0) {
            mod = buff % newS;
            if (mod >= 10) {
                result = (char)(mod + 55) + result;
            }
            else {
                result = to_string(mod) + result;
            }
            buff /= newS;
        }
        result = isM ? '-' + result : result;
        cout << result << endl;
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
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;
        case 4:
            Task4();
            break;
        case 5:
            Task5();
            break;
        case 6:
            Task6();
            break;
        case 7:
            Task7();
            break;
        case 8:
            Task8();
            break;
        case 9:
            Task9();
            break;
        default:
            break;
        }
    }

};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Dz2 Program = Dz2();
    Program.ChooseTasks();

    system("pause");
}
