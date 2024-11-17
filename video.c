#include <stdio.h>
#include <string.h>

float videoSize(int w, int h, int durationMovie, int durationCredits, int fps, const char *unit) {
    // Calculate frame sizes in bytes
    int colorFrameSize = w * h * 3; // Each color pixel uses 3 bytes (RGB)
    int bwFrameSize = w * h;        // Each B&W pixel uses 1 byte

    // Calculate the number of frames for each section
    int totalColorFrames = durationMovie * fps;
    int totalBWFrames = durationCredits * fps;

    // Calculate size of each section in bytes
    int colorSectionSize = colorFrameSize * totalColorFrames;
    int bwSectionSize = bwFrameSize * totalBWFrames;

    // Calculate total video size in bytes
    int totalSizeInBytes = colorSectionSize + bwSectionSize;

    // Convert the total size to the desired unit
    if (strcmp(unit, "KB") == 0) {
        return totalSizeInBytes / 1024.0;
    } else if (strcmp(unit, "MB") == 0) {
        return totalSizeInBytes / (1024.0 * 1024);
    } else if (strcmp(unit, "GB") == 0) {
        return totalSizeInBytes / (1024.0 * 1024 * 1024);
    } else if (strcmp(unit, "B") == 0) {
        return (float)totalSizeInBytes; // Return in bytes if "B" is specified
    } else {
        printf("Invalid unit entered. Defaulting to bytes.\n");
        return (float)totalSizeInBytes;
    }
}

int main() {
    int width, height, durationMovie, durationCredits, fps;
    char unit[3]; // Expected input for unit is "B", "KB", "MB", or "GB"

    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the duration of the color section (in seconds): ");
    scanf("%d", &durationMovie);
    printf("Enter the duration of the black-and-white section (in seconds): ");
    scanf("%d", &durationCredits);
    printf("Enter the Frames Per Second (fps): ");
    scanf("%d", &fps);
    printf("Enter the unit (B, KB, MB, GB): ");
    scanf("%2s", unit); // Limit input to 2 characters for safety

    float videoFileSize = videoSize(width, height, durationMovie, durationCredits, fps, unit);
    printf("The size of the video is: %.2f %s\n", videoFileSize, unit);

    return 0;
}
