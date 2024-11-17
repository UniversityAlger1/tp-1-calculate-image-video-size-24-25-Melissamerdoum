#include <stdio.h>

int grayScaleImageSize(int w, int h) {
    return w * h;
}

int main() {
    int width, height;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    int imageSize = grayScaleImageSize(width, height);
    printf("The size of the grayscale image is: %d bytes\n", imageSize);

    return 0;
}
