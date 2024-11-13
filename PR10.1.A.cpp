#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialnist { RI, PZ, IR };
string specialnistStr[] = { "в", "��", "��" };

struct Student {
    string prizv;
    int kurs;
    Specialnist specialnist;
    union {
        struct {
            int ocinka_fizyka;
            int ocinka_matematyka;
            int ocinka_informatyka;
        };
        int ocinki[3]; 
    };
};

// ������� ��� ��������� ������ ��������
void CreateStudents(Student* students, const int N) {
    int specialnist;
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;
        cout << " �������: ";
        cin >> students[i].prizv;
        cout << " ����: ";
        cin >> students[i].kurs;
        cout << " ������������ (0 - в, 1 - ��, 2 - ��): ";
        cin >> specialnist;
        students[i].specialnist = (Specialnist)specialnist;

        // �������� ������ � ��� ��������
        cout << " ������ � ������: ";
        cin >> students[i].ocinka_fizyka;
        cout << " ������ � ����������: ";
        cin >> students[i].ocinka_matematyka;
        cout << " ������ � �����������: ";
        cin >> students[i].ocinka_informatyka;
        cout << endl;
    }
}

// ������� ��� ��������� ������� ��������
void PrintStudents(const Student* students, const int N) {
    cout << "=============================================================================================================" << endl;
    cout << "| � | �������        | ���� | ������������ | ������ � ������ | ������ � ���������� | ������ � ����������� |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "|" << setw(2) << i + 1
            << " |  " << setw(15) << left << students[i].prizv
            << "|   " << setw(3) << students[i].kurs
            << "|" << setw(15) << specialnistStr[students[i].specialnist]
            << "|   " << setw(14) << students[i].ocinka_fizyka
            << "|   " << setw(18) << students[i].ocinka_matematyka
            << "| " << setw(20) << students[i].ocinka_informatyka << " |" << endl;
    }
    cout << "=============================================================================================================" << endl;
}

// ������� ��� ���������� ������� �������� �� ������� ����� ���� 4,5
int CountHighAverageStudents(const Student* students, const int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        double average = (students[i].ocinka_fizyka + students[i].ocinka_matematyka + students[i].ocinka_informatyka) / 3.0;
        if (average > 4.5) {
            count++;
        }
    }
    return count;
}

// ������� ��� ���������� �������� � �������� ������� �����
string FindSubjectWithHighestAverage(const Student* students, const int N) {
    double sum_fizyka = 0, sum_matematyka = 0, sum_informatyka = 0;

    for (int i = 0; i < N; i++) {
        sum_fizyka += students[i].ocinka_fizyka;
        sum_matematyka += students[i].ocinka_matematyka;
        sum_informatyka += students[i].ocinka_informatyka;
    }

    double avg_fizyka = sum_fizyka / N;
    double avg_matematyka = sum_matematyka / N;
    double avg_informatyka = sum_informatyka / N;

    if (avg_fizyka >= avg_matematyka && avg_fizyka >= avg_informatyka) {
        return "Գ����";
    }
    else if (avg_matematyka >= avg_fizyka && avg_matematyka >= avg_informatyka) {
        return "����������";
    }
    else {
        return "�����������";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "������ ������� ��������: ";
    cin >> N;

    Student* students = new Student[N];

    CreateStudents(students, N);
    PrintStudents(students, N);

    int lowAvgCount = CountHighAverageStudents(students, N);
    cout << "ʳ������ �������� �� ������� ����� ���� 4.5: " << lowAvgCount << endl;

    string lowestAvgSubject = FindSubjectWithHighestAverage(students, N);
    cout << "������� � ��������� ������� �����: " << lowestAvgSubject << endl;

    delete[] students;
    return 0;
}