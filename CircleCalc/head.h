#pragma once

constexpr char VERSION[] = "1.1";   // 版本号
constexpr char nl = '\n';           // 换行
constexpr char sp = ' ';            // 空格
constexpr char info[] = "\033[38;5;27m[*]\033[0m ";     // 蓝色提示
constexpr char error[] = "\033[38;5;1m[E]\033[0m ";     // 红色报错
constexpr char gray[] = "\033[38;5;239m";     // 灰色
constexpr char rst[] = "\033[0m";   // 重置颜色

// 舍入算法
enum ALGORITHM
{
    FLOOR = 0,
    ROUND = 1,
    CEIL = 2,
    NONE = 3
};

// 设置点坐标为(x,y)
extern void SetCoordinate(std::string point_name, double* x, double* y);

// 计算点坐标和连续出现次数
extern void CalculateCirclePos(double (*dist)[2], double radius, ALGORITHM algorithm);

// 显示结果
extern void ShowResult(const double (*result)[2], unsigned int point_count, double base_x, double base_y);