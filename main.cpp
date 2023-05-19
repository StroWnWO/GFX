/// frame buffer means we draw something then clear it and draw it again
#include<windows.h>
#include <iostream>
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

static float XSphere = 0, YSphere = 0, ZSphere = -14; /// this variable is used to Translate the object
int xAxisRotation , yAxisRotation , zAxisRotation =0 ;
float Projection=0.5; /// this variable is used to zoom in and zoom out on the object
float _angle = -70.0f;
float angle_change_rate = 1.5f;
char choose;

/// Variables to change the color of the object each variable represent the rgb number that is passed to color3f function
float c1=1.0;
float c2=0.0;
float c3=1.0;

float c4=1.0;
float c6=1.0;
float c5=1.0;

///Initializes 3D rendering
void initRendering() {
 glEnable(GL_DEPTH_TEST); ///ashan yzbot al depth
 glEnable(GL_COLOR_MATERIAL); ///ashan yzbot kol lon fi makano
 glEnable(GL_LIGHT0); ///Enable light #0 //include light i in the evaluation of the lighting equation
 glEnable(GL_NORMALIZE); ///makes OpenGL automatically set their norm to 1
 glShadeModel(GL_SMOOTH); ///Enable smooth shading
}

        ///keyboard rotation and zooming in and zooming out
void keyboard(unsigned char key, int x ,int y) //
{

    switch (key) {
        /// Move the triangle to the right when the 'd' key is pressed  on postive X-axis
        case 'd':
            XSphere += 0.1f;
            break;

        /// Move the triangle to the left when the 'a' key is pressed   negtive X-axis
        case 'a':
            XSphere -= 0.1f;
            break;

        /// Move the triangle up when the 'w' key is pressed on postive Y-axis
        case 'w':
            YSphere += 0.1f;
            break;

        /// Move the triangle down when the 's' key is pressed on negtive Y-axis
        case 's':
            YSphere -= 0.1f;
            break;

        /// Move the triangle up when the 'q' key is pressed on postive Z-axis
        case 'q':
            XSphere=YSphere+=-1.0;
            ZSphere += 0.1;
            break;

        /// Move the triangle up when the 'e' key is pressed on negtive Z-axis
        case 'e':
            XSphere=YSphere+=1.0;
            ZSphere -= 0.1;
            break;

        ///Move the home Rotation In direction X-axis
        case 'x':
            yAxisRotation=zAxisRotation=0;
            xAxisRotation=1;
            angle_change_rate = 1.5f;
            break;

        ///Move the home Rotation In direction Y-axis
        case 'y':
            xAxisRotation=zAxisRotation=0;
            yAxisRotation=1;
            angle_change_rate = 1.5f;
            break;

        ///Move the home Rotation In direction Z-axis
        case 'z':
            xAxisRotation=yAxisRotation=0;
            zAxisRotation=1;
            angle_change_rate = 1.5f;
            break;

        ///Return the shape to the original point
        case 'r':
            XSphere=YSphere=0;
            ZSphere=-14;
            break;

        ///random colors to choose either 0 or 1 to be the random value
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

            ///Zoom  In
        case '+':
            if (angle_change_rate ==0.0f )
            {
                Projection+=.05;    ///Zoom in and shape off when pressing the letter L
                angle_change_rate = 0.0f;
            }
            else
            {
                Projection+=.05;    ///Zoom in and moving shape
                angle_change_rate = 1.5f;
            }
            break;

            ///Zoom Out
        case '-':
            if (angle_change_rate ==0.0f )
            {
                Projection-=.05;    ///Zoom out and shape off when pressing the letter L
                angle_change_rate = 0.0f;
            }
            else
            {
                Projection-=.05;    ///Zoom out and moving shape
                angle_change_rate = 1.5f;
            }
            break;

            ///Set the shape to move
        case 'l':
            if (angle_change_rate == 1.5f)
                angle_change_rate = 0.0f;
           else
                angle_change_rate = 1.5f;
        default:
            break;
    }
}

    ///Mouse Function
