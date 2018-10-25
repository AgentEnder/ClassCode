#include<Windows.h>
#include<gl/GL.h>
#include<gl/glut.h>



void drawCheckerboard(GLint x, GLint y, GLint w, GLint h, GLint squareWidth, GLint squareHeight, float foregroundColor[3], float backgroundColor[3]) {
	for (int i = 0; i < h / squareHeight; i++)
	{
		for (int j = 0; j < w / squareWidth; j++)
		{
			if ((i + j) % 2 == 0)
			{
				glColor3f(foregroundColor[0], foregroundColor[1], foregroundColor[2]);
			}
			else
			{
				glColor3f(backgroundColor[0], backgroundColor[1], backgroundColor[2]);
			}
			glRecti(x + j * squareWidth, y + i * squareHeight, x + (j + 1)*squareWidth, y + (i + 1)*squareHeight);
		}
	}
}

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // set white background color
	glColor3f(0.0f, 0.0f, 0.0f);          // set the drawing color 
	glPointSize(6.0);		       // a ‘dot’ is 4 by 4 pixels
	glLineWidth(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0); //Set window size
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	float foregroundColor[3] = { 0.1f,0.1f,0.1f };
	float backgroundColor[3] = { 0.8f,0.8f,0.8f };
	drawCheckerboard(0, 0, 640, 480, 80, 60, foregroundColor, backgroundColor);
	glColor3f(0.0f, 0.0f, 0.0f);
	glFlush();
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 480);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("my first checkerboard"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}