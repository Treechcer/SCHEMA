#include "../headerFiles/funcs.h"
#include <filesystem>
#include <iostream>
#include <regex>


using std::cout;
using std::regex;
using std::regex_replace;
using std::string;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        cout << "You have to add the language you want to use";
        return 1;
    }

    std::string fileName = argv[1];
    fileName = fileName[0] == '-' ? fileName.erase(0,1) : fileName;

    string folderName = ((std::filesystem::path)getExecFolder() / "builds" / (fileName)).string();

    if (!getFolder(folderName)){
        cout << "This language doesn't have a set up, create a new folder \"" << folderName << "\" and add files you want to copy when you want this language to be initialized"; 
        return 1;
    }

    std::filesystem::copy(folderName, std::filesystem::current_path(), std::filesystem::copy_options::recursive | std::filesystem::copy_options::overwrite_existing);

    return 0;
}