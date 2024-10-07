#include <iostream>
#include <vector>
#include <cmath>

class Point
{
public:
    float x, y;
    Point(float x, float y) : x(x), y(y) {}
};

class Perceptron
{
public:
    float activate(const Point &point)
    {
        // Activation function: y - x
        return point.y - point.x;
    }
};

void plotPoints(const std::vector<Point> &points, int width, int height, Perceptron &perceptron)
{
    std::vector<std::vector<char>> canvas(height, std::vector<char>(width, ' '));

    for (const auto &point : points)
    {
        int x = static_cast<int>(point.x);
        int y = static_cast<int>(point.y);
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            if (perceptron.activate(point) < 0)
            {
                canvas[y][x] = 'X';
            }
            else
            {
                canvas[y][x] = 'O';
            }
        }
    }

    for (const auto &row : canvas)
    {
        for (const auto &pixel : row)
        {
            std::cout << pixel;
        }
        std::cout << '\n';
    }
}
int main()
{
    // Array of 100 points
    std::vector<Point> points;
    for (int i = 0; i < 100; i++)
    {
        // random point
        float x = static_cast<float>(std::rand() % 60);
        float y = static_cast<float>(std::rand() % 30);
        points.emplace_back(x, y);
    }

    Perceptron perceptron;
    plotPoints(points, 60, 30, perceptron);

    // Add y = x line
    std::vector<Point> linePoints;
    for (int i = 0; i < 60; i++)
    {
        linePoints.emplace_back(static_cast<float>(i), static_cast<float>(i));
    }

    // Plot the line
    for (const auto &point : linePoints)
    {
        int x = static_cast<int>(point.x);
        int y = static_cast<int>(point.y);
        if (x >= 0 && x < 60 && y >= 0 && y < 30)
        {
            std::cout << "\033[" << y + 1 << ";" << x + 1 << "H" << '-';
        }
    }

    std::cout << std::endl;

    return 0;
}
