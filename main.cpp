//imports
#include <windows.h>
#include <iostream>
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

//Type of shape (house or table)
char model;

//Translation variables
static float XSphere = 0, YSphere = 0, ZSphere = -14;

//Scaling variable
float Projection=0.5;

//Rotation variables
int xAxisRotation , yAxisRotation , zAxisRotation =0 ;
float _angle = -70.0f;
float angle_change_rate = 1.5f;

//Color variables
float c1=0.2;
float c2=0.3;
float c3=0.5;
float c4=0.8;
float c5=0.0;
float c6=1.0;

//Keyboard actions
void Keyboard(unsigned char key , int x ,int y) //
{

	switch (key) {
		//Move the model to the right when the 'd' key is pressed
		case 'd':
			XSphere += 0.1f;
			break;

		//Move the model to the left when the 'a' key is pressed
		case 'a':
			XSphere -= 0.1f;
			break;

		//Move the model up when the 'w' key is pressed
		case 'w':
			YSphere += 0.1f;
			break;

		//Move the model down when the 's' key is pressed
		case 's':
			YSphere -= 0.1f;
			break;

		//Zoom in when the '+' key is pressed
		case '+':
			Projection+=.05;
			break;

		//Zoom out when the '-' key is pressed
		case '-':
			if (Projection <= 0) break;
			else Projection -= 0.1;
			break;

		//Rotate the model on the x axis when the 'x' key is pressed
		case 'x':
			yAxisRotation=zAxisRotation=0;
			xAxisRotation=1;
			angle_change_rate = 1.5f;
			break;

		//Rotate the model on the y axis when the 'y' key is pressed
		case 'y':
			xAxisRotation=zAxisRotation=0;
			yAxisRotation=1;
			angle_change_rate = 1.5f;
			break;

		//Rotate the model on the z axis when the 'z' key is pressed
		case 'z':
			xAxisRotation=yAxisRotation=0;
			zAxisRotation=1;
			angle_change_rate = 1.5f;
			break;

		//Change model color
		case 'o':
			c1=rand() / (RAND_MAX + 1.);
			c3=rand() / (RAND_MAX + 1.);
			c2=rand() / (RAND_MAX + 1.);
			c4=rand() / (RAND_MAX + 1.);
			c5=rand() / (RAND_MAX + 1.);
			c6=rand() / (RAND_MAX + 1.);
			if (angle_change_rate ==0.0f )
				angle_change_rate = 0.0f;
			break;

		//Pause or resume model movement
		case 'p':
			if (angle_change_rate == 1.5f)
				angle_change_rate = 0.0f;
		   else
				angle_change_rate = 1.5f;

		//Default action
		default:
			break;
	}
}

//Mouse actions
void Mouse(int button, int state, int x, int y)
{
	switch (button)
	{
		//Move the model whereever the user clicks their left mouse button
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_UP)
			{
				XSphere = (x - 450) * 30.0 / 900;
				YSphere = (450 - y) * 30.0 / 900;
				ZSphere = -14;
				glutPostRedisplay();
			}
			break;
	}
}

