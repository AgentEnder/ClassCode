#include<Windows.h>
#include<gl/GL.h>
#include<gl/glut.h>

class GLintPoint
{
public:
	GLint x;
	GLint y;
};

GLintPoint corner[2];
bool selected = false;
int screenWidth = 640;
int screenHeight = 480;

void myInit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, screenWidth, screenHeight);
}

//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);
	if (selected)
	{
		glBegin(GL_QUADS);
		glVertex2i(corner[0].x, corner[0].y);
		glVertex2i(corner[0].x, corner[1].y);
		glVertex2i(corner[1].x, corner[1].y);
		glVertex2i(corner[1].x, corner[0].y);
		glEnd();
	}
	glutSwapBuffers();
}

void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
	{
		corner[0].x = x;
		corner[0].y = screenHeight - y;
		selected = true;
	}
	glutPostRedisplay();
}

void myPassiveMotion(int x, int y) {
	corner[1].x = x;
	corner[1].y = screenHeight - y;
	glutPostRedisplay();
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("RubberRectCraigory"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	glutMouseFunc(myMouse);
	glutPassiveMotionFunc(myPassiveMotion);
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}