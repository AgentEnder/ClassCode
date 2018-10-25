#include<Windows.h>
#include<gl/GL.h>
#include<gl/glut.h>

class GLintPoint
{
public:
	GLint x;
	GLint y;
};

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
	glFlush();
}

void myMouse(int button, int state, int x, int y) 
{
	static GLintPoint corner[2];
	static int numCorners = 0;
	
	y = 480 - y; //Convert y to be in same coordinate system as drawing.d
	
	if (state == GLUT_DOWN){
		if (button == GLUT_LEFT_BUTTON)
		{
			corner[numCorners].x = x;
			corner[numCorners].y = y;
			if (++numCorners == 2)
			{
				glRecti(corner[0].x, corner[0].y, corner[1].x, corner[1].y);
				numCorners = 0;
			}
		}
		else if (button == GLUT_RIGHT_BUTTON)
		{
			glutPostRedisplay();
		}
		glFlush();
	}

}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 480);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("RectanglesCraigory"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	glutMouseFunc(myMouse);
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}