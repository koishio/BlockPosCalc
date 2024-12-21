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

    std::cout << "简易圆方块坐标计算器 版本:" << VERSION << nl;
    std::cout << "Made by koishio" << nl << nl;
    for (;;)
    {
        SetCoordinate("圆心", &base_x, &base_y);

        // 设置半径
        do
        {
            std::cout << info << "输入半径:" << nl;
            std::cin >> radius;
            if (radius <= 0)
                std::cout << error << "半径必须大于0!" << nl;
        } while (radius <= 0);
        max_x = ceil(radius);

        // 设置舍入算法
        std::cout << info << "坐标舍入算法(0:向下取整 1:四舍五入 2:向上取整 >=3:不进行舍入):" << nl;
        std::cin >> algo;
        if (algo == 0)
            algorithm = FLOOR;
        else if (algo == 1)
            algorithm = ROUND;
        else if (algo == 2)
            algorithm = CEIL;
        else
            algorithm = NONE;
            

        // 创建保存坐标和连续出现次数的数组(0为坐标，1为出现次数)
        double (*result)[2] = new double[max_x][2];

        // 计算结果并保存到数组
        CalculateCirclePos(result, radius, ALGORITHM(algorithm));

        // 显示结果
        ShowResult(result, max_x, base_x, base_y);

        std::cout << info << "继续？(Y/N)" << nl;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y')
            return 0;
    }
}
