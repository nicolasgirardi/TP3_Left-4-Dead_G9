#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main(){
    std::fstream input;
    input.open("paths.txt",std::ifstream::in);
    std::string line;
    std::fstream output;
    output.clear();
    std::string name;
    output.open("newpaths.txt",std::ofstream::out);
    while(std::getline(input,line)){
        if(line.size()>4){
        output << "extern const std::string "; 
        name = line;
        name.erase(0,13);
        name.erase(name.size()-4);
        std::replace(name.begin(),name.end(),'/','_');
        output << name;
        output << " = \"";
        output << line;
        output << "\";";
        output << std::endl;
        output.clear();
        }
    }
    return 0;
}