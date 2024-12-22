#include <iostream>
#include "head.h"

int main()
{
    constexpr char nl = '\n';
    constexpr char info[] = "\033[38;5;27m[*]\033[0m ";
    constexpr char error[] = "\033[38;5;1m[E]\033[0m ";

    double radius = 0;
    double base_x = 0;
    double base_y = 0;
    unsigned int algo = 0;
    ALGORITHM algorithm = NONE;
    char choice = '\0';
    int max_x = 0;

    std::cout << "����Բ������������� �汾:" << VERSION << nl;
    std::cout << "Made by koishio" << nl << nl;
    for (;;)
    {
        SetCoordinate("Բ��", &base_x, &base_y);

        // ���ð뾶
        do
        {
            std::cout << info << "����뾶:" << nl;
            std::cin >> radius;
            if (radius <= 0)
                std::cout << error << "�뾶�������0!" << nl;
        } while (radius <= 0);
        max_x = ceil(radius);

        // ���������㷨
        std::cout << info << "���������㷨(0:����ȡ�� 1:�������� 2:����ȡ�� >=3:����������):" << nl;
        std::cin >> algo;
        if (algo == 0)
            algorithm = FLOOR;
        else if (algo == 1)
            algorithm = ROUND;
        else if (algo == 2)
            algorithm = CEIL;
        else
            algorithm = NONE;
            

        // ��������������������ִ���������(0Ϊ���꣬1Ϊ���ִ���)
        double (*result)[2] = new double[max_x][2];

        // �����������浽����
        CalculateCirclePos(result, radius, ALGORITHM(algorithm));

        // ��ʾ���
        ShowResult(result, max_x, base_x, base_y);

        std::cout << info << "������(Y/N)" << nl;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y')
            return 0;
    }
}
