#include <random>
#include <iostream>

class Perceptron
{
public:
    int weights[2];

    // initialize weights of perceptron
    Perceptron()
    {
        for (int i = 0; i < 2; i++)
        {
            double random_number = (static_cast<double>(std::rand()) / RAND_MAX) * 2 - 1;
            weights[i] = random_number;
        }
    }
};

int inputCalculation(int input1, int input2, Perceptron p)
{
    return input1 * p.weights[0] + input2 * p.weights[1];
}

// Activation function
int activationFunction(int input)
{
    if (input > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// function to guess the output
int guessOutput(int input1, int input2, Perceptron p)
{
    int input = inputCalculation(input1, input2, p);
    return activationFunction(input);
}

// function to train the perceptron
void trainPerceptron(int input1, int input2, int target, Perceptron &p)
{
    int guess = guessOutput(input1, input2, p);
    int error = target - guess;

    double learning_rate = 0.1;

    for (int i = 0; i < 2; i++)
    {
        p.weights[i] += error * learning_rate;
    }
}

int main()
{
    Perceptron p;

    int input1 = 2;
    int input2 = 3;

    int input = inputCalculation(input1, input2, p);
    int output = activationFunction(input);

    std::cout << "Output: " << output << std::endl;

    return 0;
}
