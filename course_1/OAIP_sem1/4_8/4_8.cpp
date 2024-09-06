#include <iostream>

long long factorial(int number)
{
    if (number == 1 || number == 0)
        return 1;
    else
        return number * factorial(number - 1);
}

int main()
{
    std::string input;
    std::cin >> input;
    long long count[52]{ 0 };
    long long perm = factorial(input.size());

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] < 91)
            count[input[i] - 65]++;
        else
            count[input[i] - 71]++;
    }

    for (int i = 0; i < 52; i++)
    {
        if (count[i] > 1)
            perm /= factorial(count[i]);
    }

    std::cout << perm;
}




























/*#include <iostream>

long long fact(int numb)
{
    if (numb == 1 || !numb)
        return 1;
    return numb * fact(numb - 1);
}
int main()
{
    std::string str;
    std::cin >> str;
    long long numb[52]{ 0 }, result = fact(str.size());
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < 91)
            numb[str[i] - 65]++;
        else
            numb[str[i] - 97 + 26]++;
    }
    for (int i = 0; i < 52; i++)
    {
        if (numb[i] == 1 || !numb[i])
            continue;
        result /= fact(numb[i]);
    }
    std::cout << result;
}*/