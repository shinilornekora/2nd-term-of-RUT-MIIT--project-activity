#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;
// Функция для расчёта среднего арифметического целочисленного столбца
double fun_Inter_sum(int** ptr, int i) {
    double inter_sum;
    inter_sum = 0;
    for (int j = 0; j < 15; j++)
        inter_sum += ptr[j][i];
    inter_sum = inter_sum / 15;
    return inter_sum;
}
// Функция для расчёта среднего арифметического вещественного столбца
double fun_Inter_sum_d(double** ptr, int i) {
    double inter_sum;
    inter_sum = 0;
    for (int j = 0; j < 15; j++)
        inter_sum += ptr[j][i];
    inter_sum = inter_sum / 15;
    return inter_sum;
}
// Функция для расчёта среднего квадратичного отклонения
double fun_refue_sum(int** ptr, double* ptr2, int i) {
    double refue_sum;
    refue_sum = 0;
    for (int j = 0; j < 15; j++) {
        refue_sum += pow(abs(ptr[j][i] - ptr2[i]), 2);
    }
    refue_sum = sqrt(refue_sum);
    return refue_sum;
}
// Функция для расчёта квадратичного отклонения у вещественных чисел
double fun_refue_sum_d(double** ptr, double* ptr2, int i) {
    double refue_sum;
    refue_sum = 0;
    for (int j = 0; j < 15; j++) {
        refue_sum += pow(abs(ptr[j][i] - ptr2[i]), 2);
    }
    refue_sum = sqrt(refue_sum/15);
    return refue_sum;
}

int count(double* arr, int n, double r) {
    int cou = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == r)
            cou++;
    return cou;
}

int* take_two_maximus(double* arr, int n) {
    int *maximums;
    maximums = new int[2];
    maximums[0] = 0;
    maximums[1] = 0;
    double max1 = -1, max2 = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
            maximums[0] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == maximums[0] && count(arr, n, arr[i]) != 2)
            continue;
        if (arr[i] > max2) {
            max2 = arr[i], maximums[1] = i;
        }
    }
    return maximums;
}
// Классификационная функция
double classific_function(double a, double b, double c, double x1, double x2) {
    return a * x1 + b * x2 - c * 0.5;
}

class Neuron_Network {
private: 
    int m = 15, n = 7;
    double
        inter_sum_a[7], inter_sum_b[7], inter_sum_c[7],
        refue_sums_a[7], refue_sums_b[7], refue_sums_c[7],
        inf_a_and_c[7], inf_b_and_a[7], inf_b_and_c[7];
    int* indab = new int[2];
    int* indcb = new int[2];
    int* indac = new int[2];

