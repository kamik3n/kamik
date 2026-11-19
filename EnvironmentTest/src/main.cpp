#include <iostream>
int main()
{
    std::cout << "EnvironmentTest OK\n";
#if defined(__clang__)
    std::cout << "Compiler: Clang " << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__ << "\n";
#elif defined(__GNUC__)
    std::cout << "Compiler: GCC " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << "\n";
#elif defined(_MSC_VER)
    std::cout << "Compiler: MSVC " << _MSC_VER << "\n";
#else
    std::cout << "Compiler: unknown\n";
#endif
    std::cout << "C++ Standard (__cplusplus): " << __cplusplus << "\n";
#ifdef NDEBUG
    std::cout << "Build type: Release\n";
#else
    std::cout << "Build type: Debug\n";
#endif
    std::cout << "Architecture: " << sizeof(void*) * 8 << "-bit\n";
    return 0;
}
