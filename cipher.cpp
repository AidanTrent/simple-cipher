//Key will allways be processed in revese due to how parseKey works.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string decrypt(std::vector<int> encryptedText, std::vector<int> key)
{
    std::string output;
    int keyIndex = 0;

    for (int i = 0; i < encryptedText.size() + 1; i++)
    {
        if (keyIndex >= key.size())
        {
            keyIndex = 0;
        }
        output += ((char)(encryptedText[i] + key[keyIndex]));
        keyIndex++;
    }
    return output;
}

std::vector<int> encrypt(std::string plainText, std::vector<int> key)
{
    std::vector<int>output;

    //Put characters into int vector
    for (int i = 0; i < plainText.length(); i++)
    {
        output.push_back(plainText[i]);
    }

    int n = plainText.length();
    int keyIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (keyIndex >= key.size())
        {
            keyIndex = 0;
        }
        output[i] -= key[keyIndex];
        keyIndex++;
    }
    return output;
}

std::vector<int> parseKey(int input)
{
    std::vector<int> processedKey{};

    if(input == 0)
    {
        processedKey.push_back(0);
        return processedKey;
    }

    int n = input;
    int digits = 0;
    for (int i = 0; n != 0; i++)
    {
        processedKey.push_back(n % 10);
        n /= 10;
    }
    return processedKey;
}

std::vector<int> parseEncryptedText(std::string input)
{
    std::vector<int> processedText;
    std::string number;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            processedText.push_back(std::stoi(number));
            number = "";
        }
        else
        {
            number += input[i];
        }
    }
    return processedText;
}

int main()
{
    std::string plainText;
    std::vector<int> key;

    std::cout << "\nEncrypt or Decrypt? (1, 2) : ";
    int userIn;
    std::cin >> userIn;

    if (userIn == 1)
    {    
        //Getting data from user
        std::cout << "Enter a string to encrypt : ";
        std::getline(std::cin >> std::ws, plainText);
        std::cout << "Enter a key (integer) : ";
        std::cin >> userIn;
        
        //Processing information
        key = parseKey(userIn);
        std::vector<int> encryptedData = encrypt(plainText, key);

        //Output encrypted information
        std::cout << "\nEncrypted : ";
        for (int i = 0; i < encryptedData.size(); i++)
        {
            std::cout << encryptedData[i];
            std::cout << " ";
        }
        std::cout << '\n';

    }
    else if (userIn == 2)
    {
        //Getting data from user
        std::cout << "Enter a string to decrypt : ";
        std::getline(std::cin >> std::ws, plainText);
        std::cout << "Enter a key (integer) : ";
        std::cin >> userIn;

        //Processing information
        key = parseKey(userIn);
        std::vector<int> processedText = parseEncryptedText(plainText);

        //Output decrypted infromation
        std::cout << "\nDecrypted : " << decrypt(processedText, key) << '\n';
    }
}