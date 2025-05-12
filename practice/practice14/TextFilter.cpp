#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>

class TextFilter 
{
public:
    virtual std::string apply(const std::string& input) = 0;
    virtual ~TextFilter() = default;
};

class ReverseFilter : public TextFilter 
{
public:
    std::string apply(const std::string& input) override 
    {
        return std::string(input.rbegin(), input.rend());
    }
};

class UppercaseFilter : public TextFilter 
{
public:
    std::string apply(const std::string& input) override 
    {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
};

class RemoveVowelsFilter : public TextFilter 
{
public:
    std::string apply(const std::string& input) override 
    {
        std::string result;
        for (char c : input) 
        {
            if (std::string("aeiouAEIOU").find(c) == std::string::npos) 
            {
                result += c;
            }
        }
        return result;
    }
};

class CensorBadWordsFilter : public TextFilter 
{
public:
    std::string apply(const std::string& input) override 
    {
        std::string result = input;
        std::vector<std::string> badWords = { "bad", "ugly" };
        for (const auto& word : badWords) {
            size_t pos;
            while ((pos = result.find(word)) != std::string::npos) 
            {
                result.replace(pos, word.length(), std::string(word.length(), '*'));
            }
        }
        return result;
    }
};

int main() 
{
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    std::map<std::string, std::shared_ptr<TextFilter>> strategies = 
    {
        { "reverse", std::make_shared<ReverseFilter>() },
        { "uppercase", std::make_shared<UppercaseFilter>() },
        { "remove_vowels", std::make_shared<RemoveVowelsFilter>() },
        { "censor", std::make_shared<CensorBadWordsFilter>() }
    };

    std::string command;
    while (true) 
    {
        std::cout << "\nChoose a strategy (reverse, uppercase, remove_vowels, censor) or 'exit': ";
        std::getline(std::cin, command);
        if (command == "exit") break;

        if (strategies.count(command))
        {
            std::cout << "Result: " << strategies[command]->apply(input) << "\n";
        }
        else {
            std::cout << "Invalid.\n";
        }
    }

    return 0;
}