//Vertexes
void Vertexes(char model)
{
	if (model == 'h')
	{
		//Door
		glBegin(GL_QUADS);
		glColor3f(c2, c5, c1);
		glVertex3f(-0.5, 0.0, 2.0);
		glVertex3f(-0.5, -1.0, 2.0);
		glVertex3f(0.0, -0.8, 2.0);
		glVertex3f(0.0, -0.2, 2.0);
		glEnd();
		glFlush();

		//Door opening 
		glBegin(GL_POLYGON);
		glColor3f(c6, c5, c4);
		glVertex3f(-0.5, 0.0, 2.0);
		glVertex3f(-0.5, -1.0, 2.0);
		glVertex3f(0.5, -1.0, 2.0);
		glVertex3f(0.5, 0.0, 2.0);
		glEnd();
		glFlush();

		//Door opening border
		glBegin(GL_LINE_LOOP);
		glColor3f(c1, c4, c6);
		glVertex3f(-0.5, 0.0, 2.0);
		glVertex3f(-0.5, -1.0, 2.0);
		glVertex3f(0.5, -1.0, 2.0);
		glVertex3f(0.5, 0.0, 2.0);
		glEnd();
		glFlush();

		//Square wall #1
		glBegin(GL_POLYGON);
		glColor3f(c4, c5, c6);
		glVertex3f(-1.0, 1.0, 2.0);
		glVertex3f(-1.0, -1.0, 2.0);
		glVertex3f(1.0, -1.0, 2.0);
		glVertex3f(1.0, 1.0, 2.0);
		glEnd();
		glFlush();

		//Square wall #2
		glBegin(GL_POLYGON);
		glColor3f(c2, c4, c6);
		glVertex3f(-1.0, 1.0, -2.0);
		glVertex3f(-1.0, -1.0, -2.0);
		glVertex3f(1.0, -1.0, -2.0);
		glVertex3f(1.0, 1.0, -2.0);
		glEnd();
		glFlush();

		//Rectangle wall #1
		glBegin(GL_POLYGON);
		glColor3f(c2, c2, c2);
		glVertex3f(1.0, 1.0, 2.0);
		glVertex3f(1.0, -1.0, 2.0);
		glVertex3f(1.0, -1.0, -2.0);
		glVertex3f(1.0, 1.0, -2.0);
		glEnd();
		glFlush();

		//Rectangle wall #2
		glBegin(GL_POLYGON);
		glColor3f(c6, c2, c4);
		glVertex3f(-1.0, 1.0, 2.0);
		glVertex3f(-1.0, -1.0, 2.0);
		glVertex3f(-1.0, -1.0, -2.0);
		glVertex3f(-1.0, 1.0, -2.0);
		glEnd();
		glFlush();

		//Small roof #1
		glBegin(GL_POLYGON);
		glColor3f(c1, c1, c1);
		glVertex3f(0.0, 2.0, 1.5);
		glVertex3f(-1.0, 1.0, 2.0);
		glVertex3f(1.0, 1.0, 2.0);
		glEnd();
		glFlush();

		//Small roof #2
		glBegin(GL_POLYGON);
		glColor3f(c1, c3, c5);
		glVertex3f(0.0, 2.0, -1.5);
		glVertex3f(-1.0, 1.0, -2.0);
		glVertex3f(1.0, 1.0, -2.0);
		glEnd();
		glFlush();

		//Big roof #1
		glBegin(GL_POLYGON);
		glColor3f(c3, c3, c3);
		glVertex3f(0.0, 2.0, 1.5);
		glVertex3f(1.0, 1.0, 2.0);
		glVertex3f(1.0, 1.0, -2.0);
		glVertex3f(0.0, 2.0, -1.5);
		glEnd();
		glFlush();

		//Big roof #2
		glBegin(GL_POLYGON);
		glColor3f(c4, c4, c4);
		glVertex3f(0.0, 2.0, 1.5);
		glVertex3f(-1.0, 1.0, 2.0);
		glVertex3f(-1.0, 1.0, -2.0);
		glVertex3f(0.0, 2.0, -1.5);
		glEnd();
		glFlush();

		//Chimney
		glBegin(GL_QUADS);
		glColor3f(c2, c2, c2);
		glVertex3f(0.3, 1.6, 0.0);
		glVertex3f(0.6, 1.3, 0.0);
		glVertex3f(0.6, 2.3, 0.0);
		glVertex3f(0.3, 2.3, 0.0);
		glVertex3f(0.3, 1.6, 0.3);
		glVertex3f(0.6, 1.3, 0.3);
		glVertex3f(0.6, 2.3, 0.3);
		glVertex3f(0.3, 2.3, 0.3);
		glVertex3f(0.3, 2.3, 0.0);
		glVertex3f(0.3, 2.3, 0.3);
		glVertex3f(0.3, 1.6, 0.3);
		glVertex3f(0.3, 1.6, 0.0);
		glVertex3f(0.6, 2.3, 0.0);
		glVertex3f(0.6, 1.3, 0.0);
		glVertex3f(0.6, 1.3, 0.3);
		glVertex3f(0.6, 2.3, 0.3);
		glEnd();
		glFlush();

		//Window #1
		glBegin(GL_POLYGON);
		glColor3f(c6, c1, c5);
		glVertex3f(1.0, 0.5, 0.5);
		glVertex3f(1.0, -0.5, 0.5);
		glVertex3f(1.0, -0.5, -0.5);
		glVertex3f(1.0, 0.5, -0.5);
		glEnd();
		glFlush();

		//Window #2
		glBegin(GL_POLYGON);
		glColor3f(c3, c5, c1);
		glVertex3f(-1.0, 0.5, 0.5);
		glVertex3f(-1.0, -0.5, 0.5);
		glVertex3f(-1.0, -0.5, -0.5);
		glVertex3f(-1.0, 0.5, -0.5);
		glEnd();
		glFlush();

		//Lines inside window #1
		glBegin(GL_LINES);
		glColor3f(c5, c5, c5);
		glVertex3f(1.0, 0.5, 0.0);
		glVertex3f(1.0, -0.5, 0.0);
		glVertex3f(1.0, 0.0, 0.5);
		glVertex3f(1.0, 0.0, -0.5);
		glEnd();

		//Lines inside window #2
		glBegin(GL_LINES);
		glColor3f(c3, c2, c1);
		glVertex3f(-1.0, 0.0, 0.5);
		glVertex3f(-1.0, 0.0, -0.5);
		glVertex3f(-1.0, 0.5, 0.0);
		glVertex3f(-1.0, -0.5, 0.0);
		glEnd();
		glFlush();

		//Border of window #1
		glBegin(GL_LINE_LOOP);
		glColor3f(c1, c2, c3);
		glVertex3f(1.0, 0.5, 0.5);
		glVertex3f(1.0, -0.5, 0.5);
		glVertex3f(1.0, -0.5, -0.5);
		glVertex3f(1.0, 0.5, -0.5);
		glEnd();
		glFlush();

		//Border of window #2
		glBegin(GL_LINE_LOOP);
		glColor3f(c1, c1, c1);
		glVertex3f(-1.0, 0.5, 0.5);
		glVertex3f(-1.0, -0.5, 0.5);
		glVertex3f(-1.0, -0.5, -0.5);
		glVertex3f(-1.0, 0.5, -0.5);
		glEnd();
		glFlush();

		//Floor
		glBegin(GL_POLYGON);
		glColor3f(c6, c4, c2);
		glVertex3f(-1.0,-1.0,2.0);
		glVertex3f(1.0, -1.0, 2.0);
		glVertex3f(1.0, -1.0, -2.0);
		glVertex3f(-1.0, -1.0, -2.0);
		glEnd();
		glFlush();
	}
	else if (model == 't')
	{
		//////////Tabletop
		//Tabletop top
		glVertex3f(2.0f, 0.2f, 2.0f);
		glVertex3f(-2.0f, 0.2f, 2.0f);
		glVertex3f(-2.0f, 0.2f, -2.0f);
		glVertex3f(2.0f, 0.2f, -2.0f);

		//Tabletop bottom
		glVertex3f(2.0f, -0.2f, 2.0f);
		glVertex3f(-2.0f, -0.2f, 2.0f);
		glVertex3f(-2.0f, -0.2f, -2.0f);
		glVertex3f(2.0f, -0.2f, -2.0f);

		//Tabletop side #1
		glVertex3f(-2.0f, -0.2f, 2.0f);
		glVertex3f(2.0f, -0.2f, 2.0f);
		glVertex3f(2.0f, 0.2f, 2.0f);
		glVertex3f(-2.0f, 0.2f, 2.0f);

		//Tabletop side #2
		glVertex3f(2.0f, -0.2f, -2.0f);
		glVertex3f(2.0f, 0.2f, -2.0f);
		glVertex3f(2.0f, 0.2f, 2.0f);
		glVertex3f(2.0f, -0.2f, 2.0f);

		//Tabletop side #3
		glVertex3f(-2.0f, -0.2f, -2.0f);
		glVertex3f(-2.0f, 0.2f, -2.0f);
		glVertex3f(2.0f, 0.2f, -2.0f);
		glVertex3f(2.0f, -0.2f, -2.0f);

		//Tabletop side #4
		glVertex3f(-2.0f, -0.2f, -2.0f);
		glVertex3f(-2.0f, -0.2f, 2.0f);
		glVertex3f(-2.0f, 0.2f, 2.0f);
		glVertex3f(-2.0f, 0.2f, -2.0f);



		//////////Leg #1
		//Leg #1 side #1
		glVertex3f(-1.8f,-0.2f,-1.2f);
		glVertex3f(-1.4f, -0.2f, -1.2f);
		glVertex3f(-1.4f, -3.0f, -1.2f);
		glVertex3f(-1.8f, -3.0f, -1.2f);

		//Leg #1 side #2
		glVertex3f(-1.8f,-0.2f,-1.6f);
		glVertex3f(-1.4f, -0.2f, -1.6f);
		glVertex3f(-1.4f, -3.0f, -1.6f);
		glVertex3f(-1.8f, -3.0f, -1.6f);

		//Leg #1 side #3
		glVertex3f(-1.8f,-0.2f,-1.6f);
		glVertex3f(-1.8f, -0.2f, -1.2f);
		glVertex3f(-1.8f, -3.0f, -1.2f);
		glVertex3f(-1.8f, -3.0f, -1.6f);

		//Leg #1 side #4
		glVertex3f(-1.4f,-0.2f,-1.6f);
		glVertex3f(-1.4f, -0.2f, -1.2f);
		glVertex3f(-1.4f, -3.0f, -1.2f);
		glVertex3f(-1.4f, -3.0f, -1.6f);



		//////////Leg #2
		//Leg #2 side #1
		glVertex3f(1.8f,-0.2f,1.6f);
		glVertex3f(1.4f, -0.2f, 1.6f);
		glVertex3f(1.4f, -3.0f, 1.6f);
		glVertex3f(1.8f, -3.0f, 1.6f);

		//Leg #2 side #2
		glVertex3f(1.8f,-0.2f,1.2f);
		glVertex3f(1.4f, -0.2f, 1.2f);
		glVertex3f(1.4f, -3.0f, 1.2f);
		glVertex3f(1.8f, -3.0f, 1.2f);

		//Leg #2 side #3
		glVertex3f(1.8f,-0.2f,1.6f);
		glVertex3f(1.8f, -0.2f, 1.2f);
		glVertex3f(1.8f, -3.0f, 1.2f);
		glVertex3f(1.8f, -3.0f, 1.6f);

		//Leg #2 side #4
		glVertex3f(1.4f,-0.2f,1.6f);
		glVertex3f(1.4f, -0.2f, 1.2f);
		glVertex3f(1.4f, -3.0f, 1.2f);
		glVertex3f(1.4f, -3.0f, 1.6f);



		//////////leg #3
		//leg #3 side #1
		glVertex3f(1.8f,-0.2f,-1.2f);
		glVertex3f(1.4f, -0.2f, -1.2f);
		glVertex3f(1.4f, -3.0f, -1.2f);
		glVertex3f(1.8f, -3.0f, -1.2f);

		//leg #3
		//leg #3 side #2
		glVertex3f(1.8f,-0.2f,-1.6f);
		glVertex3f(1.4f, -0.2f, -1.6f);
		glVertex3f(1.4f, -3.0f, -1.6f);
		glVertex3f(1.8f, -3.0f, -1.6f);

		//leg #3
		//leg #3 side #3
		glVertex3f(1.8f,-0.2f,-1.6f);
		glVertex3f(1.8f, -0.2f, -1.2f);
		glVertex3f(1.8f, -3.0f, -1.2f);
		glVertex3f(1.8f, -3.0f, -1.6f);

		//leg #3
		//leg #3 side #4
		glVertex3f(1.4f,-0.2f,-1.6f);
		glVertex3f(1.4f, -0.2f, -1.2f);
		glVertex3f(1.4f, -3.0f, -1.2f);
		glVertex3f(1.4f, -3.0f, -1.6f);



		//////////leg #4
		//leg #4 side #1
		glVertex3f(-1.8f,-0.2f,1.6f);
		glVertex3f(-1.4f, -0.2f, 1.6f);
		glVertex3f(-1.4f, -3.0f, 1.6f);
		glVertex3f(-1.8f, -3.0f, 1.6f);

		//leg #4 side #2
		glVertex3f(-1.8f,-0.2f,1.2f);
		glVertex3f(-1.4f, -0.2f, 1.2f);
		glVertex3f(-1.4f, -3.0f, 1.2f);
		glVertex3f(-1.8f, -3.0f, 1.2f);

		//leg #4 side #3
		glVertex3f(-1.8f,-0.2f,1.6f);
		glVertex3f(-1.8f, -0.2f, 1.2f);
		glVertex3f(-1.8f, -3.0f, 1.2f);
		glVertex3f(-1.8f, -3.0f, 1.6f);

		//leg #4 side #4
		glVertex3f(-1.4f,-0.2f,1.6f);
		glVertex3f(-1.4f, -0.2f, 1.2f);
		glVertex3f(-1.4f, -3.0f, 1.2f);
		glVertex3f(-1.4f, -3.0f, 1.6f);
	}
}

