
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

void run(const std::string& source)
{
    //TODO scanner , Token
    Scanner scanner = new(source);
    vector<Token> tokens = Scanner.ScanTokens() ;
    std::cout << source << '\n';
    for(auto t : tokens){
        std::cout << t << '\n'; 
    }
}

void runFile(const std::string& path)
{
    std::ifstream file(path, std::ios::binary);

    if (!file)
    {
        std::cerr << "Could not open file: " << path << '\n';
        std::exit(74);
    }

    std::string source{
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    };

    run(source);
}

void runPrompt()
{
    std::string line;

    while (true)
    {
        std::cout << "> ";

        if (!std::getline(std::cin, line))
            break;

        run(line);
    }
}

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        std::cout << "Usage: jlox [script]\n";
        return 64;
    }

    if (argc == 2)
    {
        runFile(argv[1]);
    }
    else
    {
        runPrompt();
    }

    return 0;
}
