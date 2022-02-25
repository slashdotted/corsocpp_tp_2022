namespace bar { // namespace declarations can spread over multiple files
    int add(int x, int y);
    int sub(int x, int y = 0); // Default values go into the declaration, not the definition
    // void foo(); // Ambiguous: already declared in main.cpp
}