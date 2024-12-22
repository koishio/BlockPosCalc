#pragma once

constexpr char VERSION[] = "1.1";   // �汾��
constexpr char nl = '\n';           // ����
constexpr char sp = ' ';            // �ո�
constexpr char info[] = "\033[38;5;27m[*]\033[0m ";     // ��ɫ��ʾ
constexpr char error[] = "\033[38;5;1m[E]\033[0m ";     // ��ɫ����
constexpr char gray[] = "\033[38;5;239m";     // ��ɫ
constexpr char rst[] = "\033[0m";   // ������ɫ

// �����㷨
enum ALGORITHM
{
    FLOOR = 0,
    ROUND = 1,
    CEIL = 2,
    NONE = 3
};

// ���õ�����Ϊ(x,y)
extern void SetCoordinate(std::string point_name, double* x, double* y);

// �����������������ִ���
extern void CalculateCirclePos(double (*dist)[2], double radius, ALGORITHM algorithm);

// ��ʾ���
extern void ShowResult(const double (*result)[2], unsigned int point_count, double base_x, double base_y);