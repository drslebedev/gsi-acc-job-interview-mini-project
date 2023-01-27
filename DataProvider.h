#ifndef DataProvider_H
#define DataProvider_H

template<typename T>
concept DataSourceConcept = requires(T t) {
    { t.columns() } -> std::same_as<std::optional<std::vector<std::string>>>;
    { t.next() } -> std::same_as<std::optional<std::vector<std::string>>>;
};


template<typename T>
T fromString(const std::string& s) { return s; }

template<>
double fromString<double>(const std::string& s) { return std::stod(s); }

template<>
int fromString<int>(const std::string& s) { return std::stoi(s); }

template<typename DataType>
class DataProvider {
public:
    using DataColumn_t = std::vector<DataType>;
    using DataTable_t = std::vector<DataColumn_t>;

    DataProvider() = default;
    DataProvider(const DataProvider&) = default;
    DataProvider& operator=(const DataProvider&) = default;
    DataProvider(DataProvider&&) noexcept = default;
    DataProvider& operator=(DataProvider&&) noexcept = default;
    ~DataProvider() = default;

    template<DataSourceConcept DataSource, typename... Args>
    void fill(Args&&... args) {
        DataSource source {std::forward<Args...>(args...)};
        dataTable.clear();
        auto columns { source.columns() };
        if (!columns) {
            throw std::runtime_error("Number of columns must be at least 1.");
        }
        dataTable.resize(columns.value().size());
        while (true) {
            const auto row { source.next() };
            if (!row) {
                break;
            }

            if (dataTable.size() != row.value().size()) {
                throw std::runtime_error("Invalid data format: number of headers is not equal to number of columns");
            }
            for (int i = 0; i < row.value().size(); i++) {
                dataTable[i].push_back(fromString<DataType>(row.value()[i]));
            }
        }
    }

    size_t numColumns() const {
        return dataTable.size();
    }

    const DataTable_t& table() const {
        return dataTable;
    }

    const DataColumn_t& column(int column) const {
        if (column > dataTable.size()) {
            throw std::runtime_error("Actual number of culumns is less than requested");
        }
        return dataTable[column];
    }

private:
    DataTable_t dataTable;
};

#endif
