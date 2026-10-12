#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

/* ---------- type detection ---------- */

enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

static bool isPseudoFloat(const std::string& s)
{
    return s == "nanf" || s == "+inff" || s == "-inff" || s == "inff";
}

static bool isPseudoDouble(const std::string& s)
{
    return s == "nan" || s == "+inf" || s == "-inf" || s == "inf";
}

// Checks "[+-]digits" with at least one digit
static bool isIntLiteral(const std::string& s)
{
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.length(); i++)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

// Checks "[+-]digits.digits" with exactly one dot and at least one digit
static bool isDecimalLiteral(const std::string& s)
{
    size_t i = 0;
    int    dots = 0;
    int    digits = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;
    for (; i < s.length(); i++)
    {
        if (s[i] == '.')
            dots++;
        else if (std::isdigit(s[i]))
            digits++;
        else
            return false;
    }
    return dots == 1 && digits > 0;
}

static LiteralType detectType(const std::string& s)
{
    if (s.empty())
        return INVALID;
    if (s.length() == 1 && !std::isdigit(s[0]))
        return CHAR;
    if (isPseudoFloat(s))
        return FLOAT;
    if (isPseudoDouble(s))
        return DOUBLE;
    if (isIntLiteral(s))
        return INT;
    if (s[s.length() - 1] == 'f' && isDecimalLiteral(s.substr(0, s.length() - 1)))
        return FLOAT;
    if (isDecimalLiteral(s))
        return DOUBLE;
    return INVALID;
}

/* ---------- printing ---------- */

static bool isNan(double d)
{
    return d != d;
}

static bool isInf(double d)
{
    return d == std::numeric_limits<double>::infinity()
        || d == -std::numeric_limits<double>::infinity();
}

// Turns a number into text, adding ".0" when it has no decimal part (42 -> 42.0)
// and a '+' before positive infinity
static std::string formatDecimal(double value)
{
    std::ostringstream oss;

    if (isInf(value) && value > 0)
        oss << "+";
    oss << value;
    std::string str = oss.str();
    if (!isNan(value) && !isInf(value)
        && str.find('.') == std::string::npos && str.find('e') == std::string::npos)
        str += ".0";
    return str;
}

static void printChar(double value)
{
    std::cout << "char: ";
    if (isNan(value) || isInf(value)
        || value < std::numeric_limits<char>::min()
        || value > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
    std::cout << "int: ";
    if (isNan(value) || isInf(value)
        || value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(float value)
{
    std::cout << "float: " << formatDecimal(value) << "f" << std::endl;
}

static void printDouble(double value)
{
    std::cout << "double: " << formatDecimal(value) << std::endl;
}

static void printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

/* ---------- conversion from each real type ---------- */

static void fromChar(char c)
{
    printChar(static_cast<double>(c));
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

static void fromInt(int i)
{
    printChar(static_cast<double>(i));
    std::cout << "int: " << i << std::endl;
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

static void fromFloat(float f)
{
    printChar(static_cast<double>(f));
    printInt(static_cast<double>(f));
    printFloat(f);
    printDouble(static_cast<double>(f));
}

static void fromDouble(double d)
{
    printChar(d);
    printInt(d);
    printFloat(static_cast<float>(d));
    printDouble(d);
}

/* ---------- entry point ---------- */

void ScalarConverter::convert(const std::string& literal)
{
    LiteralType type = detectType(literal);

    if (type == INVALID)
    {
        std::cout << "Error: invalid literal" << std::endl;
        return;
    }
    if (type == CHAR)
    {
        fromChar(literal[0]);
        return;
    }

    // strtod understands "nan", "+inf", "-inf" and stops at the trailing 'f'
    errno = 0;
    double value = std::strtod(literal.c_str(), NULL);
    if (errno == ERANGE)
    {
        printImpossible();
        return;
    }

    if (type == INT)
    {
        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
            printImpossible();
        else
            fromInt(static_cast<int>(value));
    }
    else if (type == FLOAT)
    {
        if (!isNan(value) && !isInf(value)
            && (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()))
            printImpossible();
        else
            fromFloat(static_cast<float>(value));
    }
    else
        fromDouble(value);
}