    // Выделяем память под обучающую выборку
    int** matr_a = new int* [m];
    int** matr_b = new int* [m];
    int** matr_c = new int* [m];
    double** matr_ac = new double* [m];
public:
    // Считываем обучающую выборку из файлов
    Neuron_Network() {
        ifstream a("thingA.txt");
        ifstream b("thingB.txt");
        ifstream c("thingC.txt");
        string as = "11 41 8 22 26 24 11 16 41 9 32 24 27 13 14 42 7 28 20 22 19 19 42 10 38 20 30 16 18 44 8 36 20 23 12 11 44 9 22 20 27 11 15 44 11 30 28 32 17 19 45 10 38 28 30 18 12 46 8 24 22 25 13 12 47 7 24 24 22 11 13 47 9 26 26 28 15 17 47 10 34 24 31 16 19 48 8 38 22 25 19 11 48 10 22 20 30 17 14 49 9 28 26 28 12";
        string bs = "19 30 16 38 22 48 13 18 31 14 36 26 43 11 11 31 16 22 22 49 15 15 31 17 30 28 52 16 19 32 15 38 22 46 19 16 33 15 32 20 44 17 14 34 14 28 24 42 13 19 34 16 38 26 49 19 18 34 17 36 28 51 16 11 35 16 22 20 47 12 15 36 15 30 24 44 11 19 37 16 38 20 49 17 12 38 14 24 26 41 18 11 38 16 22 26 47 11 16 39 15 32 22 45 14";
        string cs = "14 48 17 28 24 50 17 19 50 18 38 28 55 13 18 51 17 36 22 52 19 11 52 17 22 28 50 16 15 52 19 30 28 56 12 19 52 19 38 26 58 11 12 52 20 24 22 61 17 19 54 16 38 24 48 18 16 54 18 32 24 55 11 14 55 17 28 22 52 14 19 55 20 38 28 59 15 18 56 18 36 20 55 13 11 57 16 22 24 49 19 15 57 19 30 26 57 17 16 58 18 32 20 54 12";
        stringstream helper1, helper2, helper3;
        
        for (int i = 0; i < m; i++) {
            matr_a[i] = new int[n];
            matr_b[i] = new int[n];
            matr_c[i] = new int[n];
        }
        for (int i = 0; i < m; i++)
            for (int k = 0; k < n; k++) {
                helper1 << as;
                helper2 << bs;
                helper3 << cs;
                helper1 >> matr_a[i][k];
                helper2 >> matr_b[i][k];
                helper3 >> matr_c[i][k];
            }
    }
    // Считываем среднее арифметическое каждого признака
    void inter_counter() {
        //ofstream t("text.txt");
        for (int i = 0; i < n; i++) {
            inter_sum_a[i] = fun_Inter_sum(matr_a, i);
            inter_sum_b[i] = fun_Inter_sum(matr_b, i);
            inter_sum_c[i] = fun_Inter_sum(matr_c, i);
          //  t << inter_sum_a[i] << " " << inter_sum_b[i] << " " << inter_sum_c[i] << endl;
        }
    }
    // Считываем среднее квадратичное отклонение каждого признака
    void refues() {
        ofstream t("u.txt");
        for (int i = 0; i < n; i++) {
            refue_sums_a[i] = fun_refue_sum(matr_a, inter_sum_a, i);
            refue_sums_b[i] = fun_refue_sum(matr_b, inter_sum_b, i);
            refue_sums_c[i] = fun_refue_sum(matr_c, inter_sum_c, i);
            t << refue_sums_a[i] << " " << refue_sums_b[i] << " " << refue_sums_c[i] << endl;
        }
    }
    void informativnosti() {
        ofstream a("tet.txt");
        // Рассчитываем информативность признаков
        for (int i = 0; i < n; i++) {
            inf_b_and_a[i] = (pow((inter_sum_b[i] - inter_sum_a[i]), 2)) / (pow(refue_sums_b[i], 2) + pow(refue_sums_a[i], 2));
            inf_b_and_c[i] = (pow((inter_sum_b[i] - inter_sum_c[i]), 2)) / (pow(refue_sums_b[i], 2) + pow(refue_sums_c[i], 2));
            inf_a_and_c[i] = (pow((inter_sum_a[i] - inter_sum_c[i]), 2)) / (pow(refue_sums_a[i], 2) + pow(refue_sums_c[i], 2));
            a << inf_a_and_c[i] << " " << inf_b_and_c[i] << " " << inf_b_and_a[i] << '\n';
        }
            indab[0] = take_two_maximus(inf_b_and_a, 7)[0];
            indab[1] = take_two_maximus(inf_b_and_a, 7)[1];
            indac[0] = take_two_maximus(inf_a_and_c, 7)[0];
            indac[1] = take_two_maximus(inf_a_and_c, 7)[1];
            indcb[0] = take_two_maximus(inf_b_and_c, 7)[0];
            indcb[1] = take_two_maximus(inf_b_and_c, 7)[1]; 
    }
    // Первый узел, где мы определяем, относится ли объект к B
    char first_knot(double ar[]) {
        // A v B
        double q = classific_function(
            (inter_sum_b[indab[0]] - inter_sum_a[indab[0]]),
            (inter_sum_b[indab[1]] - inter_sum_a[indab[1]]),
            ((inter_sum_b[indab[0]] - inter_sum_a[indab[0]]) * (inter_sum_a[indab[0]] + inter_sum_b[indab[0]]) +
            (inter_sum_b[indab[1]] - inter_sum_a[indab[1]]) * (inter_sum_a[indab[1]] + inter_sum_b[indab[1]])), ar[indab[0]], ar[indab[1]]);
        // C v B
        double q1 = classific_function(
            (inter_sum_c[indcb[0]] - inter_sum_b[indcb[0]]),
            (inter_sum_c[indcb[1]] - inter_sum_b[indcb[1]]),
            ((inter_sum_c[indcb[0]] - inter_sum_b[indcb[0]]) * (inter_sum_c[indcb[0]] + inter_sum_b[indcb[0]]) +
            (inter_sum_c[indcb[1]] - inter_sum_b[indcb[1]]) * (inter_sum_c[indcb[1]] + inter_sum_b[indcb[1]])), ar[indcb[0]], ar[indcb[1]]);
        if (q > 0) {
            if (q1 > 0) {
                return 'C';
            }
            else {
                return 'B';
            }
        } 
        else {
            return '-';
        }
    }
    // Второй узел - смотрим, относится ли объект к А или С
    char second_knot(double ar[]) {
        // A v C
        ofstream l("t.txt");
        l << "indab: " << indab[0] + 1 << " " << indab[1] + 1 << endl;
        l << "indac: " << indac[0] + 1 << " " << indac[1] + 1 << endl;
        l << "indcb: " << indcb[0] + 1 << " " << indcb[1] + 1 << endl;
        double q2 = classific_function(
            (inter_sum_a[indac[0]] - inter_sum_c[indac[0]]),
            (inter_sum_a[indac[1]] - inter_sum_c[indac[1]]),
            ((inter_sum_a[indac[0]] - inter_sum_c[indac[0]]) * (inter_sum_c[indac[0]] + inter_sum_a[indac[0]]) +
            (inter_sum_a[indac[1]] - inter_sum_c[indac[1]]) * (inter_sum_c[indac[1]] + inter_sum_a[indac[1]])), ar[indac[0]], ar[indac[1]]);
        switch (q2 > 0) {
        case 1:
            return 'A';
        case 0:
            return 'C';
        }

    }
    // Предсказание нейросети на основе математики
    char prediction(double f1, double f2, double f3, double f4, double f5, double f6, double f7) {
        double all[] = { f1, f2, f3, f4, f5, f6, f7 };
        char result = first_knot(all);
        if (!(result == '-'))
            return result;
        else
            return second_knot(all);
        
    }
};