
#ifndef COLORPICKER_H
#define COLORPICKER_H

GLfloat red = static_cast<GLfloat>(rand()) / RAND_MAX;     // Random value between 0.0 and 1.0
GLfloat green = static_cast<GLfloat>(rand()) / RAND_MAX;   // Random value between 0.0 and 1.0
GLfloat blue = static_cast<GLfloat>(rand()) / RAND_MAX;    // Random value between 0.0 and 1.0

void UpdateColorPick() {
	red = static_cast<GLfloat>(rand()) / RAND_MAX;
    green = static_cast<GLfloat>(rand()) / RAND_MAX;
    blue = static_cast<GLfloat>(rand()) / RAND_MAX;
}

#endif