//Draw the 3D scene
void drawScene() {
	//Clear color and depth
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Change matrix mode to modelview mode
	glMatrixMode(GL_MODELVIEW);

	//Load the new matrix mode
	glLoadIdentity();

	//Apply scaling varaibles
	glScalef(Projection,Projection,1.0); //scaling the model

	//Apply position varaibles
	glTranslatef(XSphere, YSphere, ZSphere); // model position on the screen

	//Apply rotation varaibles
	glRotatef(_angle,xAxisRotation,yAxisRotation, zAxisRotation);

	//Apply color varaibles
	glColor3f(c1, c2, c3); //color of the back of the house

	//Apply vertexes
	Vertexes(model);

	//Performs a buffer swap
	glutSwapBuffers();
}

void Update(int value) {
	//Increase rotation angle
	_angle += angle_change_rate;
	if (_angle > 360) {
		_angle -= 360;
	}

	//Draw frame again to apply the angle change
	glutPostRedisplay();
	
	//Call this function again 25 milliseconds from now
	glutTimerFunc(25, Update, 0);
}

void handleResize(int w, int h) {
	//Change matrix mode to projection mode
	glMatrixMode(GL_MODELVIEW);

	//Load the new matrix mode
	glLoadIdentity();

	//Set viewer perspective
	gluPerspective(60.0, (double)w / (double)h, 1.0, 50.0);
}

