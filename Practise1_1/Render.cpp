// glWinApp.cpp : Defines the entry point for the application.
#include "pch.h"
#include "glWinApp.h"

extern LPCSTR s1, s2, s3;

int LoadWindowDefaultFont()
{
    int id = glGenLists(256);
    wglUseFontBitmaps(wglGetCurrentDC(), 0, 256, id);
    return id;
}

void OutText(LPCSTR str, double x, double y, double z = 0)
{
    glRasterPos3d(x, y, z);
    glListBase(idFont);
    glCallLists(strlen(str), GL_UNSIGNED_BYTE, &str[0]);
}

void Render(RECT& clientRect)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glLoadIdentity();

    int Height = clientRect.bottom - clientRect.top;
    int Width = clientRect.right - clientRect.left;

    double centerX = Width / 2.0;
    double centerY = Height / 2.0;

    double x1 = -2.0;
    double x2 = 2.5;
    double y1 = -1.0;
    double y2 = 1.5;
    double dx = (x2 - x1) / 10;
    double dy = (y2 - y1) / 5;


    glViewport(0, 0, Width, Height);
    //gluOrtho2D(0, Width - 1.0, Height - 1.0, 0);
    gluOrtho2D(x1 - dx, x2, y1 - dy, y2 + dy);

    //Axis X
    glColor3d(0, 0, 0);
    glLineWidth(6);
    glBegin(GL_LINES);
    /*glVertex2d(10, Height - 10);
    glVertex2d(Width - 25, Height - 10);*/
    glVertex2d(x1, 0);
    glVertex2d(x2 - dx, 0);
    glEnd();

    /*glBegin(GL_TRIANGLES);
    glVertex2d(Width - 30, Height - 20);
    glVertex2d(Width - 30, Height);
    glVertex2d(Width - 10, Height - 10);
    glEnd();*/

    //Axis Y
    glColor3d(0, 0, 0);
    glLineWidth(6);
    glBegin(GL_LINES);
    /*glVertex2d(10, Height - 10);
    glVertex2d(10, 25);*/
    glVertex2d(0, y1);
    glVertex2d(0, y2);
    glEnd();

    /*glBegin(GL_TRIANGLES);
    glVertex2d(0, 30);
    glVertex2d(20, 30);
    glVertex2d(10, 10);
    glEnd();*/
    
    //Figure
    glColor3f(0.5, 0.5, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
    /*glVertex2d(0.1 * Width, 0.6 * Height);
    glVertex2d(0.3 * Width, 0.8 * Height);*/


    glVertex2d(x1 + 2 * dx, y1);
    glVertex2d(x1, y1 + dy);
    glVertex2d(x1, y1 + dy);
    glVertex2d(x1, y1 + 4 * dy);
    glVertex2d(x1, y1 + 4 * dy);
    glVertex2d(x1 + dx, y2);
    glVertex2d(x1 + dx, y2);
    glVertex2d(x1 + 3 * dx, y2 - dy);
    glVertex2d(x1 + 3 * dx, y2 - dy);
    glVertex2d(x1 + 3 * dx, y1 + dy);
    glVertex2d(x1 + 3 * dx, y1 + dy);
    glVertex2d(x1 + 2 * dx, y1);

    glEnd();

    //glColor3f(0.5, 0.5, 0.5);
    //glLineWidth(5);
    //glBegin(GL_LINES);
    //glVertex2d(0.1 * Width, 0.6 * Height);
    //glVertex2d(0.1 * Width, 0.2 * Height);
    //glEnd();

    //glColor3f(0.5, 0.5, 0.5);
    //glLineWidth(5);
    //glBegin(GL_LINES);
    //glVertex2d(0.1 * Width, 0.2 * Height);
    //glVertex2d(0.2 * Width, 0);
    //glEnd();

    //glColor3f(0.5, 0.5, 0.5);
    //glLineWidth(5);
    //glBegin(GL_LINES);
    //glVertex2d(0.4 * Width, 0.2 * Height);
    //glVertex2d(0.2 * Width, 0);
    //glEnd();

    //glColor3f(0.5, 0.5, 0.5);
    //glLineWidth(5);
    //glBegin(GL_LINES);
    //glVertex2d(0.4 * Width, 0.6 * Height);
    //glVertex2d(0.4 * Width, 0.2 * Height);
    //glEnd();

    //glColor3f(0.5, 0.5, 0.5);
    //glLineWidth(5);
    //glBegin(GL_LINES);
    //glVertex2d(0.4 * Width, 0.6 * Height);
    //glVertex2d(0.3 * Width, 0.8 * Height);
    //glEnd();

    //points
    glColor3d(0.3, 0.3, 0.3);
    glPointSize(7);
    glBegin(GL_POINTS);
    glVertex2d(5 * dx + x1 + 2 * dx, y1);
    glVertex2d(5 * dx + x1, y1 + dy);
    glVertex2d(5 * dx + x1, y1 + 4 * dy);
    glVertex2d(5 * dx + x1 + dx, y2);
    glVertex2d(5 * dx + x1 + 3 * dx, y2 - dy);
    glVertex2d(5 * dx + x1 + 3 * dx, y1 + dy);
    glVertex2d(5 * dx + x1 + 2 * dx, y1);
    glEnd();

    //glColor3d(0.3, 0.3, 0.3);
    //glPointSize(7);
    //glBegin(GL_POINTS);
    //glVertex2d(0.6 * Width, 0.6 * Height);
    //glEnd();

    //glColor3d(0.3, 0.3, 0.3);
    //glPointSize(7);
    //glBegin(GL_POINTS);
    //glVertex2d(0.6 * Width, 0.2 * Height);
    //glEnd();

    //glColor3d(0.3, 0.3, 0.3);
    //glPointSize(7);
    //glBegin(GL_POINTS);
    //glVertex2d(0.7 * Width, 0.01 * Height);
    //glEnd();

    //glColor3d(0.3, 0.3, 0.3);
    //glPointSize(7);
    //glBegin(GL_POINTS);
    //glVertex2d(0.9 * Width, 0.2 * Height);
    //glEnd();

    //glColor3d(0.3, 0.3, 0.3);
    //glPointSize(7);
    //glBegin(GL_POINTS);
    //glVertex2d(0.9 * Width, 0.6 * Height);
    //glEnd();
}