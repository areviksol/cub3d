#include "cub.h"

// Function to check if a character is a valid map element
bool isValidMapElement(char c) 
{
    return c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W';
}

// Function to validate the map
bool validateMap(char** map, int mapRows, int mapCols) 
{
    // Check if map is surrounded by walls
    for (int i = 0; i < mapRows; i++) {
        for (int j = 0; j < mapCols; j++) {
            if (i == 0 || i == mapRows - 1 || j == 0 || j == mapCols - 1) {
                if (map[i][j] != '1') {
                    printf("Error: Map is not surrounded by walls.\n");
                    return false;
                }
            }
        }
    }

    // Check if map contains only valid map elements
    for (int i = 0; i < mapRows; i++) {
        for (int j = 0; j < mapCols; j++) {
            char c = map[i][j];
            if (!isValidMapElement(c)) {
                printf("Error: Invalid map element: %c\n", c);
                return false;
            }
        }
    }

    // Map is valid
    return true;
}

// Function to validate the elements in the map file
bool validateMapFile(char** fileLines, int numLines) 
{
    bool foundMap = false;
    bool foundTextures = false;
    bool foundFloorColor = false;

    for (int i = 0; i < numLines; i++) {
        char* line = fileLines[i];
        if (strlen(line) == 0) {
            // Skip empty lines
            continue;
        }

        if (!foundMap && strcmp(line, "MAP") == 0) {
            // Map element found
            foundMap = true;
            continue;
        }

        if (!foundTextures && (strncmp(line, "NO", 2) == 0 || strncmp(line, "SO", 2) == 0 ||
                                strncmp(line, "WE", 2) == 0 || strncmp(line, "EA", 2) == 0)) {
            // Textures element found
            foundTextures = true;
            continue;
        }

        if (!foundFloorColor && strncmp(line, "F", 1) == 0) {
            // Floor color element found
            foundFloorColor = true;
            continue;
        }
    }

    // Check if all required elements are found
    if (!foundMap) {
        printf("Error: Map element not found.\n");
        return false;
    }

    if (!foundTextures) {
        printf("Error: Textures element not found.\n");
        return false;
    }

    if (!foundFloorColor) {
        printf("Error: Floor color element not found.\n");
        return false;
    }

    // All elements are found
    return true;
}