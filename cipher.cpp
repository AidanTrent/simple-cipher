//Currently has to remove whitespace and punctuation.
//Key will allways be processed in revese due to how parseKey works.

#include <iostream>
#include <vector>
#include <algorithm>

std::string decrypt(std::string plainText, std::vector<int> key)
{
    std::string output = plainText;

    int n = output.length();
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (x >= key.size())
        {
            x = 0;
        }
        output[i] += key[x];
        x++;
    }
    return output;
}

std::string encrypt(std::string plainText, std::vector<int> key)
{
    std::string output = plainText;

    int n = output.length();
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (x >= key.size())
        {
            x = 0;
        }
        output[i] -= key[x];
        x++;
    }
    return output;
}

std::vector<int> parseKey(int input)
{
    std::vector<int> processedKey;
    int n = input;
    int digits = 0;
    for (int i = 0; n != 0; i++)
    {
        processedKey.push_back(n % 10);
        n /= 10;
    }
    return processedKey;
}

int main()
{
    std::string plainText;
    std::vector<int> key;

    std::cout << "\nEncrypt or Decrypt? (0, 1) : ";
    int userIn;
    std::cin >> userIn;

    if (userIn == 0)
    {    
        std::cout << "Enter a string to encrypt : ";
        std::getline(std::cin >> std::ws, plainText);
        plainText.erase(std::remove_if(plainText.begin(), plainText.end(), ::isspace), plainText.end());
        plainText.erase(std::remove_if(plainText.begin(), plainText.end(), ::ispunct), plainText.end());
        std::cout << "Enter a key (integer) : ";
        std::cin >> userIn;
        key = parseKey(userIn);

        std::cout << "\nEncrypted : " << encrypt(plainText, key) << '\n';
    }
    else if (userIn == 1)
    {
        std::cout << "Enter a string to decrypt : ";
        std::getline(std::cin >> std::ws, plainText);
        std::cout << "Enter a key : ";
        std::cin >> userIn;
        key = parseKey(userIn);

        std::cout << "\nDecrypted : " << decrypt(plainText, key) << '\n';
    }


}