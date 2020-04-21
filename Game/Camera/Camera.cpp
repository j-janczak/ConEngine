#include "Camera.hpp"

Camera::Camera(int w, int h) {
    width = w;
    height = h;
}

int Camera::calculateX(int entityX, int loppI) {
    return entityX + loppI + (width / 2) - x;
}

int Camera::calculateY(int entityY, int loppI) {
    return entityY + loppI + (height / 2) - y;
}