template<typename T>
std::string formatWithCommas(T value) {
    static_assert(std::is_integral<T>::value, "formatWithCommas requires an integral type.");

    bool isNegative = value < 0;
    T absVal = isNegative ? -value : value;

    std::string number = std::to_string(absVal);
    int insertPosition = static_cast<int>(number.length()) - 3;

    while (insertPosition > 0) {
        number.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    return isNegative ? "-" + number : number;
}