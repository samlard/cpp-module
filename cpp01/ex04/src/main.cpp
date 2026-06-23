#include "Header.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
     {
        std::cerr << "bad number of arguments" << std::endl;
        return 1;
     }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "error :s1 is empty" << std::endl;
        return 1;
    }
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "could not open infile: " << filename << std::endl;
        return 1;
    }
    std::string new_file = filename;
    new_file+= ".replace";
    std::ofstream outfile (new_file.c_str(), std::ios::out);
    if (!outfile)
    {
        std::cerr << "could not created outfile: " << new_file << std::endl;
        return (1); 
    }
    std::string line;
    std::string modified_line;
    size_t pos = 0;
    while (getline(infile, line))
    {
        size_t start = 0;
        while ((pos = line.find(s1, start)) != std::string::npos)
        {
            modified_line += line.substr(start, pos - start);
            modified_line += s2;
            start = pos + s1.length();
        }
        modified_line += line.substr(start);
        outfile << modified_line << std::endl;
        modified_line.clear();
        start = 0;
        line.clear();
    }
    return 0;
}