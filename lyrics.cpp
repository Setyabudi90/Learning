#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>

struct LineText
{
    std::string text;
    int typingSpeed;
    int lineDelay;
};

void typeWritter(std::string &text, int typingSpeed)
{
    for (char c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(typingSpeed));
    }
}

void lyricsTypeEffect(std::vector<LineText> &lyrics)
{
    for (auto &lyricsLine : lyrics)
    {
        typeWritter(lyricsLine.text, lyricsLine.typingSpeed);
        std::this_thread::sleep_for(std::chrono::milliseconds(lyricsLine.lineDelay));
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<LineText> lyrics = {
        {"Ah-ah, oh-oh", 150, 800},
        {"Dengar laraku", 100, 1000},
        {"Suara hati ini memanggil namamu", 120, 600},
        {"Kar'na separuh aku", 80, 1200},
        {"Menyentuh laramu", 80, 800},
        {"Semua lukamu t'lah menjadi lirihku", 60, 500},
        {"Kar'na separuh aku", 80, 600},
        {"Dirimu", 60, 500},
    };

    lyricsTypeEffect(lyrics);
    return 0;
}
