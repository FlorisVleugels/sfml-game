#include "XMLParser.h"
#include <fstream>
#include <iostream>

XMLParser::XMLParser(const std::string& fileName) : fileName(fileName) {}

std::string XMLParser::readFile() const {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        exit(1);
    }
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

std::string XMLParser::extractAttribute(const std::string& xmlContent, const std::string& tag, const std::string& attribute) const {
    std::string tagStart = "<" + tag;
    size_t tagPos = xmlContent.find(tagStart);
    if (tagPos == std::string::npos) {
        std::cerr << "Error: Could not find tag <" << tag << ">" << std::endl;
        exit(1);
    }

    size_t attrPos = xmlContent.find(attribute + "=\"", tagPos);
    if (attrPos == std::string::npos) {
        std::cerr << "Error: Could not find attribute " << attribute << " in tag <" << tag << ">" << std::endl;
        exit(1);
    }

    attrPos += attribute.length() + 2;
    size_t endPos = xmlContent.find("\"", attrPos);

    return xmlContent.substr(attrPos, endPos - attrPos);
}

std::string XMLParser::extractDataSection(const std::string& xmlContent) const {
    std::string startTag = "<data encoding=\"csv\">";
    std::string endTag = "</data>";

    size_t startPos = xmlContent.find(startTag);
    size_t endPos = xmlContent.find(endTag, startPos);

    if (startPos == std::string::npos || endPos == std::string::npos) {
        std::cerr << "Error: Could not find data section in XML" << std::endl;
        exit(1);
    }

    startPos += startTag.length();
    while (xmlContent[startPos] == '\n' || xmlContent[startPos] == '\r') {
        startPos++;
    }

    return xmlContent.substr(startPos, endPos - startPos);
}

std::vector<std::vector<int>> XMLParser::parseCSV(const std::string& data, int width, int height) const {
    std::vector<std::vector<int>> matrix(height, std::vector<int>(width, 0));

    size_t pos = 0;
    int row = 0, col = 0;

    while (pos < data.size()) {
        size_t commaPos = data.find(',', pos);
        if (commaPos == std::string::npos) commaPos = data.size();

        int value = std::stoi(data.substr(pos, commaPos - pos));

        matrix[row][col] = value;
        col++;

        if (col == width) {
            col = 0;
            row++;
        }

        pos = commaPos + 1;
    }

    return matrix;
}

std::vector<std::vector<int>> XMLParser::loadMatrix() {
    std::string xmlContent = readFile();

    // Extract width and height from the XML content
    int width = std::stoi(extractAttribute(xmlContent, "layer", "width"));
    int height = std::stoi(extractAttribute(xmlContent, "layer", "height"));

    std::string dataSection = extractDataSection(xmlContent);
    if (dataSection.empty()) {
        std::cerr << "Failed to extract data section." << std::endl;
        return {};
    }

    return parseCSV(dataSection, width, height);
}

// Method to print the matrix in the desired format
void XMLParser::printMatrix(const std::vector<std::vector<int>>& matrix) {
    std::cout << "const int level[] =\n{\n";
    for (const auto& row : matrix) {
        std::cout << "    ";
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << row[i];
            if (i < row.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ",\n";
    }
    std::cout << "};\n";
}