int main(int argc, char** argv) {
	//Output instructions for user
	cout << "                                                      Welcome!\n";
	cout << "If you want a house press ==> h\n";
	cout << "If you want a table press ==> t\n";
	cin >> model;
	cout << "To move the model to the right press ==> d\n";
	cout << "To move the model to the left press ==> a\n";
	cout << "To rotate the model on x_axis press ==> x\n";
	cout << "To rotate the model on y_axis press ==> y\n";
	cout << "To rotate the model on z_axis press ==> z\n";
	cout << "To change color of the object press ==> o\n";
	cout << "To zoom in press ==> +\n";
	cout << "To zoom out press ==> -\n";
	cout << "To pause or resume model movement press ==> p\n";

	//Initialize GLUT
	glutInit(&argc, argv);

	//Initialize color and depth buffers
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	//Set window size
	glutInitWindowSize(900, 780);

	//Create the window
	glutCreateWindow("Model"); //house model name of the window

	//Set window position
	glutPositionWindow(500, 35);

	//Enable depth
	glEnable(GL_DEPTH_TEST);

	//Set the handler functions we defined earlier
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);

	//Run the update function to animate rotation (every 25 millioseconds it changes rotation angle and resets scene)
	Update(0);

	//Start GLUT
	glutMainLoop();
}
