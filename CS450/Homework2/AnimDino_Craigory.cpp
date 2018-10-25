#include<iostream>
#include<fstream>

#include<Windows.h>
#include<gl/GL.h>
#include<gl/glut.h>

using namespace std;


typedef struct GLintPoint {
	GLint x, y;
};

void setWindow(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top); //Set window size
}

void setViewport(GLint left, GLint right, GLint bottom, GLint top) {
	glViewport(left, bottom, right - left, top - bottom);
}

void drawPolyLineFile(const char * fileName)
{
	fstream inStream;
	inStream.open(fileName, ios::in);	// open the file
	if (inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT);      // clear the screen 
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;		           // read the number of polylines
	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

GLintPoint dinoCenter = { 100, 100 };

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // set white background color
	glColor3f(0.0f, 0.0f, 0.0f);          // set the drawing color 
	glPointSize(6.0);		       // a ‘dot’ is 4 by 4 pixels
	glLineWidth(4.0);
	setWindow(0, 640, 0, 480);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
	glViewport(dinoCenter.x, dinoCenter.y, 128, 96);
	drawPolyLineFile("dino.dat");
	glFlush();
	glutSwapBuffers();
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
	GLint x = mouseX;
	GLint y = 480 - mouseY; // flip the y value as always
	switch (theKey)
	{
	case 'w':
		dinoCenter.y += 10;
		break;
	case 's':
		dinoCenter.y -= 10;
		break;
	case 'a':
		dinoCenter.x -= 10;
		break;
	case 'd':
		dinoCenter.x += 10;
		break;
	}
	glutPostRedisplay();
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 480);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Craigorys AnimDino"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	glutKeyboardFunc(myKeyboard);
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}