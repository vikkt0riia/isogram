#include "isogram.hpp"
#include <set>
#include <locale>
#include <cctype>

std::locale locale{""};

auto is_isogram(std::string const& word) -> bool {
    std::set<char> unique_chars;
    
    for (char ch : word) {
        if (std::isalpha(ch, locale)) {  // Проверяем, является ли символ буквой
            char upper_ch = std::toupper(ch, locale);  // Приводим букву к верхнему регистру
            if (unique_chars.find(upper_ch) != unique_chars.end()) {
                return false;  // Буква уже встречалась, значит, не изограмма
            }
            unique_chars.insert(upper_ch);  // Добавляем букву в набор
        }
    }
    
    return true;  // Нет повторяющихся букв, значит, изограмма
}
