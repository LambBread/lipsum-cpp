#ifndef LIPSUM_BUILD_STATIC
#define LIPSUM_IMPLEMENTATION
#endif
#include <lipsum.hpp>

template<typename T>
T ToType(const std::string& str)
{
    std::stringstream ss(str);
    T ret;
    ss >> std::boolalpha >> ret;
    return ret;
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        return 0;
    }

    //int realArgc = argc; //argc minus optional params
    std::vector<std::string> options;
    std::vector<std::string> commandOpts;

    for(int i = 1; i < argc; ++i)
    {
        std::string realArg = argv[i];
        if(realArg.starts_with("--"))
        {
            options.push_back(realArg);
            //--realArgc;
        }
        else
        {
            commandOpts.push_back(realArg);
        }
    }

    for(const auto& option : options)
    {
        std::cout << option << '\n';
    }

    for(const auto& option : commandOpts)
    {
        std::cout << option << '\n';
    }

    lpsm::Generator gen;
    
    if(commandOpts.size() <= 0)
    {
        return 0;
    }

    std::string subcommand = commandOpts.at(0);
    
    if(subcommand == "word")
    {
        int num = 1;
        if(commandOpts.size() >= 2)
        {    
            num = ToType<int>(commandOpts.at(1));
        }
        std::cout << gen.word(num);
    }
    else if(subcommand == "sentence_fragment")
    {
        std::cout << gen.sentence_fragment();
    }
    else if(subcommand == "sentence")
    {
        int num = 1;
        bool useLipsum = true;
        if(commandOpts.size() >= 2)
        {
            num = ToType<int>(commandOpts.at(1));
        }
        if(commandOpts.size() >= 3)
        {
            useLipsum = ToType<bool>(commandOpts.at(2));
        }
        std::cout << gen.sentence(num, useLipsum);
    }


    return 0;
}
