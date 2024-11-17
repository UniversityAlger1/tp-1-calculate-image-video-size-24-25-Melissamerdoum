#include <stdio.h>
#include <string.h>

float coloredImageSize(int w, int h, const char *unit) {
    // Calculate the image size in bytes
    int sizeInBytes = w * h * 3;

    // Convert size based on the desired unit
    if (strcmp(unit, "KB") == 0) {
        return sizeInBytes / 1024.0;
    } else if (strcmp(unit, "MB") == 0) {
        return sizeInBytes / (1024.0 * 1024);
    } else if (strcmp(unit, "GB") == 0) {
        return sizeInBytes / (1024.0 * 1024 * 1024);
    } else {
        // Default to bytes if no valid unit is provided
        return (float)sizeInBytes;
    }
}

int main() {
    int width, height;
    char unit[3]; // Expected input for unit is "B", "KB", "MB", or "GB"

    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the unit (B, KB, MB, GB): ");
    scanf("%2s", unit); // Limit input to 2 characters for safety

    float imageSize = coloredImageSize(width, height, unit);
    printf("The size of the colored image is: %.2f %s\n", imageSize, unit);

    return 0;
}
