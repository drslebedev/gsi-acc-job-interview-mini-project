#ifndef CSVSource_H
#define CSVSource_H

#include <format>
#include <fstream>
#include <optional>
#include <sstream>

class CSVSource
{
  public:
    CSVSource(const std::string path)
    {
        fileStream.open(path);
        if (!fileStream.is_open()) {
            throw std::runtime_error(std::string("Cannot open file: ") + path);
        }
    }

    CSVSource(const CSVSource&) = delete;
    CSVSource& operator=(const CSVSource&) = delete;
    CSVSource(CSVSource&&) noexcept = default;
    CSVSource& operator=(CSVSource&&) noexcept = default;

    ~CSVSource() { fileStream.close(); }

    std::optional<std::vector<std::string>> columns() { return next(); }

    std::optional<std::vector<std::string>> next()
    {
        std::string line;
        const auto& s{ std::getline(fileStream, line) };
        if (!s)
            return std::nullopt;
        return std::make_optional(split(std::move(line), ','));
    }

  private:
    std::ifstream fileStream;

    std::vector<std::string> split(const std::string& str, char delim) const
    {
        std::vector<std::string> result;
        std::stringstream ss(str);
        std::string item;
        while (getline(ss, item, delim)) {
            result.push_back(item);
        }
        return result;
    }
};

#endif
