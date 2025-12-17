#include <filesystem>
#include <string>
#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <limits.h>
#include <pwd.h>
#include <unistd.h>
#endif
#if defined(__APPLE__)
#include <mach-o/dyld.h>
#endif

std::filesystem::path getExecFolder() {
#ifdef _WIN32
    char path[MAX_PATH];
    HMODULE hModule = GetModuleHandle(nullptr);
    if (hModule && GetModuleFileNameA(hModule, path, MAX_PATH)) {
        //std::cout << std::filesystem::path(path).parent_path() << " ?? \n";
        return std::filesystem::path(path).parent_path();
    }
#elifdef __linux__
    char path[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
    if (count != -1) {
        return std::filesystem::path(std::string(path, count)).parent_path();
    }
#elifdef __APPLE__
    char path[PATH_MAX];
    uint32_t size = sizeof(path);

    if (_NSGetExecutablePath(path, &size) == 0) {
        return std::filesystem::canonical(path).parent_path();
    }
#endif
    return {};
}

bool getFolder(std::filesystem::path folder){
    if (std::filesystem::exists(folder) && std::filesystem::is_directory(folder)){
        return true;
    }

    return false;
}