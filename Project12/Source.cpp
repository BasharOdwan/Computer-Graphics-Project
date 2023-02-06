//project developed by Bashar Odwan
#include <GL/glut.h>
#include<iostream>
#include <math.h>
#include <random>
GLfloat sWidth = 500.0f, sHeight = 500.0f;
GLfloat uu = 240.0f;
GLfloat x = 0.0f, y = 0.0f;
GLfloat f = 90.0f;
GLfloat M_pi = atan(1) * 4;
GLboolean o = true;
GLint m[10][10];
int lives = 3;
GLfloat right = 1.0f, left = 1.0f, top = 1.0f, bottom = 1.0f;

void rann() {
	for (size_t i = 0; i < 5; i++)
	{
		int r = std::rand() % 10;
		int p = std::rand() % 10;
		m[r][p] = 1;
	}
}

void zeros() {
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			m[i][j] = 0;
		}
	}
}

void drawFilledSun(int x, int y, int red, int green, int blue, double radius) {
	int i;
	//glColor3ub(253, 184, 19);     
	glColor3ub(red, green, blue);
	double twicePi = 2.0 * M_pi;
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= 20; i++) {
		glVertex2f(
			(x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
		);
	}
	glEnd();
}

void bahaa(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLdouble aspectRatio = sWidth / sHeight;
	gluPerspective(60.0, aspectRatio, 0.01, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat eyePosition[] = { 0.0f,0.0f,496.0f };
	GLfloat eyeCenter[] = { 0.0f, 0.0f, 0.0f };
	GLfloat eyeUpVector[] = { 0.0f, 1.0f, 0.0f };
	gluLookAt(eyePosition[0], eyePosition[1], eyePosition[2],
		eyeCenter[0], eyeCenter[1], eyeCenter[2],
		eyeUpVector[0], eyeUpVector[1], eyeUpVector[2]);

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (m[i][j] == 1) {
				int xl = (j - 5) * 50 + (50 / 2);////////
				int yl = (i - 5) * 50 + (50 / 2);////////
				drawFilledSun(xl, yl, 255, 0, 0, 10.0);

			}
		}
	}

	if (o == true) {
		glColor3f(0.0, 0, 0);
		glRasterPos2i(-55, 265);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'P');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'P');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'C');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
		float xx = cos(f * M_pi / 180);
		float yy = sin(f * M_pi / 180);
		drawFilledSun(17.5f * xx, 17.5f * yy, 105, 105, 105, 4.0);
		drawFilledSun(30.0f * xx, 30.0f * yy, 155, 155, 155, 4.0);
		drawFilledSun(42.5f * xx, 42.5f * yy, 210, 210, 210, 4.0);
	}
	if (o == false) {
		x = x + cos(f * M_pi / 180) / 5;  //speed
		y = y + sin(f * M_pi / 180) / 5;  //speed

		if (top > 0) {
			if (f <= 180 && (y >= uu)) {
				while (f > 180)
				{
					f -= 180.0f;
				}
				f = 360 - f;
				top -= 0.5f;
			}
		}
		else
			if (f <= 180 && (y >= uu)) {
				o = true;
				x = 0.0f;
				y = 0.0f;
				lives--;
				std::cout << lives;
			}

		if (bottom > 0) {
			if (f >= 180 && (y <= -uu)) {
				while (f > 180)
				{
					f -= 180.0f;
				}
				f = 180 - f;
				bottom -= 0.5f;
			}
		}
		else
			if (f >= 180 && (y <= -uu)) {
				o = true;
				x = 0.0f;
				y = 0.0f;
				lives--;
				std::cout << lives;
			}

		if (left > 0) {
			if (f >= 180 && (x <= -uu)) {

				while (f > 180)
				{
					f -= 180.0f;
				}
				f = 360 - f;
				left -= 0.5f;
			}
			if (f <= 180 && (x <= -uu)) {
				while (f > 180)
				{
					f -= 180.0f;
				}
				f = 180 - f;
				left -= 0.5f;
			}
		}
		else
			if (f >= 180 && (x <= -uu) || (f <= 180 && (x <= -uu))) {
				o = true;
				x = 0.0f;
				y = 0.0f;
				lives--;
				std::cout << lives;
			}

		if (right > 0) {
			if (f >= 180 && (x >= uu)) {

				while (f > 180)
				{
					f -= 180.0f;
				}
				f = 360 - f;
				right -= 0.5f;
			}
			if (f <= 180 && (x >= uu)) {
				while (f > 180)
				{
					f -= 180.0f;
				}
				f = 180 - f;
				right -= 0.5f;
			}
		}
		else
			if (f >= 180 && (x >= uu) || (f <= 180 && (x >= uu))) {
				o = true;
				x = 0.0f;
				y = 0.0f;
				lives--;
				std::cout << lives;
			}

		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (m[i][j] == 1) {
					int xl = (j - 5) * 50 + (50 / 2);
					int yl = (i - 5) * 50 + (50 / 2);
					if (abs(xl - x) < 20 && (abs(yl - y) < 20))
						m[i][j] = 0;
				}
			}
		}
	}
	drawFilledSun(x, y, 0, 0, 0, 10.0);

	if (lives > 0) {
		for (int i = lives; i > 0; i--) {
			int padding = i * 30;
			int xp = -260 + padding;
			drawFilledSun(xp, 275, 0, 0, 0, 10.0);
		}
	}
	else {
		lives = 3;
		top = 1.0f;
		bottom = 1.0f;
		left = 1.0f;
		right = 1.0f;
		zeros();
		rann();
	}
	if (top > 0) {
		glColor3f(0.0f, 0.0f, top);
		glBegin(GL_QUADS);
		glVertex2f(-250.0f, 256.0f);
		glVertex2f(250.0f, 256.0f);
		glVertex2f(250.0, 250.0);
		glVertex2f(-250.0f, 250.0);
		glEnd();
	}
	if (bottom > 0) {
		glColor3f(0.0f, 0.0f, bottom);
		glBegin(GL_QUADS);
		glVertex2f(-250.0f, -256.0f);
		glVertex2f(250.0f, -256.0f);
		glVertex2f(250.0, -250.0);
		glVertex2f(-250.0f, -250.0);
		glEnd();
	}
	if (left > 0) {
		glColor3f(0.0f, 0.0f, left);
		glBegin(GL_QUADS);
		glVertex2f(-256.0f, 250.0f);
		glVertex2f(-250.0f, 250.0f);
		glVertex2f(-250.0, -250.0);
		glVertex2f(-256.0f, -250.0);
		glEnd();
	}
	if (right > 0) {
		glColor3f(0.0f, 0.0f, right);
		glBegin(GL_QUADS);
		glVertex2f(256.0f, 250.0f);
		glVertex2f(250.0f, 250.0f);
		glVertex2f(250.0, -250.0);
		glVertex2f(256.0f, -250.0);
		glEnd();
	}
	glutPostRedisplay();
	glFlush();
}
void ahmad(unsigned char inputChar, int x, int y) {
	switch (inputChar) {
	case ' ': o = false;
		break;
	case 27: exit(0); break;
	default: std::cout << inputChar << std::endl; break;
	}
}
void motionxy(int newx, int newy) {

	if (o) {
		newx = newx - sWidth / 2;
		newy = -newy + sHeight / 2;
		GLfloat dx = newx - x, dy = newy - y;
		f = 180 * atanf(dy / dx) / M_pi;
		if (dx < 0.0f)f = f + 180;
		if (dx > 0.0f && dy < 0.0f)f = f + 360;
	}
	//std::cout << f << std::endl;
}
void main(int argc, char** argv)
{
	zeros();
	srand(time(NULL));
	rann();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(sWidth, sHeight);
	glutCreateWindow("Game");

	glutPassiveMotionFunc(motionxy);
	glutDisplayFunc(bahaa);
	glutKeyboardFunc(ahmad);
	glutMainLoop();
}