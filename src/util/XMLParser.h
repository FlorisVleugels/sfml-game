#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <string>
#include <vector>

class XMLParser {
public:
    XMLParser(const std::string& fileName);
    std::vector<std::vector<int>> loadMatrix();
    void printMatrix(const std::vector<std::vector<int>>& matrix);

private:
    std::string fileName;
    std::string readFile() const;
    std::string extractAttribute(const std::string& xmlContent, const std::string& tag, const std::string& attribute) const;
    std::string extractDataSection(const std::string& xmlContent) const;
    std::vector<std::vector<int>> parseCSV(const std::string& data, int width, int height) const;
};

#endif

