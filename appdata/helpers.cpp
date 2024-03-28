// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Helper functions

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <codecvt>
#include "helpers.h"

// Helper function to get the module base address
uintptr_t il2cppi_get_base_address() {
    return (uintptr_t) GetModuleHandleW(L"GameAssembly.dll");
}

// Helper function to open a new console window and redirect stdout there
void il2cppi_new_console() {
    AllocConsole();
    freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
    freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);
    SetConsoleOutputCP(CP_UTF8);
}

void il2cppi_close_console() {
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    FreeConsole();
}

template<typename ... Args>
std::string string_format(const std::string& format, Args ... args)
{
    int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
    if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
    auto size = static_cast<size_t>(size_s);
    auto buf = std::make_unique<char[]>(size);
    std::snprintf(buf.get(), size, format.c_str(), args ...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

#if _MSC_VER >= 1920
// Helper function to convert Il2CppString to std::string
std::string il2cppi_to_string(Il2CppString* str) {
    std::u16string u16(reinterpret_cast<const char16_t*>(str->chars));
    return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(u16);
}

// Helper function to convert System.String to std::string
std::string il2cppi_to_string(app::String* str) {
    if (str == nullptr)
        return std::string("<nullptr>");
    return il2cppi_to_string(reinterpret_cast<Il2CppString*>(str));
}

app::String* string_to_il2cppi(std::string input) {
    return app::Marshal_PtrToStringAnsi((void*)input.c_str(), nullptr);
}

app::String* string_to_il2cppi(std::wstring input) {
    return app::Marshal_PtrToStringUni((void*)input.c_str(), nullptr);
}

std::string il2cppi_to_string(app::Vector2 vec) {
    return string_format("{ x = %f, y = %f }", vec.x, vec.y);
}

std::string il2cppi_to_string(app::Vector3 vec) {
    return string_format("{ x = %f, y = %f, z = %f }", vec.x, vec.y, vec.z);
}

#endif