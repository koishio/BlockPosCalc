#include <iostream>
#include <iomanip>
#include <cmath>
#include "head.h"

void SetCoordinate(std::string point_name,
    double* x, double* y)
{
    std::cout << info << "����" << point_name << "������:" << nl;
    std::cin >> *x;
    std::cout << info << "����" << point_name << "������:" << nl;
    std::cin >> *y;
}

void CalculateCirclePos(double (*dist)[2], double radius, ALGORITHM algorithm)
{
    // �������� 
    double y = 0;
    for (unsigned int x = 0; x < ceil(radius); x++)
    {
        y = sqrt(radius * radius - x * x);
        // ѡ���㷨
        switch (algorithm)
        {
        default:
            dist[x][0] = y;
            break;
        case FLOOR:
            dist[x][0] = floor(y);
            break;
        case ROUND:
            dist[x][0] = round(y);
            break;
        case CEIL:
            dist[x][0] = ceil(y);
            break;
        }
    }

    // ������ִ���
    int count = 1;
    int index = 0;
    for (int x = 0; x < ceil(radius);)
    {
        int index = x;
        // ͳ�ƴ���
        while (x < ceil(radius + 1) && dist[index][0] == dist[index + 1][0])
        {
            index++;
            count++;
        }
        // ������
        while (x <= index && x < ceil(radius))
        {
            dist[x][1] = count;
            x++;
        }
        // ���ô���
        count = 1;
    }
}

void ShowResult(double (*result)[2], unsigned int point_count, double base_x, double base_y)
{
    std::cout << "======================| �� �� |======================" << nl << nl;
    std::cout << "=====|x|=====|y|=====|disp_x|=====|disp_y|=====|count|" << nl;
    constexpr int width = 7;
    bool is_gray = 0;
    for (unsigned int x = 0; x < point_count; x++)
    {
        std::cout
            << std::setw(width) << x + base_x << sp
            << std::setw(width) << result[x][0] + base_y << sp
            << std::setw(width + 5) << x << sp
            << std::setw(width + 5) << result[x][0] << sp;
        // �Ƿ��ɫ
        if (is_gray)
            std::cout << gray;
        std::cout
            << std::setw(width + 4) << result[x][1]
            << rst << nl;
        // �Ƿ���ɫ��ǰ�����Ƿ�ͬ��
        if (x < point_count - 1 && int(result[x][1]) != int(result[x + 1][1]))
            is_gray = !is_gray;
    }
}