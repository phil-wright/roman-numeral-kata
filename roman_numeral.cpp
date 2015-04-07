#include "roman_numeral.h"

#include <sstream>

struct ValueNumeralPair {
    int value;
    std::string numeral;
};

class RomanNumeralConverter
{
public:
    RomanNumeralConverter(int arabic)
        : mRemaining(arabic)
    {
        if (arabic < 0 || arabic >= 4000) {
            throw InvalidArgumentException();
        }
    }

    std::string convert()
    {
        const ValueNumeralPair numbersToNumerals[] = {
            { 1000, "M" },
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "IX" },
            { 5, "V" },
            { 4, "IV" },
            { 1, "I" }
        };

        for (const auto& ntn : numbersToNumerals) {
            convertValue(ntn.value, ntn.numeral);
        }

        return mResult.str();
    }

private:
    void convertValue(int value, std::string numeral)
    {
        while (mRemaining >= value) {
            mResult << numeral;
            mRemaining -= value;
        }
    }

    std::ostringstream mResult;
    int mRemaining;
};

std::string romanNumeralOf(int arabic)
{
    return RomanNumeralConverter(arabic).convert();
}
