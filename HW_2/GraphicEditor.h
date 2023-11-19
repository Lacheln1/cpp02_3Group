#pragma once

class GraphicEditor {
    int num;

public:
    GraphicEditor(int i);
    virtual void show() = 0;
    int getnum();
    void subnum();
};

class Line : public GraphicEditor {
public:
    Line(int index);
    void show() override;
};

class Circle : public GraphicEditor {
public:
    Circle(int index);
    void show() override;
};

class Rect : public GraphicEditor {
public:
    Rect(int index);
    void show() override;
};