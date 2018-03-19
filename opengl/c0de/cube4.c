// Color cube in OpenGL (using additional freeglut library)
// Date: March 2018
// Author: Jaime Reyes

#include <GL/freeglut.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <time.h>

const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 240;
const int SCREEN_FPS = 60;

float theta, xr, yr, zr;

int rotationQ = 1;

int t0 = 0;

int trigger(int param){
    draw();
    glutTimerFunc( 1000 / SCREEN_FPS, trigger, 1);

    return 0;
}

int draw(void){

    glMatrixMode(GL_MODELVIEW);

    if (rotationQ == 1){
        xr = 1.0f;
        yr = 1.0f;
    }
    else if (rotationQ == 120){
        xr = 0.0f;
        yr = 1.0f;
    }
    else if (rotationQ == 320){
        xr = 1.0f;
        yr = 0.0f;
        zr = 1.0f;
    }
    else if (rotationQ == 520){
        xr = 0.0f;
        yr = 1.0f;
        zr = 1.0f;
    }
    else if (rotationQ == 720){
        rotationQ = 1;
        xr = 0.0f;
        yr = 0.0f;
        zr = 0.0f;
    }
    else{

    }

    glRotatef(theta, xr, yr, zr);
    rotationQ++;

    glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
                glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-30.0f, 30.0f, 30.0f);
            glVertex3f(-30.0f, -30.0f, 30.0f);
            glVertex3f(30.0f, -30.0f, 30.0f);
            glVertex3f(30.0f, 30.0f, 30.0f);

                glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(30.0f, 30.0f, -30.0f);
            glVertex3f(30.0f, -30.0f, -30.0f);
            glVertex3f(30.0f, -30.0f, 30.0f);
            glVertex3f(30.0f, 30.0f, 30.0f);

                glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(30.0f, 30.0f, -30.0f);
            glVertex3f(30.0f, -30.0f, -30.0f);
            glVertex3f(-30.0f, -30.0f, -30.0f);
            glVertex3f(-30.0f, 30.0f, -30.0f);

                glColor3f(0.8f, 0.8f, 0.0f);
            glVertex3f(-30.0f, 30.0f, 30.0f);
            glVertex3f(-30.0f, -30.0f, 30.0f);
            glVertex3f(-30.0f, -30.0f, -30.0f);
            glVertex3f(-30.0f, 30.0f, -30.0f);

                glColor4f(0.7f, 0.0f, 1.0f, 0.3f);
            glVertex3f(-30.0f, 30.0f, -30.0f);
            glVertex3f(-30.0f, 30.0f, 30.0f);
            glVertex3f(30.0f, 30.0f, 30.0f);
            glVertex3f(30.0f, 30.0f, -30.0f);

                glColor4f(0.0f, 0.8f, 0.6f, 0.3f);
            glVertex3f(-30.0f, -30.0f, -30.0f);
            glVertex3f(-30.0f, -30.0f, 30.0f);
            glVertex3f(30.0f, -30.0f, 30.0f);
            glVertex3f(30.0f, -30.0f, -30.0f);

        glEnd();
    glutSwapBuffers();
    return 0;
    }

int teclas(unsigned char key, int x, int y){

    switch(key){
        case '+':
            theta = theta + 1.0f;
            break;
        case '-':
            theta = theta - 1.0f;
            break;
        default:
            break;
    }

    return 0;
}

int init(){
        glClearColor ( 0x16/255.0f, 0x04/255.0f, 0x16/255.0f, 0.0); // #363636 color

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, -(SCREEN_WIDTH/2.0f), (SCREEN_HEIGHT/2.0f) ); // left, right, bottom, top, near, far

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(SCREEN_WIDTH/2.0, SCREEN_HEIGHT/2.0, 0.0f);

    theta = 3.0f;
    xr = 1.0f;
    yr = 0.0f;
    zr = 0.0f;

    return 0;
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    // centrar ventana
    glutInitWindowPosition(800-(800-SCREEN_WIDTH)/4,600-(600-SCREEN_HEIGHT)/4);

    glutCreateWindow("cube4 (amd64)");

    init();

    glutDisplayFunc(draw);
    glutKeyboardFunc(teclas);
    glutTimerFunc(1000 / SCREEN_FPS, trigger, 0);

    glutMainLoop();
    return 0;
}
