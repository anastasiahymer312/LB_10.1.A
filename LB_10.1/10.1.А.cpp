#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { MATHECON, PHYSINFO, WORKSTUDY, CS, INF };
string speciality_str[] = {
    "���������� �� ��������",
    "Գ���� �� �����������",
    "������� ��������",
    "����'����� �����",
    "�����������"
};

struct Student {
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_info;

    // ����������� ��� ����������� ���� ���������� �� �������������
    Student()
        : course(1), speciality(MATHECON), grade_physics(0), grade_math(0), grade_info(0) {}
};

void Create(Student* students, int N);
void Print(const Student* students, int N);
int CountExcellent(const Student* students, int N);
double PercentagePhysicsFive(const Student* students, int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "������ ������� �������� : ";
    cin >> N;

    Student* students = new Student[N];

    Create(students, N);
    Print(students, N);

    int excellent_count = CountExcellent(students, N);
    cout << "ʳ������ ��������, �� ������� �� '������': " << excellent_count << endl;

    double percentage_physics = PercentagePhysicsFive(students, N);
    cout << "������� ��������, �� �������� '5' � ������: "
        << fixed << setprecision(2) << percentage_physics << "%" << endl;

    delete[] students;
    return 0;
}

void Create(Student* students, int N) {
    for (int i = 0; i < N; i++) {
        cout << "������� #" << i + 1 << ":\n";
        cin.ignore();
        cout << "�������: ";
        getline(cin, students[i].surname);

        cout << "����: ";
        cin >> students[i].course;

        int speciality;
        cout << "������������ (0 - ���������� �� ��������, 1 - Գ���� �� �����������, 2 - ������� ��������, 3 - ����'����� �����, 4 - �����������): ";
        cin >> speciality;
        students[i].speciality = (Speciality)speciality;

        cout << "������ � ������: ";
        cin >> students[i].grade_physics;
        cout << "������ � ����������: ";
        cin >> students[i].grade_math;
        cout << "������ � �����������: ";
        cin >> students[i].grade_info;

        cout << endl;
    }
}

void Print(const Student* students, int N) {
    cout << "================================================================================================\n";
    cout << "| �  | �������          | ���� | ������������             | Գ���� | ���������� | �����������|\n";
    cout << "------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(3) << right << i + 1 << " "
            << "| " << setw(17) << left << students[i].surname
            << "| " << setw(4) << right << students[i].course << " "
            << "| " << setw(24) << left << speciality_str[students[i].speciality]
            << "| " << setw(7) << right << students[i].grade_physics << " "
            << "| " << setw(10) << right << students[i].grade_math << " "
            << "| " << setw(11) << right << students[i].grade_info << " |\n";
    }

    cout << "================================================================================================\n";
}

int CountExcellent(const Student* students, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].grade_physics == 5 && students[i].grade_math == 5 && students[i].grade_info == 5) {
            count++;
        }
    }
    return count;
}

double PercentagePhysicsFive(const Student* students, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].grade_physics == 5) {
            count++;
        }
    }
    return (double)count / N * 100;
}
