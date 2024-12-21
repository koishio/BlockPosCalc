#include <iostream>
#include <iomanip>
#include <cmath>
#include "head.h"

void SetCoordinate(std::string point_name,
    double* x, double* y)
{
    std::cout << info << "输入" << point_name << "横坐标:" << nl;
    std::cin >> *x;
    std::cout << info << "输入" << point_name << "纵坐标:" << nl;
    std::cin >> *y;
}

void CalculateCirclePos(double (*dist)[2], double radius, ALGORITHM algorithm)
{
    // 计算坐标 
    double y = 0;
    for (unsigned int x = 0; x < ceil(radius); x++)
    {
        y = sqrt(radius * radius - x * x);
        // 选择算法
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

    // 计算出现次数
    int count = 1;
    int index = 0;
    for (int x = 0; x < ceil(radius);)
    {
        int index = x;
        // 统计次数
        while (x < ceil(radius + 1) && dist[index][0] == dist[index + 1][0])
        {
            index++;
            count++;
        }
        // 填充次数
        while (x <= index && x < ceil(radius))
        {
            dist[x][1] = count;
            x++;
        }
        // 重置次数
        count = 1;
    }
}

void ShowResult(double (*result)[2], unsigned int point_count, double base_x, double base_y)
{
    std::cout << "======================| 结 果 |======================" << nl << nl;
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
        // 是否灰色
        if (is_gray)
            std::cout << gray;
        std::cout
            << std::setw(width + 4) << result[x][1]
            << rst << nl;
        // 是否换颜色（前后结果是否不同）
        if (x < point_count - 1 && int(result[x][1]) != int(result[x + 1][1]))
            is_gray = !is_gray;
    }
}