void MyMouse(int button, int state, int x, int y)
{
    switch (button)
    {
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
void Vertexes(char model)
{
    if(model == 'h')
    {
        //front facing
        //black lines for yellow door
        glBegin(GL_LINE_LOOP);
        glColor3f(c3,c6,c5);
        glVertex3f(-0.5, 0.0, 2.0);
        glVertex3f(-0.5, -1.0, 2.0);
        glVertex3f(0.0, -0.8, 2.0);
        glVertex3f(0.0, -0.2, 2.0);
        glEnd();
        glFlush();

        //black lines for white door inside of blue wall
        glBegin(GL_LINE_LOOP);
        glColor3f(c1, c4, c6);
        glVertex3f(-0.5, 0.0, 2.0);
        glVertex3f(-0.5, -1.0, 2.0);
        glVertex3f(0.5, -1.0, 2.0);
        glVertex3f(0.5, 0.0, 2.0);
        glEnd();
        glFlush();

        //yellow door inside of white door
        glBegin(GL_QUADS);
        glColor3f(c2, c5, c1);
        glVertex3f(-0.5, 0.0, 2.0);
        glVertex3f(-0.5, -1.0, 2.0);
        glVertex3f(0.0, -0.8, 2.0);
        glVertex3f(0.0, -0.2, 2.0);
        glEnd();

        //white door inside of blue wall
        glBegin(GL_POLYGON);
        glColor3f(c6, c5, c4);
        glVertex3f(-0.5, 0.0, 2.0);
        glVertex3f(-0.5, -1.0, 2.0);
        glVertex3f(0.5, -1.0, 2.0);
        glVertex3f(0.5, 0.0, 2.0);
        glEnd();

        //blue rectangle
        glBegin(GL_POLYGON);
        glColor3f(c4, c5, c6);
        glVertex3f(-1.0, 1.0, 2.0);
        glVertex3f(-1.0, -1.0, 2.0);
        glVertex3f(1.0, -1.0, 2.0);
        glVertex3f(1.0, 1.0, 2.0);
        glEnd();
        glFlush();
        //red traingle
        glBegin(GL_POLYGON);
        glColor3f(c1, c1, c1);
        glVertex3f(0.0, 2.0, 1.5);
        glVertex3f(-1.0, 1.0, 2.0);
        glVertex3f(1.0, 1.0, 2.0);
        glEnd();
        glFlush();
        //grey color smoke releaser
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
        //red top
        glBegin(GL_POLYGON);
        glColor3f(c3, c3, c3);
        glVertex3f(0.0, 2.0, 1.5);
        glVertex3f(1.0, 1.0, 2.0);
        glVertex3f(1.0, 1.0, -2.0);
        glVertex3f(0.0, 2.0, -1.5);
        glEnd();
        glFlush();

        glBegin(GL_POLYGON);
        glColor3f(c4, c4, c4);
        glVertex3f(0.0, 2.0, 1.5);
        glVertex3f(-1.0, 1.0, 2.0);
        glVertex3f(-1.0, 1.0, -2.0);
        glVertex3f(0.0, 2.0, -1.5);
        glEnd();
        glFlush();
        //+ shape black lines on white windows

        glBegin(GL_LINES);
        glColor3f(c5, c5, c5);
        glVertex3f(1.0, 0.5, 0.0);
        glVertex3f(1.0, -0.5, 0.0);
        glVertex3f(1.0, 0.0, 0.5);
        glVertex3f(1.0, 0.0, -0.5);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(c3, c2, c1);
        glVertex3f(-1.0, 0.0, 0.5);
        glVertex3f(-1.0, 0.0, -0.5);
        glVertex3f(-1.0, 0.5, 0.0);
        glVertex3f(-1.0, -0.5, 0.0);
        glEnd();
        glFlush();
        //square shape black outline for white window
        glBegin(GL_LINE_LOOP);
        glColor3f(c1, c2, c3);
        glVertex3f(1.0, 0.5, 0.5);
        glVertex3f(1.0, -0.5, 0.5);
        glVertex3f(1.0, -0.5, -0.5);
        glVertex3f(1.0, 0.5, -0.5);
        glEnd();
        glFlush();

        glBegin(GL_LINE_LOOP);
        glColor3f(c1, c1, c1);
        glVertex3f(-1.0, 0.5, 0.5);
        glVertex3f(-1.0, -0.5, 0.5);
        glVertex3f(-1.0, -0.5, -0.5);
        glVertex3f(-1.0, 0.5, -0.5);
        glEnd();
        glFlush();
        //white windows on yellow sides
        glBegin(GL_POLYGON);
        glColor3f(c6, c1, c5);
        glVertex3f(1.0, 0.5, 0.5);
        glVertex3f(1.0, -0.5, 0.5);
        glVertex3f(1.0, -0.5, -0.5);
        glVertex3f(1.0, 0.5, -0.5);
        glEnd();
        glFlush();

        glBegin(GL_POLYGON);
        glColor3f(c3, c5, c1);
        glVertex3f(-1.0, 0.5, 0.5);
        glVertex3f(-1.0, -0.5, 0.5);
        glVertex3f(-1.0, -0.5, -0.5);
        glVertex3f(-1.0, 0.5, -0.5);
        glEnd();
        glFlush();

        //yellow sides
        glBegin(GL_POLYGON);
        glColor3f(c2, c2, c2);
        glVertex3f(1.0, 1.0, 2.0);
        glVertex3f(1.0, -1.0, 2.0);
        glVertex3f(1.0, -1.0, -2.0);
        glVertex3f(1.0, 1.0, -2.0);
        glEnd();
        glFlush();

        glBegin(GL_POLYGON);
        glColor3f(c6, c2, c4);
        glVertex3f(-1.0, 1.0, 2.0);
        glVertex3f(-1.0, -1.0, 2.0);
        glVertex3f(-1.0, -1.0, -2.0);
        glVertex3f(-1.0, 1.0, -2.0);
        glEnd();
        glFlush();


        //back blue rectangle
        glBegin(GL_POLYGON);
        glColor3f(c2, c4, c6);
        glVertex3f(-1.0, 1.0, -2.0);
        glVertex3f(-1.0, -1.0, -2.0);
        glVertex3f(1.0, -1.0, -2.0);
        glVertex3f(1.0, 1.0, -2.0);
        glEnd();
        glFlush();

        //back red color  traingle
        glBegin(GL_POLYGON);
        glColor3f(c1, c3, c5);
        glVertex3f(0.0, 2.0, -1.5);
        glVertex3f(-1.0, 1.0, -2.0);
        glVertex3f(1.0, 1.0, -2.0);
        glEnd();
        glFlush();
        //green bottom of house
        glBegin(GL_POLYGON);
        glColor3f(c6, c4, c2);
        glVertex3f(-1.0,-1.0,2.0);
        glVertex3f(1.0, -1.0, 2.0);
        glVertex3f(1.0, -1.0, -2.0);
        glVertex3f(-1.0, -1.0, -2.0);
        glEnd();
        glFlush();
    }
    else if(model == 't')
    {

        glVertex3f(-2.0f, -0.2f, 2.0f);
        glVertex3f(2.0f, -0.2f, 2.0f);
        glVertex3f(2.0f, 0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, 2.0f);

        //Right

        glVertex3f(2.0f, -0.2f, -2.0f);
        glVertex3f(2.0f, 0.2f, -2.0f);
        glVertex3f(2.0f, 0.2f, 2.0f);
        glVertex3f(2.0f, -0.2f, 2.0f);

        //Back

        glVertex3f(-2.0f, -0.2f, -2.0f);
        glVertex3f(-2.0f, 0.2f, -2.0f);
        glVertex3f(2.0f, 0.2f, -2.0f);
        glVertex3f(2.0f, -0.2f, -2.0f);

        //Left

        glVertex3f(-2.0f, -0.2f, -2.0f);
        glVertex3f(-2.0f, -0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, -2.0f);

        //top

        glVertex3f(2.0f, 0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, -2.0f);
        glVertex3f(2.0f, 0.2f, -2.0f);

        //bottom

        glVertex3f(2.0f, -0.2f, 2.0f);
        glVertex3f(-2.0f, -0.2f, 2.0f);
        glVertex3f(-2.0f, -0.2f, -2.0f);
        glVertex3f(2.0f, -0.2f, -2.0f);

        //table leg right front
        //front

        glVertex3f(1.8f,-0.2f,1.6f);
        glVertex3f(1.4f, -0.2f, 1.6f);
        glVertex3f(1.4f, -3.0f, 1.6f);
        glVertex3f(1.8f, -3.0f, 1.6f);

        //back

        glVertex3f(1.8f,-0.2f,1.2f);
        glVertex3f(1.4f, -0.2f, 1.2f);
        glVertex3f(1.4f, -3.0f, 1.2f);
        glVertex3f(1.8f, -3.0f, 1.2f);

        //right

        glVertex3f(1.8f,-0.2f,1.6f);
        glVertex3f(1.8f, -0.2f, 1.2f);
        glVertex3f(1.8f, -3.0f, 1.2f);
        glVertex3f(1.8f, -3.0f, 1.6f);

        //left

        glVertex3f(1.4f,-0.2f,1.6f);
        glVertex3f(1.4f, -0.2f, 1.2f);
        glVertex3f(1.4f, -3.0f, 1.2f);
        glVertex3f(1.4f, -3.0f, 1.6f);

        //leg right back
        //front


        glVertex3f(1.8f,-0.2f,-1.2f);
        glVertex3f(1.4f, -0.2f, -1.2f);
        glVertex3f(1.4f, -3.0f, -1.2f);
        glVertex3f(1.8f, -3.0f, -1.2f);

        //back

        glVertex3f(1.8f,-0.2f,-1.6f);
        glVertex3f(1.4f, -0.2f, -1.6f);
        glVertex3f(1.4f, -3.0f, -1.6f);
        glVertex3f(1.8f, -3.0f, -1.6f);

        //right

        glVertex3f(1.8f,-0.2f,-1.6f);
        glVertex3f(1.8f, -0.2f, -1.2f);
        glVertex3f(1.8f, -3.0f, -1.2f);
        glVertex3f(1.8f, -3.0f, -1.6f);

        //left

        glVertex3f(1.4f,-0.2f,-1.6f);
        glVertex3f(1.4f, -0.2f, -1.2f);
        glVertex3f(1.4f, -3.0f, -1.2f);
        glVertex3f(1.4f, -3.0f, -1.6f);

        //leg left front

        glVertex3f(-1.8f,-0.2f,1.6f);
        glVertex3f(-1.4f, -0.2f, 1.6f);
        glVertex3f(-1.4f, -3.0f, 1.6f);
        glVertex3f(-1.8f, -3.0f, 1.6f);

        //back

        glVertex3f(-1.8f,-0.2f,1.2f);
        glVertex3f(-1.4f, -0.2f, 1.2f);
        glVertex3f(-1.4f, -3.0f, 1.2f);
        glVertex3f(-1.8f, -3.0f, 1.2f);

        //right

        glVertex3f(-1.8f,-0.2f,1.6f);
        glVertex3f(-1.8f, -0.2f, 1.2f);
        glVertex3f(-1.8f, -3.0f, 1.2f);
        glVertex3f(-1.8f, -3.0f, 1.6f);

        //left

        glVertex3f(-1.4f,-0.2f,1.6f);
        glVertex3f(-1.4f, -0.2f, 1.2f);
        glVertex3f(-1.4f, -3.0f, 1.2f);
        glVertex3f(-1.4f, -3.0f, 1.6f);

        //left back left

        //front

        glVertex3f(-1.8f,-0.2f,-1.2f);
        glVertex3f(-1.4f, -0.2f, -1.2f);
        glVertex3f(-1.4f, -3.0f, -1.2f);
        glVertex3f(-1.8f, -3.0f, -1.2f);

        //back

        glVertex3f(-1.8f,-0.2f,-1.6f);
        glVertex3f(-1.4f, -0.2f, -1.6f);
        glVertex3f(-1.4f, -3.0f, -1.6f);
        glVertex3f(-1.8f, -3.0f, -1.6f);

        //right

        glVertex3f(-1.8f,-0.2f,-1.6f);
        glVertex3f(-1.8f, -0.2f, -1.2f);
        glVertex3f(-1.8f, -3.0f, -1.2f);
        glVertex3f(-1.8f, -3.0f, -1.6f);

        //left

        glVertex3f(-1.4f,-0.2f,-1.6f);
        glVertex3f(-1.4f, -0.2f, -1.2f);
        glVertex3f(-1.4f, -3.0f, -1.2f);
        glVertex3f(-1.4f, -3.0f, -1.6f);


    }
}
    ///Draws the 3D scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///clearing color and depth

    glMatrixMode(GL_MODELVIEW); /// keep it like this // model viewing window
    glLoadIdentity(); /// resets current matrix

    glScalef(Projection,Projection,1.0); ///scaling the model

    /// we should do translation first
    glTranslatef(XSphere, YSphere, ZSphere); /// model position on the screen

    glRotatef(_angle,xAxisRotation,yAxisRotation, zAxisRotation); ///rotation


    glColor3f(c1,c2, c3); ///color of the back of the house

    glBegin(GL_QUADS); ///draw 4 sided figure

    Vertexes(choose);

    glEnd();
    glutSwapBuffers(); ///Performs a buffer swap on the layer in use for the current window because we using double buffer mode
}

    ///updating of the rotating angle of y-axis
void update(int value) {
    _angle += angle_change_rate;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay(); ///Mark the normal plane of current window as needing to be redisplayed
    glutTimerFunc(25, update, 0); ///timer for recalling the function
}

    ///Called when the window is resized --> without it model disappears
void handleResize(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION); ///glMatrixMode —> change matrix mode (to projection matrix)
    glLoadIdentity(); ///resets current projection matrix
    gluPerspective(60.0, (double)w / (double)h, 1.0, 50.0); ///setup projection function (view angle to y-axis, width / hight,The distance from the viewer to the near clipping plane,The distance from the viewer to the far clipping plane)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }
    int main(int argc, char** argv) {
    cout << "                                                      HELLO\n";
    cout << "If you want a house press ==> h\n";
    cout << "If you want a table press ==> t\n";
    cin >> choose;
    cout << "To rotate the model on x_axis press ==> x\n";
    cout << "To rotate the model on y_axis press ==> y\n";
    cout << "To rotate the model on z_axis press ==> z\n";
    cout << "To change color of the object press ==> o\n";
    cout << "To change Return the shape to the original point of the object press ==> r\n";
    cout << "To stabilize shape press ==> l\n";
    cout << "To Translate the model on postive  X_axis press ==> d\n";
    cout << "To Translate the model on negative X_axis press ==> a\n";
    cout << "To Translate the model on postive  Y_axis press ==> w\n";
    cout << "To Translate the model on negative Y_axis press ==> s\n";
    cout << "To Translate the model on postive  Z_axis press ==> q\n";
    cout << "To Translate the model on negative Z_axis press ==> e\n";
    cout << "To zoom in press ==> +\n";
    cout << "To zoom out press ==> -\n";


    ///Initialize GLUT
    glutInit(&argc, argv); ///glutInit is used to initialize the GLUT library
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); ///(two buffers,colors,depth)
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(300, -100);

    ///Create the window
    glutCreateWindow("house model"); ///house model name of the window
    initRendering();

    ///Set handler functions
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(MyMouse);
    update(0);
    glutMainLoop();
    return 0;
}
