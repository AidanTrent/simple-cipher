#include <iostream>
#include <vector>

int key[6] = {5, 2, 8, 3, 7, 2};

std::string decrypt(std::string plainText)
{
    std::string output = plainText;

    int n = output.length();
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (x > 6)
        {
            x = 0;
        }
        output[i] += key[x];
        x++;
    }
    return output;
}

std::string encrypt(std::string plainText)
{
    std::string output = plainText;

    int n = output.length();
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (x > 6)
        {
            x = 0;
        }
        output[i] -= key[x];
        x++;
    }
    return output;
}

int main()
{
    std::string plainText;
    
    std::cout << "Enter a string to encrypt : ";
    std::getline(std::cin, plainText);

    std::cout << "\n Encrypted : " << encrypt(plainText);

    std::cout << "\n Decrypted : " << decrypt(encrypt(plainText)) << '\n';
}